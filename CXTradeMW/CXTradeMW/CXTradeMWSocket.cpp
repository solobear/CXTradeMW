#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "libs/jsoncpp/json.h"
#include "CXTradeMWSocket.h"
#include "CXTradeMWCommand.h"
#include "CXTradeMWUtils.h"
#include "CXTradeMWConfig.h"
#include "CXTradeMWConns.h"
#include "CXTradeSpiImpl.h"
#include "api/TradeApi.h"
#include "log4z.h"

using namespace zsummer::log4z;
using namespace std;
using namespace Json;

/// COUNT
int CXMWSocket::COUNT = 0;

///
CXMWSocket::CXMWSocket()
	: m_nLength(0)
{
	//
	STOP = false;

	// 初始化
	memset(m_recvBuf, 0, sizeof(m_recvBuf));
	memset(m_sendBuf, 0, sizeof(m_sendBuf));

	//重复使用时，用这个初始化
	while (!m_sendQue.empty()){
		m_sendQue.pop_back();
	}
}

///
CXMWSocket::~CXMWSocket(void)
{
	LOGI("--Done!");
	LOGI("");
	LOGI("");
}


/// 保存连接信息
void CXMWSocket::ParseConnInfo(){
	// IP和端口
	GetPeerName(m_strIP, m_nPort);
	m_strAddr.Format("%s:%d", m_strIP, m_nPort);
}



///
void CXMWSocket::OnClose(int nErrorCode){
	//LOGD("--2.0 OnClose");

	// STOP
	STOP = true;

	// 释放 TradeAPI
	if (NULL != pApi){
		pApi->Release();
		pApi = NULL;
		Sleep(300);
	}

	// 删除 SPI
	if (NULL != pSpi){
		delete pSpi;
	}

	// 停socket
	if (m_hSocket != INVALID_SOCKET)
	{
		LOGI("--断开该Socket连接");
		Close();
	}

	//
	CAsyncSocket::OnClose(nErrorCode);

	// Delete
	delete this;
}



