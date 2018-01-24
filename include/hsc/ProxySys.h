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
     * Description: 系统复位
     */
    HMCErrCode reset();

    /**
     * @Description: 系统是否就绪
	 * @return: 已/未就绪
     */
	HMCErrCode isReady(bool & ok);

    /**
     * Description: 系统消息
     * @param type:  类型
     * @param code:  错误码
     * @param strMsg:  消息
     * @param ulWaitTime:  等待时间
     */
    HMCErrCode getMessage(int32_t & type, uint64_t & code, std::string & strMsg, uint32_t ulWaitTime);

    /**
     * @Description: 获取版本信息
     * @param key:  键
	 * @return: 版本信息
     */
    HMCErrCode getVersion(const std::string & key, std::string & value);

    /**
     * @Description: 关机
     */
	HMCErrCode shutdown();
	
	/**
     * @Description: 重启
     */
	HMCErrCode reboot();

private:
    CommApi * m_pNet;
};
