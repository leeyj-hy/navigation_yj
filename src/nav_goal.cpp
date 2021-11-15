#include <ros/ros.h>
#include "geometry_msgs/PoseStamped.h"

int main(int argc, char** argv)
{
	ros:: init(argc, argv, "pub_node");
	ros::NodeHandle nh;

	ros::Publisher goal_pose = nh.advertise<geometry_msgs::PoseStamped>("goal_pose", 10);

	ros::Rate loop_rate(1);
	geometry_msgs::PoseStamped goal_pose_msg;

	goal_pose_msg.pose.position.x=0;
	goal_pose_msg.pose.position.y=0;
	goal_pose_msg.pose.position.z=0;

	ROS_INFO("nav_ready!");

	while(ros::ok())
	{
		goal_pose.publish(goal_pose_msg);

		ROS_INFO("goal_pose x : %d", goal_pose_msg.pose.position.x);
		ROS_INFO("goal_pose y : %d", goal_pose_msg.pose.position.y);
		ROS_INFO("goal_pose z : %d", goal_pose_msg.pose.position.z);
	

		ros::spinOnce();
		loop_rate.sleep();
	}


}