///
void CXMWSocket::OnReceive(int nErrorCode)
{
	//LOGD("--2.4 OnReceive");

	// 收到数据
	m_nLength = Receive(m_recvBuf, sizeof(m_recvBuf), 0); //接收数据
	m_recvBuf[m_nLength] = '\0';
	//LOGD("--收到请求: " << m_recvBuf);

	//////////////////////////////////////////
	Json::Reader jsonReader;  // Reader
	Json::Value jsonRoot;     // Value

	int commandID;            // Command
	Json::Value jsonParams;   // 参数表

	try
	{
		if (jsonReader.parse(m_recvBuf, jsonRoot))  // reader将Json字符串解析到root
		{
			commandID = jsonRoot["commandID"].asInt();    // CommandID
			jsonParams = jsonRoot["jsonParams"];          // 参数列表
			//if (!jsonParams.isNull()){
			//	LOGI("--请求参数: " << jsonParams);
			//}
			switch (commandID){
			case REQ_CONNECT:
				LOGI("--登陆CX交易接口:");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					m_username = jsonRoot["username"].asCString();
					m_password = jsonRoot["password"].asCString();

					//启动交易接口: 请求线程和回传线程
					hApiReqThread = AfxBeginThread((AFX_THREADPROC)CXTradeApiReqThread, this);
					hApiRespThread = AfxBeginThread((AFX_THREADPROC)CXTradeApiRespThread, this);
				}
				break;
			case Req_OpenMarketOrder:
				LOGI("--收到请求：CommandID=" << commandID << " OpenMarketOrder");
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
				LOGI("--收到请求：CommandID=" << commandID << " Req_CloseMarketOrder");
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
				LOGI("--收到请求：CommandID=" << commandID << " Req_OpenLimitOrder");
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
				LOGI("--收到请求：CommandID=" << commandID << " Req_LimitClosePosition");
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
				LOGI("--收到请求：CommandID=" << commandID << " Req_LimitRevoke");
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
				LOGI("--收到请求：CommandID=" << commandID << " Req_CloseMarketOrderMany");
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
				LOGI("--收到请求：CommandID=" << commandID << " ReqQry_AccountInfo");
				pApi->ReqQryAccountInfo();
				break;
			case ReqQry_Commodity:
				LOGI("--收到请求：CommandID=" << commandID << " ReqQry_Commodity");
				pApi->ReqQryCommodity();
				break;
			case ReqQry_PositionOrder:
				LOGI("--收到请求：CommandID=" << commandID << " ReqQry_PositionOrder");
				pApi->ReqQryPositionOrder();
				break;
			case ReqQry_LimitOrder:
				LOGI("--收到请求：CommandID=" << commandID << " ReqQry_LimitOrder");
				pApi->ReqQryLimitOrder();
				break;
			case ReqQry_ClosePosition:
				LOGI("--收到请求：CommandID=" << commandID << " ReqQry_ClosePosition");
				pApi->ReqQryClosePosition();
				break;
			case ReqQry_HoldPositionTotal:
				LOGI("--收到请求：CommandID=" << commandID << " ReqQry_HoldPositionTotal");
				pApi->ReqQryHoldPositionTotal();
				break;
			case ReqQry_MarketStatus:
				LOGI("--收到请求：CommandID=" << commandID << " ReqQry_MarketStatus");
				pApi->ReqQryMarketStatus();
				break;
			case ReqQry_HoldPositionByID:
				LOGI("--收到请求：CommandID=" << commandID << " ReqQry_HoldPositionByID");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					long nHoldPositionID = jsonRoot["nHoldPositionID"].asUInt();
					pApi->ReqQryHoldPositionByID(nHoldPositionID);
				}
				break;
			case ReqQry_LimitOrderByID:
				LOGI("--收到请求：CommandID=" << commandID << " ReqQry_LimitOrderByID");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					long nLimitOrderID = jsonRoot["nLimitOrderID"].asUInt();
					pApi->ReqQryLimitOrderByID(nLimitOrderID);
				}
				break;
			case ReqQry_ClosePositionByID:
				LOGI("--收到请求：CommandID=" << commandID << " ReqQry_ClosePositionByID");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					long nClosePositionID = jsonRoot["nClosePositionID"].asUInt();
					pApi->ReqQryClosePositionByID(nClosePositionID);
				}
				break;
			case ReqQry_HoldPositionTotalByCommodityID:
				LOGI("--收到请求：CommandID=" << commandID << " ReqQry_HoldPositionTotalByCommodityID");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					long nCommodityID = jsonRoot["nCommodityID"].asInt();
					long nOpenDirector = jsonRoot["nOpenDirector"].asInt();
					pApi->ReqQryHoldPositionTotalByCommodityID(nCommodityID, nOpenDirector);
				}
				break;
			case ReqQry_CommodityQuote:
				LOGI("--收到请求：CommandID=" << commandID << " ReqQry_CommodityQuote");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					long nCommodityID = jsonRoot["nCommodityID"].asInt();
					pApi->ReqQryCommodityQuote(nCommodityID);
				}
				break;
			case ReqQry_OpenMarketOrderConf:
				LOGI("--收到请求：CommandID=" << commandID << " ReqQry_OpenMarketOrderConf");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					long nCommodityID = jsonRoot["nCommodityID"].asInt();
					pApi->ReqQryOpenMarketOrderConf(nCommodityID);
				}
				break;
			case ReqQry_OpenLimitOrderConf:
				LOGI("--收到请求：CommandID=" << commandID << " ReqQry_OpenLimitOrderConf");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					long nCommodityID = jsonRoot["nCommodityID"].asInt();
					pApi->ReqQryOpenLimitOrderConf(nCommodityID);
				}
				break;
			case ReqQry_CloseMarketOrderConf:
				LOGI("--收到请求：CommandID=" << commandID << " ReqQry_CloseMarketOrderConf");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					long nCommodityID = jsonRoot["nCommodityID"].asInt();
					pApi->ReqQryCloseMarketOrderConf(nCommodityID);
				}
				break;
			case ReqQry_LimitClosePositionConf:
				LOGI("--收到请求：CommandID=" << commandID << " ReqQry_LimitClosePositionConf");
				if (jsonReader.parse(jsonParams.asCString(), jsonRoot)){
					long nCommodityID = jsonRoot["nCommodityID"].asInt();
					pApi->ReqQryLimitClosePositionConf(nCommodityID);
				}
				break;
			case REQ_RELEASE:
				LOGI("--收到请求：CommandID=" << commandID << " Release");
				pApi->Release();
				STOP = true; // 退出数据处理线程
				break;
			default:
				LOGA("--未知请求: " << m_recvBuf);
				break;
			}
		}
		else{
			LOGE("--ERROR，无效请求：" << m_recvBuf);
			CXTradeMWConns::Instance()->InsertIntoBlackList(this->m_strIP);

			if (CXTradeMWConns::Instance()->InBlackList(this->m_strIP)){
				LOGW("--断开连接，拒绝服务 ");
				Close();
			}
		}
	}
	catch (std::exception &ex)
	{
		LOGE("--请求数据异常: " << ex.what());
	}

	//重置Buf
	memset(m_recvBuf, 0, sizeof(m_recvBuf));

	/////////////////////////////////////////
	CAsyncSocket::OnReceive(nErrorCode);
}

