#pragma once

#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>


// namespace HsIII
// {
    // �Ĵ�������
    enum RegType
    {
        REG_R,
        REG_JR,
        REG_LR,
        REG_MAX,
    };

    // ����״̬
    enum CommState
    {
        COMM_ST_DISCONNECTED = 0,   //�Ͽ�
        COMM_ST_CONNECTED,          //������
        COMM_ST_MAX,
    };

    // ����ģʽ����
    enum OpMode
    {
        OP_NONE,
        OP_T1,
        OP_T2,
        OP_AUT,
        OP_EXT
    };

    // ����ϵ
    enum FrameType
    {
        FRAME_NONE = 0,
        FRAME_JOINT,            
        FRAME_WORLD,
        FRAME_TOOL,
        FRAME_BASE,
        FRAME_MAX,
    };

    // �㶯����
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

    // �ֶ�����״̬����
    enum ManState
    {
        MAN_STATE_WAIT = 0,     // 0-�ȴ��ź�
        MAN_STATE_GET_PARA,     // 1-��ȡ����
        MAN_STATE_JOG,          // 2-�㶯����
        MAN_STATE_INCH,         // 3-�綯����
        MAN_STATE_LOCATION,     // 4-��λ����
        MAN_STATE_ERROR,        // 5-����״̬
        MAN_STATE_MAX,
    };

    // �Զ�����ģʽ
    enum AutoMode
    {
        AUTO_MODE_CONTINUE = 0,    // 0-����
        AUTO_MODE_STEP,            // 1-����
        AUTO_MODE_DEBUG,            // 2-����
        AUTO_MODE_MAX,
    };

    // �Զ�����״̬����
    enum AutoState
    {
        AUTO_STATE_IDLE = 0,    // ����
        AUTO_STATE_READY,       // ����
        AUTO_STATE_RUNNING,     // ����
        AUTO_STATE_PAUSE,       // ��ͣ
        AUTO_STATE_ERROR,       // ����
        AUTO_STATE_MAX,
    };

    //�ѿ�������
    typedef std::vector<double> DcartPos;
    //�ؽ�����
    typedef std::vector<double> JointPos;

    /**
    * @param isJoint: ��λ-�Ƿ�ؽڵ�
    * @param ufNum:   ��λ-�����ţ�1..n��
    * @param utNum:   ��λ-���ߺţ�1..n��
    * @param config:  ��λ-config ��ע�⡿�ο������˳����λ�����е�CONFIG����
    * @param strPos:  ��λ-�����ݣ���ʽ�����������𡢰�Ƕ��ŷָ������У�����{1.0,2.0,3.0,4.0,5.0,6.0,}����
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

