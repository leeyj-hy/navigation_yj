cmake_minimum_required(VERSION 3.0.2)
project(navigation_yj)


find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
)


# generate_messages(
#   DEPENDENCIES
#   geometry_msgs
# )

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES navigation_yj
#  CATKIN_DEPENDS geometry_msgs roscpp rospy
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/navigation_yj.cpp
# )

add_executable(${PROJECT_NAME}_node src/nav_goal.cpp)

set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME node PREFIX "")

add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
)
