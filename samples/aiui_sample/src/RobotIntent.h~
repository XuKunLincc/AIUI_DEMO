#pragma once

#include "RobotAgent.h"
#include "jsoncpp/json/json.h"

#define MOVE_INITENT "FSHSTEST.robot_move"

using namespace VA;
using namespace std;


class RobotIntent{

protected:
	RobotAgent *robot;
	Json::Value semanticJson;
	Json::Value subIntentJson;
	Json::Value slotsJson;
 	Json::Value parameterJson;
public:
	RobotIntent(RobotAgent *robot, Json::Value intent);
	//~RobotIntent();

	virtual void execAction(){};	// 执行对应的Action
};


/*
*	机器人状态控制意图类
*/
/*
class ControlIntent::public RobotIntent{
private:

public:
	ControlIntent(RobotAgent *robot, Json::Value intent);
	void execAction();

}*/
