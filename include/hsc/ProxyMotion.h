#pragma once
#ifdef _LINUX_
#define DLL_EXPORT __attribute__((visibility("default")))
#else
#define DLL_EXPORT _declspec(dllexport) 
#endif

#include "CommDef.h"
#include "Hsc3Def.h"
#include <stdint.h>


class CommApi;

class DLL_EXPORT ProxyMotion
{
public:
    ProxyMotion(CommApi * pNet);
    ~ProxyMotion();

// 全局作用域

	/**
     * Description: 操作模式（2-手动T1，3-手动T2，4-自动，5-外部）
     * @param mode: 【注意】枚举值参考运动层定义
     */
    HMCErrCode setOpMode(OpMode mode);
    HMCErrCode getOpMode(OpMode & mode);
	
	/**
     * Description: 手动类型（0-持续，非0-增量）
     * @param mode: 【注意】枚举值参考运动层定义
     */
	HMCErrCode setManualMode(ManualMode mode);
    HMCErrCode getManualMode(ManualMode & mode);
	
	/**
     * Description: 手动增量距离
     * @param len:  距离大小（单位根据坐标系确定，关节：°；笛卡尔：mm）
     */
	HMCErrCode setInchLen(double length);
    HMCErrCode getInchLen(double & length);
	
	/**
     * Description: 手动运行模式（0-等待信号，1-获取参数，2-点动运行，3-寸动运行，4-定位运行，5-错误状态）
     * @param mode: 【注意】枚举值参考运动层定义
     */
    HMCErrCode getManualStat(ManState & state);
	
	/**
     * Description: 自动运行模式（1-连续，2-单步，3-任意行，4—调试模式）
     * @param mode: 【注意】枚举值参考运动层定义
     */
	HMCErrCode setAutoMode(AutoMode mode);
    HMCErrCode getAutoMode(AutoMode & mode);
	
	/**
     * Description: 自动运动倍率
     * @param vord:  倍率（1~100，单位：%）
     */
	HMCErrCode setVord(int32_t vord);
    HMCErrCode getVord(int32_t & vord);
	
	/**
     * Description: 手动运动倍率
     * @param vord:  倍率（1~100，单位：%）
     */
	HMCErrCode setJogVord(int32_t vord);
    HMCErrCode getJogVord(int32_t & vord);
	
	/**
     * Description: 急停
     * @param en:  是否急停
     */
	HMCErrCode setEstop(bool estop);
    HMCErrCode getEstop(bool & estop);
	

// 组作用域

	/**
     * Description: 组使能
	 * @param gpId:  组号（0..n-1）
     * @param en:    是否使能
     */
	HMCErrCode setGpEn(int8_t gpId, bool en);
    HMCErrCode getGpEn(int8_t gpId, bool & en);
	 
	/**
     * Description: 组复位
	 * @param gpId:  组号（0..n-1）
     */
	HMCErrCode gpReset(int8_t gpId);

    /**
     * Description:  零点校准接口
     * @param gpId:  组号（0..n-1）
     * @param strPos:零点设定值，例如{0，-90，0，0，90，0}
     * @param mask:  掩码，低9位有效，最低位代表组中第1个轴，第9位代表组中第9个轴。
     */
    HMCErrCode setHomePosition(int8_t gpId, const JointPos& pos, int32_t mask);

    /**
     * @Description:  获取零点接口
     * @param gpId:  组号（0..n-1）
	 * @return:  点数据（格式：大括号扩起、半角逗号分隔的数列，例“{1.0,2.0,3.0,4.0,5.0,6.0,}”）
     */
    HMCErrCode getHomePosition(int8_t gpId, JointPos & pos);

    /**
     * @Description:  设置软限位接口
     * @param gpId:  组号（0..n-1）
     * @param strLimitPos:正向设定值，例如{90，90，90，90，90，90}
	 * @param strLimitNeg:负向设定值，例如{-90，-90，-90，-90，-90，-90}
     * @param mask:  使能掩码，低9位有效，最低位代表组中第1个轴，第9位代表组中第9个轴。
     */
    HMCErrCode setJointLimit(int8_t gpId, const JointPos & pos, const JointPos & neg, int32_t mask);
	
	/**
     * @Description:  获取软限位接口
     * @param gpId:  组号（0..n-1）
     * @param mask:  使能掩码，低9位有效，最低位代表组中第1个轴，第9位代表组中第9个轴。
	 * @return :     限位信息（格式：例“pos={1,1,}, neg={-1,-1,}, mask=0x1ff”，其中“pos”是正向设定值，
						“neg”是负向设定值，“mask”是使能掩码）
     */
    HMCErrCode getJointLimit(int8_t gpId, JointPos & pos, JointPos & neg, int32_t & mask);

