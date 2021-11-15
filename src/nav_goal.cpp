#include <ros/ros.h>
#include "geometry_msgs/PoseStamped.h"
int i=6;
int main(int argc, char** argv)
{
	ros:: init(argc, argv, "pub_node");
	ros::NodeHandle nh;

	ros::Publisher goal_pose = nh.advertise<geometry_msgs::PoseStamped>("goal_pose", 10);

	ros::Rate loop_rate(1);
	geometry_msgs::PoseStamped goal_pose_yj;

	goal_pose_yj.pose.position.x=18;
	goal_pose_yj.pose.position.y=18;
	goal_pose_yj.pose.position.z=18;

	ROS_INFO("nav_ready!");

	while(ros::ok())
	{	i-=1;
		if(i>0)
			ROS_INFO("publish start in %d sec", i);
		else
		{
			goal_pose.publish(goal_pose_yj);

			ROS_INFO("goal_pose published!");

		}
		
		ros::spinOnce();
		loop_rate.sleep();
	}


}