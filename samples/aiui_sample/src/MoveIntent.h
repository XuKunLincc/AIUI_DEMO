#pragma once

#include "RobotIntent.h"
#include <map>

#define MOVE_BY_DIREC 			"move_by_direction"
#define TRANSLATION_BY_DIREC 		"translation_by_direction"
#define MOVEAXIS_CLOCKWISE		"moveaxis_by_clockwise"
#define MOVEAXIS_ANTICLOCK		"moveaxis_by_anticlock"
#define ENABLE_STR 	"enable"
#define UNABLE_STR 	"unable"
#define SPPED_UP 	"speed_up"
#define SPPED_DOWN 	"speed_down"
#define SPEED_SET 	"speed_set"

#define speedStep 10 

class MoveIntent : public RobotIntent{

	typedef void (MoveIntent:: *PAction)();

private:
	map<string, PAction> actionMap;

	void translation();
	void moveAxisCW();
	void moveAxisAC();
	void moveAxis(int axisId, bool isClockwise);
	int getAxisId();
	void enable();
	void unable();
	void speedUp();
	void speedDown();
	void speedSet();
	RobotAgent::Direction getDirec();

public:
	MoveIntent(RobotAgent *robot, Json::Value intent);

	void execAction();
};
