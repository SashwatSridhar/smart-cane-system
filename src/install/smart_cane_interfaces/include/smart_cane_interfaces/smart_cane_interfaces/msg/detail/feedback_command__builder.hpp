// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from smart_cane_interfaces:msg/FeedbackCommand.idl
// generated code does not contain a copyright notice

#ifndef SMART_CANE_INTERFACES__MSG__DETAIL__FEEDBACK_COMMAND__BUILDER_HPP_
#define SMART_CANE_INTERFACES__MSG__DETAIL__FEEDBACK_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "smart_cane_interfaces/msg/detail/feedback_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace smart_cane_interfaces
{

namespace msg
{

namespace builder
{

class Init_FeedbackCommand_audio_enabled
{
public:
  explicit Init_FeedbackCommand_audio_enabled(::smart_cane_interfaces::msg::FeedbackCommand & msg)
  : msg_(msg)
  {}
  ::smart_cane_interfaces::msg::FeedbackCommand audio_enabled(::smart_cane_interfaces::msg::FeedbackCommand::_audio_enabled_type arg)
  {
    msg_.audio_enabled = std::move(arg);
    return std::move(msg_);
  }

private:
  ::smart_cane_interfaces::msg::FeedbackCommand msg_;
};

class Init_FeedbackCommand_vibration_intensity
{
public:
  explicit Init_FeedbackCommand_vibration_intensity(::smart_cane_interfaces::msg::FeedbackCommand & msg)
  : msg_(msg)
  {}
  Init_FeedbackCommand_audio_enabled vibration_intensity(::smart_cane_interfaces::msg::FeedbackCommand::_vibration_intensity_type arg)
  {
    msg_.vibration_intensity = std::move(arg);
    return Init_FeedbackCommand_audio_enabled(msg_);
  }

private:
  ::smart_cane_interfaces::msg::FeedbackCommand msg_;
};

class Init_FeedbackCommand_vibration_enabled
{
public:
  explicit Init_FeedbackCommand_vibration_enabled(::smart_cane_interfaces::msg::FeedbackCommand & msg)
  : msg_(msg)
  {}
  Init_FeedbackCommand_vibration_intensity vibration_enabled(::smart_cane_interfaces::msg::FeedbackCommand::_vibration_enabled_type arg)
  {
    msg_.vibration_enabled = std::move(arg);
    return Init_FeedbackCommand_vibration_intensity(msg_);
  }

private:
  ::smart_cane_interfaces::msg::FeedbackCommand msg_;
};

class Init_FeedbackCommand_message_text
{
public:
  explicit Init_FeedbackCommand_message_text(::smart_cane_interfaces::msg::FeedbackCommand & msg)
  : msg_(msg)
  {}
  Init_FeedbackCommand_vibration_enabled message_text(::smart_cane_interfaces::msg::FeedbackCommand::_message_text_type arg)
  {
    msg_.message_text = std::move(arg);
    return Init_FeedbackCommand_vibration_enabled(msg_);
  }

private:
  ::smart_cane_interfaces::msg::FeedbackCommand msg_;
};

class Init_FeedbackCommand_header
{
public:
  Init_FeedbackCommand_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FeedbackCommand_message_text header(::smart_cane_interfaces::msg::FeedbackCommand::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_FeedbackCommand_message_text(msg_);
  }

private:
  ::smart_cane_interfaces::msg::FeedbackCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::smart_cane_interfaces::msg::FeedbackCommand>()
{
  return smart_cane_interfaces::msg::builder::Init_FeedbackCommand_header();
}

}  // namespace smart_cane_interfaces

#endif  // SMART_CANE_INTERFACES__MSG__DETAIL__FEEDBACK_COMMAND__BUILDER_HPP_
