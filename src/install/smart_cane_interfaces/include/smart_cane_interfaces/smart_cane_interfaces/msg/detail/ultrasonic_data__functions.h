// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from smart_cane_interfaces:msg/UltrasonicData.idl
// generated code does not contain a copyright notice

#ifndef SMART_CANE_INTERFACES__MSG__DETAIL__ULTRASONIC_DATA__FUNCTIONS_H_
#define SMART_CANE_INTERFACES__MSG__DETAIL__ULTRASONIC_DATA__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "smart_cane_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "smart_cane_interfaces/msg/detail/ultrasonic_data__struct.h"

/// Initialize msg/UltrasonicData message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * smart_cane_interfaces__msg__UltrasonicData
 * )) before or use
 * smart_cane_interfaces__msg__UltrasonicData__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_smart_cane_interfaces
bool
smart_cane_interfaces__msg__UltrasonicData__init(smart_cane_interfaces__msg__UltrasonicData * msg);

/// Finalize msg/UltrasonicData message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_smart_cane_interfaces
void
smart_cane_interfaces__msg__UltrasonicData__fini(smart_cane_interfaces__msg__UltrasonicData * msg);

/// Create msg/UltrasonicData message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * smart_cane_interfaces__msg__UltrasonicData__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_smart_cane_interfaces
smart_cane_interfaces__msg__UltrasonicData *
smart_cane_interfaces__msg__UltrasonicData__create();

/// Destroy msg/UltrasonicData message.
/**
 * It calls
 * smart_cane_interfaces__msg__UltrasonicData__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_smart_cane_interfaces
void
smart_cane_interfaces__msg__UltrasonicData__destroy(smart_cane_interfaces__msg__UltrasonicData * msg);

/// Check for msg/UltrasonicData message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_smart_cane_interfaces
bool
smart_cane_interfaces__msg__UltrasonicData__are_equal(const smart_cane_interfaces__msg__UltrasonicData * lhs, const smart_cane_interfaces__msg__UltrasonicData * rhs);

/// Copy a msg/UltrasonicData message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_smart_cane_interfaces
bool
smart_cane_interfaces__msg__UltrasonicData__copy(
  const smart_cane_interfaces__msg__UltrasonicData * input,
  smart_cane_interfaces__msg__UltrasonicData * output);

/// Initialize array of msg/UltrasonicData messages.
/**
 * It allocates the memory for the number of elements and calls
 * smart_cane_interfaces__msg__UltrasonicData__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_smart_cane_interfaces
bool
smart_cane_interfaces__msg__UltrasonicData__Sequence__init(smart_cane_interfaces__msg__UltrasonicData__Sequence * array, size_t size);

/// Finalize array of msg/UltrasonicData messages.
/**
 * It calls
 * smart_cane_interfaces__msg__UltrasonicData__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_smart_cane_interfaces
void
smart_cane_interfaces__msg__UltrasonicData__Sequence__fini(smart_cane_interfaces__msg__UltrasonicData__Sequence * array);

/// Create array of msg/UltrasonicData messages.
/**
 * It allocates the memory for the array and calls
 * smart_cane_interfaces__msg__UltrasonicData__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_smart_cane_interfaces
smart_cane_interfaces__msg__UltrasonicData__Sequence *
smart_cane_interfaces__msg__UltrasonicData__Sequence__create(size_t size);

/// Destroy array of msg/UltrasonicData messages.
/**
 * It calls
 * smart_cane_interfaces__msg__UltrasonicData__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_smart_cane_interfaces
void
smart_cane_interfaces__msg__UltrasonicData__Sequence__destroy(smart_cane_interfaces__msg__UltrasonicData__Sequence * array);

/// Check for msg/UltrasonicData message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_smart_cane_interfaces
bool
smart_cane_interfaces__msg__UltrasonicData__Sequence__are_equal(const smart_cane_interfaces__msg__UltrasonicData__Sequence * lhs, const smart_cane_interfaces__msg__UltrasonicData__Sequence * rhs);

/// Copy an array of msg/UltrasonicData messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_smart_cane_interfaces
bool
smart_cane_interfaces__msg__UltrasonicData__Sequence__copy(
  const smart_cane_interfaces__msg__UltrasonicData__Sequence * input,
  smart_cane_interfaces__msg__UltrasonicData__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SMART_CANE_INTERFACES__MSG__DETAIL__ULTRASONIC_DATA__FUNCTIONS_H_
