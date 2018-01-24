#pragma once

#include <stdint.h>
#include <string>
#include <map>

typedef unsigned char byte;
typedef std::pair<std::string,std::string> Value;

struct MFileInfo
{
    std::string strName;//�ļ�����
    unsigned long ulSize;// ��С
    unsigned char ucType; //���� 0��ʾ�ļ���1��ʾĿ¼
    std::string strModifyTime; //�޸�ʱ��
};

typedef uint64_t HMCErrCode;

// �������ȼ�ö��
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