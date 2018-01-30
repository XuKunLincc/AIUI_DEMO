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
		RECORD,
		NORMAL_MODE,
		DRAG_MODE,
		REPEAT,
		CLEAN_POS,
		RESET,
		GO_HOME
	} controlState;
	
	void startTasket();
	void stopTasket();
	void continueTasket();
	void record();
	void repeat();
	void normal_mode();
	void drag_mode();
	void clean_pos();
	void go_home();
	void reset();

public:
	ControlIntent(RobotAgent *robot, Json::Value intent);
	void execAction();

};
