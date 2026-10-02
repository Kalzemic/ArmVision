#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <trajectory_msgs/msg/joint_trajectory.hpp>
#include <Eigen/Core>
#include "trajectory/srv/trajectory.hpp"
#include <algorithm>
#include <stdexcept>


namespace armvision
{

class Trajectory : public rclcpp::Node
{
public: 
    Trajectory() : Node("ArmVision_Trajectory")
    {
        // Parameters
        // this->declare_parameter<double>("trajectory.duration", 2.0);
        // this->get_parameter("trajectory.duration", this->duration_);
        this->declare_parameter<double>("frequency", 1000.0);
        this->get_parameter("frequency", this->frequency_);

        // if (this->duration_ <= 0.0)
        // {
        //     throw std::invalid_argument("trajectory.duration must be greater than 0");
        // }

        if (this->frequency_ <= 0.0)
        {
            throw std::invalid_argument("frequency must be greater than 0");
        }

        this->joint_sub_ = this->create_subscription<sensor_msgs::msg::JointState>( "joint_states", 10,std::bind(&Trajectory::joint_callback, this, std::placeholders::_1));
        this->service_ = this->create_service<trajectory::srv::Trajectory>(
            "trajectory",
            std::bind(&Trajectory::service_callback, this, std::placeholders::_1, std::placeholders::_2)
        );

    }
private:

    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_sub_;
    rclcpp::Service<trajectory::srv::Trajectory>::SharedPtr service_;
    double duration_;
    double frequency_;
    sensor_msgs::msg::JointState::SharedPtr state_ = nullptr;

    void joint_callback(const sensor_msgs::msg::JointState::SharedPtr msg)
    {
        this->state_ = msg;
    }

    void service_callback(
        const std::shared_ptr<trajectory::srv::Trajectory::Request> request,
        std::shared_ptr<trajectory::srv::Trajectory::Response> response
    )
    {
        if(!this->state_)
        {
            response->success = false;
            return;
        }
        if (request->goal.position.size() != this->state_->position.size())
        {
            response->success = false;
            return;
        }
        if (this->state_->name.size() != this->state_->position.size() || request->goal.name.size() != request->goal.position.size())
        {
            response->success = false;
            return;
        }


        Eigen::VectorXd q0 = Eigen::Map<const Eigen::VectorXd>(this->state_->position.data(), this->state_->position.size());
        Eigen::VectorXd qf(q0.size());
        for (size_t i = 0; i < this->state_->name.size(); ++i)
        {
            const auto& joint_name = this->state_->name[i];
            auto it = std::find(request->goal.name.begin(), request->goal.name.end(), joint_name);
            if (it == request->goal.name.end())
            {
                response->success = false;
                return;
            }
            size_t goal_index = std::distance(request->goal.name.begin(), it);
            qf[i] = request->goal.position[goal_index];
        }

        rclcpp::Duration duration(request->duration);
        double T = static_cast<double>(duration.seconds()) + static_cast<double>(duration.nanoseconds()) * 1e-9;

        Eigen::VectorXd a0 = q0;
        Eigen::VectorXd a1 = Eigen::VectorXd::Zero(q0.size());
        Eigen::VectorXd a2 = -3.0 * (q0 - qf) / (T * T);
        Eigen::VectorXd a3 = 2 * (q0 - qf) / (T * T * T);

        response->trajectory.joint_names = this->state_->name;
        
        size_t samples = static_cast<size_t>(T * this->frequency_);
        for( size_t i = 0; i <= samples; i++)
        {
            trajectory_msgs::msg::JointTrajectoryPoint point;

            double t = i / this->frequency_;
            double t2 = t * t;
            double t3 = t2 * t;
            
            Eigen::VectorXd ddq = (2 * a2) + (6 * a3 * t);
            Eigen::VectorXd dq =  a1 + (2 * a2 * t) + (3 * a3 * t2);  
            Eigen::VectorXd q = a0 + (a1 * t) + (a2 * t2) + (a3 * t3);
            
            point.time_from_start = rclcpp::Duration::from_seconds(t);
            point.positions.assign(q.data(), q.data() + q.size());
            point.velocities.assign(dq.data(), dq.data() + dq.size());
            point.accelerations.assign(ddq.data(), ddq.data() + ddq.size());

            response->trajectory.points.push_back(point);
        }

        response->success = true;
    }
};

}
int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<armvision::Trajectory>();

    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}