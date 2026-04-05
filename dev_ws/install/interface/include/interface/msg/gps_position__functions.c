// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interface:msg/GpsPosition.idl
// generated code does not contain a copyright notice
#include "interface/msg/gps_position__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
interface__msg__GpsPosition__init(interface__msg__GpsPosition * msg)
{
  if (!msg) {
    return false;
  }
  // latitude
  // longitude
  // satellites
  return true;
}

void
interface__msg__GpsPosition__fini(interface__msg__GpsPosition * msg)
{
  if (!msg) {
    return;
  }
  // latitude
  // longitude
  // satellites
}

interface__msg__GpsPosition *
interface__msg__GpsPosition__create()
{
  interface__msg__GpsPosition * msg = (interface__msg__GpsPosition *)malloc(sizeof(interface__msg__GpsPosition));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interface__msg__GpsPosition));
  bool success = interface__msg__GpsPosition__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
interface__msg__GpsPosition__destroy(interface__msg__GpsPosition * msg)
{
  if (msg) {
    interface__msg__GpsPosition__fini(msg);
  }
  free(msg);
}


bool
interface__msg__GpsPosition__Sequence__init(interface__msg__GpsPosition__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  interface__msg__GpsPosition * data = NULL;
  if (size) {
    data = (interface__msg__GpsPosition *)calloc(size, sizeof(interface__msg__GpsPosition));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interface__msg__GpsPosition__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interface__msg__GpsPosition__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
interface__msg__GpsPosition__Sequence__fini(interface__msg__GpsPosition__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interface__msg__GpsPosition__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

interface__msg__GpsPosition__Sequence *
interface__msg__GpsPosition__Sequence__create(size_t size)
{
  interface__msg__GpsPosition__Sequence * array = (interface__msg__GpsPosition__Sequence *)malloc(sizeof(interface__msg__GpsPosition__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = interface__msg__GpsPosition__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
interface__msg__GpsPosition__Sequence__destroy(interface__msg__GpsPosition__Sequence * array)
{
  if (array) {
    interface__msg__GpsPosition__Sequence__fini(array);
  }
  free(array);
}
