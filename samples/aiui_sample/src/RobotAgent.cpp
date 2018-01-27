#include "RobotAgent.h"
#include "RobotDebug.h"
#include <iostream>

// 测试模式标志
#define TEST_MODE  0

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
void RobotAgent::moveAxis(int axId, bool isClockwise, int len){
#if (TEST_MODE == 0)
	if(len > 0){
		mProxyMotion->setManualMode(MANUAL_INCREMENT);
		mProxyMotion->setInchLen(len);

	}else{
		mProxyMotion->setManualMode(MANUAL_CONTINUE);
	}
#endif
cout << "单轴逆时针" << len << "du"<< endl;

if(isClockwise){	// 顺时针
		cout << "单轴顺时针" << endl;
#if (TEST_MODE == 0)
		mProxyMotion->startJog(0, axId - 1, POSITIVE);
#endif
	}else{	// 逆时针
		cout << "单轴逆时针" << endl;
#if (TEST_MODE == 0)
		mProxyMotion->startJog(0, axId - 1, NEGATIVE);
#endif
	}
}


// 世界坐标下的平移
void RobotAgent::translation(Direction direc){

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

int RobotAgent::enable(bool enable){
#if TEST_MODE == 0
	HMCErrCode errorCode = mProxyMotion->setGpEn(0, enable);		// 上使能
	if(errorCode){
		cout << "setGpEn err" << endl;
		return -1;
	}
	return 0;
#else
	robot_debug("set the robot enable \n");
#endif
}

void RobotAgent::record(){
	mProxyMotion->getJointPos(0, jointPos);
}
void RobotAgent::repeat(){
	LocationParameter param = {
		.isJoint = true,
		.ufNum = 0,
		.utNum = 0,
		.config = 0,
		.vecPos = jointPos
	};
	mProxyMotion->moveTo(0, param, false);
}

void RobotAgent::drag_mode(bool isIn){
	string tmp;
	if(isIn)
		mCommApi->NetSendStr("mot.setGpDrag(0, true)", tmp, 1);
	else
		mCommApi->NetSendStr("mot.setGpDrag(0, false)", tmp, 1);
	cout << "tmp" << endl;
}

int RobotAgent::setSpeed(int speed){
#if TEST_MODE == 0
	HMCErrCode errorCode = mProxyMotion->setJogVord(speed);
	if(errorCode){
		cout << "set sepeed err" << endl;
		return -1;
	}
	return 0;
#else
	robot_debug("set the robot speed \n");
#endif
}

int RobotAgent::getSpeed(int &speed){
#if TEST_MODE == 0
	HMCErrCode errorCode = mProxyMotion->getJogVord(speed);		// 上使能
	if(errorCode){
		cout << "set sepeed err" << endl;
		return -1;
	}
	return 0;
#else
	robot_debug("get the robot speed \n");
	return 0;
#endif
}

void RobotAgent::startTasket(){
	robot_debug("startTasket \n");
}

void RobotAgent::stopTasket(){
	robot_debug("stopTasket \n");
#if (TEST_MODE == 0)
	mProxyMotion->stopJog(0);
#endif
}


int RobotAgent::initRobot(){
#if (TEST_MODE == 1)
	robot_debug("initRobot \n");
#else
	if(mCommApi == NULL){
		cout << "华数三型API接口初始化错误" << endl;
		return -1;	
	}
	mProxyMotion->setOpMode(OP_T1);		// 设置为手动T1模式
	mProxyMotion->setJogVord(10);			// 默认10的倍速
	HMCErrCode errorCode = mProxyMotion->setGpEn(0, true);		// 上使能
	if(errorCode){
		cout << "setGpEn err" << endl;
	}
#endif
}

RobotAgent::RobotAgent(const string &ip, uint16_t port){
	mCommApi = new CommApi();
	HMCErrCode errorCode = mCommApi->NetConnect(ip, port);			// 连接控制器
	sleep(1);
	if(mCommApi->isConnected())
		cout << "connected" << endl;
	cout << errorCode << endl;	
	if(errorCode){
		cout << "robot connect faile" << endl;
	}

	robot_debug("IPC connect \n");
	mProxyMotion = new ProxyMotion(mCommApi);
}

RobotAgent::~RobotAgent(){
	mCommApi->NetExit();						// 断开控制器
	robot_debug("IPC disconnect \n");
}
