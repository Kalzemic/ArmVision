// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kinematics:srv/Kinematics.idl
// generated code does not contain a copyright notice

#ifndef KINEMATICS__SRV__DETAIL__KINEMATICS__BUILDER_HPP_
#define KINEMATICS__SRV__DETAIL__KINEMATICS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "kinematics/srv/detail/kinematics__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace kinematics
{

namespace srv
{

namespace builder
{

class Init_Kinematics_Request_target
{
public:
  Init_Kinematics_Request_target()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kinematics::srv::Kinematics_Request target(::kinematics::srv::Kinematics_Request::_target_type arg)
  {
    msg_.target = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kinematics::srv::Kinematics_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinematics::srv::Kinematics_Request>()
{
  return kinematics::srv::builder::Init_Kinematics_Request_target();
}

}  // namespace kinematics


namespace kinematics
{

namespace srv
{

namespace builder
{

class Init_Kinematics_Response_solution
{
public:
  explicit Init_Kinematics_Response_solution(::kinematics::srv::Kinematics_Response & msg)
  : msg_(msg)
  {}
  ::kinematics::srv::Kinematics_Response solution(::kinematics::srv::Kinematics_Response::_solution_type arg)
  {
    msg_.solution = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kinematics::srv::Kinematics_Response msg_;
};

class Init_Kinematics_Response_success
{
public:
  Init_Kinematics_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Kinematics_Response_solution success(::kinematics::srv::Kinematics_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Kinematics_Response_solution(msg_);
  }

private:
  ::kinematics::srv::Kinematics_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinematics::srv::Kinematics_Response>()
{
  return kinematics::srv::builder::Init_Kinematics_Response_success();
}

}  // namespace kinematics

#endif  // KINEMATICS__SRV__DETAIL__KINEMATICS__BUILDER_HPP_
