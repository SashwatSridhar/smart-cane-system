// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from smart_cane_interfaces:msg/FeedbackCommand.idl
// generated code does not contain a copyright notice

#include "smart_cane_interfaces/msg/detail/feedback_command__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_smart_cane_interfaces
const rosidl_type_hash_t *
smart_cane_interfaces__msg__FeedbackCommand__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xcb, 0xbd, 0x3f, 0x05, 0xaa, 0x9c, 0x54, 0x88,
      0xe3, 0xd8, 0xc9, 0x29, 0x06, 0xdc, 0xcf, 0x4a,
      0x11, 0xbc, 0xce, 0x32, 0x85, 0x8e, 0x1d, 0xee,
      0x0b, 0x90, 0x91, 0x4a, 0x42, 0xc5, 0xd5, 0x96,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "std_msgs/msg/detail/header__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char smart_cane_interfaces__msg__FeedbackCommand__TYPE_NAME[] = "smart_cane_interfaces/msg/FeedbackCommand";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char smart_cane_interfaces__msg__FeedbackCommand__FIELD_NAME__header[] = "header";
static char smart_cane_interfaces__msg__FeedbackCommand__FIELD_NAME__message_text[] = "message_text";
static char smart_cane_interfaces__msg__FeedbackCommand__FIELD_NAME__vibration_enabled[] = "vibration_enabled";
static char smart_cane_interfaces__msg__FeedbackCommand__FIELD_NAME__vibration_intensity[] = "vibration_intensity";
static char smart_cane_interfaces__msg__FeedbackCommand__FIELD_NAME__audio_enabled[] = "audio_enabled";

static rosidl_runtime_c__type_description__Field smart_cane_interfaces__msg__FeedbackCommand__FIELDS[] = {
  {
    {smart_cane_interfaces__msg__FeedbackCommand__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {smart_cane_interfaces__msg__FeedbackCommand__FIELD_NAME__message_text, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {smart_cane_interfaces__msg__FeedbackCommand__FIELD_NAME__vibration_enabled, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {smart_cane_interfaces__msg__FeedbackCommand__FIELD_NAME__vibration_intensity, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {smart_cane_interfaces__msg__FeedbackCommand__FIELD_NAME__audio_enabled, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription smart_cane_interfaces__msg__FeedbackCommand__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
smart_cane_interfaces__msg__FeedbackCommand__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {smart_cane_interfaces__msg__FeedbackCommand__TYPE_NAME, 41, 41},
      {smart_cane_interfaces__msg__FeedbackCommand__FIELDS, 5, 5},
    },
    {smart_cane_interfaces__msg__FeedbackCommand__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Feedback system commands\n"
  "std_msgs/Header header\n"
  "string message_text\n"
  "bool vibration_enabled\n"
  "float32 vibration_intensity\n"
  "bool audio_enabled\n"
  "";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
smart_cane_interfaces__msg__FeedbackCommand__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {smart_cane_interfaces__msg__FeedbackCommand__TYPE_NAME, 41, 41},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 141, 141},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
smart_cane_interfaces__msg__FeedbackCommand__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *smart_cane_interfaces__msg__FeedbackCommand__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
