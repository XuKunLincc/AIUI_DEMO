#ifndef __ROBOT__H__
#define __ROBOT__H__

#include <iostream>

using namespace std;



class RobotAgent{
private:
	int lastTasket;
	int nowTasket;

public:

	enum Direction{LEFT, RIGHT, TOP, BOTTOM, FRONT, BACK};

	void moveByDirection(Direction direc);		// 根据方向进行运动
	void translationByDirec(Direction direc);	// 根据方向进行平移
	void moveByAxis(int axId, bool isClockwise);	// 根据轴ID进行运动
	void startTasket();							// 启动当前任务
	void stopTasket();							// 停止当前任务
	void initRobot();							// 初始化机械臂
	//void robotGrap();							// 控制机械臂抓取
	//void robotUnclasp();						// 控制机械臂松开

	RobotAgent();		// 控制器IP
	~RobotAgent();
};

#endif

