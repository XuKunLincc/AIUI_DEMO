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

	slotsJson = (semanticJson["slots"]);
	if(slotsJson.empty())
		cout << "slotsJson was null" << endl;

	cout << slotsJson.size() << endl;

	for(int index = 0;  index < slotsJson.size(); ++index){
		parameterMap.insert(pair<int, Json::Value>(index, (slotsJson[index])["normValue"]));
	}
	
	this->robot = robot;
}

