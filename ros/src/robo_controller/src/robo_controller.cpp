#include <memory>
#include <functional>

#include <pluginlib/class_list_macros.hpp>
#include <Eigen/Dense>
#include <controller_interface/controller_interface.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp_lifecycle/state.hpp>
#include <trajectory_msgs/msg/joint_trajectory_point.hpp>
#include <pinocchio/parsers/urdf.hpp>
#include <pinocchio/multibody/model.hpp>
#include <pinocchio/multibody/data.hpp>
#include <pinocchio/algorithm/rnea.hpp>
#include <realtime_tools/realtime_buffer.hpp>


namespace RoboController{
class RoboController : public controller_interface::ControllerInterface
{
public:

    controller_interface::CallbackReturn on_init() override
    {
        return controller_interface::CallbackReturn::SUCCESS;
    }

   controller_interface::CallbackReturn on_configure(const rclcpp_lifecycle::State &) override  
    {
        
        auto node = this->get_node();

        node->declare_parameter<double>("frequency",5.0);    
        node->declare_parameter<double>("damping_ratio",1.0);    

        double wn = node->get_parameter("frequency").as_double();
        double zeta = node->get_parameter("damping_ratio").as_double();

        this->kp_ = wn * wn;
        this->kv_ = 2.0 * zeta *wn;
 
        this->trajectory_sub_ = node->create_subscription<trajectory_msgs::msg::JointTrajectoryPoint>(
            "trajectory_point",10, std::bind(&RoboController::trajectory_callback, this, std::placeholders::_1));

        std::string urdf;
        node->get_parameter("robot_description", urdf);

        pinocchio::urdf::buildModelFromXML(urdf, this->model_);
        data_ = std::make_unique<pinocchio::Data>(model_);
        
        return controller_interface::CallbackReturn::SUCCESS;
    }

    controller_interface::InterfaceConfiguration state_interface_configuration() const override
    {
        return {
            controller_interface::interface_configuration_type::ALL
        };
    }

    controller_interface::InterfaceConfiguration command_interface_configuration() const override
    {
        return {
            controller_interface::interface_configuration_type::ALL
        };
    }


    controller_interface::return_type update(const rclcpp::Time&, const rclcpp::Duration&) override
    {
        auto trajectory = this->trajectory_buffer_.readFromRT();

        if(!trajectory || !(*trajectory)) return controller_interface::return_type::OK;

        const auto& point = *(*trajectory);

        Eigen::Map<const Eigen::VectorXd> q_d(point.positions.data(),point.positions.size());
        Eigen::Map<const Eigen::VectorXd> qdot_d(point.velocities.data(),point.velocities.size());
        Eigen::Map<const Eigen::VectorXd> qdotdot_d(point.accelerations.data(),point.accelerations.size());
        
        Eigen::VectorXd q(model_.nq);
        Eigen::VectorXd qdot(model_.nv);

        size_t pos_idx = 0;
        size_t vel_idx = 0;
        for(size_t i=0; i < state_interfaces_.size();i++)
        {
            const auto& iface = state_interfaces_[i];

            if (iface.get_interface_name() == "position")
            { 
                q[pos_idx] = iface.get_value();
                pos_idx++;
            }
            else if (iface.get_interface_name() == "velocity") 
            {
                qdot[vel_idx] = iface.get_value();
                vel_idx++;
            }
        }

        auto acc = this->kp_ * (q_d - q) + this->kv_ * (qdot_d - qdot) + qdotdot_d;


        auto tau = pinocchio::rnea(this->model_, *data_, q, qdot, acc);

        size_t torque_idx = 0;

        for (auto& iface : command_interfaces_)
        {
            if (iface.get_interface_name() == "effort")
                iface.set_value(tau[torque_idx++]);
        }

        return controller_interface::return_type::OK;
    } 


private:

    void trajectory_callback(const trajectory_msgs::msg::JointTrajectoryPoint::SharedPtr msg)
    {
       trajectory_buffer_.writeFromNonRT(msg);
    }



    rclcpp::Subscription<trajectory_msgs::msg::JointTrajectoryPoint>::SharedPtr trajectory_sub_;
    pinocchio::Model model_;
    std::unique_ptr<pinocchio::Data> data_;
    realtime_tools::RealtimeBuffer<std::shared_ptr<trajectory_msgs::msg::JointTrajectoryPoint>> trajectory_buffer_;

    double kp_;
    double kv_;
};
}


PLUGINLIB_EXPORT_CLASS(
    RoboController::RoboController,
    controller_interface::ControllerInterface
)