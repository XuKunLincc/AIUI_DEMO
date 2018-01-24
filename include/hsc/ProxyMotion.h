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

// ȫ��������

	/**
     * Description: ����ģʽ��2-�ֶ�T1��3-�ֶ�T2��4-�Զ���5-�ⲿ��
     * @param mode: ��ע�⡿ö��ֵ�ο��˶��㶨��
     */
    HMCErrCode setOpMode(OpMode mode);
    HMCErrCode getOpMode(OpMode & mode);
	
	/**
     * Description: �ֶ����ͣ�0-��������0-������
     * @param mode: ��ע�⡿ö��ֵ�ο��˶��㶨��
     */
	HMCErrCode setManualMode(ManualMode mode);
    HMCErrCode getManualMode(ManualMode & mode);
	
	/**
     * Description: �ֶ���������
     * @param len:  �����С����λ��������ϵȷ�����ؽڣ��㣻�ѿ�����mm��
     */
	HMCErrCode setInchLen(double length);
    HMCErrCode getInchLen(double & length);
	
	/**
     * Description: �ֶ�����ģʽ��0-�ȴ��źţ�1-��ȡ������2-�㶯���У�3-�綯���У�4-��λ���У�5-����״̬��
     * @param mode: ��ע�⡿ö��ֵ�ο��˶��㶨��
     */
    HMCErrCode getManualStat(ManState & state);
	
	/**
     * Description: �Զ�����ģʽ��1-������2-������3-�����У�4������ģʽ��
     * @param mode: ��ע�⡿ö��ֵ�ο��˶��㶨��
     */
	HMCErrCode setAutoMode(AutoMode mode);
    HMCErrCode getAutoMode(AutoMode & mode);
	
	/**
     * Description: �Զ��˶�����
     * @param vord:  ���ʣ�1~100����λ��%��
     */
	HMCErrCode setVord(int32_t vord);
    HMCErrCode getVord(int32_t & vord);
	
	/**
     * Description: �ֶ��˶�����
     * @param vord:  ���ʣ�1~100����λ��%��
     */
	HMCErrCode setJogVord(int32_t vord);
    HMCErrCode getJogVord(int32_t & vord);
	
	/**
     * Description: ��ͣ
     * @param en:  �Ƿ�ͣ
     */
	HMCErrCode setEstop(bool estop);
    HMCErrCode getEstop(bool & estop);
	

