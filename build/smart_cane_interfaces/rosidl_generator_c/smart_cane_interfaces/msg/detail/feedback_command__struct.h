// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from smart_cane_interfaces:msg/FeedbackCommand.idl
// generated code does not contain a copyright notice

#ifndef SMART_CANE_INTERFACES__MSG__DETAIL__FEEDBACK_COMMAND__STRUCT_H_
#define SMART_CANE_INTERFACES__MSG__DETAIL__FEEDBACK_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'message_text'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/FeedbackCommand in the package smart_cane_interfaces.
/**
  * Feedback system commands
 */
typedef struct smart_cane_interfaces__msg__FeedbackCommand
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String message_text;
  bool vibration_enabled;
  float vibration_intensity;
  bool audio_enabled;
} smart_cane_interfaces__msg__FeedbackCommand;

// Struct for a sequence of smart_cane_interfaces__msg__FeedbackCommand.
typedef struct smart_cane_interfaces__msg__FeedbackCommand__Sequence
{
  smart_cane_interfaces__msg__FeedbackCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} smart_cane_interfaces__msg__FeedbackCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SMART_CANE_INTERFACES__MSG__DETAIL__FEEDBACK_COMMAND__STRUCT_H_
