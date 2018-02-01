#ifndef __ROBOT_ALARM_THREAD__
#define __ROBOT_ALARM_THREAD__

#include <RobotAgent.h>
#include <boost/thread.hpp>  
#include "jsoncpp/json/json.h"

using namespace std;  
using namespace boost;  
using namespace VA;
  
#define BOOST_DATE_TIME_SOURCE  
#define BOOST_THREAD_NO_LIB  

enum MsgLevel	{
	MSG_INFO = 0,
	MSG_WARNING = 1,
	MSG_ERROR = 2,
};

class RobotAlarmThread
{
private:
	RobotAgent *mRobot;
	RobotAlarmThread *mThread;
	RobotAlarmThread();
	void getRobotAlarm();		// get the robot alarm
	void speechAlarm();		// specak the robot alarm by speech
public:
	RobotAlarmThread * creatRobotAlarmThread(RobotAgent * mRobot);
	void run();
	void stop();
};

#endif