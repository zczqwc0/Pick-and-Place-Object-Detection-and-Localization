// Generated by gencpp from file cw3_team_14/example.msg
// DO NOT EDIT!


#ifndef CW3_TEAM_14_MESSAGE_EXAMPLE_H
#define CW3_TEAM_14_MESSAGE_EXAMPLE_H

#include <ros/service_traits.h>


#include <cw3_team_14/exampleRequest.h>
#include <cw3_team_14/exampleResponse.h>


namespace cw3_team_14
{

struct example
{

typedef exampleRequest Request;
typedef exampleResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct example
} // namespace cw3_team_14


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::cw3_team_14::example > {
  static const char* value()
  {
    return "978efc3b4d217b6a9fca06d03983e5b2";
  }

  static const char* value(const ::cw3_team_14::example&) { return value(); }
};

template<>
struct DataType< ::cw3_team_14::example > {
  static const char* value()
  {
    return "cw3_team_14/example";
  }

  static const char* value(const ::cw3_team_14::example&) { return value(); }
};


// service_traits::MD5Sum< ::cw3_team_14::exampleRequest> should match
// service_traits::MD5Sum< ::cw3_team_14::example >
template<>
struct MD5Sum< ::cw3_team_14::exampleRequest>
{
  static const char* value()
  {
    return MD5Sum< ::cw3_team_14::example >::value();
  }
  static const char* value(const ::cw3_team_14::exampleRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::cw3_team_14::exampleRequest> should match
// service_traits::DataType< ::cw3_team_14::example >
template<>
struct DataType< ::cw3_team_14::exampleRequest>
{
  static const char* value()
  {
    return DataType< ::cw3_team_14::example >::value();
  }
  static const char* value(const ::cw3_team_14::exampleRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::cw3_team_14::exampleResponse> should match
// service_traits::MD5Sum< ::cw3_team_14::example >
template<>
struct MD5Sum< ::cw3_team_14::exampleResponse>
{
  static const char* value()
  {
    return MD5Sum< ::cw3_team_14::example >::value();
  }
  static const char* value(const ::cw3_team_14::exampleResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::cw3_team_14::exampleResponse> should match
// service_traits::DataType< ::cw3_team_14::example >
template<>
struct DataType< ::cw3_team_14::exampleResponse>
{
  static const char* value()
  {
    return DataType< ::cw3_team_14::example >::value();
  }
  static const char* value(const ::cw3_team_14::exampleResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // CW3_TEAM_14_MESSAGE_EXAMPLE_H
