#include "RobotIntentFactory.h"


RobotIntent* RobotIntentFactory::createRobotIntent(RobotAgent *mRobot, Json::Value intentJson){
	string intentStr = intentJson["service"].asString();
	
	if(intentStr == "FSHSTEST.robot_move"){
		MoveIntent *moveIntent = new MoveIntent(mRobot, intentJson);
		return moveIntent;
	}else if(intentStr == "FSHSTEST.robot_control"){
		ControlIntent *controlIntent = new ControlIntent(mRobot, intentJson);
		return controlIntent;
	}
	// }else if(intentStr == "FSHSTEST.robot_grab"){
	// 	GrabIntent *grabIntent = new GrabIntent(mRobot, intentJson);
	// 	return grabIntent;
	// }

	return NULL;
}