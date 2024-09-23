// Generated by gencpp from file cw3_team_14/exampleResponse.msg
// DO NOT EDIT!


#ifndef CW3_TEAM_14_MESSAGE_EXAMPLERESPONSE_H
#define CW3_TEAM_14_MESSAGE_EXAMPLERESPONSE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Point.h>

namespace cw3_team_14
{
template <class ContainerAllocator>
struct exampleResponse_
{
  typedef exampleResponse_<ContainerAllocator> Type;

  exampleResponse_()
    : success(false)
    , example_std_vector_of_points()  {
    }
  exampleResponse_(const ContainerAllocator& _alloc)
    : success(false)
    , example_std_vector_of_points(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _success_type;
  _success_type success;

   typedef std::vector< ::geometry_msgs::Point_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::geometry_msgs::Point_<ContainerAllocator> >> _example_std_vector_of_points_type;
  _example_std_vector_of_points_type example_std_vector_of_points;





  typedef boost::shared_ptr< ::cw3_team_14::exampleResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cw3_team_14::exampleResponse_<ContainerAllocator> const> ConstPtr;

}; // struct exampleResponse_

typedef ::cw3_team_14::exampleResponse_<std::allocator<void> > exampleResponse;

typedef boost::shared_ptr< ::cw3_team_14::exampleResponse > exampleResponsePtr;
typedef boost::shared_ptr< ::cw3_team_14::exampleResponse const> exampleResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cw3_team_14::exampleResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cw3_team_14::exampleResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::cw3_team_14::exampleResponse_<ContainerAllocator1> & lhs, const ::cw3_team_14::exampleResponse_<ContainerAllocator2> & rhs)
{
  return lhs.success == rhs.success &&
    lhs.example_std_vector_of_points == rhs.example_std_vector_of_points;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::cw3_team_14::exampleResponse_<ContainerAllocator1> & lhs, const ::cw3_team_14::exampleResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace cw3_team_14

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::cw3_team_14::exampleResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cw3_team_14::exampleResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cw3_team_14::exampleResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cw3_team_14::exampleResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cw3_team_14::exampleResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cw3_team_14::exampleResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cw3_team_14::exampleResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "21f33296fbcf2cd9ca27d7591c7a3051";
  }

  static const char* value(const ::cw3_team_14::exampleResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x21f33296fbcf2cd9ULL;
  static const uint64_t static_value2 = 0xca27d7591c7a3051ULL;
};

template<class ContainerAllocator>
struct DataType< ::cw3_team_14::exampleResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cw3_team_14/exampleResponse";
  }

  static const char* value(const ::cw3_team_14::exampleResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cw3_team_14::exampleResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# this is the return message\n"
"bool success\n"
"geometry_msgs/Point[] example_std_vector_of_points\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::cw3_team_14::exampleResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cw3_team_14::exampleResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
      stream.next(m.example_std_vector_of_points);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct exampleResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cw3_team_14::exampleResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cw3_team_14::exampleResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
    s << indent << "example_std_vector_of_points[]" << std::endl;
    for (size_t i = 0; i < v.example_std_vector_of_points.size(); ++i)
    {
      s << indent << "  example_std_vector_of_points[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::Point_<ContainerAllocator> >::stream(s, indent + "    ", v.example_std_vector_of_points[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // CW3_TEAM_14_MESSAGE_EXAMPLERESPONSE_H