///
void CXMWSocket::OnSend(int nErrorCode)
{
	//LOGD("--2.5 OnSend");


	/////////////////////////////////////////
	CAsyncSocket::OnSend(nErrorCode);
}


///
/// CxTradeApi Funcs
///

/// CXTradeApi接收线程
int CXMWSocket::CXTradeApiRespThread(LPVOID pParam)
{
	CXMWSocket *pObj = (CXMWSocket *)pParam;
	pObj->SendBackTradeData();
	return 0;
}


/// CXTradeApi接收线程
void CXMWSocket::SendBackTradeData()
{
	while (true){
		try{
			// 安全退出
			if (STOP){
				break;
			}

			// 有数据才处理
			if (m_sendQue.size()>0 && m_sendQue.size()<1000){
				strcat_s(m_sendBuf, m_sendQue.front().c_str());
				//LOGD("--  取数据, size: " << m_sendQue.size() << " = " << m_sendQue.front());

				// 发送数据
				Send(m_sendBuf, strlen(m_sendBuf));

				// 删除数据
				m_lock.Lock();
				m_sendQue.pop_front();
				m_lock.Unlock();
				//LOGD("--  取后数据, size: " << m_sendQue.size());

				// 仅仅 LogLevel=DEBUG 的时候才显示内容
				if (CXTradeMWConfig::Instance()->LogLevel()<LOG_LEVEL_INFO){
					m_sendBuf[strlen(m_sendBuf) - 1] = '\0';
					LOGI("--发送数据: " << m_strIP << ":" << m_nPort << " - " << m_sendBuf);
				}

				//重置Buf
				memset(m_sendBuf, 0, sizeof(m_sendBuf));
			}
			else if (m_sendQue.size()>1000){
				m_sendQue.clear();
			}

			// 重新竞争上岗
			Sleep(0);
		}
		catch (std::exception &e){
			cout << e.what() << endl;
		}
	}
}

/// 存数据进队列, 需要锁机制
void CXMWSocket::Enque(string str){
	try{
		// 安全退出
		if (STOP){
			return;
		}

		//LOGD("--  收到数据, size: " << m_sendQue.size() << " = ");
		m_lock.Lock();
		m_sendQue.push_back(str);
		m_lock.Unlock();
		//LOGD("--存数据完毕.");
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}



/// CXTradeApi请求线程
int CXMWSocket::CXTradeApiReqThread(LPVOID pParam)
{
	CXMWSocket *pObj = (CXMWSocket *)pParam;
	pObj->Login();
	return 0;
}


/// CXTradeApi登陆
void CXMWSocket::Login()
{
	try{
		CXUtils::PrintCurrentDir();
		char dir[30] = {0};
		sprintf_s(dir, "./log/%d", COUNT++);

		CXUtils::CheckDir(dir);
		pApi = CTradeApi::CreateTradeApi(dir);
		pSpi = new CXTradeSpiImpl(pApi, this);
		pApi->RegisterSpi(pSpi);

		// Config
		CXTradeMWConfig* config = CXTradeMWConfig::Instance();
		pApi->RegisterFront(config->ServerIP(), config->ServerPort());
		pApi->SetAppMessage(config->AppCode(), config->VendorPassword(), config->VendorID());

		int res = pApi->Init();
		if (res)
		{
			LOGE("--CXTradeApi Init Failed, Result: " << res);
			LOGE("交易接口初始化失败!");
			return;
		}

		//用户名/密码
		//LOGI("--CXTradeApi| Login with " << username);
		char *u = m_username.GetBuffer(0);
		m_username.ReleaseBuffer();
		char *p = m_password.GetBuffer(0);
		m_password.ReleaseBuffer();

		LOGW("--CXTradeApi | Login as " << u);
		pApi->ReqUserLogin(u, p);

		pApi->Join();
		LOGI("--退出CX交易接口");
	}
	catch (std::exception &e){
		LOGE(e.what());
	}
	catch (...){
		LOGE("接口未知错误。");
	}
}
