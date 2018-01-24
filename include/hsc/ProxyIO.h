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

class DLL_EXPORT ProxyIO
{
public:
    ProxyIO(CommApi * pNet);
    ~ProxyIO();


    /**
     * Description: 数字IO
	 * @param grpIndex:  组号（0..n-1）
	 * @param portIndex: 端子号（0..n-1）
	 * @param value: 值
	 * @param stat: 是否虚拟IO
     */
	HMCErrCode getMaxDinNum(int32_t & num);
	HMCErrCode getMaxDoutNum(int32_t & num);
	HMCErrCode getMaxDinGrp(int32_t & num);
	HMCErrCode getMaxDoutGrp(int32_t & num);
	HMCErrCode getDinGrp(int32_t grpIndex, int32_t & num);
	HMCErrCode getDoutGrp(int32_t grpIndex, int32_t & num);
	HMCErrCode getDinMaskGrp(int32_t grpIndex, int32_t & num);
	HMCErrCode getDoutMaskGrp(int32_t grpIndex, int32_t & num);
	HMCErrCode setDin(int32_t portIndex, bool value);
	HMCErrCode setDout(int32_t portIndex, bool value);
	HMCErrCode setDinMaskBit(int32_t portIndex, bool stat);
	HMCErrCode setDoutMaskBit(int32_t portIndex, bool stat);

private:
    inline HMCErrCode getGlobalCommand(std::string cmd, std::string & ret);
    inline HMCErrCode getGroupCommand(std::string cmd, int8_t gpId, std::string & ret);

private:
    CommApi * m_pNet;
};