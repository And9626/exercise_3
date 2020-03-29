#include "ros/ros.h"
#include "exercise_3/andrea.h"
#include <iostream>
#include <string>

#define max 50

class ROS_PUB{
	public:
		ROS_PUB();
		void ex3_publisher();

	private:
	ros::NodeHandle nh;
	ros::Publisher ex3_pub= nh.advertise<exercise_3::andrea> ("/custom", 10);
	};

void ROS_PUB::ex3_publisher(){
	exercise_3::andrea msg;
	ros::Rate rate(1);
	
	float a, b;
	while(ros::ok()){
		a=static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/max));
		b=static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/max));
		msg.data1=a;
		msg.data2=b;
		ex3_pub.publish(msg);
		rate.sleep();
	}
}

ROS_PUB::ROS_PUB(){
	
	}


int main(int argc, char **argv){

	ros::init(argc, argv, "ex3_publisher");
	ROS_PUB rs;
	rs.ex3_publisher();		

	return 0;
}