#include "ros/ros.h"
#include "std_msgs/String.h"

void raptoroutCallback(const std_msgs::String::ConstPtr& signMsg)
{
  ROS_INFO("Received message on RaptorOUT is: %s", signMsg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "RaptorOUT");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("/RaptorOUT", 100, raptoroutCallback);

  ros::spin();

  return 0;
}
