/* feel free to change any part of this file, or delete this file. In general,
you can do whatever you want with this template code, including deleting it all
and starting from scratch. The only requirment is to make sure your entire 
solution is contained within the cw3_team_<your_team_number> package */

#include <cw3_class.h> // change to your team name here!

///////////////////////////////////////////////////////////////////////////////

cw3::cw3(ros::NodeHandle nh):

it(nh),
tf2_listener_(tf2_buffer_)

{
  /* class constructor */

  nh_ = nh;

  // define public variables
  d_orientation.x = 0.9238795;
  d_orientation.y = -0.3826834;
  d_orientation.z = 0.0;
  d_orientation.w = 0.0;

  r_orientation.x = 0.9238795;
  r_orientation.y = -0.3826834;
  r_orientation.z = 0.0;
  r_orientation.w = 0.0;

  depthImage = cv::Mat::zeros(480, 640, CV_16UC1);

  lower_bounds = {cv::Scalar(100, 40, 45), cv::Scalar(0, 130, 70), cv::Scalar(125, 40, 46)};
  upper_bounds = {cv::Scalar(120, 255, 255), cv::Scalar(10, 255, 255), cv::Scalar(155, 255, 255)};
  color_names = {"blue", "red", "purple"};

  // advertise solutions for coursework tasks
  t1_service_  = nh_.advertiseService("/task1_start", 
    &cw3::t1_callback, this);
  t2_service_  = nh_.advertiseService("/task2_start", 
    &cw3::t2_callback, this);
  t3_service_  = nh_.advertiseService("/task3_start",
    &cw3::t3_callback, this);
  
  set_arm_srv_ = nh_.advertiseService("/set_arm",
    &cw3::setArmCallback, this);
  set_gripper_srv_ = nh_.advertiseService("/set_gripper",
    &cw3::setGripperCallback, this);

  ROS_INFO("cw3 class initialised");
}

///////////////////////////////////////////////////////////////////////////////

bool
cw3::t1_callback(cw3_world_spawner::Task1Service::Request &request,
  cw3_world_spawner::Task1Service::Response &response) 
{
  /* function which should solve task 1 */

  ROS_INFO("The coursework solving callback for task 1 has been triggered");

  // call function for solving task 1
  t1_service(request.object_point, request.shape_type, request.goal_point);

  return true;
}

///////////////////////////////////////////////////////////////////////////////

bool
cw3::t2_callback(cw3_world_spawner::Task2Service::Request &request,
  cw3_world_spawner::Task2Service::Response &response)
{
  /* function which should solve task 2 */

  ROS_INFO("The coursework solving callback for task 2 has been triggered");

  // define response variable
  int mystery_object_num;

  // call function for solving task 2
  mystery_object_num = t2_service(request.ref_object_points, request.mystery_object_point);

  // return a number of which reference the mystery shape mathces
  response.mystery_object_num = mystery_object_num;

  std::cout << "\nmystery object has the same shape as reference " << mystery_object_num << std::endl;

  return true;
}

///////////////////////////////////////////////////////////////////////////////

bool
cw3::t3_callback(cw3_world_spawner::Task3Service::Request &request,
  cw3_world_spawner::Task3Service::Response &response)
{
  /* function which should solve task 3 */

  ROS_INFO("The coursework solving callback for task 3 has been triggered");

  // define response variable
  std::vector<int> t3_response;

  // call function for solving task 3
  t3_response = t3_service();

  // return service responses
  response.total_num_shapes = t3_response[0];
  response.num_most_common_shape = t3_response[1];

  std::cout << "\ntotal number of shapes is " << t3_response[0] << std::endl;
  std::cout << "number of most common shape is " << t3_response[1] << std::endl;

  return true;
}

///////////////////////////////////////////////////////////////////////////////

void
cw3::cameraInfoCallback(const sensor_msgs::CameraInfo &msg)
{
  camera_info = msg;
}

///////////////////////////////////////////////////////////////////////////////

void
cw3::imageCallback(const sensor_msgs::ImageConstPtr &msg)
{
  // convert ROS message to CvImage
  cv_bridge::CvImagePtr cv_ptr;

  try
  {
    cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
  }
  catch (cv_bridge::Exception &e)
  {
    ROS_ERROR("cv_bridge exception: %s", e.what());
  }

  colorImage = cv_ptr->image;
}

///////////////////////////////////////////////////////////////////////////////

void
cw3::depthCallback(const sensor_msgs::ImageConstPtr &msg)
{
  // convert ROS message to CvImage
  cv_bridge::CvImagePtr cv_ptr;

  try
  {
    cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::TYPE_16UC1);
  }
  catch (cv_bridge::Exception &e)
  {
    ROS_ERROR("cv_bridge exception: %s", e.what());
  }

  depthImage = cv_ptr->image;
}

