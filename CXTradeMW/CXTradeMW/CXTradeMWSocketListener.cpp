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
	LOGI("--�յ�������, ����Socket����");
	CXMWSocket *pSocket = new CXMWSocket();
	if (Accept(*pSocket))
	{
		CString strAddr("");
		CString strip("");
		UINT nPort;
		pSocket->GetPeerName(strip, nPort);
		strAddr.Format("%s:%d", strip, nPort);
		LOGI("--��ʼ��������: " << strAddr);
	}
	else
	{
		LOGI("--����ʧ�ܣ�");
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