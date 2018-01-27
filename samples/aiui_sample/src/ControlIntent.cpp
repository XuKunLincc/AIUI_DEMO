#include "ControlIntent.h"

ControlIntent::ControlIntent(RobotAgent *robot, Json::Value intent):RobotIntent(robot, intent){
	string subIntentStr = subIntentJson.asString();
	if(subIntentStr == "stop"){
		this->controlState = STOP;
	}else if(subIntentStr == "record"){
		this->controlState = RECORD;
	}else if(subIntentStr == "repeat"){
		this->controlState = REPEAT;
	}else if(subIntentStr == "drag_mode"){
		this->controlState = DRAG_MODE;
	}else if(subIntentStr == "normal_mode"){
		this->controlState = NORMAL_MODE;
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
		case RECORD:
			record();
			break;
		case NORMAL_MODE:
			normal_mode();
			break;
		case DRAG_MODE:
			drag_mode();
			break;
		case REPEAT:
			repeat();
			break;
		
	}
}


void ControlIntent::record(){
	robot->record();
}
void ControlIntent::repeat(){
	robot->repeat();
}
void ControlIntent::normal_mode(){
	robot->drag_mode(false);
}
void ControlIntent::drag_mode(){
	robot->drag_mode(true);
}