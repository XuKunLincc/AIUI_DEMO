#pragma once
#include "RobotAgent.h"

class RobotTask{
private:
	RobotAgent * mRobot;
	bool canRepeat;
public:
	RobotTask();
	
	void init();
	void start();
	void stop();
	bool canRepeat();
	void repeat();
};

class CanRepeatTask : public RobotTask{
public:
	CanRepeatTask();
	~CanRepeatTask();
	
};

class CantRepeatTask : public RobotTask{
public:
	CantRepeatTask();
	~CantRepeatTask();
};
