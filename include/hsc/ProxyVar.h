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
     * Description: ���������
     * @param axId:  ��ţ�0..n-1��
     */
    HMCErrCode saveAx();
	HMCErrCode saveAx(int8_t axId);
	
	/**
     * Description: ���������
     * @param gpId:  ��ţ�0..n-1��
     */
    HMCErrCode saveGp();
	HMCErrCode saveGp(int8_t gpId);
    
//     /**
//      * Description: ����
//      * @param gpId:  ��ţ�0..n-1��
// 	 * @param axId:  ��ţ�0..n-1��
// 	 * @param variable:  ����������ʽ������������"a"/"b"�����������"a[i][j]"���ṹ�������"a.b.c"��
// 	 * @param value:     ֵ����ʽ����������ֵ��"1"/"true"/"2.0"������ֵ��"{1, 2, 3}"���ṹ��ֵ��"{1, true, 2.0}"��
//      */
//     HMCErrCode setGroupVariable(int8_t gpId, const std::string & var, const std::string & value);
//     HMCErrCode setAxisVariable(int8_t axId, const std::string & var, const std::string & value);
//     HMCErrCode setAxisVariable(int8_t axId_1, const std::string & var_1, int8_t axId_2, const std::string & var_2);
// 
// 	/**
//      * Description: ��ȡ
//      * @param gpId:  ��ţ�0..n-1��
// 	 * @param axId:  ��ţ�0..n-1��
//      */
//     HMCErrCode getGroupVariable(int8_t gpId, const std::string & var, std::string & value);
//     HMCErrCode getAxisVariable(int8_t axId, const std::string & var, std::string & value);
//     
private:
    CommApi * m_pNet;
};