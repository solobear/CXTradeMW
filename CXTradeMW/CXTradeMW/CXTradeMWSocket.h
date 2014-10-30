#pragma once
#include <deque>
#include "afxsock.h"
#include "api/TradeApi.h"
#include "Lock.h" 
#include "CXTradeMWSocketListener.h"

using namespace std;

//����ר��������ͻ��˽���socketͨ��
class CXMWSocket :
	public CAsyncSocket
{
public:
	CXMWSocket();
	virtual ~CXMWSocket(void);

public:
	CString m_strAddr;
	CString m_strIP;
	UINT m_nPort;
	void ParseConnInfo();

public:
	// Funcs
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	virtual void OnClose(int nErrorCode);

protected:
	static int COUNT;

protected:
	bool STOP;

	// CXTradeApi: Req and Resp
	CTradeApi* pApi;
	static int CXTradeApiReqThread(LPVOID pParam);
	void Login();              // ��½

	CTradeSpi* pSpi;
	static int CXTradeApiRespThread(LPVOID pParam);
	void SendBackTradeData();  //���ݻش�

	HANDLE hApiReqThread;
	HANDLE hApiRespThread;

	// �˺�
	CString m_username;
	CString m_password;

protected:
	// ��Ϣ����
	UINT m_nLength;

	// ��Ϣ������
	char m_recvBuf[2048];     //���ջ�����

	// �����ݽ�����
	char m_sendBuf[2048];     //���ͻ�����
	Mutex m_lock;	//����һ��������� 
	deque<string> m_sendQue;  //�������ݶ���

public:
	void Enque(string); //��������
};