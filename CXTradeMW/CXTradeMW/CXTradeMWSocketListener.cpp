#include "StdAfx.h"
#include "CXTradeMWSocketListener.h"
#include "log4z.h"

using namespace zsummer::log4z;

CXMWSocketListener::CXMWSocketListener(void)
{
	//printf("-- CXMWSocketListener\n");
}


CXMWSocketListener::~CXMWSocketListener(void)
{
	//printf("-- ~CXMWSocketListener\n");
}

void CXMWSocketListener::OnAccept(int nErrorCode)
{
	LOGI("");
	LOGI("");
	LOGI("--收到新请求, 创建Socket连接");
	CXMWSocket *pSocket = new CXMWSocket();
	if (Accept(*pSocket))
	{
		CString strAddr("");
		CString strip("");
		UINT nPort;
		pSocket->GetPeerName(strip, nPort);
		strAddr.Format("%s:%d", strip, nPort);
		LOGI("--开始处理连接: " << strAddr);
	}
	else
	{
		LOGI("--连接失败！");
		delete pSocket;
	}

	CAsyncSocket::OnAccept(nErrorCode);
}

void CXMWSocketListener::OnConnect(int nErrorCode){
	LOGI("-- CXMWSocketListener: OnConnect");
	CAsyncSocket::OnConnect(nErrorCode);
}

void CXMWSocketListener::OnClose(int nErrorCode){
	LOGI("-- CXMWSocketListener: OnClose");
	CAsyncSocket::OnClose(nErrorCode);
}