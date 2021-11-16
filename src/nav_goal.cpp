#include <ros/ros.h>
#include "move_base_msgs/MoveBaseActionGoal.h"
int i=6;
int main(int argc, char** argv)
{
	ros:: init(argc, argv, "pub_node");
	ros::NodeHandle nh;

	ros::Publisher goal_pose = nh.advertise<move_base_msgs::MoveBaseActionGoal>("/move_base/goal", 10);

	ros::Rate loop_rate(1);
	move_base_msgs::MoveBaseActionGoal goal_pose_yj;

	goal_pose_yj.goal.target_pose.header.frame_id="map";
	goal_pose_yj.goal.target_pose.pose.position.x=3.9;
	goal_pose_yj.goal.target_pose.pose.position.y=5.89;
	goal_pose_yj.goal.target_pose.pose.orientation.z=0.1131;
	goal_pose_yj.goal.target_pose.pose.orientation.w=1;
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