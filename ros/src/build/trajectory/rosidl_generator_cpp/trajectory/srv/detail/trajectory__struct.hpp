// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from trajectory:srv/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef TRAJECTORY__SRV__DETAIL__TRAJECTORY__STRUCT_HPP_
#define TRAJECTORY__SRV__DETAIL__TRAJECTORY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'goal'
#include "sensor_msgs/msg/detail/joint_state__struct.hpp"
// Member 'duration'
#include "builtin_interfaces/msg/detail/duration__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__trajectory__srv__Trajectory_Request __attribute__((deprecated))
#else
# define DEPRECATED__trajectory__srv__Trajectory_Request __declspec(deprecated)
#endif

namespace trajectory
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Trajectory_Request_
{
  using Type = Trajectory_Request_<ContainerAllocator>;

  explicit Trajectory_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal(_init),
    duration(_init)
  {
    (void)_init;
  }

  explicit Trajectory_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal(_alloc, _init),
    duration(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_type =
    sensor_msgs::msg::JointState_<ContainerAllocator>;
  _goal_type goal;
  using _duration_type =
    builtin_interfaces::msg::Duration_<ContainerAllocator>;
  _duration_type duration;

  // setters for named parameter idiom
  Type & set__goal(
    const sensor_msgs::msg::JointState_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }
  Type & set__duration(
    const builtin_interfaces::msg::Duration_<ContainerAllocator> & _arg)
  {
    this->duration = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trajectory::srv::Trajectory_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const trajectory::srv::Trajectory_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trajectory::srv::Trajectory_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trajectory::srv::Trajectory_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trajectory::srv::Trajectory_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trajectory::srv::Trajectory_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trajectory::srv::Trajectory_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trajectory::srv::Trajectory_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trajectory::srv::Trajectory_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trajectory::srv::Trajectory_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trajectory__srv__Trajectory_Request
    std::shared_ptr<trajectory::srv::Trajectory_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trajectory__srv__Trajectory_Request
    std::shared_ptr<trajectory::srv::Trajectory_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Trajectory_Request_ & other) const
  {
    if (this->goal != other.goal) {
      return false;
    }
    if (this->duration != other.duration) {
      return false;
    }
    return true;
  }
  bool operator!=(const Trajectory_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Trajectory_Request_

// alias to use template instance with default allocator
using Trajectory_Request =
  trajectory::srv::Trajectory_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace trajectory


// Include directives for member types
// Member 'trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__trajectory__srv__Trajectory_Response __attribute__((deprecated))
#else
# define DEPRECATED__trajectory__srv__Trajectory_Response __declspec(deprecated)
#endif

namespace trajectory
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Trajectory_Response_
{
  using Type = Trajectory_Response_<ContainerAllocator>;

  explicit Trajectory_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : trajectory(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit Trajectory_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : trajectory(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _trajectory_type =
    trajectory_msgs::msg::JointTrajectory_<ContainerAllocator>;
  _trajectory_type trajectory;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__trajectory(
    const trajectory_msgs::msg::JointTrajectory_<ContainerAllocator> & _arg)
  {
    this->trajectory = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trajectory::srv::Trajectory_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const trajectory::srv::Trajectory_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trajectory::srv::Trajectory_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trajectory::srv::Trajectory_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trajectory::srv::Trajectory_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trajectory::srv::Trajectory_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trajectory::srv::Trajectory_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trajectory::srv::Trajectory_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trajectory::srv::Trajectory_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trajectory::srv::Trajectory_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trajectory__srv__Trajectory_Response
    std::shared_ptr<trajectory::srv::Trajectory_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trajectory__srv__Trajectory_Response
    std::shared_ptr<trajectory::srv::Trajectory_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Trajectory_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->trajectory != other.trajectory) {
      return false;
    }
    return true;
  }
  bool operator!=(const Trajectory_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Trajectory_Response_

// alias to use template instance with default allocator
using Trajectory_Response =
  trajectory::srv::Trajectory_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace trajectory

namespace trajectory
{

namespace srv
{

struct Trajectory
{
  using Request = trajectory::srv::Trajectory_Request;
  using Response = trajectory::srv::Trajectory_Response;
};

}  // namespace srv

}  // namespace trajectory

#endif  // TRAJECTORY__SRV__DETAIL__TRAJECTORY__STRUCT_HPP_
