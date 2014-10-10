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

	// CXTradeApi: Req and Resp
	bool STOP;
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

	// ��Ϣ����
	UINT m_nLength;

	// ��Ϣ������
	char m_recvBuf[4096];     //���ջ�����

	// �����ݽ�����
	char m_sendBuf[4096];     //���ͻ�����
	deque<string> m_sendQue;  //�������ݶ���
	void Enque(string);
	Mutex m_lock;	//����һ��������� 

};