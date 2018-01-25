#pragma once

#include "RobotIntent.h"

#define MOVE_BY_DIREC 			"move_by_direction"
#define TRANSLATION_BY_DIREC 		"translation_by_direction"
#define MOVEAXIS_CLOCKWISE		"moveaxis_by_clockwise"
#define MOVEAXIS_ANTICLOCK		"moveaxis_by_anticlock"
#define ENABLE_STR "enable"
#define UNABLE_STR "unable"


class MoveIntent : public RobotIntent{
private:
	enum SubIntent
	{
		NOTHING = -1,
		MOVE_BY_DIRECTION,				// 整体方向运动
		MOVE_BY_AXIS_CLOCKWISE,			// 单轴运动 顺时针
		MOVE_BY_AXIS_ANTICLOCK,			// 单轴运动 逆时针
		TRAN_BY_DIRECTION,				// 平移运动
		ENABLE,
		UNABLE,
		SPEED_UP,
		SPEED_DOWN,
	} subIntent;

	RobotAgent::Direction direction;
	bool isClockwise;
	int axisId;
	int nowSpeed, speedStep;


	void moveByDirec();
	void moveByDirecInit();
	void translation();
	void translationByDirecInit();
	void moveAxis();
	void getAxisId();
	int enable();
	int unable();
	void speed_up();
	void speed_down();

public:
	MoveIntent(RobotAgent *robot, Json::Value intent);

	void execAction();
};
