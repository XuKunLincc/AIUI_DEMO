#pragma once

#include "RobotIntent.h"

#define GRAB_STR		"grab_default"
#define UNCLASP_STR		"unclasp_default"

class GrabIntent : public RobotIntent
{
private:
	enum SubIntent
	{
		NOTHING = -1,
		GRAB,			// grab
		UNCLASP,		// unclasp
	} subIntent;

public:
	GrabIntent();
	~GrabIntent();
	
};