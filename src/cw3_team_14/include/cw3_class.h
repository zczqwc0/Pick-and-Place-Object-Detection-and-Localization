/* feel free to change any part of this file, or delete this file. In general,
you can do whatever you want with this template code, including deleting it all
and starting from scratch. The only requirment is to make sure your entire 
solution is contained within the cw3_team_<your_team_number> package */

// include guards, prevent .h file being defined multiple times (linker error)
#ifndef CW3_CLASS_H_
#define CW3_CLASS_H_

// system includes
#include <ros/ros.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Quaternion.h>
#include <sensor_msgs/PointCloud2.h>
#include <moveit/move_group_interface/move_group_interface.h>

// include tf2 for transformation
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

// include opencv2
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

// include cv bridge and image transport
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>

// standard c++ library includes (std::string, std::vector)
#include <string>
#include <vector>

// include services from the spawner package - we will be responding to these
#include "cw3_world_spawner/Task1Service.h"
#include "cw3_world_spawner/Task2Service.h"
#include "cw3_world_spawner/Task3Service.h"

// // include any services created in this package
// #include "cw3_team_x/example.h"
#include <cw3_team_14/set_arm.h>
#include <cw3_team_14/set_gripper.h>

static const std::string OPENCV_WINDOW = "Image window";

class cw3
{
public:

  /* ----- class member functions ----- */

  // constructor
  cw3(ros::NodeHandle nh);

  // service callbacks for tasks 1, 2, and 3
  bool 
  t1_callback(cw3_world_spawner::Task1Service::Request &request,
    cw3_world_spawner::Task1Service::Response &response);
  bool 
  t2_callback(cw3_world_spawner::Task2Service::Request &request,
    cw3_world_spawner::Task2Service::Response &response);
  bool 
  t3_callback(cw3_world_spawner::Task3Service::Request &request,
    cw3_world_spawner::Task3Service::Response &response);
  bool
  setArmCallback(cw3_team_14::set_arm::Request &request,
    cw3_team_14::set_arm::Response &response);
  bool
  setGripperCallback(cw3_team_14::set_gripper::Request &request,
    cw3_team_14::set_gripper::Response &response);
  void
  cameraInfoCallback(const sensor_msgs::CameraInfo &msg);
  void
  imageCallback(const sensor_msgs::ImageConstPtr &msg);
  void
  depthCallback(const sensor_msgs::ImageConstPtr &msg);

  void
  t1_service(geometry_msgs::PointStamped object_point, 
    std::string shape_type, geometry_msgs::PointStamped goal_point);
  int
  t2_service(std::vector<geometry_msgs::PointStamped> ref_object_points,
    geometry_msgs::PointStamped mystery_object_point);
  std::vector<int>
  t3_service();
  bool
  moveArm(geometry_msgs::Pose target_pose);
  bool
  moveGripper(float width);
  geometry_msgs::Pose
  graspPosition(geometry_msgs::PointStamped centroid_point, std::string shape_type);
  void
  pickObject(geometry_msgs::PointStamped centroid_point, std::string shape_type);
  void
  placeObject(geometry_msgs::PointStamped centroid_point, std::string shape_type);
  double
  pixel_to_real(int pixel_x, int pixel_y);
  geometry_msgs::Point
  computePosition(int pixel_x, int pixel_y);
  double
  computeDepth(geometry_msgs::Point target_point);
  geometry_msgs::Point
  objectPosition(geometry_msgs::Point target_point);
  std::vector<geometry_msgs::Point>
  scanPosition();

  /* ----- define constant values ----- */
  std::string base_frame_ = "panda_link0";
  double gripper_open_ = 80e-3;
  double gripper_closed_ = 0.0;

  /* ----- define necessary variables----- */
  ros::Subscriber camera_info_sub;

  geometry_msgs::Quaternion d_orientation;
  geometry_msgs::Quaternion r_orientation;

  tf2_ros::Buffer tf2_buffer_;
  tf2_ros::TransformListener tf2_listener_;

  image_transport::ImageTransport it;
  image_transport::Subscriber color_sub, depth_sub;
  
  cv::Mat colorImage, depthImage;
  sensor_msgs::CameraInfo camera_info;

  std::vector<std::string> color_names;
  std::vector<cv::Scalar> lower_bounds, upper_bounds;

  /* ----- class member variables ----- */

  ros::NodeHandle nh_;
  ros::ServiceServer t1_service_;
  ros::ServiceServer t2_service_;
  ros::ServiceServer t3_service_;
  ros::ServiceServer set_arm_srv_;
  ros::ServiceServer set_gripper_srv_;

  moveit::planning_interface::MoveGroupInterface arm_group_{"panda_arm"};
  moveit::planning_interface::MoveGroupInterface hand_group_{"hand"};
};

#endif // end of include guard for cw3_CLASS_H_
