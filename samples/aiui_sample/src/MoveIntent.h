#pragma once

#include "RobotIntent.h"

#define MOVE_BY_DIREC 			"move_by_direction"
#define TRANSLATION_BY_DIREC 		"translation_by_direction"



class MoveIntent : public RobotIntent{
private:
	enum SubIntent
	{
		NOTHING = 0,
		MOVE_BY_DIRECTION,	// 整体方向运动
		MOVE_BY_AXIS,		// 单轴运动
		TRAN_BY_DIRECTION,	// 平移运动
	} subIntent;

	RobotAgent::Direction direction;

	void moveByDirec();
	void moveByDirecInit();
	void translationByDirec();
	void translationByDirecInit();

public:
	MoveIntent(RobotAgent *robot, Json::Value intent);

	void execAction();
};