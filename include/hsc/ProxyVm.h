#pragma once

#ifdef _LINUX_
#define DLL_EXPORT __attribute__((visibility("default")))
#else
#define DLL_EXPORT _declspec(dllexport) 
#endif

#include "CommDef.h"
#include <stdint.h>
#include <vector>


class CommApi;
struct ProgInfo;

class DLL_EXPORT ProxyVm
{
public:
    ProxyVm(CommApi * pNet);
    ~ProxyVm();


    /**
     * Description: 加载程序
	 * @param path:  路径
	 * @param fileName:   文件名
     */
	HMCErrCode load(const std::string & path, const std::string & fileName);
	
	/**
     * Description: 启动程序
	 * @param fileName:   文件名
     */
	HMCErrCode start(const std::string & fileName);
	
	/**
     * Description: 暂停程序
	 * @param fileName:   文件名
     */
	HMCErrCode pause(const std::string & fileName);
	
	/**
     * Description: 停止程序
	 * @param fileName:   文件名
     */
	HMCErrCode stop(const std::string & fileName);
	
	/**
     * Description: 单步执行程序
	 * @param fileName:   文件名
     */
	HMCErrCode step(const std::string & fileName);
	
	/**
     * Description: 卸载程序
	 * @param fileName:   文件名
     */
	HMCErrCode unload(const std::string & fileName);
	
	/**
     * Description: 获取程序状态
	 * @param fileName:   文件名
	 * @return: 1-停止运行状态，2-等待状态,等待Action，3-运行中状态，4-延时，5-错误
     */
	HMCErrCode progState(const std::string & fileName, int8_t & state);

	/**
     * Description: 设置单步模式
	 * @param fileName:   文件名
	 * @param en:  是否单步
     */
	HMCErrCode setStepMode(const std::string & fileName, bool en);
	
	/**
     * Description: 是否已加载
	 * @param fileName:   文件名
     */
	HMCErrCode isLoaded(const std::string & fileName, bool & fl);
	
	/**
     * Description: 获取当前行
	 * @param fileName:   文件名
	 * @return: 行（1..n）
     */
	HMCErrCode getCurLineNo(const std::string & fileName, int32_t & row);
	
	/**
     * Description: 获取当前运行程序名
	 * @param fileName:   文件名（主程序名）
     */
	HMCErrCode getCurProgName(const std::string & fileName, std::string & progName);
	
	/**
     * Description: 获取已加载的主程序列表
	 * @return: 程序列表（格式：中括号扩起、半角逗号分隔的字符串队列，例“[ abc.prg, def.prg ]”）
     */
    HMCErrCode mainProgNames(std::string & strProgNames);
	HMCErrCode mainProgNames(std::vector<std::string> & progList);

    /**
     * @Description: 获取程序信息
	 * @param fileName:   文件名（主程序名）
	 * @return :     信息内容（格式：例“ret=0, cur_prog="***", line_no=0, state=1”，其中“ret”是获取返回值，“cur_prog”是当前程序名，“line_no”是行号，“state”是运行状态）
     */
	HMCErrCode getProgInfo(const std::string & fileName, ProgInfo & info);

private:
    CommApi * m_pNet;
};