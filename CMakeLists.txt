cmake_minimum_required(VERSION 2.8.3)
project(first_task)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

## Declare ROS messages and services

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(MAIN src/raptorMainNode.cpp)
target_link_libraries(MAIN ${catkin_LIBRARIES})
add_dependencies (MAIN first_task_generate_messages_cpp)

add_executable(IN src/raptorIN.cpp)
target_link_libraries(IN ${catkin_LIBRARIES})
add_dependencies(IN first_task_generate_messages_cpp)

add_executable(OUT src/raptorOUT.cpp)
target_link_libraries(OUT ${catkin_LIBRARIES})
add_dependencies(OUT first_task_generate_messages_cpp)
