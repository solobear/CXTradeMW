#include "StdAfx.h"
#include "CXTradeMWSocketListener.h"
#include "CXTradeMWConns.h"
#include "log4z.h"

using namespace zsummer::log4z;
using namespace std;

///
CXMWSocketListener::CXMWSocketListener(void)
{
	//printf("-- CXMWSocketListener\n");
}

///
CXMWSocketListener::~CXMWSocketListener(void)
{
	//printf("-- ~CXMWSocketListener\n");
}


///
void CXMWSocketListener::OnAccept(int nErrorCode)
{
	try{
		LOGI("");
		LOGI("");
		LOGI("--收到新请求, 创建Socket连接");
		CXMWSocket *pSocket = new CXMWSocket();
		if (Accept(*pSocket))
		{
			// 解析IP和端口
			pSocket->ParseConnInfo();

			if (CXTradeMWConns::Instance()->InBlackList(pSocket->m_strIP)){
				LOGW("--" << pSocket->m_strAddr << "  黑名单，拒绝服务。");
				pSocket->Close();
				delete pSocket;
			}
			else{
				LOGI("--开始处理连接: " << pSocket->m_strAddr);
			}
		}
		else
		{
			LOGI("--连接失败！");
			delete pSocket;
		}
	}
	catch (std::exception e){
		LOGE("--" << e.what());
	}
	CAsyncSocket::OnAccept(nErrorCode);
}


///
void CXMWSocketListener::OnConnect(int nErrorCode){
	LOGI("-- CXMWSocketListener: OnConnect");
	CAsyncSocket::OnConnect(nErrorCode);
}


///
void CXMWSocketListener::OnClose(int nErrorCode){
	LOGI("-- CXMWSocketListener: OnClose");
	CAsyncSocket::OnClose(nErrorCode);
}
