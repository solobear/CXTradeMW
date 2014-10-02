#pragma once
#include <deque>
#include "afxsock.h"
#include "api/TradeApi.h"
#include "Lock.h" 

using namespace std;

//此类专门用来与客户端进行socket通信
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
	void Login();              // 登陆
	CTradeSpi* pSpi;
	static int CXTradeApiRespThread(LPVOID pParam);
	void SendBackTradeData();  //数据回传

	HANDLE hApiReqThread;
	HANDLE hApiRespThread;

	// 账号
	CString username;
	CString password;

	// 消息长度
	UINT m_nLength;

	// 消息缓冲区
	char m_recvBuf[4096];     //接收缓冲区

	// 存数据进队列
	char m_sendBuf[4096];     //发送缓冲区
	deque<string> m_sendQue;  //发送数据队列
	void Enque(string);
	Mutex m_lock;	//创建一个互斥对象 

};