#pragma once

#include "RobotIntent.h"

#define CONTROL_START "start"
#define CONTROL_STOP "stop"
#define CONTROL_CONTINUE "continue"
#define CONTROL_INIT "init"

class ControlIntent : public RobotIntent{

private:
	enum ControlState{
		READY = 0,
		START,
		STOP,
		CONTINUE,
		INIT
	} controlState;
	
	void startTasket();
	void stopTasket();
	void continueTasket();

public:
	ControlIntent(RobotAgent *robot, Json::Value intent);
	void execAction();

};