///////////////////////////////////////////////////////////////////////////////

bool

cw3::setArmCallback(cw3_team_14::set_arm::Request &request,
  cw3_team_14::set_arm::Response &response)
  {
    // set arm position
    bool success = moveArm(request.pose);

    response.success = success;

    return success;
  }

///////////////////////////////////////////////////////////////////////////////

bool
cw3::setGripperCallback(cw3_team_14::set_gripper::Request &request,
  cw3_team_14::set_gripper::Response &response)
{
  // set gripper fingers to a specific width
  bool success = moveGripper(request.finger_distance);

  response.success = success;

  return success;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

bool
cw3::moveArm(geometry_msgs::Pose target_pose)
{
  // setup the target pose
  //ROS_INFO("Setting pose target");
  arm_group_.setPoseTarget(target_pose);

  // create a movement plan for the arm
  //ROS_INFO("Attempting to plan the path");
  moveit::planning_interface::MoveGroupInterface::Plan my_plan;
  bool success = (arm_group_.plan(my_plan) ==
    moveit::planning_interface::MoveItErrorCode::SUCCESS);

  //ROS_INFO("Visualising plan %s", success ? "" : "FAILED");

  // execute the planned path
  arm_group_.move();

  return success;
}

///////////////////////////////////////////////////////////////////////////////

bool
cw3::moveGripper(float width)
{
  // safety checks in case width exceeds safe values
  if (width > gripper_open_) 
    width = gripper_open_;
  if (width < gripper_closed_) 
    width = gripper_closed_;

  // calculate the joint targets as half each of the requested distance
  double eachJoint = width / 2.0;

  // create a vector to hold the joint target for each joint
  std::vector<double> gripperJointTargets(2);
  gripperJointTargets[0] = eachJoint;
  gripperJointTargets[1] = eachJoint;

  // apply the joint target
  hand_group_.setJointValueTarget(gripperJointTargets);

  // move the robot hand
  moveit::planning_interface::MoveGroupInterface::Plan my_plan;
  bool success = (hand_group_.plan(my_plan) ==
    moveit::planning_interface::MoveItErrorCode::SUCCESS);

  // move the gripper joints
  hand_group_.move();

  return success;
}

///////////////////////////////////////////////////////////////////////////////

geometry_msgs::Pose
cw3::graspPosition(geometry_msgs::PointStamped centroid_point, std::string shape_type)
{
  // define target pose
  geometry_msgs::Pose target_pose;

  // assign target position
  target_pose.position = centroid_point.point;
  target_pose.orientation = r_orientation;

  // set up grasp position according to object shape
  if (shape_type == "cross")
  {
    target_pose.position.x += 0.04;
  }
  else if (shape_type == "nought")
  {
    target_pose.position.y += 0.08;
  } 

  // add offset in z-axis
  target_pose.position.z += 0.3;

  return target_pose;
}

///////////////////////////////////////////////////////////////////////////////

void
cw3::pickObject(geometry_msgs::PointStamped centroid_point, std::string shape_type)
{
  // define target pose
  geometry_msgs::Pose target_pose;

  // compute target position
  target_pose = graspPosition(centroid_point, shape_type);

  // move to the object position
  moveArm(target_pose);

  // open the gripper
  moveGripper(0.10);

  // grap the object
  target_pose.position.z -= 0.16;
  moveArm(target_pose);
  moveGripper(0.025);

  // set post-grasp retreat
  target_pose.position.z += 0.3;
  moveArm(target_pose);
}

///////////////////////////////////////////////////////////////////////////////

void
cw3::placeObject(geometry_msgs::PointStamped centroid_point, std::string shape_type)
{
  // define target pose
  geometry_msgs::Pose target_pose;

  // compute target position
  target_pose = graspPosition(centroid_point, shape_type);

  // move to the object position
  moveArm(target_pose);

  // place the object
  moveGripper(0.10);
  ros::Duration(1,0).sleep();
  moveGripper(0.025);
}

///////////////////////////////////////////////////////////////////////////////

double
cw3::pixel_to_real(int pixel_x, int pixel_y)
{
  // define variable
  double real_z;

  real_z = depthImage.at<u_int16_t>(pixel_y, pixel_x) / 1000.0;

  return real_z;
}

///////////////////////////////////////////////////////////////////////////////

geometry_msgs::Point
cw3::computePosition(int pixel_x, int pixel_y)
{
  // define necessary variables
  geometry_msgs::PoseStamped camera_frame;
  geometry_msgs::PoseStamped world_frame;

  double camera_position_z = pixel_to_real(pixel_x, pixel_y);
  double camera_position_x = (pixel_x - camera_info.K.at(2)) / camera_info.K.at(0) * camera_position_z;
  double camera_position_y = (pixel_y - camera_info.K.at(5)) / camera_info.K.at(4) * camera_position_z;

  // construct input pose from camera frame
  camera_frame.pose.position.x = camera_position_x;
  camera_frame.pose.position.y = camera_position_y;
  camera_frame.pose.position.z = camera_position_z;
  
  try
  {
    camera_frame.header.frame_id = "color";
    camera_frame.header.stamp = ros::Time();
    camera_frame.pose.orientation.w = 1.0;
    
    // transform camera frame to world frame
    world_frame = tf2_buffer_.transform(camera_frame, "world");
  }
  catch(tf2::TransformException &ex)
  {
    ROS_ERROR("[adventure_tf]: (wait) %s", ex.what());
    ros::Duration(1,0).sleep();
  }

  return world_frame.pose.position;
}

///////////////////////////////////////////////////////////////////////////////

double
cw3::computeDepth(geometry_msgs::Point target_point)
{
  // define necessary variable
  double real_z_center;
  geometry_msgs::Pose target_pose;

  // set target position and orientation
  target_pose.position.x = target_point.x;
  target_pose.position.y = target_point.y;
  target_pose.position.z = 0.6;

  target_pose.orientation = d_orientation;

  // move to target position
  moveArm(target_pose);
  ros::Duration(1,0).sleep();

  // convert input image to HSV
  cv::Mat hsvImage;
  cv::cvtColor(colorImage, hsvImage, CV_BGR2HSV);
  ros::Duration(1,0).sleep();

  for (int i = 0; i < color_names.size(); i++)
  {
    // create a mask of the image
    cv::Mat mask;
    cv::inRange(hsvImage, lower_bounds[i], upper_bounds[i], mask);
    int count = cv::countNonZero(mask);

    // find contour of the image
    std::vector<cv::Vec4i> hierarchy;
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(mask, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    // draw outline
    for (const auto &contour : contours)
    {
      // compute the size of object
      cv::Rect bounding_rect = cv::boundingRect(contour);

      if (bounding_rect.area() > 44000 && bounding_rect.area() < 190000)
      {
        cv::Point center = (bounding_rect.br() + bounding_rect.tl()) / 2;
        cv::rectangle(colorImage, bounding_rect, cv::Scalar(0, 255, 0), 2);
        real_z_center = pixel_to_real(center.x, center.y);
      }
    }
  }

  return real_z_center;
}

///////////////////////////////////////////////////////////////////////////////

geometry_msgs::Point
cw3::objectPosition(geometry_msgs::Point target_point)
{
  // define necessary variable
  geometry_msgs::Pose target_pose;
  geometry_msgs::Point object_position;

  // set target position and orientation
  target_pose.position.x = target_point.x;
  target_pose.position.y = target_point.y;
  target_pose.position.z = 0.6;

  target_pose.orientation = d_orientation;

  // move to target position
  moveArm(target_pose);
  ros::Duration(1,0).sleep();

  // convert input image to HSV
  cv::Mat hsvImage;
  cv::cvtColor(colorImage, hsvImage, CV_BGR2HSV);

  for (int i = 0; i < color_names.size(); i++)
  {
    // create a mask of the image
    cv::Mat mask;
    cv::inRange(hsvImage, lower_bounds[i], upper_bounds[i], mask);
    int count = cv::countNonZero(mask);

    // find contour of the image
    std::vector<cv::Vec4i> hierarchy;
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(mask, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    // draw outline
    for (const auto &contour : contours)
    {
      // compute the size of object
      cv::Rect bounding_rect = cv::boundingRect(contour);

      if (bounding_rect.area() > 44000 && bounding_rect.area() < 190000)
      {
        cv::Point center = (bounding_rect.br() + bounding_rect.tl()) / 2;
        cv::rectangle(colorImage, bounding_rect, cv::Scalar(0, 255, 0), 2);
        object_position = computePosition(center.x, center.y);
      }
    }
  }

  return object_position;
}

///////////////////////////////////////////////////////////////////////////////

std::vector<geometry_msgs::Point>
cw3::scanPosition()
{
  // define necessary variable
  std::vector<geometry_msgs::Point> scan_positions;

  // define pin points for scanning
  geometry_msgs::Point pin_point;

  pin_point.x = 0.45;
  pin_point.y = 0.40;
  pin_point.z = 0.50;
  scan_positions.push_back(pin_point);

  for (int i = 0; i < 2; i++)
  {
    pin_point.y -= 0.40;
    scan_positions.push_back(pin_point);
  }

  for (int j = 0; j < 3; j++)
  {
    pin_point.x -= 0.30;
    scan_positions.push_back(pin_point);
  }

  pin_point.z -= 0.10;
  for (int k = 0; k < 2; k++)
  {
    pin_point.y += 0.40;
    scan_positions.push_back(pin_point);
  }

  pin_point.z += 0.10;
  for (int l = 0; l < 2; l++)
  {
    pin_point.x += 0.30;
    scan_positions.push_back(pin_point);
  }

  return scan_positions;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void
cw3::t1_service(geometry_msgs::PointStamped object_point, 
  std::string shape_type, geometry_msgs::PointStamped goal_point)
{
  // move to the object and pick it up
  pickObject(object_point, shape_type);

  // move to the box and place the object
  placeObject(goal_point, shape_type);
}

///////////////////////////////////////////////////////////////////////////////

int
cw3::t2_service(std::vector<geometry_msgs::PointStamped> ref_object_points,
  geometry_msgs::PointStamped mystery_object_point)
{
  // define necessary variables
  int mystery_object_num;
  double object_depth;
  double depth_difference;
  std::vector<double> ref_depth;
  std::vector<double> depth_compare_list;

  // define subscriber
  color_sub = it.subscribe("/r200/camera/color/image_raw",
    1, &cw3::imageCallback, this);
  depth_sub = it.subscribe("/r200/camera/depth/image_raw",
    1, &cw3::depthCallback, this);

  // investigate reference points
  for (int i = 0; i < ref_object_points.size(); i++)
  {
    // compute depth of reference objects
    object_depth = computeDepth(ref_object_points[i].point);
    ref_depth.push_back(object_depth);
    ros::Duration(1,0).sleep();
  }

  // compute depth of mystery object
  object_depth = computeDepth(mystery_object_point.point);
  ros::Duration(1,0).sleep();

  // compare mystery object and reference objects
  double depth_min = 1.0;
  for (int j = 0; j < ref_depth.size(); j++)
  {
    depth_difference = abs(ref_depth[j] - object_depth);

    if (depth_min > depth_difference)
    {
      depth_min = depth_difference;
      mystery_object_num = j + 1;
    }
  }

  // close subscriber
  color_sub.shutdown();
  depth_sub.shutdown();

  return mystery_object_num;
}

///////////////////////////////////////////////////////////////////////////////

std::vector<int>
cw3::t3_service()
{
  // define necessary variables
  std::string shape_type;
  std::vector<int> t3_response;
  int total_num_shapes, num_most_common_shape;
  double object_depth;
  std::vector<geometry_msgs::Point> num_nought, num_cross;
  std::vector<geometry_msgs::Point> scan_positions;
  geometry_msgs::Point object_position, goal_position;
  geometry_msgs::PointStamped object_pose, goal_pose;

  // define subscriber
  color_sub = it.subscribe("/r200/camera/color/image_raw",
    1, &cw3::imageCallback, this);
  depth_sub = it.subscribe("/r200/camera/depth/image_raw",
    1, &cw3::depthCallback, this);
  camera_info_sub = nh_.subscribe("/r200/camera/depth/camera_info", 
    1, &cw3::cameraInfoCallback, this);
  ros::Duration(1,0).sleep();

  // perform scanning
  scan_positions = scanPosition(); 
  for (int i = 0; i < scan_positions.size(); i++)
  {
    object_depth = computeDepth(scan_positions[i]);
    ros::Duration(1,0).sleep();
    if (object_depth > 0.30 && object_depth < 0.50)
    {
      object_position = objectPosition(scan_positions[i]);
      num_cross.push_back(object_position);
    }
    else if (object_depth > 0.50 && object_depth <= 0.52)
    {
      goal_position = objectPosition(scan_positions[i]);
    }
    else if (object_depth > 0.52)
    {
      object_position = objectPosition(scan_positions[i]);
      num_nought.push_back(object_position);
    }
    
    ros::Duration(1,0).sleep();
  }

  // count total number of objects
  total_num_shapes = num_nought.size() + num_cross.size();
  t3_response.push_back(total_num_shapes);

  // select which shape is more common
  if (num_cross.size() > num_nought.size())
  {
    shape_type = "cross";
    object_pose.point.x = num_cross[0].x;
    object_pose.point.y = num_cross[0].y;
    object_pose.point.z = 0.0;
    num_most_common_shape = num_cross.size();
  }
  else
  {
    shape_type = "nought";
    object_pose.point.x = num_nought[0].x;
    object_pose.point.y = num_nought[0].y;
    object_pose.point.z = 0.0;
    num_most_common_shape = num_nought.size();
  }

  t3_response.push_back(num_most_common_shape);

  // move to the object and pick it up
  pickObject(object_pose, shape_type);

  // move to the box and place the object
  goal_pose.point.x = goal_position.x;
  goal_pose.point.y = goal_position.y;
  goal_pose.point.z = 0.0;
  placeObject(goal_pose, shape_type);

  // close subscriber
  color_sub.shutdown();
  depth_sub.shutdown();
  camera_info_sub.shutdown();

  return t3_response;
}