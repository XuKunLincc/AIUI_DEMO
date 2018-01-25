#pragma once

#include "jsoncpp/json/json.h"
#include "MoveIntent.h"
#include "ControlIntent.h"

using namespace VA;

class RobotIntentFactory{
public:
	static RobotIntent* createRobotIntent(RobotAgent *mRobot, Json::Value intentJson);
};