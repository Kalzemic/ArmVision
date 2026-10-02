#include <rclcpp/rclcpp.hpp>


#include <sensor_msgs/msg/joint_state.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include "kinematics/srv/kinematics.hpp"

#include <memory>
#include <string>

#include <Eigen/Core>
#include <Eigen/Geometry>

#include <pinocchio/parsers/urdf.hpp>
#include <pinocchio/algorithm/kinematics.hpp>
#include <pinocchio/algorithm/frames.hpp>
#include <pinocchio/algorithm/jacobian.hpp>
#include <pinocchio/multibody/model.hpp>
#include <pinocchio/multibody/data.hpp>
#include <pinocchio/spatial/explog.hpp>
#include <pinocchio/algorithm/joint-configuration.hpp>








namespace armvision{
class Kinematics : public rclcpp::Node
{

public: 
    Kinematics(const rclcpp::NodeOptions& options) : Node("Armvision_Kinematics", options)
    {
        
        // Parameters 
        this->declare_parameter<int>("ik.max_iterations", 100);
        this->declare_parameter<double>("ik.epsilon", 1e-4);
        this->declare_parameter<double>("ik.step_size", 0.5);
        this->declare_parameter<double>("ik.damping", 1e-3);
        this->declare_parameter<std::string>("end_effector", "end_effector");
        
        std::string ee_name;
        this->get_parameter("end_effector", ee_name);


        this->get_parameter("ik.max_iterations", max_iterations_);
        this->get_parameter("ik.epsilon", epsilon_);
        this->get_parameter("ik.step_size", step_size_);
        this->get_parameter("ik.damping", damping_);


        // this->pub_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_goal", 10);
        // this->sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>("pose",10, std::bind(&Kinematics::pose_callback,this,std::placeholders::_1));
        this->service_ = this->create_service<kinematics::srv::Kinematics>("kinematics",std::bind(&Kinematics::service_callback,this,std::placeholders::_1, std::placeholders::_2));
        this->joint_sub_ = this->create_subscription<sensor_msgs::msg::JointState>( "joint_states", 10,std::bind(&Kinematics::joint_callback, this, std::placeholders::_1));
        
        this->declare_parameter<std::string>("robot_description", "");
        std::string urdf;
        this->get_parameter("robot_description",urdf);
    
        pinocchio::urdf::buildModelFromXML(urdf, this->model_);
        
        if (!this->model_.existFrame(ee_name))
        {
            throw std::invalid_argument("End-effector frame does not exist: " + ee_name);
        }
        this->end_effector_ = this->model_.getFrameId(ee_name);
        
        data_ = std::make_unique<pinocchio::Data>(model_);
    }

    void joint_callback(const sensor_msgs::msg::JointState::SharedPtr msg)
    {
        this->state_ = msg;
    }

    Eigen::VectorXd jointStateToQ(const sensor_msgs::msg::JointState& state)
    {
        Eigen::VectorXd q = pinocchio::neutral(this->model_);
        if (state.position.size() != state.name.size())
            return q;

        for (size_t i = 0; i < state.name.size(); ++i)
        {
            if(!this->model_.existJointName(state.name[i]))
                continue;

            pinocchio::JointIndex joint_id = this->model_.getJointId(state.name[i]);
            
            const auto& joint = this->model_.joints[joint_id];

            if(joint.nq() == 1)
                q[joint.idx_q()] = state.position[i];
        }
        return q;
    }
    void qToJointState(const Eigen::VectorXd& q, sensor_msgs::msg::JointState& state)
    {
        state.name = this->state_->name;
        state.position.resize(state.name.size());

        for (size_t i = 0; i < state.name.size(); ++i)
        {
            if (!this->model_.existJointName(state.name[i]))
                continue;

            pinocchio::JointIndex joint_id = this->model_.getJointId(state.name[i]);

            const auto& joint = this->model_.joints[joint_id];

            if (joint.nq() == 1)
                state.position[i] = q[joint.idx_q()];
        }
    }

    void service_callback( const std::shared_ptr<kinematics::srv::Kinematics::Request> request, std::shared_ptr<kinematics::srv::Kinematics::Response> response)
    {   
        if (!this->state_)
        {
            response->success = false;
            return;
        }

        // Target Construction
        const auto& msg = request->target;
        Eigen::Vector3d position(msg.pose.position.x, msg.pose.position.y, msg.pose.position.z);
        Eigen::Quaterniond quaternion(msg.pose.orientation.w, msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z);
        quaternion.normalize();
        pinocchio::SE3 target(quaternion.toRotationMatrix(),position);
        pinocchio::FrameIndex frame_id = this->model_.getFrameId(msg.header.frame_id);
        target = this->data_->oMf[frame_id] * target;

        // State Evaluation
        Eigen::VectorXd q = jointStateToQ(*this->state_);
        q = q.cwiseMax(this->model_.lowerPositionLimit).cwiseMin(this->model_.upperPositionLimit);
        
        const double rot_w = request->position_only? 0.0 : 1.0;
        Eigen::Matrix<double, 6, 1> w;
        w << 1, 1, 1, rot_w, rot_w, rot_w;
        Eigen::MatrixXd J(6, this->model_.nv);

        for(int i = 0; i < this->max_iterations_; i++)
        {
            // Forward kinematics
            pinocchio::forwardKinematics(this->model_, *this->data_, q);
            pinocchio::updateFramePlacements(this->model_, *this->data_);
            const pinocchio::SE3& current = data_->oMf[this->end_effector_];

            // Error computation
            Eigen::Matrix<double, 6, 1> err;
            err.head<3>() = target.translation() - current.translation();
            const Eigen::Matrix3d E = target.rotation() * current.rotation().transpose();
            err.tail<3>() = pinocchio::log3(E);

            err = w.asDiagonal() * err;
            // Goal Pose 
            if (err.norm() < this->epsilon_)
            {
                response->success = true;
                qToJointState(q, response->solution);
                return;
            }


            // Jacobian Computation
            J.setZero();
            pinocchio::computeFrameJacobian(this->model_, *this->data_, q, this->end_effector_, pinocchio::LOCAL_WORLD_ALIGNED, J);
    
            Eigen::Matrix3d Jlog;
            pinocchio::Jlog3(E, Jlog);
            J.bottomRows<3>() = Jlog * J.bottomRows<3>();
            J = w.asDiagonal() * J;

            // A = J * J_T
            Eigen::Matrix<double, 6, 6> A = J * J.transpose();

            
            // A = A + lambda**2 * I
            A.diagonal().array() += this->damping_ * this->damping_;

            // dq = J_T * A ** -1 
            auto J_pinv = J.transpose() * A.ldlt().solve(Eigen::Matrix<double, 6, 6>::Identity());

            // 
            Eigen::VectorXd dq = J_pinv * err;
            q = pinocchio::integrate(this->model_, q, this->step_size_ * dq);
            q = q.cwiseMax(this->model_.lowerPositionLimit).cwiseMin(this->model_.upperPositionLimit);
        }
        
        response->success = false;
        return;   
    }

private:
    int max_iterations_;
    double epsilon_;
    double step_size_;
    double damping_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_sub_;
    rclcpp::Service<kinematics::srv::Kinematics>::SharedPtr service_;
    // rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr sub_;
    // rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr pub_;
    sensor_msgs::msg::JointState::SharedPtr state_ = nullptr;
    pinocchio::Model model_;
    std::unique_ptr<pinocchio::Data> data_;
    pinocchio::FrameIndex end_effector_;
};
}

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<armvision::Kinematics>(rclcpp::NodeOptions{});

    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}