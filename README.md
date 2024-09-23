# Pick-and-Place-Object-Detection-and-Localization

## Project Overview
The objective of this project is to perform pick and place tasks in Gazebo, using MoveIt! to move the robot and PCL (Point Cloud Library) to detect object positions and colors.

## Environment Setup

### 1. Install Ubuntu
Follow the instructions in `env_installation.pdf` to install **Ubuntu 20.04.05** in your virtual machine.

### 2. Set Up ROS
Make sure to install the basic ROS environment as outlined in `env_installation.pdf`. You can use the following commands (modify according to your ROS version):

```bash
sudo apt update
sudo apt install ros-noetic-desktop-full
```

### 3. Clone the Repository
Clone this repository along with its submodules:

```bash
git clone --recurse-submodules git@github.com:zczqwc0/Pick-and-Place-Object-Detection-and-Localization.git
```

This repository contains the following submodules:
- panda_description: Robot description for the Panda robot.
- panda_moveit_config: MoveIt! configuration for the Panda robot.
- realsense_gazebo_plugin: Plugin for integrating RealSense cameras in Gazebo.
- rpl_panda_with_rs: Custom implementation for the Panda robot with RealSense support.

### 4. Build the Project

```bash
cd Pick-and-Place-Object-Detection-and-Localization
catkin build
```


### 5. Run the Project
Follow the instructions provided in the COMP0129-S23_CW3.pdf for executing the project and performing pick-and-place tasks.

The project was launched from run_solution.launch.
```bash
roslaunch cw3_team_14 run_solution.launch
```
To begin the task1, just call:
```bash
rosservice call /task 1
```
task2,
```bash
rosservice call /task 2
```
and task 3.
```bash
rosservice call /task 3
```

## Additional Notes
- Ensure that all dependencies are installed as specified in the submodules.
- Make sure to source your ROS workspace before running the project:
```bash
source devel/setup.bash
```
