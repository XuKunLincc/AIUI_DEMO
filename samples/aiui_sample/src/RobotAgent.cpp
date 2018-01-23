#include "RobotAgent.h"
#include "RobotDebug.h"
#include <iostream>


// 关节坐标下的运动
void RobotAgent::moveByDirection(Direction direc){

	switch(direc){
		case RobotAgent::RIGHT:
			cout << "往右运动" << endl;
			break;
		case RobotAgent::LEFT:
			cout << "往左运动" << endl;
			break;
		case RobotAgent::TOP:
			cout << "往上运动" << endl;
			break;
		case RobotAgent::BOTTOM:
			cout << "往下运动" << endl;
			break;
	}

}


// 根据轴ID和方向进行转动
void RobotAgent::moveByAxis(int axId, bool isClockwise){

	if(isClockwise){	// 顺时针
		cout << "单轴顺时针" << endl;
	}else{	// 逆时针
		cout << "单轴逆时针" << endl;
	}
}


// 世界坐标下的平移
void RobotAgent::translationByDirec(Direction direc){

	switch(direc){
		case RobotAgent::RIGHT:
			cout << "往右平移" << endl;
			break;
		case RobotAgent::LEFT:
			cout << "往左平移" << endl;
			break;
		case RobotAgent::TOP:
			cout << "往上平移" << endl;
			break;
		case RobotAgent::BOTTOM:
			cout << "往下平移" << endl;
			break;
	}
	
}


void RobotAgent::startTasket(){
	robot_debug("startTasket \n");
}

void RobotAgent::stopTasket(){
	robot_debug("stopTasket \n");
}


void RobotAgent::initRobot(){
	robot_debug("initRobot \n");
}

RobotAgent::RobotAgent(){
	//NetConnect(ip, port);			// 连接控制器
	robot_debug("IPC connect \n");
}

RobotAgent::~RobotAgent(){
	//NetExit();						// 断开控制器
	robot_debug("IPC disconnect \n");
}
