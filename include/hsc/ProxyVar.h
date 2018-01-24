#pragma once
#ifdef _LINUX_
#define DLL_EXPORT __attribute__((visibility("default")))
#else
#define DLL_EXPORT _declspec(dllexport) 
#endif

#include "Hsc3Def.h"
#include "CommDef.h"
#include <stdint.h>


class CommApi;

class ProxyVar
{
public:
    ProxyVar(CommApi * pNet);
    ~ProxyVar();

    /**
     * Description: 保存轴参数
     * @param axId:  轴号（0..n-1）
     */
    HMCErrCode saveAx();
	HMCErrCode saveAx(int8_t axId);
	
	/**
     * Description: 保存组参数
     * @param gpId:  组号（0..n-1）
     */
    HMCErrCode saveGp();
	HMCErrCode saveGp(int8_t gpId);
    
//     /**
//      * Description: 设置
//      * @param gpId:  组号（0..n-1）
// 	 * @param axId:  轴号（0..n-1）
// 	 * @param variable:  变量名（格式，基础变量："a"/"b"；数组变量："a[i][j]"；结构体变量："a.b.c"）
// 	 * @param value:     值（格式，基础类型值："1"/"true"/"2.0"；数组值："{1, 2, 3}"；结构体值："{1, true, 2.0}"）
//      */
//     HMCErrCode setGroupVariable(int8_t gpId, const std::string & var, const std::string & value);
//     HMCErrCode setAxisVariable(int8_t axId, const std::string & var, const std::string & value);
//     HMCErrCode setAxisVariable(int8_t axId_1, const std::string & var_1, int8_t axId_2, const std::string & var_2);
// 
// 	/**
//      * Description: 获取
//      * @param gpId:  组号（0..n-1）
// 	 * @param axId:  轴号（0..n-1）
//      */
//     HMCErrCode getGroupVariable(int8_t gpId, const std::string & var, std::string & value);
//     HMCErrCode getAxisVariable(int8_t axId, const std::string & var, std::string & value);
//     
private:
    CommApi * m_pNet;
};