	/**
     * Description: 手动移动
	 * @param gpId:  组号（0..n-1）
	 * @param axId:  轴号（0..n-1）
	 * @param direc: 方向 【注意】枚举值参考运动层定义
     */
	HMCErrCode startJog(int8_t gpId, int8_t axId, DirectType direc);
	HMCErrCode stopJog(int8_t gpId);
	
	/**
     * Description: 运动定位
	 * @param gpId:  组号（0..n-1）
	 * @param isJoint: 点位-是否关节点
	 * @param ufNum:   点位-工件号（1..n）
	 * @param utNum:   点位-工具号（1..n）
	 * @param config:  点位-config 【注意】参考机器人程序点位定义中的CONFIG定义
	 * @param strPos:  点位-点数据（格式：大括号扩起、半角逗号分隔的数列，例“{1.0,2.0,3.0,4.0,5.0,6.0,}”）
	 * @param isLinear:  是否直线运动
     */
	HMCErrCode moveTo(int8_t gpId, const LocationParameter & point, bool isLinear);

	/**
     * Description: 工作坐标系
	 * @param gpId:  组号（0..n-1）
	 * @param frame: 【注意】枚举值参考运动层定义
     */
	HMCErrCode setWorkFrame(int8_t gpId, FrameType frame);
    HMCErrCode getWorkFrame(int8_t gpId, FrameType & frame);
	
	/**
     * Description: 获取关节坐标
	 * @param gpId:  组号（0..n-1）
	 * @return : 点数据（格式：大括号扩起、半角逗号分隔的数列，例“{1.0,2.0,3.0,4.0,5.0,6.0,}”）
     */
	 HMCErrCode getJointPos(int8_t gpId, JointPos & pos);

	/**
     * Description: 获取笛卡尔坐标
	 * @param gpId:  组号（0..n-1）
	 * @return : 点数据（格式：大括号扩起、半角逗号分隔的数列，例“{1.0,2.0,3.0,4.0,5.0,6.0,}”）
     */
	 HMCErrCode getLocPos(int8_t gpId, DcartPos & pos);

     /**
     * @Description: 获取Config
	 * @param gpId:  组号（0..n-1）
	 * @return : Config
     */
	 HMCErrCode getConfig(int8_t gpId, int32_t & config);
	
	/**
     * Description: 工具坐标系
	 * @param gpId:  组号（0..n-1）
	 * @param index: 工具索引（1..n）
	 * @param data:  点数据（格式：大括号扩起、半角逗号分隔的数列，例“{1.0,2.0,3.0,4.0,5.0,6.0,}”）
     */
	HMCErrCode setTool(int8_t gpId, int8_t index, const DcartPos & pos);
	HMCErrCode getTool(int8_t gpId, int8_t index, DcartPos & pos);
	
	/**
     * Description: 工件坐标系
	 * @param gpId:  组号（0..n-1）
	 * @param index: 工件索引（1..n）
	 * @param data:  点数据（格式：大括号扩起、半角逗号分隔的数列，例“{1.0,2.0,3.0,4.0,5.0,6.0,}”）
     */
	HMCErrCode setWorkpiece(int8_t gpId, int8_t index, const DcartPos & pos);
	HMCErrCode getWorkpiece(int8_t gpId, int8_t index, DcartPos & pos);
	
	/**
     * Description: 工具号
	 * @param gpId:  组号（0..n-1）
	 * @param num:   工具号
     */
	HMCErrCode setToolNum(int8_t gpId, int8_t num);
	HMCErrCode getToolNum(int8_t gpId, int8_t & num);
    
	/**
     * Description: 工件号
	 * @param gpId:  组号（0..n-1）
	 * @param num:   工件号
     */
	HMCErrCode setWorkpieceNum(int8_t gpId, int8_t num);
	HMCErrCode getWorkpieceNum(int8_t gpId, int8_t & num);

    /**
     * @Description: 标定（标定成功后数据会设置至内存，但不会保存至文件）
	 * @param what:  标定对象（工具-“TOOL”，工件-“BASE”）
	 * @param gpId:  组号（0..n-1）
	 * @param num:   工具号/工件号
	 * @param type:  标定方法编号 【注意】参考机器人程序点位定义中的CONFIG定义
	 * @param strData:   标定数据（格式：半角分号分隔的点数据队列，例“{1,2,};{3,4,};{5,6,}”）
	 * @return :     标定结果（格式：例“ret=0x0, data={7,8,}”，其中“ret”是标定返回值，“data”是标定结果）
     */
	HMCErrCode gpCalibrate(const std::string & what, int8_t gpId, int8_t num, int8_t type, const std::string & strData, std::string & strResult);

private:
    inline HMCErrCode getGlobalCommand(std::string cmd, std::string & ret);
    inline HMCErrCode getGroupCommand(std::string cmd, int8_t gpId, std::string & ret);

private:
    CommApi * m_pNet;
};

