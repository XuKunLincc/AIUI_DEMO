#include "RobotAgent.h"
#include "RobotDebug.h"
#include <iostream>
#include <boost/thread.hpp>
#include <boost/bind.hpp>

using namespace boost;  
  
#define BOOST_DATE_TIME_SOURCE  
#define BOOST_THREAD_NO_LIB  

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

// 打印当前坐标到终端，测试用
void RobotAgent::print_location(std::vector<double>& v)
{
	cout << "当前笛卡尔坐标 ";
	for(std::vector<double>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

double pot_arr[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};// 要到达的点位
std::vector<double> pot(pot_arr,pot_arr+6);
LocationParameter Locate = {false,0,0,1,pot};

// 世界坐标下的平移
void RobotAgent::translation(Direction direc, int len){
	if(robotStatus != READY)
		return;
	switch(direc){
		case RobotAgent::RIGHT:
			cout << "往右平移" << endl;
			mProxyMotion->getLocPos(0,Locate.vecPos);	// 获取当前笛卡尔坐标		
			Locate.vecPos[1] = Locate.vecPos[1] + MOVE_STEP;// 更改坐标系Y沿正方向运动
			mProxyMotion->moveTo(0, Locate, true);    	// 运动到点
			print_location(Locate.vecPos);			// 笛卡尔坐标打印到终端				
			break;
		case RobotAgent::LEFT:
			cout << "往左平移" << endl;
			mProxyMotion->getLocPos(0,Locate.vecPos);	// 获取当前笛卡尔坐标
			Locate.vecPos[1] = Locate.vecPos[1] - MOVE_STEP;// 更改坐标系Y沿负方向运动
			mProxyMotion->moveTo(0, Locate, true);    	// 运动到点
			print_location(Locate.vecPos);			// 笛卡尔坐标打印到终端	
			break;
		case RobotAgent::TOP:
			cout << "往上平移" << endl;
			mProxyMotion->getLocPos(0,Locate.vecPos);	// 获取当前笛卡尔坐标		
			Locate.vecPos[2] = Locate.vecPos[2] + MOVE_STEP;// 更改坐标系Z沿正方向运动
			mProxyMotion->moveTo(0, Locate, true);    	// 运动到点
			print_location(Locate.vecPos);			// 笛卡尔坐标打印到终端	
			break;
		case RobotAgent::BOTTOM:
			cout << "往下平移" << endl;
			mProxyMotion->getLocPos(0,Locate.vecPos);	// 获取当前笛卡尔坐标		
			Locate.vecPos[2] = Locate.vecPos[2] - MOVE_STEP;// 更改坐标系Z沿负方向运动
			mProxyMotion->moveTo(0, Locate, true);    	// 运动到点
			print_location(Locate.vecPos);			// 笛卡尔坐标打印到终端	
			break;
		case RobotAgent::FRONT:
			cout << "往前平移" << endl;
			mProxyMotion->getLocPos(0,Locate.vecPos);	// 获取当前笛卡尔坐标		
			Locate.vecPos[0] = Locate.vecPos[0] + MOVE_STEP;// 更改坐标系X沿正方向运动
			mProxyMotion->moveTo(0, Locate, true);    	// 运动到点
			print_location(Locate.vecPos);			// 笛卡尔坐标打印到终端	
			break;
		case RobotAgent::BACK:
			cout << "往后平移" << endl;
			mProxyMotion->getLocPos(0,Locate.vecPos);	// 获取当前笛卡尔坐标		
			Locate.vecPos[0] = Locate.vecPos[0] - MOVE_STEP;// 更改坐标系X沿负方向运动
			mProxyMotion->moveTo(0, Locate, true);    	// 运动到点
			print_location(Locate.vecPos);			// 笛卡尔坐标打印到终端	
			break;
	}
	
}

int RobotAgent::enable(bool enable){
#if TEST_MODE == 0
	HMCErrCode errorCode = mProxyMotion->setGpEn(0, enable);	// 上使能
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

	JointPos *tmpPos = new JointPos();
	mProxyMotion->getJointPos(0, *tmpPos);
	jointPosVec.push_back(*tmpPos);
}

void RobotAgent::__repeat(){
	ManState state;	
	for(int i = 0;  i < jointPosVec.size();  i++){
		LocationParameter param = {
			.isJoint = true,
			.ufNum = 0,
			.utNum = 0,
			.config = 0,
			.vecPos = jointPosVec[i]
		};
		mProxyMotion->moveTo(0, param, false);
		cout << "repeat to pos"<< i << endl;
		do{
			boost::this_thread::sleep(boost::posix_time::milliseconds(100));
			mProxyMotion->getManualStat(state);
		}while(state == MAN_STATE_LOCATION);

		if(robotStatus != REPEATING)
			return;
	}
		robotStatus = READY;
}

void RobotAgent::repeat(){
	if(robotStatus != REPEATING){
		robotStatus = REPEATING;
		boost::function0< void> f =  boost::bind(&RobotAgent::__repeat,this);
		boost::thread repeatThd(f);
		repeatThd.timed_join(boost::posix_time::milliseconds(1));
	}
}

// 拖动示教
void RobotAgent::drag_mode(bool isIn){
	string tmp;
	if(isIn){
		cout << "掉使能，开启拖动示教" << endl;
		enable(false);						// 调用使能方法
		mCommApi->NetSendStr("mot.setGpDrag(0, true)", tmp, 1);
}
	else{
		cout << "上使能" << endl;
		enable(true);						// 调用使能方法
		mCommApi->NetSendStr("mot.setGpDrag(0, false)", tmp, 1);
}
	cout << "tmp" << endl;
}

// 回零点
void RobotAgent::goHome(){
	cout << "回零点" << endl;
	const double home_arr[6] = {0.0, -90.0, 0.0, 0.0, 90.0, 0.0};	// 零点
	std::vector<double> home_pot(home_arr,home_arr+6);
	LocationParameter home_locate = {true,0,0,1,home_pot};
	mProxyMotion->moveTo(0, home_locate, false);    		// 运动到点
	print_location(Locate.vecPos);					// 笛卡尔坐标打印到终端		
}

// 复位
int RobotAgent::reset(){
#if TEST_MODE == 0
	HMCErrCode errorCode = mProxyMotion->gpReset(0);
	if(errorCode){
		cout << "group reset err" << endl;
		return -1;
	}
	return 0;
#else
	robot_debug("group reset \n");
#endif
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
	HMCErrCode errorCode = mProxyMotion->getJogVord(speed);		
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

#if (TEST_MODE == 0)
	if(robotStatus == REPEATING){
		mProxyMotion->setEstop(true);
		robotStatus = READY;
		sleep(1);
		mProxyMotion->setEstop(false);
		return ;
	}
	robotStatus = READY;
	robot_debug("stopTasket \n");
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
	mProxyMotion->setOpMode(OP_T1);					// 设置为手动T1模式
	mProxyMotion->setJogVord(10);					// 默认10的倍速
	HMCErrCode errorCode = mProxyMotion->setGpEn(0, true);		// 上使能
	if(errorCode){
		cout << "setGpEn err" << endl;
	}
#endif
	robotStatus = READY;
}

RobotAgent::RobotAgent(const string &ip, uint16_t port){
	mCommApi = new CommApi();
	HMCErrCode errorCode = mCommApi->NetConnect(ip, port);		// 连接控制器
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


void RobotAgent::cleanPos(){

}
