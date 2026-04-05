// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interface:msg/GpsPosition.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__GPS_POSITION__TRAITS_HPP_
#define INTERFACE__MSG__GPS_POSITION__TRAITS_HPP_

#include "interface/msg/gps_position__struct.hpp"
#include <rosidl_generator_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interface::msg::GpsPosition>()
{
  return "interface::msg::GpsPosition";
}

template<>
struct has_fixed_size<interface::msg::GpsPosition>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interface::msg::GpsPosition>
  : std::integral_constant<bool, true> {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACE__MSG__GPS_POSITION__TRAITS_HPP_
