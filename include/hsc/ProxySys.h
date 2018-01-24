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

class DLL_EXPORT ProxySys
{
public:
    ProxySys(CommApi * pNet);
    ~ProxySys();

    /**
     * Description: ϵͳ��λ
     */
    HMCErrCode reset();

    /**
     * @Description: ϵͳ�Ƿ����
	 * @return: ��/δ����
     */
	HMCErrCode isReady(bool & ok);

    /**
     * Description: ϵͳ��Ϣ
     * @param type:  ����
     * @param code:  ������
     * @param strMsg:  ��Ϣ
     * @param ulWaitTime:  �ȴ�ʱ��
     */
    HMCErrCode getMessage(int32_t & type, uint64_t & code, std::string & strMsg, uint32_t ulWaitTime);

    /**
     * @Description: ��ȡ�汾��Ϣ
     * @param key:  ��
	 * @return: �汾��Ϣ
     */
    HMCErrCode getVersion(const std::string & key, std::string & value);

    /**
     * @Description: �ػ�
     */
	HMCErrCode shutdown();
	
	/**
     * @Description: ����
     */
	HMCErrCode reboot();

private:
    CommApi * m_pNet;
};
