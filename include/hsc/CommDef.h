#pragma once

#include <stdint.h>
#include <string>
#include <map>

typedef unsigned char byte;
typedef std::pair<std::string,std::string> Value;

struct MFileInfo
{
    std::string strName;//文件名称
    unsigned long ulSize;// 大小
    unsigned char ucType; //类型 0表示文件，1表示目录
    std::string strModifyTime; //修改时间
};

typedef uint64_t HMCErrCode;

// 命令优先级枚举
enum CmdPriority
{
    PRIORITY_MIN = 0,
    PRIORITY_HIGHEST,
    PRIORITY_HIGH,
    PRIORITY_NORMAL,
    PRIORITY_LOW,
    PRIORITY_LOWEST,
    PRIORITY_MAX,
};