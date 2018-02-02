#include "RobotAlarmThread.h"

RobotAlarmThread *RobotAlarmThread::mAlarmThread = NULL;

RobotAlarmThread * RobotAlarmThread::creatRobotAlarmThread(RobotAgent * robot){
	if(mAlarmThread == NULL)
		mAlarmThread = new RobotAlarmThread(robot);
	return mAlarmThread;
}

RobotAlarmThread::RobotAlarmThread(RobotAgent *robot){
	this->mRobot = robot;
	running = false;
}

void RobotAlarmThread::run(){
	running = true;
	boost::function0< void> f =  boost::bind(&RobotAlarmThread::getRobotAlarm,this);
	boost::thread getAlarmThr(f);
	getAlarmThr.timed_join(boost::posix_time::milliseconds(1));
}

void RobotAlarmThread::stop(){
	running = false;
}

void RobotAlarmThread::getRobotAlarm(){
	int type, ret;
	uint64_t code;
	string strMsg;

	cout << "start getRobotAlarm theread" << endl;
	while(running){

		ret = this->mRobot->getAlarm(type, code, strMsg);
		if(ret == KM_ERR_NO_MESSAGE || ret == KM_ERR_INVALID_MESSAGE){
			
		}else if(0 == ret && -1 < type){
			cout << "the robot have a alarm" << endl;
			cout << "++++++++the alarm code was " << code << endl;
			cout << "@@@@@the alarm message was " << strMsg << endl;
			cout << "@@@@@the alarm type was " << type << endl;
			//if(this->mRobot->getState() != ALARM){
			this->mRobot->setState(ALARM);
			speechAlarm(code);
			//}
		}
		
		boost::this_thread::sleep(boost::posix_time::milliseconds(500));
	}
}

void RobotAlarmThread::speechAlarm(uint64_t errorCode){
	cout << "i can't speak chinese" << endl;
}
