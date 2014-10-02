#include "StdAfx.h"
#include "CXMWSocketListener.h"

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
	printf("\n--收到新请求, 创建Socket连接\n");
	CXMWSocket *pSocket = new CXMWSocket();
	if (Accept(*pSocket))
	{
		CString strAddr("");
		CString strip("");
		UINT nPort;
		pSocket->GetPeerName(strip, nPort);
		strAddr.Format("%s:%d", strip, nPort);
		printf("--开始处理连接: %s\n", strAddr);
	}
	else
	{
		printf("--连接失败！\n");
		delete pSocket;
	}

	CAsyncSocket::OnAccept(nErrorCode);
}

void CXMWSocketListener::OnConnect(int nErrorCode){
	printf("-- CXMWSocketListener: OnConnect\n");
	CAsyncSocket::OnConnect(nErrorCode);
}

void CXMWSocketListener::OnClose(int nErrorCode){
	printf("-- CXMWSocketListener: OnClose\n");
	CAsyncSocket::OnClose(nErrorCode);
}