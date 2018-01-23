#include "RobotIntent.h"

RobotIntent::RobotIntent(RobotAgent *robot, Json::Value intentJson){

	if(intentJson.empty())
		cout << "intentJson was null" << endl;

	semanticJson = (intentJson["semantic"])[0];
	if(semanticJson.empty())
		cout << "semanticJson was null" << endl;

	subIntentJson = semanticJson["intent"];
	if(subIntentJson.empty())
		cout << "subIntentJson was null" << endl;

	slotsJson = (semanticJson["slots"])[0];
	if(slotsJson.empty())
		cout << "slotsJson was null" << endl;

	parameterJson = slotsJson["normValue"];
	if(parameterJson.empty())
		cout << "parameterJson was null" << endl;

	this->robot = robot;
}

