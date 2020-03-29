#include "ros/ros.h"
#include "exercise_3/andrea.h"
#include "exercise_3/andrea1.h"
#include <iostream>

using namespace std;

class ROS_SUBPUB{
	public:
		ROS_SUBPUB();
		void ex3_cb( exercise_3::andrea msg);
		
	private:
		ros::NodeHandle _nh;
		ros::Subscriber _ex3_sub;
		ros::NodeHandle nh1;
		ros::Publisher ex3_pub1= nh1.advertise<exercise_3::andrea> ("/custom1", 10);
	};

ROS_SUBPUB::ROS_SUBPUB(){
	_ex3_sub = _nh.subscribe("/custom", 10, &ROS_SUBPUB::ex3_cb, this);
}

void ROS_SUBPUB::ex3_cb(exercise_3::andrea msg){

	exercise_3::andrea msg1;

	cout<<"Dati acquisiti, li sommo..."<<endl;;
	
	msg1.data1=msg.data1;
	msg1.data2=msg.data2;

	msg1.result=msg1.data1+msg1.data2;
	ex3_pub1.publish(msg1);
}





int main(int argc, char** argv){

	ros::init(argc, argv, "ex3_subpub");
	ROS_SUBPUB rs;
	
	ros::spin();

		
	return 0;
}

