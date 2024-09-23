execute_process(COMMAND "/home/bruce/catkin_ws/build/cw3_world_spawner/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/bruce/catkin_ws/build/cw3_world_spawner/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
