#include "ros/ros.h"
#include <gazebo_msgs/LinkStates.h>

#include <string>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle nh;
    ros::NodeHandle nhp("~");

    int rate;
    nhp.param<int>("rate", rate, 1000);
    
    ros::Publisher pub = nh.advertise<gazebo_msgs::LinkStates>("test1",10);

    // Create message
    gazebo_msgs::LinkStates msg;
    for (int i = 0; i < 5; i++)
    {
        msg.name.push_back(std::string(1,char(i+65)));
        msg.pose.push_back(geometry_msgs::Pose());
        msg.twist.push_back(geometry_msgs::Twist());
    }
    
    ros::Rate r(rate);
    while(ros::ok())
    {
        pub.publish(msg);
        r.sleep();
    }
    
    return 0;
}
