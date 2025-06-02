// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from smart_cane_interfaces:msg/FeedbackCommand.idl
// generated code does not contain a copyright notice

#ifndef SMART_CANE_INTERFACES__MSG__DETAIL__FEEDBACK_COMMAND__STRUCT_HPP_
#define SMART_CANE_INTERFACES__MSG__DETAIL__FEEDBACK_COMMAND__STRUCT_HPP_

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
# define DEPRECATED__smart_cane_interfaces__msg__FeedbackCommand __attribute__((deprecated))
#else
# define DEPRECATED__smart_cane_interfaces__msg__FeedbackCommand __declspec(deprecated)
#endif

namespace smart_cane_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FeedbackCommand_
{
  using Type = FeedbackCommand_<ContainerAllocator>;

  explicit FeedbackCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->message_text = "";
      this->vibration_enabled = false;
      this->vibration_intensity = 0.0f;
      this->audio_enabled = false;
    }
  }

  explicit FeedbackCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    message_text(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->message_text = "";
      this->vibration_enabled = false;
      this->vibration_intensity = 0.0f;
      this->audio_enabled = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _message_text_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_text_type message_text;
  using _vibration_enabled_type =
    bool;
  _vibration_enabled_type vibration_enabled;
  using _vibration_intensity_type =
    float;
  _vibration_intensity_type vibration_intensity;
  using _audio_enabled_type =
    bool;
  _audio_enabled_type audio_enabled;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__message_text(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message_text = _arg;
    return *this;
  }
  Type & set__vibration_enabled(
    const bool & _arg)
  {
    this->vibration_enabled = _arg;
    return *this;
  }
  Type & set__vibration_intensity(
    const float & _arg)
  {
    this->vibration_intensity = _arg;
    return *this;
  }
  Type & set__audio_enabled(
    const bool & _arg)
  {
    this->audio_enabled = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    smart_cane_interfaces::msg::FeedbackCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const smart_cane_interfaces::msg::FeedbackCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<smart_cane_interfaces::msg::FeedbackCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<smart_cane_interfaces::msg::FeedbackCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      smart_cane_interfaces::msg::FeedbackCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<smart_cane_interfaces::msg::FeedbackCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      smart_cane_interfaces::msg::FeedbackCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<smart_cane_interfaces::msg::FeedbackCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<smart_cane_interfaces::msg::FeedbackCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<smart_cane_interfaces::msg::FeedbackCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__smart_cane_interfaces__msg__FeedbackCommand
    std::shared_ptr<smart_cane_interfaces::msg::FeedbackCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__smart_cane_interfaces__msg__FeedbackCommand
    std::shared_ptr<smart_cane_interfaces::msg::FeedbackCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FeedbackCommand_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->message_text != other.message_text) {
      return false;
    }
    if (this->vibration_enabled != other.vibration_enabled) {
      return false;
    }
    if (this->vibration_intensity != other.vibration_intensity) {
      return false;
    }
    if (this->audio_enabled != other.audio_enabled) {
      return false;
    }
    return true;
  }
  bool operator!=(const FeedbackCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FeedbackCommand_

// alias to use template instance with default allocator
using FeedbackCommand =
  smart_cane_interfaces::msg::FeedbackCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace smart_cane_interfaces

#endif  // SMART_CANE_INTERFACES__MSG__DETAIL__FEEDBACK_COMMAND__STRUCT_HPP_
