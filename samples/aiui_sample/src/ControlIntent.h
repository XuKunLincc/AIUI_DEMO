#pragma once

#include "RobotIntent.h"

#define CONTROL_START_STR "start"
#define CONTROL_STOP_STR "stop"
#define CONTROL_CONTINUE_STR "continue"
#define CONTROL_INIT_STR "init"

class ControlIntent : public RobotIntent{

private:
	enum ControlState{
		READY = -1,
		START,
		STOP,
		CONTINUE,
		INIT,
	} controlState;
	
	void startTasket();
	void stopTasket();
	void continueTasket();

public:
	ControlIntent(RobotAgent *robot, Json::Value intent);
	void execAction();

};
