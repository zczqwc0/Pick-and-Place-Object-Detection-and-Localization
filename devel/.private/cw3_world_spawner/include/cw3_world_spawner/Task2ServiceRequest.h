// Generated by gencpp from file cw3_world_spawner/Task2ServiceRequest.msg
// DO NOT EDIT!


#ifndef CW3_WORLD_SPAWNER_MESSAGE_TASK2SERVICEREQUEST_H
#define CW3_WORLD_SPAWNER_MESSAGE_TASK2SERVICEREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/PointStamped.h>
#include <geometry_msgs/PointStamped.h>

namespace cw3_world_spawner
{
template <class ContainerAllocator>
struct Task2ServiceRequest_
{
  typedef Task2ServiceRequest_<ContainerAllocator> Type;

  Task2ServiceRequest_()
    : ref_object_points()
    , mystery_object_point()  {
    }
  Task2ServiceRequest_(const ContainerAllocator& _alloc)
    : ref_object_points(_alloc)
    , mystery_object_point(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector< ::geometry_msgs::PointStamped_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::geometry_msgs::PointStamped_<ContainerAllocator> >> _ref_object_points_type;
  _ref_object_points_type ref_object_points;

   typedef  ::geometry_msgs::PointStamped_<ContainerAllocator>  _mystery_object_point_type;
  _mystery_object_point_type mystery_object_point;





  typedef boost::shared_ptr< ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator> const> ConstPtr;

}; // struct Task2ServiceRequest_

typedef ::cw3_world_spawner::Task2ServiceRequest_<std::allocator<void> > Task2ServiceRequest;

typedef boost::shared_ptr< ::cw3_world_spawner::Task2ServiceRequest > Task2ServiceRequestPtr;
typedef boost::shared_ptr< ::cw3_world_spawner::Task2ServiceRequest const> Task2ServiceRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator1> & lhs, const ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator2> & rhs)
{
  return lhs.ref_object_points == rhs.ref_object_points &&
    lhs.mystery_object_point == rhs.mystery_object_point;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator1> & lhs, const ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace cw3_world_spawner

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5b1ec94690a4a67e2e9cfe653f9e4890";
  }

  static const char* value(const ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5b1ec94690a4a67eULL;
  static const uint64_t static_value2 = 0x2e9cfe653f9e4890ULL;
};

template<class ContainerAllocator>
struct DataType< ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cw3_world_spawner/Task2ServiceRequest";
  }

  static const char* value(const ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/PointStamped[] ref_object_points\n"
"geometry_msgs/PointStamped mystery_object_point\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/PointStamped\n"
"# This represents a Point with reference coordinate frame and timestamp\n"
"Header header\n"
"Point point\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.ref_object_points);
      stream.next(m.mystery_object_point);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Task2ServiceRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cw3_world_spawner::Task2ServiceRequest_<ContainerAllocator>& v)
  {
    s << indent << "ref_object_points[]" << std::endl;
    for (size_t i = 0; i < v.ref_object_points.size(); ++i)
    {
      s << indent << "  ref_object_points[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::PointStamped_<ContainerAllocator> >::stream(s, indent + "    ", v.ref_object_points[i]);
    }
    s << indent << "mystery_object_point: ";
    s << std::endl;
    Printer< ::geometry_msgs::PointStamped_<ContainerAllocator> >::stream(s, indent + "  ", v.mystery_object_point);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CW3_WORLD_SPAWNER_MESSAGE_TASK2SERVICEREQUEST_H
