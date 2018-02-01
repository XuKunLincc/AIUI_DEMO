#ifndef __ROBOT__H__
#define __ROBOT__H__

#include <iostream>
#include <stdint.h>
#include "hsc/CommApi.h"
#include "hsc/ProxyMotion.h"
#include "hsc/ProxySys.h"
#include <list>
#include <stdint.h>

#define MOVE_STEP 150

using namespace std;

enum RobotStatus{
	NOTHING = -1,
	REPEATING,
	READY,
	ALARM,
};

class RobotAgent{
private:
	RobotStatus robotStatus;
	ProxyMotion *mProxyMotion;
	ProxySys *mProxySys;
	CommApi *mCommApi;
	vector<JointPos> jointPosVec;

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
	void goHome();					// 回零点
	int reset();					// 复位
	void drag_mode(bool isIn);
	int getAlarm(int &type, uint64_t &code, string &strMsg);					// get the error code
	int setState(RobotStatus status);
	RobotStatus getState();

	RobotAgent(const string &ip, uint16_t port);	// 控制器IP
	void print_location(std::vector<double>& v);	// 打印当前坐标到终端
	void __repeat();
	~RobotAgent();
};

#endif

