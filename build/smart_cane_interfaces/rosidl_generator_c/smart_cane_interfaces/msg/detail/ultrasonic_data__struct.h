// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from smart_cane_interfaces:msg/UltrasonicData.idl
// generated code does not contain a copyright notice

#ifndef SMART_CANE_INTERFACES__MSG__DETAIL__ULTRASONIC_DATA__STRUCT_H_
#define SMART_CANE_INTERFACES__MSG__DETAIL__ULTRASONIC_DATA__STRUCT_H_

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

/// Struct defined in msg/UltrasonicData in the package smart_cane_interfaces.
/**
  * Ultrasonic sensor data message
 */
typedef struct smart_cane_interfaces__msg__UltrasonicData
{
  std_msgs__msg__Header header;
  float distance_cm;
  float confidence;
  bool obstacle_detected;
} smart_cane_interfaces__msg__UltrasonicData;

// Struct for a sequence of smart_cane_interfaces__msg__UltrasonicData.
typedef struct smart_cane_interfaces__msg__UltrasonicData__Sequence
{
  smart_cane_interfaces__msg__UltrasonicData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} smart_cane_interfaces__msg__UltrasonicData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SMART_CANE_INTERFACES__MSG__DETAIL__ULTRASONIC_DATA__STRUCT_H_
