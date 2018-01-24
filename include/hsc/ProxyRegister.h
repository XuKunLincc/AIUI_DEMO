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
     * Description: R��ʵ�����Ĵ���
     * @param index:  ������0..n-1��
	 * @param value:  ������ֵ
     */
	HMCErrCode setR(int32_t index, double value);
	HMCErrCode getR(int32_t index, double & value);
    HMCErrCode getR(int32_t index, int32_t len, std::vector<double> & value);
	
	/**
     * Description: JR���ؽ����꣩�Ĵ���
     * @param index:  ������0..n-1��
	 * @param value:  �����ݣ���ʽ�����������𡢰�Ƕ��ŷָ������У�����{1.0,2.0,3.0,4.0,5.0,6.0,}����
     */
	HMCErrCode setJR(int32_t index, const std::vector<double>& value);
	HMCErrCode getJR(int32_t index, std::vector<double> & value);
    HMCErrCode getJR(int32_t index, int32_t len, std::vector<JointPos> & value);
	
	/**
     * Description: LR���ѿ������꣩�Ĵ���
     * @param index:  ������0..n-1��
	 * @param value:  �����ݣ���ʽ�����������𡢰�Ƕ��ŷָ������У�����{1.0,2.0,3.0,4.0,5.0,6.0,}����
     */
	HMCErrCode setLR(int32_t index, const std::vector<double>& value);
	HMCErrCode getLR(int32_t index, std::vector<double> & value);
    HMCErrCode getLR(int32_t index, int32_t len, std::vector<DcartPos> & value);

    /**
     * Description: ����R��ʵ�����Ĵ���
     * @param index:  ������0..n-1��
	 * @param len:    ����
     */
	HMCErrCode saveR();	// ��������
	HMCErrCode saveR(int32_t index, int32_t len);

    /**
     * Description: ����JR���ؽ����꣩�Ĵ���
     * @param index:  ������0..n-1��
	 * @param len:    ����
     */
	HMCErrCode saveJR();	// ��������
	HMCErrCode saveJR(int32_t index, int32_t len);

    /**
     * Description: ����LR���ؽ����꣩�Ĵ���
     * @param index:  ������0..n-1��
	 * @param len:    ����
     */
	HMCErrCode saveLR();	// ��������
	HMCErrCode saveLR(int32_t index, int32_t len);

    HMCErrCode saveVar(RegType type);

private:
    CommApi * m_pNet;
};

