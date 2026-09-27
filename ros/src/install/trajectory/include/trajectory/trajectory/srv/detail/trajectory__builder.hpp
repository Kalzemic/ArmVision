// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trajectory:srv/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef TRAJECTORY__SRV__DETAIL__TRAJECTORY__BUILDER_HPP_
#define TRAJECTORY__SRV__DETAIL__TRAJECTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "trajectory/srv/detail/trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace trajectory
{

namespace srv
{

namespace builder
{

class Init_Trajectory_Request_duration
{
public:
  explicit Init_Trajectory_Request_duration(::trajectory::srv::Trajectory_Request & msg)
  : msg_(msg)
  {}
  ::trajectory::srv::Trajectory_Request duration(::trajectory::srv::Trajectory_Request::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trajectory::srv::Trajectory_Request msg_;
};

class Init_Trajectory_Request_goal
{
public:
  Init_Trajectory_Request_goal()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Trajectory_Request_duration goal(::trajectory::srv::Trajectory_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return Init_Trajectory_Request_duration(msg_);
  }

private:
  ::trajectory::srv::Trajectory_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::trajectory::srv::Trajectory_Request>()
{
  return trajectory::srv::builder::Init_Trajectory_Request_goal();
}

}  // namespace trajectory


namespace trajectory
{

namespace srv
{

namespace builder
{

class Init_Trajectory_Response_trajectory
{
public:
  explicit Init_Trajectory_Response_trajectory(::trajectory::srv::Trajectory_Response & msg)
  : msg_(msg)
  {}
  ::trajectory::srv::Trajectory_Response trajectory(::trajectory::srv::Trajectory_Response::_trajectory_type arg)
  {
    msg_.trajectory = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trajectory::srv::Trajectory_Response msg_;
};

class Init_Trajectory_Response_success
{
public:
  Init_Trajectory_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Trajectory_Response_trajectory success(::trajectory::srv::Trajectory_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Trajectory_Response_trajectory(msg_);
  }

private:
  ::trajectory::srv::Trajectory_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::trajectory::srv::Trajectory_Response>()
{
  return trajectory::srv::builder::Init_Trajectory_Response_success();
}

}  // namespace trajectory

#endif  // TRAJECTORY__SRV__DETAIL__TRAJECTORY__BUILDER_HPP_
