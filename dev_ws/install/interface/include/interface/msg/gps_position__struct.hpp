// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interface:msg/GpsPosition.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__GPS_POSITION__STRUCT_HPP_
#define INTERFACE__MSG__GPS_POSITION__STRUCT_HPP_

#include <rosidl_generator_cpp/bounded_vector.hpp>
#include <rosidl_generator_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

// Protect against ERROR being predefined on Windows, in case somebody defines a
// constant by that name.
#if defined(_WIN32)
  #if defined(ERROR)
    #undef ERROR
  #endif
  #if defined(NO_ERROR)
    #undef NO_ERROR
  #endif
#endif

#ifndef _WIN32
# define DEPRECATED__interface__msg__GpsPosition __attribute__((deprecated))
#else
# define DEPRECATED__interface__msg__GpsPosition __declspec(deprecated)
#endif

namespace interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GpsPosition_
{
  using Type = GpsPosition_<ContainerAllocator>;

  explicit GpsPosition_(rosidl_generator_cpp::MessageInitialization _init = rosidl_generator_cpp::MessageInitialization::ALL)
  {
    if (rosidl_generator_cpp::MessageInitialization::ALL == _init ||
      rosidl_generator_cpp::MessageInitialization::ZERO == _init)
    {
      this->latitude = 0.0f;
      this->longitude = 0.0f;
      this->satellites = 0;
    }
  }

  explicit GpsPosition_(const ContainerAllocator & _alloc, rosidl_generator_cpp::MessageInitialization _init = rosidl_generator_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_generator_cpp::MessageInitialization::ALL == _init ||
      rosidl_generator_cpp::MessageInitialization::ZERO == _init)
    {
      this->latitude = 0.0f;
      this->longitude = 0.0f;
      this->satellites = 0;
    }
  }

  // field types and members
  using _latitude_type =
    float;
  _latitude_type latitude;
  using _longitude_type =
    float;
  _longitude_type longitude;
  using _satellites_type =
    uint8_t;
  _satellites_type satellites;

  // setters for named parameter idiom
  Type & set__latitude(
    const float & _arg)
  {
    this->latitude = _arg;
    return *this;
  }
  Type & set__longitude(
    const float & _arg)
  {
    this->longitude = _arg;
    return *this;
  }
  Type & set__satellites(
    const uint8_t & _arg)
  {
    this->satellites = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interface::msg::GpsPosition_<ContainerAllocator> *;
  using ConstRawPtr =
    const interface::msg::GpsPosition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interface::msg::GpsPosition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interface::msg::GpsPosition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interface::msg::GpsPosition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interface::msg::GpsPosition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interface::msg::GpsPosition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interface::msg::GpsPosition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interface::msg::GpsPosition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interface::msg::GpsPosition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interface__msg__GpsPosition
    std::shared_ptr<interface::msg::GpsPosition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interface__msg__GpsPosition
    std::shared_ptr<interface::msg::GpsPosition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GpsPosition_ & other) const
  {
    if (this->latitude != other.latitude) {
      return false;
    }
    if (this->longitude != other.longitude) {
      return false;
    }
    if (this->satellites != other.satellites) {
      return false;
    }
    return true;
  }
  bool operator!=(const GpsPosition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GpsPosition_

// alias to use template instance with default allocator
using GpsPosition =
  interface::msg::GpsPosition_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interface

#endif  // INTERFACE__MSG__GPS_POSITION__STRUCT_HPP_
