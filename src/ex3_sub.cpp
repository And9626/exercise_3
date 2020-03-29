#include "ros/ros.h"
#include "exercise_3/andrea.h"
#include "exercise_3/andrea1.h"
#include <iostream>

class ROS_SUB{
	public:
		ROS_SUB();
		void ex3_cb1( exercise_3::andrea msg);

	private:
		ros::NodeHandle _nh1;
		ros::Subscriber _ex3_sub1;
	};

ROS_SUB::ROS_SUB(){
	_ex3_sub1 = _nh1.subscribe("/custom1", 10, &ROS_SUB::ex3_cb1, this);
}

void ROS_SUB::ex3_cb1(exercise_3::andrea msg){
	std::cout<<"Primo addendo: "<<msg.data1<<std::endl;
	std::cout<<"Secondo addendo: "<<msg.data2<<std::endl;
	std::cout<<"Risultato della somma "<<msg.result<<std::endl;
	std::cout<<std::endl;
}





int main(int argc, char** argv){

	ros::init(argc, argv, "ex3_sub1");
	ROS_SUB rs;
	
	ros::spin();

		
	return 0;
}

