#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "libs/jsoncpp/json.h"
#include "CXMWSocket.h"
#include "CXMWCommand.h"
#include "api/TradeApi.h"
#include "CXTradeSpiImpl.h"
#include "CXUtils.h"

using namespace std;
using namespace Json;

///
CXMWSocket::CXMWSocket(void)
	: m_nLength(0)
{
	STOP = false;

	// ��ʼ��
	memset(m_recvBuf, 0, sizeof(m_recvBuf));
	memset(m_sendBuf, 0, sizeof(m_sendBuf));

	//�ظ�ʹ��ʱ���������ʼ��
	while (!m_sendQue.empty()){
		m_sendQue.pop_back();
	}
}

///
CXMWSocket::~CXMWSocket(void)
{
	printf("--Done!\n\n");

	// �ͷ� TradeAPI
	pApi = NULL;
}


///
void CXMWSocket::OnReceive(int nErrorCode)
{
	//printf("--2.4 OnReceive\n");

	// �յ�����
	m_nLength = Receive(m_recvBuf, sizeof(m_recvBuf), 0); //��������
	m_recvBuf[m_nLength] = '\0';
	cout << "--�յ�����: " << m_recvBuf;

	//////////////////////////////////////////
	Json::Reader jsonReader;  // Reader
	Json::Value jsonRoot;     // Value

	int commandID;            // Command
	Json::Value jsonParams;   // ������

	try
	{
		if (jsonReader.parse(m_recvBuf, jsonRoot))  // reader��Json�ַ���������root
		{
			commandID = jsonRoot["commandID"].asInt();    // CommandID
			jsonParams = jsonRoot["jsonParams"];          // �����б�
			//if (!jsonParams.isNull()){
			//	printf("--�������: %s\n", jsonParams);
			//}
			switch (commandID){
			case REQ_CONNECT:
				printf("\n--��½CX���׽ӿ�:\n");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					username = jsonRoot["username"].asCString();
					password = jsonRoot["password"].asCString();

					//�������׽ӿ�: �����̺߳ͻش��߳�
					hApiReqThread = AfxBeginThread((AFX_THREADPROC)CXTradeApiReqThread, this);
					hApiRespThread = AfxBeginThread((AFX_THREADPROC)CXTradeApiRespThread, this);
				}
				break;
			case Req_OpenMarketOrder:
				printf(" OpenMarketOrder\n");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					CXOpenMarketOrderParam param;
					param.nCommodityID = jsonRoot["nCommodityID"].asInt();
					param.nOpenDirector = jsonRoot["nOpenDirector"].asInt();
					param.dbPrice = jsonRoot["dbPrice"].asDouble();
					param.nQuantity = jsonRoot["nQuantity"].asInt();
					param.dbTradeRange = jsonRoot["dbTradeRange"].asDouble();
					param.nOrderType = jsonRoot["nOrderType"].asInt();
					pApi->ReqOpenMarketOrder(&param);
				}
				break;
			case Req_CloseMarketOrder:
				printf(" Req_CloseMarketOrder\n");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					CXCloseMarketOrderParam param;
					param.nCommodityID = jsonRoot["nCommodityID"].asInt();
					param.nHoldPositionID = jsonRoot["nHoldPositionID"].asInt64();
					param.dbPrice = jsonRoot["dbPrice"].asDouble();
					param.nQuantity = jsonRoot["nQuantity"].asInt();
					param.nTradeRange = jsonRoot["nTradeRange"].asInt();
					param.nClosePositionType = jsonRoot["nClosePositionType"].asInt();
					pApi->ReqCloseMarketOrder(&param);
				}
				break;
			case Req_OpenLimitOrder:
				printf(" Req_OpenLimitOrder\n");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					CXOpenLimitOrderParam param;
					param.nCommodityID = jsonRoot["nCommodityID"].asInt();
					param.nExpireType = jsonRoot["nExpireType"].asInt();
					param.nOpenDirector = jsonRoot["nOpenDirector"].asInt();
					param.nQuantity = jsonRoot["nQuantity"].asInt();
					param.nOrderType = jsonRoot["nOrderType"].asInt();
					param.dbOrderPrice = jsonRoot["dbOrderPrice"].asDouble();
					param.dbTPPrice = jsonRoot["dbTPPrice"].asDouble();
					param.dbSLPrice = jsonRoot["dbSLPrice"].asDouble();
					pApi->ReqOpenLimitOrder(&param);
				}
				break;
			case Req_LimitClosePosition:
				printf(" Req_LimitClosePosition\n");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					CXCloseLimitOrderParam param;
					param.nCommodityID = jsonRoot["nCommodityID"].asInt();
					param.nHoldPositionID = jsonRoot["nHoldPositionID"].asInt64();
					param.dbClosePrice = jsonRoot["dbClosePrice"].asDouble();
					param.nQuantity = jsonRoot["nQuantity"].asInt();
					param.nExpireType = jsonRoot["nExpireType"].asInt();
					param.dbSLPrice = jsonRoot["dbSLPrice"].asDouble();
					param.dbTPPrice = jsonRoot["dbTPPrice"].asDouble();
					pApi->ReqLimitClosePosition(&param);
				}
				break;
			case Req_LimitRevoke:
				printf(" Req_LimitRevoke\n");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					CXLimitRevokeParam param;
					param.nCommodityID = jsonRoot["nCommodityID"].asInt();
					param.nLimitOrderID = jsonRoot["nLimitOrderID"].asInt64();
					param.nOrderType = jsonRoot["nOrderType"].asInt();
					param.nLimitType = jsonRoot["nLimitType"].asInt();
					pApi->ReqLimitRevoke(&param);
				}
				break;
			case Req_CloseMarketOrderMany:
				printf(" Req_CloseMarketOrderMany\n");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					CXCloseMarketOrderManyParam param;
					param.nCommodityID = jsonRoot["nCommodityID"].asInt();
					param.dbPrice = jsonRoot["dbPrice"].asDouble();
					param.nQuantity = jsonRoot["nQuantity"].asInt();
					param.nTradeRange = jsonRoot["nTradeRange"].asInt();
					param.nClosePositionType = jsonRoot["nClosePositionType"].asInt();
					param.nCloseDirector = jsonRoot["nCloseDirector"].asInt();
					pApi->ReqCloseMarketOrderMany(&param);
				}
				break;
			case ReqQry_AccountInfo:
				printf(" ReqQry_AccountInfo\n");
				pApi->ReqQryAccountInfo();
				break;
			case ReqQry_Commodity:
				printf(" ReqQry_Commodity\n");
				pApi->ReqQryCommodity();
				break;
			case ReqQry_PositionOrder:
				printf(" ReqQry_PositionOrder\n");
				pApi->ReqQryPositionOrder();
				break;
			case ReqQry_LimitOrder:
				printf(" ReqQry_LimitOrder\n");
				pApi->ReqQryLimitOrder();
				break;
			case ReqQry_ClosePosition:
				printf(" ReqQry_ClosePosition\n");
				pApi->ReqQryClosePosition();
				break;
			case ReqQry_HoldPositionTotal:
				printf(" ReqQry_HoldPositionTotal\n");
				pApi->ReqQryHoldPositionTotal();
				break;
			case ReqQry_MarketStatus:
				printf(" ReqQry_MarketStatus\n");
				pApi->ReqQryMarketStatus();
				break;
			case ReqQry_HoldPositionByID:
				printf(" ReqQry_HoldPositionByID\n");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					long nHoldPositionID = jsonRoot["nHoldPositionID"].asUInt();
					pApi->ReqQryHoldPositionByID(nHoldPositionID);
				}
				break;
			case ReqQry_LimitOrderByID:
				printf(" ReqQry_LimitOrderByID\n");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					long nLimitOrderID = jsonRoot["nLimitOrderID"].asUInt();
					pApi->ReqQryLimitOrderByID(nLimitOrderID);
				}
				break;
			case ReqQry_ClosePositionByID:
				printf(" ReqQry_ClosePositionByID\n");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					long nClosePositionID = jsonRoot["nClosePositionID"].asUInt();
					pApi->ReqQryClosePositionByID(nClosePositionID);
				}
				break;
			case ReqQry_HoldPositionTotalByCommodityID:
				printf(" ReqQry_HoldPositionTotalByCommodityID\n");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					long nCommodityID = jsonRoot["nCommodityID"].asInt();
					long nOpenDirector = jsonRoot["nOpenDirector"].asInt();
					pApi->ReqQryHoldPositionTotalByCommodityID(nCommodityID, nOpenDirector);
				}
				break;
			case ReqQry_CommodityQuote:
				printf(" ReqQry_CommodityQuote\n");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					long nCommodityID = jsonRoot["nCommodityID"].asInt();
					pApi->ReqQryCommodityQuote(nCommodityID);
				}
				break;
			case ReqQry_OpenMarketOrderConf:
				printf(" ReqQry_OpenMarketOrderConf\n");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					long nCommodityID = jsonRoot["nCommodityID"].asInt();
					pApi->ReqQryOpenMarketOrderConf(nCommodityID);
				}
				break;
			case ReqQry_OpenLimitOrderConf:
				printf(" ReqQry_OpenLimitOrderConf\n");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					long nCommodityID = jsonRoot["nCommodityID"].asInt();
					pApi->ReqQryOpenLimitOrderConf(nCommodityID);
				}
				break;
			case ReqQry_CloseMarketOrderConf:
				printf(" ReqQry_CloseMarketOrderConf\n");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					long nCommodityID = jsonRoot["nCommodityID"].asInt();
					pApi->ReqQryCloseMarketOrderConf(nCommodityID);
				}
				break;
			case ReqQry_LimitClosePositionConf:
				printf(" ReqQry_LimitClosePositionConf\n");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					long nCommodityID = jsonRoot["nCommodityID"].asInt();
					pApi->ReqQryLimitClosePositionConf(nCommodityID);
				}
				break;
			case REQ_RELEASE:
				printf(" Release\n");
				pApi->Release();
				STOP = true; // �˳����ݴ����߳�
				break;
			default:
				printf(" Unknown Command\n");
				break;
			}
		}
		else{
			cout << "--ERROR: ��Ч����" << endl;
		}
	}
	catch (std::exception &ex)
	{
		printf("--���������쳣: %s\n", ex.what());
	}

	//����Buf
	memset(m_recvBuf, 0, sizeof(m_recvBuf));

	/////////////////////////////////////////
	CAsyncSocket::OnReceive(nErrorCode);
}

