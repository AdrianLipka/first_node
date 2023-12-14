#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

void raptorCallback(const std_msgs::String::ConstPtr& msg)
{
  std::string receivedMsg = msg->data;
  ROS_INFO("[%s]", msg->data.c_str());

  std::string author = "Adrian Lipka";
  std::stringstream signedMsg;
  signedMsg << "<" << author << " / " << ros::Time::now() << ">" << receivedMsg;

  ros::NodeHandle n;

  ros::Publisher publisher = n.advertise<std_msgs::String>("/RaptorOUT", 100);
  std_msgs::String signedMessage;
  signedMessage.data = signedMsg.str();
  publisher.publish(signedMessage);
  ROS_INFO("%s", signedMessage.data.c_str());
  ros::spin();
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "raptorMainNode");

  ros::NodeHandle n;

  ros::Subscriber subscriber = n.subscribe("/RaptorIN", 100, raptorCallback);

  ros::spin();

  return 0;
}