// ��������

	/**
     * Description: ��ʹ��
	 * @param gpId:  ��ţ�0..n-1��
     * @param en:    �Ƿ�ʹ��
     */
	HMCErrCode setGpEn(int8_t gpId, bool en);
    HMCErrCode getGpEn(int8_t gpId, bool & en);
	 
	/**
     * Description: �鸴λ
	 * @param gpId:  ��ţ�0..n-1��
     */
	HMCErrCode gpReset(int8_t gpId);

    /**
     * Description:  ���У׼�ӿ�
     * @param gpId:  ��ţ�0..n-1��
     * @param strPos:����趨ֵ������{0��-90��0��0��90��0}
     * @param mask:  ���룬��9λ��Ч�����λ�������е�1���ᣬ��9λ�������е�9���ᡣ
     */
    HMCErrCode setHomePosition(int8_t gpId, const JointPos& pos, int32_t mask);

    /**
     * @Description:  ��ȡ���ӿ�
     * @param gpId:  ��ţ�0..n-1��
	 * @return:  �����ݣ���ʽ�����������𡢰�Ƕ��ŷָ������У�����{1.0,2.0,3.0,4.0,5.0,6.0,}����
     */
    HMCErrCode getHomePosition(int8_t gpId, JointPos & pos);

    /**
     * @Description:  ��������λ�ӿ�
     * @param gpId:  ��ţ�0..n-1��
     * @param strLimitPos:�����趨ֵ������{90��90��90��90��90��90}
	 * @param strLimitNeg:�����趨ֵ������{-90��-90��-90��-90��-90��-90}
     * @param mask:  ʹ�����룬��9λ��Ч�����λ�������е�1���ᣬ��9λ�������е�9���ᡣ
     */
    HMCErrCode setJointLimit(int8_t gpId, const JointPos & pos, const JointPos & neg, int32_t mask);
	
	/**
     * @Description:  ��ȡ����λ�ӿ�
     * @param gpId:  ��ţ�0..n-1��
     * @param mask:  ʹ�����룬��9λ��Ч�����λ�������е�1���ᣬ��9λ�������е�9���ᡣ
	 * @return :     ��λ��Ϣ����ʽ������pos={1,1,}, neg={-1,-1,}, mask=0x1ff�������С�pos���������趨ֵ��
						��neg���Ǹ����趨ֵ����mask����ʹ�����룩
     */
    HMCErrCode getJointLimit(int8_t gpId, JointPos & pos, JointPos & neg, int32_t & mask);

	/**
     * Description: �ֶ��ƶ�
	 * @param gpId:  ��ţ�0..n-1��
	 * @param axId:  ��ţ�0..n-1��
	 * @param direc: ���� ��ע�⡿ö��ֵ�ο��˶��㶨��
     */
	HMCErrCode startJog(int8_t gpId, int8_t axId, DirectType direc);
	HMCErrCode stopJog(int8_t gpId);
	
	/**
     * Description: �˶���λ
	 * @param gpId:  ��ţ�0..n-1��
	 * @param isJoint: ��λ-�Ƿ�ؽڵ�
	 * @param ufNum:   ��λ-�����ţ�1..n��
	 * @param utNum:   ��λ-���ߺţ�1..n��
	 * @param config:  ��λ-config ��ע�⡿�ο������˳����λ�����е�CONFIG����
	 * @param strPos:  ��λ-�����ݣ���ʽ�����������𡢰�Ƕ��ŷָ������У�����{1.0,2.0,3.0,4.0,5.0,6.0,}����
	 * @param isLinear:  �Ƿ�ֱ���˶�
     */
	HMCErrCode moveTo(int8_t gpId, const LocationParameter & point, bool isLinear);

	/**
     * Description: ��������ϵ
	 * @param gpId:  ��ţ�0..n-1��
	 * @param frame: ��ע�⡿ö��ֵ�ο��˶��㶨��
     */
	HMCErrCode setWorkFrame(int8_t gpId, FrameType frame);
    HMCErrCode getWorkFrame(int8_t gpId, FrameType & frame);
	
	/**
     * Description: ��ȡ�ؽ�����
	 * @param gpId:  ��ţ�0..n-1��
	 * @return : �����ݣ���ʽ�����������𡢰�Ƕ��ŷָ������У�����{1.0,2.0,3.0,4.0,5.0,6.0,}����
     */
	 HMCErrCode getJointPos(int8_t gpId, JointPos & pos);

	/**
     * Description: ��ȡ�ѿ�������
	 * @param gpId:  ��ţ�0..n-1��
	 * @return : �����ݣ���ʽ�����������𡢰�Ƕ��ŷָ������У�����{1.0,2.0,3.0,4.0,5.0,6.0,}����
     */
	 HMCErrCode getLocPos(int8_t gpId, DcartPos & pos);

     /**
     * @Description: ��ȡConfig
	 * @param gpId:  ��ţ�0..n-1��
	 * @return : Config
     */
	 HMCErrCode getConfig(int8_t gpId, int32_t & config);
	
	/**
     * Description: ��������ϵ
	 * @param gpId:  ��ţ�0..n-1��
	 * @param index: ����������1..n��
	 * @param data:  �����ݣ���ʽ�����������𡢰�Ƕ��ŷָ������У�����{1.0,2.0,3.0,4.0,5.0,6.0,}����
     */
	HMCErrCode setTool(int8_t gpId, int8_t index, const DcartPos & pos);
	HMCErrCode getTool(int8_t gpId, int8_t index, DcartPos & pos);
	
	/**
     * Description: ��������ϵ
	 * @param gpId:  ��ţ�0..n-1��
	 * @param index: ����������1..n��
	 * @param data:  �����ݣ���ʽ�����������𡢰�Ƕ��ŷָ������У�����{1.0,2.0,3.0,4.0,5.0,6.0,}����
     */
	HMCErrCode setWorkpiece(int8_t gpId, int8_t index, const DcartPos & pos);
	HMCErrCode getWorkpiece(int8_t gpId, int8_t index, DcartPos & pos);
	
	/**
     * Description: ���ߺ�
	 * @param gpId:  ��ţ�0..n-1��
	 * @param num:   ���ߺ�
     */
	HMCErrCode setToolNum(int8_t gpId, int8_t num);
	HMCErrCode getToolNum(int8_t gpId, int8_t & num);
    
	/**
     * Description: ������
	 * @param gpId:  ��ţ�0..n-1��
	 * @param num:   ������
     */
	HMCErrCode setWorkpieceNum(int8_t gpId, int8_t num);
	HMCErrCode getWorkpieceNum(int8_t gpId, int8_t & num);

    /**
     * @Description: �궨���궨�ɹ������ݻ��������ڴ棬�����ᱣ�����ļ���
	 * @param what:  �궨���󣨹���-��TOOL��������-��BASE����
	 * @param gpId:  ��ţ�0..n-1��
	 * @param num:   ���ߺ�/������
	 * @param type:  �궨������� ��ע�⡿�ο������˳����λ�����е�CONFIG����
	 * @param strData:   �궨���ݣ���ʽ����Ƿֺŷָ��ĵ����ݶ��У�����{1,2,};{3,4,};{5,6,}����
	 * @return :     �궨�������ʽ������ret=0x0, data={7,8,}�������С�ret���Ǳ궨����ֵ����data���Ǳ궨�����
     */
	HMCErrCode gpCalibrate(const std::string & what, int8_t gpId, int8_t num, int8_t type, const std::string & strData, std::string & strResult);

private:
    inline HMCErrCode getGlobalCommand(std::string cmd, std::string & ret);
    inline HMCErrCode getGroupCommand(std::string cmd, int8_t gpId, std::string & ret);

private:
    CommApi * m_pNet;
};

