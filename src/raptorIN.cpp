#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "raptorIN");
  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("/RaptorIN", 100);

  ros::Rate loop_rate(10);

  while (ros::ok())
  {
     std_msgs::String msg;

     std::stringstream ss;
     ss << "Hello!";
     msg.data = ss.str();

     ROS_INFO("%s", msg.data.c_str());

     chatter_pub.publish(msg);

     ros::spinOnce();

     loop_rate.sleep();
  }

  return 0;
}
