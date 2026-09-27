// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kinematics:srv/Kinematics.idl
// generated code does not contain a copyright notice

#ifndef KINEMATICS__SRV__DETAIL__KINEMATICS__STRUCT_HPP_
#define KINEMATICS__SRV__DETAIL__KINEMATICS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'target'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__kinematics__srv__Kinematics_Request __attribute__((deprecated))
#else
# define DEPRECATED__kinematics__srv__Kinematics_Request __declspec(deprecated)
#endif

namespace kinematics
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Kinematics_Request_
{
  using Type = Kinematics_Request_<ContainerAllocator>;

  explicit Kinematics_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target(_init)
  {
    (void)_init;
  }

  explicit Kinematics_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _target_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _target_type target;

  // setters for named parameter idiom
  Type & set__target(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->target = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kinematics::srv::Kinematics_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinematics::srv::Kinematics_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinematics::srv::Kinematics_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinematics::srv::Kinematics_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinematics::srv::Kinematics_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinematics::srv::Kinematics_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinematics::srv::Kinematics_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinematics::srv::Kinematics_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinematics::srv::Kinematics_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinematics::srv::Kinematics_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinematics__srv__Kinematics_Request
    std::shared_ptr<kinematics::srv::Kinematics_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinematics__srv__Kinematics_Request
    std::shared_ptr<kinematics::srv::Kinematics_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Kinematics_Request_ & other) const
  {
    if (this->target != other.target) {
      return false;
    }
    return true;
  }
  bool operator!=(const Kinematics_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Kinematics_Request_

// alias to use template instance with default allocator
using Kinematics_Request =
  kinematics::srv::Kinematics_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kinematics


// Include directives for member types
// Member 'solution'
#include "sensor_msgs/msg/detail/joint_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__kinematics__srv__Kinematics_Response __attribute__((deprecated))
#else
# define DEPRECATED__kinematics__srv__Kinematics_Response __declspec(deprecated)
#endif

namespace kinematics
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Kinematics_Response_
{
  using Type = Kinematics_Response_<ContainerAllocator>;

  explicit Kinematics_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : solution(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit Kinematics_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : solution(_alloc, _init)
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
  using _solution_type =
    sensor_msgs::msg::JointState_<ContainerAllocator>;
  _solution_type solution;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__solution(
    const sensor_msgs::msg::JointState_<ContainerAllocator> & _arg)
  {
    this->solution = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kinematics::srv::Kinematics_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinematics::srv::Kinematics_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinematics::srv::Kinematics_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinematics::srv::Kinematics_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinematics::srv::Kinematics_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinematics::srv::Kinematics_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinematics::srv::Kinematics_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinematics::srv::Kinematics_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinematics::srv::Kinematics_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinematics::srv::Kinematics_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinematics__srv__Kinematics_Response
    std::shared_ptr<kinematics::srv::Kinematics_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinematics__srv__Kinematics_Response
    std::shared_ptr<kinematics::srv::Kinematics_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Kinematics_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->solution != other.solution) {
      return false;
    }
    return true;
  }
  bool operator!=(const Kinematics_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Kinematics_Response_

// alias to use template instance with default allocator
using Kinematics_Response =
  kinematics::srv::Kinematics_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kinematics

namespace kinematics
{

namespace srv
{

struct Kinematics
{
  using Request = kinematics::srv::Kinematics_Request;
  using Response = kinematics::srv::Kinematics_Response;
};

}  // namespace srv

}  // namespace kinematics

#endif  // KINEMATICS__SRV__DETAIL__KINEMATICS__STRUCT_HPP_
