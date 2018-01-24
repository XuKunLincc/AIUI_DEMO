#pragma once

#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>


// namespace HsIII
// {
    // 寄存器类型
    enum RegType
    {
        REG_R,
        REG_JR,
        REG_LR,
        REG_MAX,
    };

    // 网络状态
    enum CommState
    {
        COMM_ST_DISCONNECTED = 0,   //断开
        COMM_ST_CONNECTED,          //已连接
        COMM_ST_MAX,
    };

    // 运行模式类型
    enum OpMode
    {
        OP_NONE,
        OP_T1,
        OP_T2,
        OP_AUT,
        OP_EXT
    };

    // 坐标系
    enum FrameType
    {
        FRAME_NONE = 0,
        FRAME_JOINT,            
        FRAME_WORLD,
        FRAME_TOOL,
        FRAME_BASE,
        FRAME_MAX,
    };

    // 点动类型
    enum ManualMode
    {
        MANUAL_CONTINUE = 0,
        MANUAL_INCREMENT,
    };

    enum DirectType
    {
        POSITIVE = 0,
        NEGATIVE
    };

    // 手动运行状态类型
    enum ManState
    {
        MAN_STATE_WAIT = 0,     // 0-等待信号
        MAN_STATE_GET_PARA,     // 1-获取参数
        MAN_STATE_JOG,          // 2-点动运行
        MAN_STATE_INCH,         // 3-寸动运行
        MAN_STATE_LOCATION,     // 4-定位运行
        MAN_STATE_ERROR,        // 5-错误状态
        MAN_STATE_MAX,
    };

    // 自动运行模式
    enum AutoMode
    {
        AUTO_MODE_CONTINUE = 0,    // 0-连续
        AUTO_MODE_STEP,            // 1-单步
        AUTO_MODE_DEBUG,            // 2-调试
        AUTO_MODE_MAX,
    };

    // 自动运行状态类型
    enum AutoState
    {
        AUTO_STATE_IDLE = 0,    // 空闲
        AUTO_STATE_READY,       // 就绪
        AUTO_STATE_RUNNING,     // 运行
        AUTO_STATE_PAUSE,       // 暂停
        AUTO_STATE_ERROR,       // 出错
        AUTO_STATE_MAX,
    };

    //笛卡尔坐标
    typedef std::vector<double> DcartPos;
    //关节坐标
    typedef std::vector<double> JointPos;

    /**
    * @param isJoint: 点位-是否关节点
    * @param ufNum:   点位-工件号（1..n）
    * @param utNum:   点位-工具号（1..n）
    * @param config:  点位-config 【注意】参考机器人程序点位定义中的CONFIG定义
    * @param strPos:  点位-点数据（格式：大括号扩起、半角逗号分隔的数列，例“{1.0,2.0,3.0,4.0,5.0,6.0,}”）
    */
    struct LocationParameter
    {
        bool isJoint;
        int8_t ufNum;
        int8_t utNum;
        int32_t config;
        std::vector<double> vecPos;
    };

    struct ProgInfo
    {
        std::string cur_prog;
        int32_t line_no;
        int32_t state;
    };


// };

