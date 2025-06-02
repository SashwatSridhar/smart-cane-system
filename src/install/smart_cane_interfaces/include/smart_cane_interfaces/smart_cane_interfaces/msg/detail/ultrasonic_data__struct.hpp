// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from smart_cane_interfaces:msg/UltrasonicData.idl
// generated code does not contain a copyright notice

#ifndef SMART_CANE_INTERFACES__MSG__DETAIL__ULTRASONIC_DATA__STRUCT_HPP_
#define SMART_CANE_INTERFACES__MSG__DETAIL__ULTRASONIC_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__smart_cane_interfaces__msg__UltrasonicData __attribute__((deprecated))
#else
# define DEPRECATED__smart_cane_interfaces__msg__UltrasonicData __declspec(deprecated)
#endif

namespace smart_cane_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UltrasonicData_
{
  using Type = UltrasonicData_<ContainerAllocator>;

  explicit UltrasonicData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distance_cm = 0.0f;
      this->confidence = 0.0f;
      this->obstacle_detected = false;
    }
  }

  explicit UltrasonicData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distance_cm = 0.0f;
      this->confidence = 0.0f;
      this->obstacle_detected = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _distance_cm_type =
    float;
  _distance_cm_type distance_cm;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _obstacle_detected_type =
    bool;
  _obstacle_detected_type obstacle_detected;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__distance_cm(
    const float & _arg)
  {
    this->distance_cm = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__obstacle_detected(
    const bool & _arg)
  {
    this->obstacle_detected = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    smart_cane_interfaces::msg::UltrasonicData_<ContainerAllocator> *;
  using ConstRawPtr =
    const smart_cane_interfaces::msg::UltrasonicData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<smart_cane_interfaces::msg::UltrasonicData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<smart_cane_interfaces::msg::UltrasonicData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      smart_cane_interfaces::msg::UltrasonicData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<smart_cane_interfaces::msg::UltrasonicData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      smart_cane_interfaces::msg::UltrasonicData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<smart_cane_interfaces::msg::UltrasonicData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<smart_cane_interfaces::msg::UltrasonicData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<smart_cane_interfaces::msg::UltrasonicData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__smart_cane_interfaces__msg__UltrasonicData
    std::shared_ptr<smart_cane_interfaces::msg::UltrasonicData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__smart_cane_interfaces__msg__UltrasonicData
    std::shared_ptr<smart_cane_interfaces::msg::UltrasonicData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UltrasonicData_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->distance_cm != other.distance_cm) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->obstacle_detected != other.obstacle_detected) {
      return false;
    }
    return true;
  }
  bool operator!=(const UltrasonicData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UltrasonicData_

// alias to use template instance with default allocator
using UltrasonicData =
  smart_cane_interfaces::msg::UltrasonicData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace smart_cane_interfaces

#endif  // SMART_CANE_INTERFACES__MSG__DETAIL__ULTRASONIC_DATA__STRUCT_HPP_
