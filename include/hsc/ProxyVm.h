#pragma once

#ifdef _LINUX_
#define DLL_EXPORT __attribute__((visibility("default")))
#else
#define DLL_EXPORT _declspec(dllexport) 
#endif

#include "CommDef.h"
#include <stdint.h>
#include <vector>


class CommApi;
struct ProgInfo;

class DLL_EXPORT ProxyVm
{
public:
    ProxyVm(CommApi * pNet);
    ~ProxyVm();


    /**
     * Description: ���س���
	 * @param path:  ·��
	 * @param fileName:   �ļ���
     */
	HMCErrCode load(const std::string & path, const std::string & fileName);
	
	/**
     * Description: ��������
	 * @param fileName:   �ļ���
     */
	HMCErrCode start(const std::string & fileName);
	
	/**
     * Description: ��ͣ����
	 * @param fileName:   �ļ���
     */
	HMCErrCode pause(const std::string & fileName);
	
	/**
     * Description: ֹͣ����
	 * @param fileName:   �ļ���
     */
	HMCErrCode stop(const std::string & fileName);
	
	/**
     * Description: ����ִ�г���
	 * @param fileName:   �ļ���
     */
	HMCErrCode step(const std::string & fileName);
	
	/**
     * Description: ж�س���
	 * @param fileName:   �ļ���
     */
	HMCErrCode unload(const std::string & fileName);
	
	/**
     * Description: ��ȡ����״̬
	 * @param fileName:   �ļ���
	 * @return: 1-ֹͣ����״̬��2-�ȴ�״̬,�ȴ�Action��3-������״̬��4-��ʱ��5-����
     */
	HMCErrCode progState(const std::string & fileName, int8_t & state);

	/**
     * Description: ���õ���ģʽ
	 * @param fileName:   �ļ���
	 * @param en:  �Ƿ񵥲�
     */
	HMCErrCode setStepMode(const std::string & fileName, bool en);
	
	/**
     * Description: �Ƿ��Ѽ���
	 * @param fileName:   �ļ���
     */
	HMCErrCode isLoaded(const std::string & fileName, bool & fl);
	
	/**
     * Description: ��ȡ��ǰ��
	 * @param fileName:   �ļ���
	 * @return: �У�1..n��
     */
	HMCErrCode getCurLineNo(const std::string & fileName, int32_t & row);
	
	/**
     * Description: ��ȡ��ǰ���г�����
	 * @param fileName:   �ļ���������������
     */
	HMCErrCode getCurProgName(const std::string & fileName, std::string & progName);
	
	/**
     * Description: ��ȡ�Ѽ��ص��������б�
	 * @return: �����б���ʽ�����������𡢰�Ƕ��ŷָ����ַ������У�����[ abc.prg, def.prg ]����
     */
    HMCErrCode mainProgNames(std::string & strProgNames);
	HMCErrCode mainProgNames(std::vector<std::string> & progList);

    /**
     * @Description: ��ȡ������Ϣ
	 * @param fileName:   �ļ���������������
	 * @return :     ��Ϣ���ݣ���ʽ������ret=0, cur_prog="***", line_no=0, state=1�������С�ret���ǻ�ȡ����ֵ����cur_prog���ǵ�ǰ����������line_no�����кţ���state��������״̬��
     */
	HMCErrCode getProgInfo(const std::string & fileName, ProgInfo & info);

private:
    CommApi * m_pNet;
};