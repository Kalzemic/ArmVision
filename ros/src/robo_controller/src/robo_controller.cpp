#include <memory>
#include <atomic>
#include <functional>
#include <rclcpp_action/rclcpp_action.hpp>
#include <control_msgs/action/follow_joint_trajectory.hpp>
#include <pluginlib/class_list_macros.hpp>
#include <Eigen/Dense>
#include <controller_interface/controller_interface.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp_lifecycle/state.hpp>
#include <trajectory_msgs/msg/joint_trajectory.hpp>
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
 
        this->action_server_ = rclcpp_action::create_server<control_msgs::action::FollowJointTrajectory>(
            node,
            "follow_joint_trajectory",
            std::bind(&RoboController::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
            std::bind(&RoboController::handle_cancel, this, std::placeholders::_1),
            std::bind(&RoboController::handle_accepted, this, std::placeholders::_1)
        );

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


    controller_interface::return_type update(const rclcpp::Time& time, const rclcpp::Duration&) override
    {
        if (!this->goal_active_.load())
            return controller_interface::return_type::OK;
        auto trajectory = this->trajectory_buffer_.readFromRT();
        auto goal_handle = this->goal_handle_buffer_.readFromRT();
        auto result = this->result_buffer_.readFromRT();
        if (!trajectory || !(*trajectory) || !goal_handle || !(*goal_handle) || !result || !(*result))
        {
            return controller_interface::return_type::OK;
        }

        if (this->cancel_requested_.load())
        {
            (*goal_handle)->canceled(*result);

            // this->trajectory_buffer_.writeFromRT(nullptr);
            // this->goal_handle_buffer_.writeFromRT(nullptr);
            // this->result_buffer_.writeFromRT(nullptr);

            this->goal_active_.store(false);
            this->cancel_requested_.store(false);
            this->trajectory_start_time_ = rclcpp::Time(0);

            return controller_interface::return_type::OK;
        }

        if (this->trajectory_start_time_.nanoseconds() == 0)
            this->trajectory_start_time_ = time;
        double elapsed = (time - this->trajectory_start_time_).seconds();
        
        

        const auto& points = (*trajectory)->points;
        size_t point_idx = 0;
        while (point_idx < points.size() && rclcpp::Duration(points[point_idx].time_from_start).seconds() < elapsed)
        {
            ++point_idx;
        }
        if (point_idx >= points.size())
        {
            (*goal_handle)->succeed(*result);

            // this->trajectory_buffer_.writeFromRT(nullptr);
            // this->goal_handle_buffer_.writeFromRT(nullptr);
            // this->result_buffer_.writeFromRT(nullptr);
            this->goal_active_.store(false);
            this->trajectory_start_time_ = rclcpp::Time(0);

            return controller_interface::return_type::OK;
        }

        const auto& point = points[point_idx];
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

    rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID&, std::shared_ptr<const control_msgs::action::FollowJointTrajectory::Goal> goal)
    {
        if (goal->trajectory.points.empty())
            return rclcpp_action::GoalResponse::REJECT;

        bool expected = false;

        if (!this->goal_active_.compare_exchange_strong(expected, true))
            return rclcpp_action::GoalResponse::REJECT;
        
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }
    rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<rclcpp_action::ServerGoalHandle<control_msgs::action::FollowJointTrajectory>>)
    {
        this->cancel_requested_.store(true);
        return rclcpp_action::CancelResponse::ACCEPT;
    }

    void handle_accepted(const std::shared_ptr<rclcpp_action::ServerGoalHandle<control_msgs::action::FollowJointTrajectory>> goal_handle)
    {
        auto trajectory = std::make_shared<trajectory_msgs::msg::JointTrajectory>(goal_handle->get_goal()->trajectory);
        this->trajectory_buffer_.writeFromNonRT(trajectory);
        this->goal_handle_buffer_.writeFromNonRT(goal_handle);
        this->result_buffer_.writeFromNonRT(std::make_shared<control_msgs::action::FollowJointTrajectory::Result>());
        this->trajectory_start_time_ = rclcpp::Time(0);
    }
    
    rclcpp_action::Server<control_msgs::action::FollowJointTrajectory>::SharedPtr action_server_;
    realtime_tools::RealtimeBuffer<std::shared_ptr<rclcpp_action::ServerGoalHandle<control_msgs::action::FollowJointTrajectory>>> goal_handle_buffer_;
    
    pinocchio::Model model_;
    std::unique_ptr<pinocchio::Data> data_;

    std::atomic<bool> goal_active_{false};
    std::atomic<bool> cancel_requested_{false};
    realtime_tools::RealtimeBuffer<std::shared_ptr<trajectory_msgs::msg::JointTrajectory>> trajectory_buffer_;
    realtime_tools::RealtimeBuffer<std::shared_ptr<control_msgs::action::FollowJointTrajectory::Result>> result_buffer_;
    rclcpp::Time trajectory_start_time_;
    
    double kp_;
    double kv_;
};
}


PLUGINLIB_EXPORT_CLASS(
    RoboController::RoboController,
    controller_interface::ControllerInterface
)