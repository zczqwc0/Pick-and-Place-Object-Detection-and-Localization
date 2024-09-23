# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "cw3_team_14: 0 messages, 3 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/noetic/share/geometry_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/noetic/share/sensor_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(cw3_team_14_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/bruce/catkin_ws/src/cw3_team_14/srv/example.srv" NAME_WE)
add_custom_target(_cw3_team_14_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cw3_team_14" "/home/bruce/catkin_ws/src/cw3_team_14/srv/example.srv" "geometry_msgs/Quaternion:geometry_msgs/Pose:geometry_msgs/Point"
)

get_filename_component(_filename "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_arm.srv" NAME_WE)
add_custom_target(_cw3_team_14_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cw3_team_14" "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_arm.srv" "geometry_msgs/Quaternion:geometry_msgs/Pose:geometry_msgs/Point"
)

get_filename_component(_filename "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_gripper.srv" NAME_WE)
add_custom_target(_cw3_team_14_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cw3_team_14" "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_gripper.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(cw3_team_14
  "/home/bruce/catkin_ws/src/cw3_team_14/srv/example.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cw3_team_14
)
_generate_srv_cpp(cw3_team_14
  "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_arm.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cw3_team_14
)
_generate_srv_cpp(cw3_team_14
  "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_gripper.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cw3_team_14
)

### Generating Module File
_generate_module_cpp(cw3_team_14
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cw3_team_14
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(cw3_team_14_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(cw3_team_14_generate_messages cw3_team_14_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bruce/catkin_ws/src/cw3_team_14/srv/example.srv" NAME_WE)
add_dependencies(cw3_team_14_generate_messages_cpp _cw3_team_14_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_arm.srv" NAME_WE)
add_dependencies(cw3_team_14_generate_messages_cpp _cw3_team_14_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_gripper.srv" NAME_WE)
add_dependencies(cw3_team_14_generate_messages_cpp _cw3_team_14_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(cw3_team_14_gencpp)
add_dependencies(cw3_team_14_gencpp cw3_team_14_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cw3_team_14_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services
_generate_srv_eus(cw3_team_14
  "/home/bruce/catkin_ws/src/cw3_team_14/srv/example.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cw3_team_14
)
_generate_srv_eus(cw3_team_14
  "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_arm.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cw3_team_14
)
_generate_srv_eus(cw3_team_14
  "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_gripper.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cw3_team_14
)

### Generating Module File
_generate_module_eus(cw3_team_14
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cw3_team_14
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(cw3_team_14_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(cw3_team_14_generate_messages cw3_team_14_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bruce/catkin_ws/src/cw3_team_14/srv/example.srv" NAME_WE)
add_dependencies(cw3_team_14_generate_messages_eus _cw3_team_14_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_arm.srv" NAME_WE)
add_dependencies(cw3_team_14_generate_messages_eus _cw3_team_14_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_gripper.srv" NAME_WE)
add_dependencies(cw3_team_14_generate_messages_eus _cw3_team_14_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(cw3_team_14_geneus)
add_dependencies(cw3_team_14_geneus cw3_team_14_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cw3_team_14_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(cw3_team_14
  "/home/bruce/catkin_ws/src/cw3_team_14/srv/example.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cw3_team_14
)
_generate_srv_lisp(cw3_team_14
  "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_arm.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cw3_team_14
)
_generate_srv_lisp(cw3_team_14
  "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_gripper.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cw3_team_14
)

### Generating Module File
_generate_module_lisp(cw3_team_14
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cw3_team_14
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(cw3_team_14_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(cw3_team_14_generate_messages cw3_team_14_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bruce/catkin_ws/src/cw3_team_14/srv/example.srv" NAME_WE)
add_dependencies(cw3_team_14_generate_messages_lisp _cw3_team_14_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_arm.srv" NAME_WE)
add_dependencies(cw3_team_14_generate_messages_lisp _cw3_team_14_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_gripper.srv" NAME_WE)
add_dependencies(cw3_team_14_generate_messages_lisp _cw3_team_14_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(cw3_team_14_genlisp)
add_dependencies(cw3_team_14_genlisp cw3_team_14_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cw3_team_14_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services
_generate_srv_nodejs(cw3_team_14
  "/home/bruce/catkin_ws/src/cw3_team_14/srv/example.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cw3_team_14
)
_generate_srv_nodejs(cw3_team_14
  "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_arm.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cw3_team_14
)
_generate_srv_nodejs(cw3_team_14
  "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_gripper.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cw3_team_14
)

### Generating Module File
_generate_module_nodejs(cw3_team_14
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cw3_team_14
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(cw3_team_14_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(cw3_team_14_generate_messages cw3_team_14_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bruce/catkin_ws/src/cw3_team_14/srv/example.srv" NAME_WE)
add_dependencies(cw3_team_14_generate_messages_nodejs _cw3_team_14_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_arm.srv" NAME_WE)
add_dependencies(cw3_team_14_generate_messages_nodejs _cw3_team_14_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_gripper.srv" NAME_WE)
add_dependencies(cw3_team_14_generate_messages_nodejs _cw3_team_14_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(cw3_team_14_gennodejs)
add_dependencies(cw3_team_14_gennodejs cw3_team_14_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cw3_team_14_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(cw3_team_14
  "/home/bruce/catkin_ws/src/cw3_team_14/srv/example.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cw3_team_14
)
_generate_srv_py(cw3_team_14
  "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_arm.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cw3_team_14
)
_generate_srv_py(cw3_team_14
  "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_gripper.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cw3_team_14
)

### Generating Module File
_generate_module_py(cw3_team_14
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cw3_team_14
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(cw3_team_14_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(cw3_team_14_generate_messages cw3_team_14_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bruce/catkin_ws/src/cw3_team_14/srv/example.srv" NAME_WE)
add_dependencies(cw3_team_14_generate_messages_py _cw3_team_14_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_arm.srv" NAME_WE)
add_dependencies(cw3_team_14_generate_messages_py _cw3_team_14_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bruce/catkin_ws/src/cw3_team_14/srv/set_gripper.srv" NAME_WE)
add_dependencies(cw3_team_14_generate_messages_py _cw3_team_14_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(cw3_team_14_genpy)
add_dependencies(cw3_team_14_genpy cw3_team_14_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cw3_team_14_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cw3_team_14)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cw3_team_14
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(cw3_team_14_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(cw3_team_14_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(cw3_team_14_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cw3_team_14)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cw3_team_14
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(cw3_team_14_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(cw3_team_14_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET sensor_msgs_generate_messages_eus)
  add_dependencies(cw3_team_14_generate_messages_eus sensor_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cw3_team_14)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cw3_team_14
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(cw3_team_14_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(cw3_team_14_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(cw3_team_14_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cw3_team_14)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cw3_team_14
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(cw3_team_14_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(cw3_team_14_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET sensor_msgs_generate_messages_nodejs)
  add_dependencies(cw3_team_14_generate_messages_nodejs sensor_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cw3_team_14)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cw3_team_14\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cw3_team_14
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(cw3_team_14_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(cw3_team_14_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(cw3_team_14_generate_messages_py sensor_msgs_generate_messages_py)
endif()
