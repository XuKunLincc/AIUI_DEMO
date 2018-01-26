#include "MoveIntent.h"
#include <stdlib.h>

MoveIntent::MoveIntent(RobotAgent *robot, Json::Value intent) : RobotIntent(robot, intent){

	PAction pEnable = &MoveIntent::enable;
	PAction pUnable = &MoveIntent::unable;
	PAction pMoveAxisCW = &MoveIntent::moveAxisCW;
	PAction pMoveAxisAC = &MoveIntent::moveAxisAC;
	PAction pTranslation = &MoveIntent::translation;
	PAction pSpeedUp = &MoveIntent::speedUp;
	PAction pSpeedDown = &MoveIntent::speedDown;

	pair<string, PAction> pairEnable = make_pair(ENABLE_STR,pEnable);
	pair<string, PAction> pairUnable = make_pair(UNABLE_STR,pUnable);
	pair<string, PAction> pairMoveAxisCW = make_pair(MOVEAXIS_CLOCKWISE,pMoveAxisCW);
	pair<string, PAction> pairMoveAxisAC = make_pair(MOVEAXIS_ANTICLOCK,pMoveAxisAC);
	pair<string, PAction> pairTranslation = make_pair(TRANSLATION_BY_DIREC,pTranslation);
	pair<string, PAction> pairSpeedUp = make_pair(SPPED_UP,pSpeedUp);
	pair<string, PAction> pairSpeedDown = make_pair(SPPED_DOWN,pSpeedDown);

	actionMap.insert(pairEnable);
	actionMap.insert(pairUnable);
	actionMap.insert(pairMoveAxisCW);
	actionMap.insert(pairMoveAxisAC);
	actionMap.insert(pairTranslation);
	actionMap.insert(pairSpeedUp);
	actionMap.insert(pairSpeedDown);
}

RobotAgent::Direction MoveIntent::getDirec(){
	string direcStr = parameterMap[0].asString();
	RobotAgent::Direction direction;
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
	return direction;
}


void MoveIntent::enable(){
	robot->enable(true);
}

void MoveIntent::unable(){
	robot->enable(false);
}

void MoveIntent::execAction(){
	string subIntentStr = subIntentJson.asString();
	(this->*actionMap[subIntentStr])();
}

void  MoveIntent::translation(){
	this->robot->translation(getDirec());	// 控制机械臂进行平移运动
}

int MoveIntent::getAxisId(){
	int tmp = atoi(parameterMap[0].asString().c_str());
	int axisId;
	if(tmp > 0 && tmp <= 6)
		axisId = tmp;
	else
		axisId = -1;
	return axisId;
}

void MoveIntent::moveAxisCW(){
	moveAxis( getAxisId(), true);
}

void MoveIntent::moveAxisAC(){
	moveAxis( getAxisId(), false);
}

void MoveIntent::moveAxis(int axisId, bool isClockwise){

	if(parameterMap.count(1) > 0)
		this->robot->moveAxis(axisId, isClockwise, atoi(parameterMap[1].asString().c_str()));
	else
		this->robot->moveAxis(axisId, isClockwise, 0);
}

void MoveIntent::speedUp(){
	int nowSpeed;
	this->robot->getSpeed(nowSpeed);
	this->robot->setSpeed(nowSpeed + speedStep);
}

void MoveIntent::speedDown(){
	int nowSpeed;
	this->robot->getSpeed(nowSpeed);
	this->robot->setSpeed(nowSpeed - speedStep);
}