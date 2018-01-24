#pragma once
#ifdef _LINUX_
#define DLL_EXPORT __attribute__((visibility("default")))
#else
#define DLL_EXPORT _declspec(dllexport) 
#endif

#include "Hsc3Def.h"
#include "CommDef.h"
#include <stdint.h>
#include <vector>


class CommApi;

class DLL_EXPORT ProxyRegister
{
public:
    ProxyRegister(CommApi * pNet);
    ~ProxyRegister();

	/**
     * Description: R（实数）寄存器
     * @param index:  索引（0..n-1）
	 * @param value:  浮点数值
     */
	HMCErrCode setR(int32_t index, double value);
	HMCErrCode getR(int32_t index, double & value);
    HMCErrCode getR(int32_t index, int32_t len, std::vector<double> & value);
	
	/**
     * Description: JR（关节坐标）寄存器
     * @param index:  索引（0..n-1）
	 * @param value:  点数据（格式：大括号扩起、半角逗号分隔的数列，例“{1.0,2.0,3.0,4.0,5.0,6.0,}”）
     */
	HMCErrCode setJR(int32_t index, const std::vector<double>& value);
	HMCErrCode getJR(int32_t index, std::vector<double> & value);
    HMCErrCode getJR(int32_t index, int32_t len, std::vector<JointPos> & value);
	
	/**
     * Description: LR（笛卡尔坐标）寄存器
     * @param index:  索引（0..n-1）
	 * @param value:  点数据（格式：大括号扩起、半角逗号分隔的数列，例“{1.0,2.0,3.0,4.0,5.0,6.0,}”）
     */
	HMCErrCode setLR(int32_t index, const std::vector<double>& value);
	HMCErrCode getLR(int32_t index, std::vector<double> & value);
    HMCErrCode getLR(int32_t index, int32_t len, std::vector<DcartPos> & value);

    /**
     * Description: 保存R（实数）寄存器
     * @param index:  索引（0..n-1）
	 * @param len:    数量
     */
	HMCErrCode saveR();	// 保存所有
	HMCErrCode saveR(int32_t index, int32_t len);

    /**
     * Description: 保存JR（关节坐标）寄存器
     * @param index:  索引（0..n-1）
	 * @param len:    数量
     */
	HMCErrCode saveJR();	// 保存所有
	HMCErrCode saveJR(int32_t index, int32_t len);

    /**
     * Description: 保存LR（关节坐标）寄存器
     * @param index:  索引（0..n-1）
	 * @param len:    数量
     */
	HMCErrCode saveLR();	// 保存所有
	HMCErrCode saveLR(int32_t index, int32_t len);

    HMCErrCode saveVar(RegType type);

private:
    CommApi * m_pNet;
};

