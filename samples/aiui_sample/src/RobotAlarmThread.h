#ifndef __ROBOT_ALARM_THREAD__
#define __ROBOT_ALARM_THREAD__

#include "RobotAgent.h"
#include <boost/thread.hpp>  
#include "jsoncpp/json/json.h"
#include <stdint.h>
#include "hsc/ErrDef.h"

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

public:
	static RobotAlarmThread * creatRobotAlarmThread(RobotAgent * robot);
	void run();
	void stop();
private:
	bool running;
	RobotAgent *mRobot;
	static RobotAlarmThread * mAlarmThread;
	RobotAlarmThread(RobotAgent * robot);
	void getRobotAlarm();				// get the robot alarm
	void speechAlarm(uint64_t code);		// specak the robot alarm by speech
};

#endif