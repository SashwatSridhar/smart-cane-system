// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from smart_cane_interfaces:msg/FeedbackCommand.idl
// generated code does not contain a copyright notice
#include "smart_cane_interfaces/msg/detail/feedback_command__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "smart_cane_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "smart_cane_interfaces/msg/detail/feedback_command__struct.h"
#include "smart_cane_interfaces/msg/detail/feedback_command__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // message_text
#include "rosidl_runtime_c/string_functions.h"  // message_text
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_smart_cane_interfaces
bool cdr_serialize_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_smart_cane_interfaces
bool cdr_deserialize_std_msgs__msg__Header(
  eprosima::fastcdr::Cdr & cdr,
  std_msgs__msg__Header * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_smart_cane_interfaces
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_smart_cane_interfaces
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_smart_cane_interfaces
bool cdr_serialize_key_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_smart_cane_interfaces
size_t get_serialized_size_key_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_smart_cane_interfaces
size_t max_serialized_size_key_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_smart_cane_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _FeedbackCommand__ros_msg_type = smart_cane_interfaces__msg__FeedbackCommand;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_smart_cane_interfaces
bool cdr_serialize_smart_cane_interfaces__msg__FeedbackCommand(
  const smart_cane_interfaces__msg__FeedbackCommand * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: message_text
  {
    const rosidl_runtime_c__String * str = &ros_message->message_text;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: vibration_enabled
  {
    cdr << (ros_message->vibration_enabled ? true : false);
  }

  // Field name: vibration_intensity
  {
    cdr << ros_message->vibration_intensity;
  }

  // Field name: audio_enabled
  {
    cdr << (ros_message->audio_enabled ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_smart_cane_interfaces
bool cdr_deserialize_smart_cane_interfaces__msg__FeedbackCommand(
  eprosima::fastcdr::Cdr & cdr,
  smart_cane_interfaces__msg__FeedbackCommand * ros_message)
{
  // Field name: header
  {
    cdr_deserialize_std_msgs__msg__Header(cdr, &ros_message->header);
  }

  // Field name: message_text
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->message_text.data) {
      rosidl_runtime_c__String__init(&ros_message->message_text);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->message_text,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'message_text'\n");
      return false;
    }
  }

  // Field name: vibration_enabled
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->vibration_enabled = tmp ? true : false;
  }

  // Field name: vibration_intensity
  {
    cdr >> ros_message->vibration_intensity;
  }

  // Field name: audio_enabled
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->audio_enabled = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_smart_cane_interfaces
size_t get_serialized_size_smart_cane_interfaces__msg__FeedbackCommand(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FeedbackCommand__ros_msg_type * ros_message = static_cast<const _FeedbackCommand__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: message_text
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->message_text.size + 1);

  // Field name: vibration_enabled
  {
    size_t item_size = sizeof(ros_message->vibration_enabled);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: vibration_intensity
  {
    size_t item_size = sizeof(ros_message->vibration_intensity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: audio_enabled
  {
    size_t item_size = sizeof(ros_message->audio_enabled);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_smart_cane_interfaces
size_t max_serialized_size_smart_cane_interfaces__msg__FeedbackCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: message_text
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: vibration_enabled
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: vibration_intensity
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: audio_enabled
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = smart_cane_interfaces__msg__FeedbackCommand;
    is_plain =
      (
      offsetof(DataType, audio_enabled) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_smart_cane_interfaces
bool cdr_serialize_key_smart_cane_interfaces__msg__FeedbackCommand(
  const smart_cane_interfaces__msg__FeedbackCommand * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_key_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: message_text
  {
    const rosidl_runtime_c__String * str = &ros_message->message_text;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: vibration_enabled
  {
    cdr << (ros_message->vibration_enabled ? true : false);
  }

  // Field name: vibration_intensity
  {
    cdr << ros_message->vibration_intensity;
  }

  // Field name: audio_enabled
  {
    cdr << (ros_message->audio_enabled ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_smart_cane_interfaces
size_t get_serialized_size_key_smart_cane_interfaces__msg__FeedbackCommand(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FeedbackCommand__ros_msg_type * ros_message = static_cast<const _FeedbackCommand__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_key_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: message_text
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->message_text.size + 1);

  // Field name: vibration_enabled
  {
    size_t item_size = sizeof(ros_message->vibration_enabled);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: vibration_intensity
  {
    size_t item_size = sizeof(ros_message->vibration_intensity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: audio_enabled
  {
    size_t item_size = sizeof(ros_message->audio_enabled);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_smart_cane_interfaces
size_t max_serialized_size_key_smart_cane_interfaces__msg__FeedbackCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: message_text
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: vibration_enabled
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: vibration_intensity
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: audio_enabled
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = smart_cane_interfaces__msg__FeedbackCommand;
    is_plain =
      (
      offsetof(DataType, audio_enabled) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _FeedbackCommand__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const smart_cane_interfaces__msg__FeedbackCommand * ros_message = static_cast<const smart_cane_interfaces__msg__FeedbackCommand *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_smart_cane_interfaces__msg__FeedbackCommand(ros_message, cdr);
}

static bool _FeedbackCommand__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  smart_cane_interfaces__msg__FeedbackCommand * ros_message = static_cast<smart_cane_interfaces__msg__FeedbackCommand *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_smart_cane_interfaces__msg__FeedbackCommand(cdr, ros_message);
}

static uint32_t _FeedbackCommand__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_smart_cane_interfaces__msg__FeedbackCommand(
      untyped_ros_message, 0));
}

static size_t _FeedbackCommand__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_smart_cane_interfaces__msg__FeedbackCommand(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_FeedbackCommand = {
  "smart_cane_interfaces::msg",
  "FeedbackCommand",
  _FeedbackCommand__cdr_serialize,
  _FeedbackCommand__cdr_deserialize,
  _FeedbackCommand__get_serialized_size,
  _FeedbackCommand__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _FeedbackCommand__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FeedbackCommand,
  get_message_typesupport_handle_function,
  &smart_cane_interfaces__msg__FeedbackCommand__get_type_hash,
  &smart_cane_interfaces__msg__FeedbackCommand__get_type_description,
  &smart_cane_interfaces__msg__FeedbackCommand__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, smart_cane_interfaces, msg, FeedbackCommand)() {
  return &_FeedbackCommand__type_support;
}

#if defined(__cplusplus)
}
#endif
