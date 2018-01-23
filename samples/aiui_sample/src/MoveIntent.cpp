#include "MoveIntent.h"

MoveIntent::MoveIntent(RobotAgent *robot, Json::Value intent) : RobotIntent(robot, intent){

	string subIntentStr = subIntentJson.asString();
	
	if(subIntentStr == MOVE_BY_DIREC){
		//robot_intent_debug("the subIntent was %s \n", MOVE_BY_DIREC);
		this->subIntent = MOVE_BY_DIRECTION;
		moveByDirecInit();
	}else if(subIntentStr == TRANSLATION_BY_DIREC){
		this->subIntent = TRAN_BY_DIRECTION; 
		translationByDirecInit();
	}else if()
}

void MoveIntent::moveByDirecInit(){
	string direcStr = parameterJson.asString();

	if(direcStr == "左"){
		direction = RobotAgent::LEFT;
	}else if(direcStr == "右"){
		direction = RobotAgent::RIGHT;
	}else if(direcStr == "上"){
		direction = RobotAgent::TOP;
	}else if(direcStr == "下"){
		direction = RobotAgent::BOTTOM;
	}else if(direcStr == "前"){

	}else if(direcStr == "后"){
			
	}
}

void MoveIntent::execAction(){
	switch(subIntent){
		case MOVE_BY_DIRECTION:
			moveByDirec();	// 开始运动
			break;
	}
}

void MoveIntent::moveByDirec(){
	this->robot->moveByDirection(this->direction);	// 控制机器人运动
}


void MoveIntent::translationByDirecInit(){
	moveByDirecInit();				// 可以使用同一个初始化函数
}

void MoveIntent::translationByDirec(){
	this->robot->translationByDirec(this->direction);	// 控制机械臂进行平移运动
}

