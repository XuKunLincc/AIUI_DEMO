﻿/*
* AIUIAgentTest.h
*
*  Created on: 2017年3月9日
*      Author: hj
*/

#ifndef AIUIAGENTTEST_H_
#define AIUIAGENTTEST_H_

#include "aiui/AIUI.h"
#include "RobotAgent.h"
#include "RobotAlarmThread.h"

#include <string>
#include <iostream>

#include "FileUtil.h"

#ifdef _MSC_VER
#include <windows.h>
#include <process.h>
#define TEST_ROOT_DIR ".\\AIUI"
#define CFG_FILE_PATH TEST_ROOT_DIR##"\\cfg\\aiui.cfg"
#define TEST_AUDIO_PATH TEST_ROOT_DIR##"\\audio\\test.pcm"
#define LOG_DIR TEST_ROOT_DIR##"\\log"
#else
#include <unistd.h>
#include <pthread.h>
#define TEST_ROOT_DIR "./AIUI/"
#define CFG_FILE_PATH "./AIUI/cfg/aiui.cfg"
#define TEST_AUDIO_PATH "./AIUI/audio/test.pcm"
#define LOG_DIR "./AIUI/log"
#endif

#include "jsoncpp/json/json.h"

#define ALSA_PCM_NEW_HW_PARAMS_API
#include <alsa/asoundlib.h>

using namespace aiui;
using namespace std;
using namespace VA;


class WriteAudioThread
{
private:
	IAIUIAgent* mAgent;

	string mAudioPath;

	bool mRepeat;

	bool mRun;

	snd_pcm_t *handle;
	char *audioBuffer;
	snd_pcm_uframes_t frames;

	FileUtil::DataFileHelper* mFileHelper;

  pthread_t thread_id;
  bool thread_created;

private:
	bool threadLoop();
	int readAudio();
	void initAudio();

  static void* thread_proc(void * paramptr);

public:
	WriteAudioThread(IAIUIAgent* agent, const string& audioPath, bool repeat);

	~WriteAudioThread();

	void stopRun();

	bool run();

};


class TestListener : public IAIUIListener
{
public:
	void onEvent(const IAIUIEvent& event) const;
	RobotAgent* mRobot;
};


class AIUITester
{
private:
	IAIUIAgent* agent;

	TestListener listener;

	RobotAgent* mRobot;
	RobotAlarmThread *mRobotAlarmThr;

	WriteAudioThread * writeThread;
public:
	AIUITester() ;

	~AIUITester();
private:
	void createAgent();
	void wakeup();
	void start();
	void stop();
	void write(bool repeat);
	void stopWriteThread();
	void reset();
	void writeText();
	void destory();
	void createRobot();
	

public:
	void readCmd();
	void test();
};



#endif /* AIUIAGENTTEST_H_ */
