// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from smart_cane_interfaces:msg/UltrasonicData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "smart_cane_interfaces/msg/detail/ultrasonic_data__rosidl_typesupport_introspection_c.h"
#include "smart_cane_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "smart_cane_interfaces/msg/detail/ultrasonic_data__functions.h"
#include "smart_cane_interfaces/msg/detail/ultrasonic_data__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void smart_cane_interfaces__msg__UltrasonicData__rosidl_typesupport_introspection_c__UltrasonicData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  smart_cane_interfaces__msg__UltrasonicData__init(message_memory);
}

void smart_cane_interfaces__msg__UltrasonicData__rosidl_typesupport_introspection_c__UltrasonicData_fini_function(void * message_memory)
{
  smart_cane_interfaces__msg__UltrasonicData__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember smart_cane_interfaces__msg__UltrasonicData__rosidl_typesupport_introspection_c__UltrasonicData_message_member_array[4] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(smart_cane_interfaces__msg__UltrasonicData, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distance_cm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(smart_cane_interfaces__msg__UltrasonicData, distance_cm),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "confidence",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(smart_cane_interfaces__msg__UltrasonicData, confidence),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "obstacle_detected",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(smart_cane_interfaces__msg__UltrasonicData, obstacle_detected),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers smart_cane_interfaces__msg__UltrasonicData__rosidl_typesupport_introspection_c__UltrasonicData_message_members = {
  "smart_cane_interfaces__msg",  // message namespace
  "UltrasonicData",  // message name
  4,  // number of fields
  sizeof(smart_cane_interfaces__msg__UltrasonicData),
  smart_cane_interfaces__msg__UltrasonicData__rosidl_typesupport_introspection_c__UltrasonicData_message_member_array,  // message members
  smart_cane_interfaces__msg__UltrasonicData__rosidl_typesupport_introspection_c__UltrasonicData_init_function,  // function to initialize message memory (memory has to be allocated)
  smart_cane_interfaces__msg__UltrasonicData__rosidl_typesupport_introspection_c__UltrasonicData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t smart_cane_interfaces__msg__UltrasonicData__rosidl_typesupport_introspection_c__UltrasonicData_message_type_support_handle = {
  0,
  &smart_cane_interfaces__msg__UltrasonicData__rosidl_typesupport_introspection_c__UltrasonicData_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_smart_cane_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, smart_cane_interfaces, msg, UltrasonicData)() {
  smart_cane_interfaces__msg__UltrasonicData__rosidl_typesupport_introspection_c__UltrasonicData_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!smart_cane_interfaces__msg__UltrasonicData__rosidl_typesupport_introspection_c__UltrasonicData_message_type_support_handle.typesupport_identifier) {
    smart_cane_interfaces__msg__UltrasonicData__rosidl_typesupport_introspection_c__UltrasonicData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &smart_cane_interfaces__msg__UltrasonicData__rosidl_typesupport_introspection_c__UltrasonicData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
