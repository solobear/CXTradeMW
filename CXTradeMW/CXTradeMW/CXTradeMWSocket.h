#pragma once
#include <deque>
#include "afxsock.h"
#include "api/TradeApi.h"
#include "Lock.h" 

using namespace std;

//����ר��������ͻ��˽���socketͨ��
class CXMWSocket :
	public CAsyncSocket
{
public:
	CXMWSocket(void);
	virtual ~CXMWSocket(void);

public:
	// Funcs
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	virtual void OnClose(int nErrorCode);

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
	CString username;
	CString password;

protected:
	// ��Ϣ����
	UINT m_nLength;

	// ��Ϣ������
	char m_recvBuf[4096];     //���ջ�����

	// �����ݽ�����
	char m_sendBuf[4096];     //���ͻ�����
	Mutex m_lock;	//����һ��������� 
	deque<string> m_sendQue;  //�������ݶ���

public:
	void Enque(string); //��������
};