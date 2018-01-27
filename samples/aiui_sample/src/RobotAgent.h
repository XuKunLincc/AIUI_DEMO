#ifndef __ROBOT__H__
#define __ROBOT__H__

#include <iostream>
#include <stdint.h>
#include "hsc/CommApi.h"
#include "hsc/ProxyMotion.h"

using namespace std;

#include <list>

class RobotAgent{
private:
	int lastTasket;
	int nowTasket;
	int speedNow;					// 当前机器人速率
	int speedStep;					// 每次机器人运行速率的变化歩长
	ProxyMotion *mProxyMotion;
	CommApi *mCommApi;

	//list<JointPos> jointPosList;
	JointPos jointPos;

public:

	enum Direction{LEFT, RIGHT, TOP, BOTTOM, FRONT, BACK};

	void moveByDirection(Direction direc);		// 根据方向进行运动
	void translation(Direction direc);		// 根据方向进行平移
	//void translationLen(Direction direc, int len);
	void moveAxis(int axId, bool isClockwise, int len);	// 根据轴ID进行运动
	void startTasket();				// 启动当前任务
	void stopTasket();				// 停止当前任务
	int initRobot();					// 初始化机械臂
	int enable(bool isEnable);
	int setSpeed(int spped);
	int getSpeed(int & speed);
	void record();
	void repeat();
	void drag_mode(bool isIn);
	//int recordDecaCoord(DcartPos  &pos);
	//int recordDecaCoord(JointPos &pos):
	//void robotGrap();				// 控制机械臂抓取
	//void robotUnclasp();				// 控制机械臂松开

	RobotAgent(const string &ip, uint16_t port);	// 控制器IP
	~RobotAgent();
};

#endif

