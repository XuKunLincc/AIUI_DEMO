#ifndef __ROBOT__H__
#define __ROBOT__H__

#include <iostream>
#include <stdint.h>
#include "hsc/CommApi.h"
#include "hsc/ProxyMotion.h"
#include <list>

#define MOVE_STEP 150

using namespace std;

class RobotAgent{
private:
	enum RobotStatus
	{
		ERROR = -1,
		REPEATING,
		READY,
	} robotStatus;
	int lastTasket;
	int nowTasket;
	int speedNow;					// 当前机器人速率
	int speedStep;					// 每次机器人运行速率的变化歩长
	ProxyMotion *mProxyMotion;
	CommApi *mCommApi;

	vector<JointPos> jointPosVec;
	JointPos jointPos;

public:

	enum Direction{LEFT, RIGHT, TOP, BOTTOM, FRONT, BACK};

	void moveByDirection(Direction direc);		// 根据方向进行运动
	void translation(Direction direc, int len);		// 根据方向进行平移
	//void translationLen(Direction direc, int len);
	void moveAxis(int axId, bool isClockwise, int len);	// 根据轴ID进行运动
	void startTasket();				// 启动当前任务
	void stopTasket();				// 停止当前任务
	int initRobot();					// 初始化机械臂
	int enable(bool isEnable);
	int setSpeed(int spped);
	int getSpeed(int & speed);
	void record();
	void cleanPos();
	void repeat();
	void drag_mode(bool isIn);
	//int recordDecaCoord(DcartPos  &pos);
	//int recordDecaCoord(JointPos &pos):
	//void robotGrap();				// 控制机械臂抓取
	//void robotUnclasp();				// 控制机械臂松开

	RobotAgent(const string &ip, uint16_t port);	// 控制器IP
	void print_location(std::vector<double>& v);	// 打印当前坐标到终端
	void __repeat();
	~RobotAgent();
};

#endif

