#pragma once

#include "RobotAgent.h"
#include "jsoncpp/json/json.h"
#include <map>

#define MOVE_INITENT "FSHSTEST.robot_move"


using namespace VA;
using namespace std;


class RobotIntent{

protected:
	RobotAgent *robot;
	Json::Value semanticJson;
	Json::Value subIntentJson;
	Json::Value slotsJson;
	map<int,Json::Value> parameterMap;

public:
	RobotIntent(RobotAgent *robot, Json::Value intent);
	//~RobotIntent();

	virtual void execAction(){};	// 执行对应的Action
};

