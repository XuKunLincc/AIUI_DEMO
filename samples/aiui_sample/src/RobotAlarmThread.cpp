#include "RobotAlarmThread.h"


RobotAlarmThread * RobotAlarmThread::creatRobotAlarmThread(RobotAgent * mRobot){
	if(mThread == NULL)
		mThread = new RobotAlarmThread(mRobot);
	return mThread;
}

RobotAlarmThread::RobotAlarmThread(RobotAgent *robot){
	this->mRobot = robot;
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
	int type, code, ret;
	string strMsg;

	while(running){

		ret = this->mRobot->getAlarm(type, code, strMsg);
		if(ret == KM_ERR_NO_MESSAGE || ret == KM_ERR_INVALID_MESSAGE){
			if(this->mRobot->getState() == ALARM)
				this->mRobot->setState(READY);
		}else if(0 == ret){
			cout << "the robot have a alarm" << endl;
			cout << "++++++++the alarm code was" << code << endl;
			cout << "@@@@@the alarm message was" << strMsg << endl;
			if(this->mRobot->getState() != ALARM)
				this->mRobot->setState(ALARM);
		}

		boost::this_thread::sleep(boost::posix_time::milliseconds(500));
	}
}

void RobotAlarmThread::speechAlarm(int errorCode){

}