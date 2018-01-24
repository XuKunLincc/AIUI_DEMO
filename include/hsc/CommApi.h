#pragma once
#ifdef _LINUX_
#define DLL_EXPORT __attribute__((visibility("default")))
#else
#define DLL_EXPORT _declspec(dllexport) 
#endif

#include "CommDef.h"
#include <stdint.h>
#include <string>
#include <vector>


class CommApp;
class FtpApi;

class DLL_EXPORT CommApi
{
public:
    CommApi(const std::string & strLogPath = "");
    ~CommApi(void);

    std::string getVersionStr();

    void setAutoConn(bool en);
    void setUseUdp(bool en);
    bool isConnected();
    HMCErrCode NetConnect(const std::string & strIp, uint16_t uPort);
    HMCErrCode NetExit();
    HMCErrCode NetSendStr(const std::string & strCmd, std::string & strRet, int priority);
    HMCErrCode NetGetAsyncMsg(std::string & strMsg);
    HMCErrCode NetClearAsyncMsg();

    // UDP
    HMCErrCode getUdpMsg(std::string & strMsg);
    HMCErrCode getUdpSessionId(int & id);
    HMCErrCode clearUdpMsg();

    // FTP
    // 下载文件    
    HMCErrCode fileGet(const std::string & strLocalName, const std::string & strSrcName);
    // 上传文件
    HMCErrCode filePut(const std::string & strDstName, const std::string & strLocalName);
    // 删除文件
    HMCErrCode fileDel(const std::string & strPath);
    // 创建文件夹
    HMCErrCode dirMk(const std::string & strPath);
    // 获取文件列表
    HMCErrCode fileListInfo(const std::string & strDirPath, std::vector<MFileInfo>& pFileInfo);

private:
    CommApp * m_pNet;
    FtpApi * m_pFtp;
};

