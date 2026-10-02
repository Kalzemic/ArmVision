#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <control_msgs/action/follow_joint_trajectory.hpp>
#include "motion_executor/action/move_to_pose.hpp"

#include "kinematics/srv/kinematics.hpp"
#include "trajectory/srv/trajectory.hpp"
#include <trajectory_msgs/msg/joint_trajectory_point.hpp>
#include <thread>
#include <atomic>
#include <chrono>
#include <future>



namespace armvision
{
class MotionExecutor : public rclcpp::Node
{
public:
    MotionExecutor() : Node("Motion_Executor")
    {
        this->server_ = rclcpp_action::create_server<motion_executor::action::MoveToPose>(
            this, 
            "move_to_pose",
            std::bind(&MotionExecutor::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
            std::bind(&MotionExecutor::handle_cancel, this, std::placeholders::_1),
            std::bind(&MotionExecutor::handle_accepted, this, std::placeholders::_1)
        );
        this->controller_client_ = rclcpp_action::create_client<control_msgs::action::FollowJointTrajectory>(this, "follow_joint_trajectory");
        this->kinematics_client_ = this->create_client<kinematics::srv::Kinematics>("kinematics");
        this->trajectory_client_ = this->create_client<trajectory::srv::Trajectory>("trajectory");

        RCLCPP_INFO(get_logger(),"Motion Executor online");
    }
private: 
    rclcpp_action::Server<motion_executor::action::MoveToPose>::SharedPtr server_;
    rclcpp::Client<kinematics::srv::Kinematics>::SharedPtr kinematics_client_;
    rclcpp::Client<trajectory::srv::Trajectory>::SharedPtr trajectory_client_;
    rclcpp_action::Client<control_msgs::action::FollowJointTrajectory>::SharedPtr controller_client_;

    std::atomic<bool> goal_active_{false};


    rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID&, std::shared_ptr<const motion_executor::action::MoveToPose::Goal>)
    {
        bool expected = false;
        if (!this->goal_active_.compare_exchange_strong(expected, true))
            return rclcpp_action::GoalResponse::REJECT;
        

        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<rclcpp_action::ServerGoalHandle<motion_executor::action::MoveToPose>>)
    {
        return rclcpp_action::CancelResponse::ACCEPT;
    }

    void handle_accepted(const std::shared_ptr<rclcpp_action::ServerGoalHandle<motion_executor::action::MoveToPose>> goal_handle)
    {
        std::thread{std::bind(&MotionExecutor::execute, this, goal_handle)}.detach();
    }

    void execute(const std::shared_ptr<rclcpp_action::ServerGoalHandle<motion_executor::action::MoveToPose>> goal_handle)
    {
        const auto goal = goal_handle->get_goal();
        auto result = std::make_shared<motion_executor::action::MoveToPose::Result>();
        
        if(!this->kinematics_client_->service_is_ready() || !this->trajectory_client_->service_is_ready() || !this->controller_client_->action_server_is_ready())
        {
            result->success = false;
            goal_handle->abort(result);
            this->goal_active_.store(false);
            return;
        }
        
        auto kinematics_request = std::make_shared<kinematics::srv::Kinematics::Request>();

        kinematics_request->target = goal->target;
        kinematics_request->position_only = goal->position_only;

        auto kinematics_future = this->kinematics_client_->async_send_request(kinematics_request);
        auto kinematics_response = kinematics_future.get();
        if (!kinematics_response->success)
        {
            result->success = false;
            goal_handle->abort(result);
            this->goal_active_.store(false);
            return;
        }

        if(goal_handle->is_canceling())
        {
            result->success = false;
            goal_handle->canceled(result);
            this->goal_active_.store(false);
            return;
        }

        auto trajectory_request = std::make_shared<trajectory::srv::Trajectory::Request>();
        rclcpp::Duration duration(goal->duration);
        trajectory_request->duration = duration;
        trajectory_request->goal = kinematics_response->solution;
        auto trajectory_future = this->trajectory_client_->async_send_request(trajectory_request);
        auto trajectory_response = trajectory_future.get();
        if (!trajectory_response->success)
        {
            result->success = false;
            goal_handle->abort(result);
            this->goal_active_.store(false);
            return;
        }

        if(goal_handle->is_canceling())
        {
            result->success = false;
            goal_handle->canceled(result);
            this->goal_active_.store(false);
            return;
        }

        control_msgs::action::FollowJointTrajectory::Goal controller_goal;

        controller_goal.trajectory = trajectory_response->trajectory;
        
        auto controller_future=  this->controller_client_->async_send_goal(controller_goal);

        auto controller_goal_handle = controller_future.get();

        if(!controller_goal_handle)
        {
            result->success = false;
            goal_handle->abort(result);
            this->goal_active_.store(false);
            return;
        }

        auto controller_result_future = this->controller_client_->async_get_result(controller_goal_handle);
        
        bool cancel_sent = false;
        while(controller_result_future.wait_for(std::chrono::milliseconds(10)) != std::future_status::ready)
        {
            if(goal_handle->is_canceling() && !cancel_sent)
            {
                cancel_sent = true;
                this->controller_client_->async_cancel_goal(controller_goal_handle);
            }
        }
        auto controller_result = controller_result_future.get();

        if(controller_result.code == rclcpp_action::ResultCode::SUCCEEDED)
        {
            result->success = true;
            goal_handle->succeed(result);
        }
        else if (controller_result.code == rclcpp_action::ResultCode::CANCELED  && goal_handle->is_canceling())
        {
            result->success = false;
            goal_handle->canceled(result);
        }
        else
        {
            result->success = false;
            goal_handle->abort(result);
        }

        this->goal_active_.store(false);
        

    }
};
}


int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<armvision::MotionExecutor>();
    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}