///
void CXMWSocket::OnSend(int nErrorCode)
{
	//printf("--2.5 OnSend\n");


	/////////////////////////////////////////
	CAsyncSocket::OnSend(nErrorCode);
}

///
void CXMWSocket::OnClose(int nErrorCode){
	//printf("--2.0 OnClose\n");

	// STOP
	STOP = true;

	if (pApi != NULL){
		// ֹͣ���׽ӿ�
		pApi->Release();

		// ɾ��SPI
		delete pSpi;
	}

	// ͣsocket
	if (m_hSocket != INVALID_SOCKET)
	{
		printf("--�Ͽ���Socket����\n");
		Close();
	}

	// Delete
	delete this;

	CAsyncSocket::OnClose(nErrorCode);
}



///
/// CxTradeApi Funcs
///

/// CXTradeApi�����߳�
int CXMWSocket::CXTradeApiRespThread(LPVOID pParam)
{
	CXMWSocket *pObj = (CXMWSocket *)pParam;
	pObj->SendBackTradeData();
	return 0;
}


/// CXTradeApi�����߳�
void CXMWSocket::SendBackTradeData()
{
	while (true){
		try{
			// ��ȫ�˳�
			if (STOP){
				break;
			}

			// �����ݲŴ���
			if (m_sendQue.size()>0 && m_sendQue.size()<1000){
				//cout << "--  ȡ����, size: " << m_sendQue.size() << " = " << m_sendQue.front();

				strcat_s(m_sendBuf, m_sendQue.front().c_str());
				//cout << strlen(m_sendBuf) << endl;
				//cout << "--ԭʼ����: " << m_sendQue.front() << endl;
				cout << "--��������: " << m_sendBuf;

				// ��������
				Send(m_sendBuf, strlen(m_sendBuf));

				// ɾ������
				m_lock.Lock();
				m_sendQue.pop_front();
				m_lock.Unlock();
				//cout << "--  ȡ������, size: " << m_sendQue.size() << endl;

				//����Buf
				memset(m_sendBuf, 0, sizeof(m_sendBuf));
			}
			else if (m_sendQue.size()>1000){
				m_sendQue.clear();
			}

			// ���¾����ϸ�
			Sleep(20);
		}
		catch (std::exception &e){
			cout << e.what() << endl;
		}
	}
}

