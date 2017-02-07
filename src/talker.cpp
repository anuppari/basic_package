#include "ros/ros.h"
#include "std_msgs/String.h"

#include <string>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle nh;
    
    ros::Publisher pub = nh.advertise<std_msgs::String>("test1",10);
    
    ros::Rate r(1000);
    std_msgs::String msg;
    msg.data = std::string("hello");
    while(ros::ok())
    {
        pub.publish(msg);
        r.sleep();
    }
    
    return 0;
}
