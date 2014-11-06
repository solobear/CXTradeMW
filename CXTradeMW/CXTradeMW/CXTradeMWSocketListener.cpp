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
		LOGI("--�յ�������, ����Socket����");
		CXMWSocket *pSocket = new CXMWSocket();
		if (Accept(*pSocket))
		{
			// ����IP�Ͷ˿�
			pSocket->ParseConnInfo();

			if (CXTradeMWConns::Instance()->InBlackList(pSocket->m_strIP)){
				LOGW("--" << pSocket->m_strAddr << "  ���������ܾ�����");
				pSocket->Close();
				delete pSocket;
			}
			else{
				LOGI("--��ʼ��������: " << pSocket->m_strAddr);
			}
		}
		else
		{
			LOGI("--����ʧ�ܣ�");
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
