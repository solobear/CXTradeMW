#pragma once
#include <deque>
#include "afxsock.h"
#include "api/TradeApi.h"
#include "Lock.h" 
#include "CXTradeMWSocketListener.h"

using namespace std;

//此类专门用来与客户端进行socket通信
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

	CTradeSpi* pSpi;
	static int CXTradeApiRespThread(LPVOID pParam);

	HANDLE hApiReqThread;
	HANDLE hApiRespThread;

	// 账号
	CString m_username;
	CString m_password;

	// 交易锁
	static Mutex M_TradeLock;	      //创建一个交易锁 
protected:
	void SendBackTradeData();  //数据回传

	void Login();              // 登陆
	void Logout();             // 退出

protected:
	// 消息长度
	UINT m_nLength;

	// 消息缓冲区
	char m_recvBuf[2048];     //接收缓冲区

	// 存数据进队列
	char m_sendBuf[2048];     //发送缓冲区
	Mutex m_DataLock;	      //创建一个数据锁 
	deque<string> m_sendQue;  //发送数据队列

public:
	void Enque(string); //数据入列
};