#include "ControlIntent.h"

ControlIntent::ControlIntent(RobotAgent *robot, Json::Value intent):RobotIntent(robot, intent){
	string subIntentStr = subIntentJson.asString();
	if(subIntentStr == "pause"){
		this->controlState = STOP;
	}
}

void ControlIntent::startTasket(){
	
}

void ControlIntent::stopTasket(){
	robot->stopTasket();
}

void ControlIntent::continueTasket(){

}

void ControlIntent::execAction(){
	
	switch(this->controlState){
		case STOP:
			stopTasket();
			break;
	}
}
