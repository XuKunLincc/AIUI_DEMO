#include "MoveIntent.h"
#include <stdlib.h>
#include <map>

MoveIntent::MoveIntent(RobotAgent *robot, Json::Value intent) : RobotIntent(robot, intent){

	string subIntentStr = subIntentJson.asString();

	if(subIntentStr == MOVE_BY_DIREC){
		//robot_intent_debug("the subIntent was %s \n", MOVE_BY_DIREC);
		this->subIntent = MOVE_BY_DIRECTION;
		moveByDirecInit();
	}else if(subIntentStr == TRANSLATION_BY_DIREC){
		this->subIntent = TRAN_BY_DIRECTION; 
		translationByDirecInit();
	}else if(subIntentStr == MOVEAXIS_CLOCKWISE){	// 顺时针 单关节
		this->isClockwise = true;
		this->subIntent = MOVE_BY_AXIS_CLOCKWISE;
		getAxisId();
	}else if(subIntentStr == MOVEAXIS_ANTICLOCK){	// 逆时针 单关节
		this->isClockwise = false;
		this->subIntent = MOVE_BY_AXIS_ANTICLOCK;
		getAxisId();
	}else if(subIntentStr == ENABLE_STR){
		this->subIntent = ENABLE;
	}else if(subIntentStr == UNABLE_STR){
		this->subIntent = UNABLE;
	}
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
		direction = RobotAgent::FRONT;
	}else if(direcStr == "后"){
		direction = RobotAgent::BACK;
	}
}


int MoveIntent::enable(){
	robot->enable(true);
}

int MoveIntent::unable(){
	robot->enable(false);
}

void MoveIntent::execAction(){
	switch(subIntent){
		case MOVE_BY_DIRECTION:
			moveByDirec();			// 开始运动
			break;
		case MOVE_BY_AXIS_CLOCKWISE:
			moveAxis();			// 单关节运动
			break;
		case MOVE_BY_AXIS_ANTICLOCK:
			moveAxis();			// 单关节运动
			break;
		case TRAN_BY_DIRECTION:
			translation();
			break;
		case ENABLE:
			enable();
			break;
		case UNABLE:
			unable();
			break;
		case SPEED_UP:
			speed_up();
			break;
		case SPEED_DOWN:
			speed_down();
			break;
	}
}

void MoveIntent::moveByDirec(){
	this->robot->moveByDirection(this->direction);	// 控制机器人运动
}


void MoveIntent::translationByDirecInit(){
	moveByDirecInit();				// 可以使用同一个初始化函数
}

void MoveIntent::translation(){
	this->robot->translation(this->direction);	// 控制机械臂进行平移运动
}

void MoveIntent::getAxisId(){
	int tmp = atoi(parameterJson.asString().c_str());
	if(tmp > 0 && tmp <= 6)
		axisId = tmp;
	else
		axisId = -1;
}

void MoveIntent::moveAxis(){
	this->robot->moveAxis(axisId, isClockwise);
}

void MoveIntent::speed_up(){
	nowSpeed += speedStep;
	this->robot->setSpeed(nowSpeed);
}

void MoveIntent::speed_down(){
	nowSpeed -= speedStep;
	this->robot->setSpeed(nowSpeed);
}