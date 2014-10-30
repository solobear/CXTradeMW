#pragma once
#include <afxcoll.h>
#include "afxsock.h"
#include "CXTradeMWSocket.h"

using namespace std;

// Listener
class CXMWSocketListener :
	public CAsyncSocket
{

public:
	CXMWSocketListener(void);
	~CXMWSocketListener(void);

public:
	virtual void OnAccept(int nErrorCode);

	virtual void OnConnect(int nErrorCode);
	virtual void OnClose(int nErrorCode);
};