/// �����ݽ�����, ��Ҫ������
void CXMWSocket::Enque(string str){
	try{
		// ��ȫ�˳�
		if (STOP){
			return;
		}

		//cout << "--  �յ�����, size: " << m_sendQue.size() << " = " << str;

		m_lock.Lock();
		m_sendQue.push_back(str);
		m_lock.Unlock();

		//cout << "--���������." << endl;
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}



/// CXTradeApi�����߳�
int CXMWSocket::CXTradeApiReqThread(LPVOID pParam)
{
	CXMWSocket *pObj = (CXMWSocket *)pParam;
	pObj->Login();
	return 0;
}


/// CXTradeApi��½
void CXMWSocket::Login()
{
	try{
		CXUtils::PrintCurrentDir();
		char* dir = "./log/";
		CXUtils::CheckDir(dir);
		pApi = CTradeApi::CreateTradeApi(dir);
		pSpi = new CXTradeSpiImpl(pApi, this);
		pApi->RegisterSpi(pSpi);

		pApi->RegisterFront("183.62.250.18", 9745);
		pApi->SetAppMessage("test1", "123456", "874987497234");

		int res = pApi->Init();
		if (res)
		{
			cout << "--CXTradeApi Init | Result: " << res << endl;
			AfxMessageBox(_T("���׽ӿڳ�ʼ��ʧ��!"));
			return;
		}

		//�û���/����
		//printf("--CXTradeApi|Login with %s:%s\n", username, password);
		char* u = new char[64];
		char* p = new char[64];
		strcpy_s(u, 64, username);
		strcpy_s(p, 64, password);
		printf("--CXTradeApi | Login as %s\n", u);
		pApi->ReqUserLogin(u, p);

		pApi->Join();
		printf("--�˳�CX���׽ӿ�\n");
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}
