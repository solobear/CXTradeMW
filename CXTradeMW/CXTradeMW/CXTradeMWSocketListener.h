#pragma once
#include "afxsock.h"
#include "CXTradeMWSocket.h"

// Listener
class CXMWSocketListener :
	public CAsyncSocket
{
public:
	CXMWSocketListener(void);
	~CXMWSocketListener(void);

	virtual void OnAccept(int nErrorCode);

	virtual void OnConnect(int nErrorCode);
	virtual void OnClose(int nErrorCode);
};

