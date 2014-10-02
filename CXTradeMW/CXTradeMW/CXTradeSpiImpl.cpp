#pragma once
#include <iostream>
#include "CXMWCommand.h"
#include "CXTradeSpiImpl.h"
#include "libs/jsoncpp/json.h"

using namespace std;
using namespace Json;


///���ͽ�����������ݵ��ͻ���
///@param������,json��ʽ
void CXTradeSpiImpl::SendBack(Json::Value &jsonRoot){
	//����Json�������ݽ�����
	FastWriter writer;
	std::string outData = writer.write(jsonRoot);
	m_mwSocket->Enque(outData);
}



///��¼��Ӧ����
///@param pLoginEvent���û���¼��Ϣ��
void CXTradeSpiImpl::OnRtnUserLogin(const CXProcessResult *result)
{
	try{
		Json::Value jsonResps;
		jsonResps["RetCode"] = result->RetCode;
		jsonResps["Message"] = result->Message;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRtnUserLogin;
		jsonRoot[RESPDESC] = "OnRtnUserLogin";
		jsonRoot[RESPJSONS] = jsonResps;

		//����Json�������ݽ�����
		SendBack(jsonRoot);

		printf("--[TE] Login Result! Ret:%d, Msg:%s\n", result->RetCode, result->Message);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}

///ʵʱ��������
///@param pQuoteEvent��������Ϣ��
void CXTradeSpiImpl::OnRtnQuote(const CXRealTimeQuote *quote)
{
	try{
		Json::Value jsonResps;
		jsonResps["CommodityID"] = quote->CommodityID;
		jsonResps["LowPrice"] = quote->LowPrice;
		jsonResps["BuyPrice"] = quote->BuyPrice;
		jsonResps["SellPrice"] = quote->SellPrice;
		jsonResps["HighPrice"] = quote->HighPrice;
		jsonResps["QuoteTime"] = quote->QuoteTime;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRtnQuote;
		jsonRoot[RESPDESC] = "OnRtnQuote";
		jsonRoot[RESPJSONS] = jsonResps;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}

///�м۵����ֻر���Ϣ����
///@param pOpenMarketOrder���м۵����ֻر���Ϣ��
void CXTradeSpiImpl::OnRtnOpenMarketOrder(long long HoldPositionID, const CXProcessResult *result)
{
	try{
		Json::Value jsonResps;
		jsonResps["RetCode"] = result->RetCode;
		jsonResps["Message"] = result->Message;
		jsonResps["HoldPositionID"] = HoldPositionID;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRtnOpenMarketOrder;
		jsonRoot[RESPDESC] = "OnRtnOpenMarketOrder";
		jsonRoot[RESPJSONS] = jsonResps;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}

///�м۵�ƽ�ֻر���Ϣ����
///@param pCloseMarketOrder���м۵�ƽ�ֻر���Ϣ��
void CXTradeSpiImpl::OnRtnCloseMarketOrder(long long HoldPositionID, const CXProcessResult *result)
{
	try{
		Json::Value jsonResps;
		jsonResps["RetCode"] = result->RetCode;
		jsonResps["Message"] = result->Message;
		jsonResps["HoldPositionID"] = HoldPositionID;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRtnCloseMarketOrder;
		jsonRoot[RESPDESC] = "OnRtnCloseMarketOrder";
		jsonRoot[RESPJSONS] = jsonResps;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}

///�޼۵����ֻر���Ϣ����
///@param pOpenLimitOrder���޼۵����ֻر���Ϣ��
void CXTradeSpiImpl::OnRtnOpenLimitOrder(long long LimitOrderID, const CXProcessResult *result)
{
	try{
		Json::Value jsonResps;
		jsonResps["RetCode"] = result->RetCode;
		jsonResps["Message"] = result->Message;
		jsonResps["LimitOrderID"] = LimitOrderID;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRtnOpenLimitOrder;
		jsonRoot[RESPDESC] = "OnRtnOpenLimitOrder";
		jsonRoot[RESPJSONS] = jsonResps;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}

///�޼۵�ƽ�ֻر���Ϣ����
///@param pOpenLimitOrder���޼۵�ƽ�ֻر���Ϣ��
void CXTradeSpiImpl::OnRtnLimitClosePosition(long long HoldPositionID, const CXProcessResult *result)
{
	try{
		Json::Value jsonResps;
		jsonResps["RetCode"] = result->RetCode;
		jsonResps["Message"] = result->Message;
		jsonResps["HoldPositionID"] = HoldPositionID;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRtnLimitClosePosition;
		jsonRoot[RESPDESC] = "OnRtnLimitClosePosition";
		jsonRoot[RESPJSONS] = jsonResps;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}

///�޼۵������ر���Ϣ����
///@param pRevokeLimitOrder���޼۵������ر���Ϣ��
void CXTradeSpiImpl::OnRtnRevokeLimitOrder(long long LimitOrderID, const CXProcessResult *result)
{
	try{
		Json::Value jsonResps;
		jsonResps["RetCode"] = result->RetCode;
		jsonResps["Message"] = result->Message;
		jsonResps["LimitOrderID"] = LimitOrderID;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRtnRevokeLimitOrder;
		jsonRoot[RESPDESC] = "OnRtnRevokeLimitOrder";
		jsonRoot[RESPJSONS] = jsonResps;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}


///ϵͳ֪ͨ��Ϣ����
///@param pSysBulletin��ϵͳ֪ͨ��Ϣ��
void CXTradeSpiImpl::OnRtnSysBulletin(const CXSysBulletinInfo *pSysBulletin)
{
	try{
		Json::Value jsonResps;
		jsonResps["LoginID"] = pSysBulletin->LoginID;
		jsonResps["BulletinID"] = pSysBulletin->BulletinID;
		jsonResps["TradeMode"] = pSysBulletin->TradeMode;
		jsonResps["BulletinType"] = pSysBulletin->BulletinType;
		jsonResps["BulletinPriorty"] = pSysBulletin->BulletinPriorty;
		jsonResps["BulletinMethod"] = pSysBulletin->BulletinMethod;
		jsonResps["BulletinHeader"] = pSysBulletin->BulletinHeader;
		jsonResps["BulletinContent"] = pSysBulletin->BulletinContent;
		jsonResps["PublisherName"] = pSysBulletin->PublisherName;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRtnSysBulletin;
		jsonRoot[RESPDESC] = "OnRtnSysBulletin";
		jsonRoot[RESPJSONS] = jsonResps;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}

///�û���¼�ر�
///@param pszLoginAccount���˻���
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspUserLogin(const char* pszLoginAccount, int errCode)
{
	try{
		Json::Value jsonResps;
		jsonResps["pszLoginAccount"] = pszLoginAccount;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspUserLogin;
		jsonRoot[RESPDESC] = "OnRspUserLogin";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}

///�м۵����ֻر�
///@param pOnRspOpenMarketOrderField���м۵����ֽṹ��
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspOpenMarketOrder(const CXOpenMarketOrderParam *pRspOpenMarketOrderField, int errCode)
{
	try{
		Json::Value jsonResps;
		jsonResps["nCommodityID"] = pRspOpenMarketOrderField->nCommodityID;
		jsonResps["nOpenDirector"] = pRspOpenMarketOrderField->nOpenDirector;
		jsonResps["dbPrice"] = pRspOpenMarketOrderField->dbPrice;
		jsonResps["nQuantity"] = pRspOpenMarketOrderField->nQuantity;
		jsonResps["dbTradeRange"] = pRspOpenMarketOrderField->dbTradeRange;
		jsonResps["nOrderType"] = pRspOpenMarketOrderField->nOrderType;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspOpenMarketOrder;
		jsonRoot[RESPDESC] = "OnRspOpenMarketOrder";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}


///�м۵�ƽ�ֻر�
///@param pOnRspCloseMarketOrderField���м۵�ƽ�ֽṹ��
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspCloseMarketOrder(const CXCloseMarketOrderParam *pOnRspCloseMarketOrderField, int errCode)
{
	try{
		Json::Value jsonResps;
		jsonResps["nHoldPositionID"] = pOnRspCloseMarketOrderField->nHoldPositionID;
		jsonResps["nCommodityID"] = pOnRspCloseMarketOrderField->nCommodityID;
		jsonResps["nQuantity"] = pOnRspCloseMarketOrderField->nQuantity;
		jsonResps["dbPrice"] = pOnRspCloseMarketOrderField->dbPrice;
		jsonResps["nTradeRange"] = pOnRspCloseMarketOrderField->nTradeRange;
		jsonResps["nClosePositionType"] = pOnRspCloseMarketOrderField->nClosePositionType;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspCloseMarketOrder;
		jsonRoot[RESPDESC] = "OnRspCloseMarketOrder";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}


///�޼۵����ֻر�
///@param pOnRspOpenLimitOrderField���޼۵����ֽṹ��
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspOpenLimitOrder(const CXOpenLimitOrderParam *pOnRspOpenLimitOrderField, int errCode)
{
	try{
		Json::Value jsonResps;
		jsonResps["nExpireType"] = pOnRspOpenLimitOrderField->nExpireType;
		jsonResps["nCommodityID"] = pOnRspOpenLimitOrderField->nCommodityID;
		jsonResps["nQuantity"] = pOnRspOpenLimitOrderField->nQuantity;
		jsonResps["nOpenDirector"] = pOnRspOpenLimitOrderField->nOpenDirector;
		jsonResps["nOrderType"] = pOnRspOpenLimitOrderField->nOrderType;
		jsonResps["dbOrderPrice"] = pOnRspOpenLimitOrderField->dbOrderPrice;
		jsonResps["dbTPPrice"] = pOnRspOpenLimitOrderField->dbTPPrice;
		jsonResps["dbSLPrice"] = pOnRspOpenLimitOrderField->dbSLPrice;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspOpenLimitOrder;
		jsonRoot[RESPDESC] = "OnRspOpenLimitOrder";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}


///�޼۵�ƽ�ֻر�
///@param pOnRspCloseLimitOrderField���޼۵�ƽ�ֽṹ��
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspLimitClosePosition(const CXCloseLimitOrderParam *pOnRspCloseLimitOrderField, int errCode)
{
	try{
		Json::Value jsonResps;
		jsonResps["nExpireType"] = pOnRspCloseLimitOrderField->nExpireType;
		jsonResps["nCommodityID"] = pOnRspCloseLimitOrderField->nCommodityID;
		jsonResps["dbClosePrice"] = pOnRspCloseLimitOrderField->dbClosePrice;
		jsonResps["nHoldPositionID"] = pOnRspCloseLimitOrderField->nHoldPositionID;
		jsonResps["nOrderType"] = pOnRspCloseLimitOrderField->nOrderType;
		jsonResps["nQuantity"] = pOnRspCloseLimitOrderField->nQuantity;
		jsonResps["dbTPPrice"] = pOnRspCloseLimitOrderField->dbTPPrice;
		jsonResps["dbSLPrice"] = pOnRspCloseLimitOrderField->dbSLPrice;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspLimitClosePosition;
		jsonRoot[RESPDESC] = "OnRspLimitClosePosition";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}

///�����ر�
///@param pOnRspLimitRevokeField�������ṹ��
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspLimitRevoke(const CXLimitRevokeParam *pOnRspLimitRevokeField, int errCode)
{
	try{
		Json::Value jsonResps;
		jsonResps["nLimitOrderID"] = pOnRspLimitRevokeField->nLimitOrderID;
		jsonResps["nCommodityID"] = pOnRspLimitRevokeField->nCommodityID;
		jsonResps["nOrderType"] = pOnRspLimitRevokeField->nOrderType;
		jsonResps["nLimitType"] = pOnRspLimitRevokeField->nLimitType;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspLimitRevoke;
		jsonRoot[RESPDESC] = "OnRspLimitRevoke";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}


///�м۵�����ƽ�ֻر�
///@param pOnRspCloseMarketOrderManyField���м۵�����ƽ�ֽṹ��
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspCloseMarketOrderMany(const CXCloseMarketOrderManyParam *pOnRspCloseMarketOrderManyField, int errCode)
{
	try{
		Json::Value jsonResps;
		jsonResps["nQuantity"] = pOnRspCloseMarketOrderManyField->nQuantity;
		jsonResps["nCommodityID"] = pOnRspCloseMarketOrderManyField->nCommodityID;
		jsonResps["nTradeRange"] = pOnRspCloseMarketOrderManyField->nTradeRange;
		jsonResps["dbPrice"] = pOnRspCloseMarketOrderManyField->dbPrice;
		jsonResps["nClosePositionType"] = pOnRspCloseMarketOrderManyField->nClosePositionType;
		jsonResps["nCloseDirector"] = pOnRspCloseMarketOrderManyField->nCloseDirector;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspCloseMarketOrderMany;
		jsonRoot[RESPDESC] = "OnRspCloseMarketOrderMany";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}


///��ѯ�˻���Ϣ�ر�
///@param account���˻���Ϣ��
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspQryAccountInfo(const CXAccountInfo *pAccount, int errCode)
{
	try{
		Json::Value jsonResps;
		jsonResps["Account"] = pAccount->Account;
		jsonResps["LoginAccount"] = pAccount->LoginAccount;
		jsonResps["CustomerName"] = pAccount->CustomerName;
		jsonResps["NAVPrice"] = pAccount->NAVPrice;
		jsonResps["Amount"] = pAccount->Amount;
		jsonResps["OpenProfit"] = pAccount->OpenProfit;
		jsonResps["ExchangeReserve"] = pAccount->ExchangeReserve;
		jsonResps["PerformanceReserve"] = pAccount->PerformanceReserve;
		jsonResps["FrozenReserve"] = pAccount->FrozenReserve;
		jsonResps["RiskRate"] = pAccount->RiskRate;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryAccountInfo;
		jsonRoot[RESPDESC] = "OnRspQryAccountInfo";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}


///��ѯ��Ʒ��Ϣ�ر�
///@param vCommodity����Ʒ��Ϣ��
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspQryCommodity(std::vector<CXCommodityInfo> &vCommodity, int errCode)
{
	try{
		Json::Value jsonResps;
		std::vector<CXCommodityInfo>::iterator it;
		for (it = vCommodity.begin(); it != vCommodity.end(); it++)
		{
			Json::Value jsonItem;
			jsonItem["CommodityID"] = it->CommodityID;
			jsonItem["CommodityName"] = it->CommodityName;
			jsonItem["CommodityRight"] = it->CommodityRight;
			jsonItem["TradeRight"] = it->TradeRight;
			jsonItem["AgreeUnit"] = it->AgreeUnit;
			jsonItem["Currency"] = it->Currency;
			jsonItem["MinQuoteChangeUnit"] = it->MinQuoteChangeUnit;
			jsonItem["MinPriceUnit"] = it->MinPriceUnit;
			jsonItem["FixedSpread"] = it->FixedSpread;
			jsonItem["BuyPrice"] = it->BuyPrice;
			jsonItem["SellPrice"] = it->SellPrice;
			jsonItem["HighPrice"] = it->HighPrice;
			jsonItem["LowPrice"] = it->LowPrice;
			jsonItem["QuoteTime"] = it->QuoteTime;

			jsonResps.append(jsonItem);
		}

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryCommodity;
		jsonRoot[RESPDESC] = "OnRspQryCommodity";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}


///��ѯ�ֲֵ���Ϣ�ر�
///@param vHoldPosition���ֲֵ���Ϣ��
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspQryPositionOrder(std::vector<CXHoldPositionInfo>& vHoldPosition, int errCode)
{
	try{
		Json::Value jsonResps;
		std::vector<CXHoldPositionInfo>::iterator it;
		for (it = vHoldPosition.begin(); it != vHoldPosition.end(); it++)
		{
			Json::Value jsonItem;
			jsonItem["CommodityID"] = it->CommodityID;
			jsonItem["CommodityName"] = it->CommodityName;
			jsonItem["HoldPositionID"] = it->HoldPositionID;
			jsonItem["OpenType"] = it->OpenType;
			jsonItem["OpenDirector"] = it->OpenDirector;
			jsonItem["Quantity"] = it->Quantity;
			jsonItem["OpenPrice"] = it->OpenPrice;
			jsonItem["SLLimitOrderID"] = it->SLLimitOrderID;
			jsonItem["TPLimitOrderID"] = it->TPLimitOrderID;
			jsonItem["SLPrice"] = it->SLPrice;
			jsonItem["TPPrice"] = it->TPPrice;
			jsonItem["HoldPositionPrice"] = it->HoldPositionPrice;
			jsonItem["ClosePrice"] = it->ClosePrice;
			jsonItem["OpenProfit"] = it->OpenProfit;
			jsonItem["CommissionAmount"] = it->CommissionAmount;
			jsonItem["OpenDate"] = it->OpenDate;
			jsonItem["AgreeMargin"] = it->AgreeMargin;
			jsonItem["Freezemargin"] = it->Freezemargin;
			jsonItem["OverdueFindFund"] = it->OverdueFindFund;

			jsonResps.append(jsonItem);
		}

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryPositionOrder;
		jsonRoot[RESPDESC] = "OnRspQryPositionOrder";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}



///��ѯ�޼۵���Ϣ�ر�
///@param vLimitOrder���޼۵���Ϣ��
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspQryLimitOrder(std::vector<CXLimitOrderInfo>& vLimitOrder, int errCode)
{
	try{
		Json::Value jsonResps;
		std::vector<CXLimitOrderInfo>::iterator it;
		for (it = vLimitOrder.begin(); it != vLimitOrder.end(); it++)
		{
			Json::Value jsonItem;
			jsonItem["CommodityID"] = it->CommodityID;
			jsonItem["CommodityName"] = it->CommodityName;
			jsonItem["LimitOrderID"] = it->LimitOrderID;
			jsonItem["LimitType"] = it->LimitType;
			jsonItem["OrderType"] = it->OrderType;
			jsonItem["OpenDirector"] = it->OpenDirector;
			jsonItem["OrderPrice"] = it->OrderPrice;
			jsonItem["SLPrice"] = it->SLPrice;
			jsonItem["TPPrice"] = it->TPPrice;
			jsonItem["OpenQuantity"] = it->OpenQuantity;
			jsonItem["CreateDate"] = it->CreateDate;
			jsonItem["ExpireType"] = it->ExpireType;
			jsonItem["UpdateDate"] = it->UpdateDate;
			jsonItem["FreeszMargin"] = it->FreeszMargin;

			jsonResps.append(jsonItem);
		}

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryLimitOrder;
		jsonRoot[RESPDESC] = "OnRspQryLimitOrder";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}

///��ѯƽ����Ϣ�ر�
///@param vClosePosition��ƽ����Ϣ��
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspQryClosePosition(std::vector<CXClosePositionInfo>& vClosePosition, int errCode)
{
	try{
		Json::Value jsonResps;
		std::vector<CXClosePositionInfo>::iterator it;
		for (it = vClosePosition.begin(); it != vClosePosition.end(); it++)
		{
			Json::Value jsonItem;
			jsonItem["CommodityID"] = it->CommodityID;
			jsonItem["CommodityName"] = it->CommodityName;
			jsonItem["ClosePositionID"] = it->ClosePositionID;
			jsonItem["Quantity"] = it->Quantity;
			jsonItem["CloseDirector"] = it->CloseDirector;
			jsonItem["OpenPrice"] = it->OpenPrice;
			jsonItem["HoldPrice"] = it->HoldPrice;
			jsonItem["ClosePrice"] = it->ClosePrice;
			jsonItem["OpenPositionID"] = it->OpenPositionID;
			jsonItem["CommissionAmount"] = it->CommissionAmount;
			jsonItem["OpenDate"] = it->OpenDate;
			jsonItem["CloseDate"] = it->CloseDate;
			jsonItem["MemberID"] = it->MemberID;
			jsonItem["CloseType"] = it->CloseType;
			jsonItem["OpenType"] = it->OpenType;

			jsonResps.append(jsonItem);
		}

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryClosePosition;
		jsonRoot[RESPDESC] = "OnRspQryClosePosition";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}


///��ѯ�ֲֵ������ر�
///@param vTotal���ֲֵ�������
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspQryHoldPositionTotal(std::vector<CXHoldPositionTotalInfo>& vTotal, int errCode)
{
	try{
		Json::Value jsonResps;
		std::vector<CXHoldPositionTotalInfo>::iterator it;
		for (it = vTotal.begin(); it != vTotal.end(); it++)
		{
			Json::Value jsonItem;
			jsonItem["CommodityID"] = it->CommodityID;
			jsonItem["CommodityName"] = it->CommodityName;
			jsonItem["OpenDirector"] = it->OpenDirector;
			jsonItem["Quantity"] = it->Quantity;
			jsonItem["OpenPriceTotal"] = it->OpenPriceTotal;
			jsonItem["AvgOpenPrice"] = it->AvgOpenPrice;
			jsonItem["HoldPriceTotal"] = it->HoldPriceTotal;
			jsonItem["AvgHoldPrice"] = it->AvgHoldPrice;
			jsonItem["ClosePrice"] = it->ClosePrice;
			jsonItem["OpenProfit"] = it->OpenProfit;

			jsonResps.append(jsonItem);
		}

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryHoldPositionTotal;
		jsonRoot[RESPDESC] = "OnRspQryHoldPositionTotal";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}

///��ѯ�г�������״̬�ر�
///@param nMarketStatus���г�������״̬�� MARKET_STATUS_OPEN��0 MARKET_STATUS_CLOSE��1
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspQryMarketStatus(int nMarketStatus, int errCode)
{
	if (CX_MARKET_STATUS_OPEN == nMarketStatus){
		m_pTradeApi->ReqQryCommodity();
	}

	try{
		Json::Value jsonResps;
		jsonResps["MarketStatus"] = nMarketStatus;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryMarketStatus;
		jsonRoot[RESPDESC] = "OnRspQryMarketStatus";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}

///���ݳֲֵ�ID����ȡ�ֲֵ���Ϣ�ر�
///@param pHoldPosition���ֲֵ���Ϣ��
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspQryHoldPositionByID(const CXHoldPositionInfo* pHoldPosition, int errCode)
{
	try{
		Json::Value jsonResps;
		jsonResps["CommodityID"] = pHoldPosition->CommodityID;
		jsonResps["CommodityName"] = pHoldPosition->CommodityName;
		jsonResps["HoldPositionID"] = pHoldPosition->HoldPositionID;
		jsonResps["OpenType"] = pHoldPosition->OpenType;
		jsonResps["OpenDirector"] = pHoldPosition->OpenDirector;
		jsonResps["OpenDirector"] = pHoldPosition->OpenDirector;
		jsonResps["OpenPrice"] = pHoldPosition->OpenPrice;
		jsonResps["SLLimitOrderID"] = pHoldPosition->SLLimitOrderID;
		jsonResps["SLPrice"] = pHoldPosition->SLPrice;
		jsonResps["TPLimitOrderID"] = pHoldPosition->TPLimitOrderID;
		jsonResps["TPPrice"] = pHoldPosition->TPPrice;
		jsonResps["Quantity"] = pHoldPosition->Quantity;
		jsonResps["HoldPositionPrice"] = pHoldPosition->HoldPositionPrice;
		jsonResps["ClosePrice"] = pHoldPosition->ClosePrice;
		jsonResps["OpenProfit"] = pHoldPosition->OpenProfit;
		jsonResps["CommissionAmount"] = pHoldPosition->CommissionAmount;
		jsonResps["OpenDate"] = pHoldPosition->OpenDate;
		jsonResps["AgreeMargin"] = pHoldPosition->AgreeMargin;
		jsonResps["Freezemargin"] = pHoldPosition->Freezemargin;
		jsonResps["OverdueFindFund"] = pHoldPosition->OverdueFindFund;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryHoldPositionByID;
		jsonRoot[RESPDESC] = "OnRspQryHoldPositionByID";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}

///�����޼۵�ID����ȡ�޼۵���Ϣ�ر�
///@param pLimitOrder���޼۵���Ϣ��
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspQryLimitOrderByID(const CXLimitOrderInfo* pLimitOrder, int errCode)
{
	try{
		Json::Value jsonResps;
		jsonResps["CommodityID"] = pLimitOrder->CommodityID;
		jsonResps["CommodityName"] = pLimitOrder->CommodityName;
		jsonResps["LimitOrderID"] = pLimitOrder->LimitOrderID;
		jsonResps["LimitType"] = pLimitOrder->LimitType;
		jsonResps["OrderType"] = pLimitOrder->OrderType;
		jsonResps["OpenDirector"] = pLimitOrder->OpenDirector;
		jsonResps["OrderPrice"] = pLimitOrder->OrderPrice;
		jsonResps["SLPrice"] = pLimitOrder->SLPrice;
		jsonResps["TPPrice"] = pLimitOrder->TPPrice;
		jsonResps["OpenQuantity"] = pLimitOrder->OpenQuantity;
		jsonResps["CreateDate"] = pLimitOrder->CreateDate;
		jsonResps["ExpireType"] = pLimitOrder->ExpireType;
		jsonResps["UpdateDate"] = pLimitOrder->UpdateDate;
		jsonResps["FreeszMargin"] = pLimitOrder->FreeszMargin;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryLimitOrderByID;
		jsonRoot[RESPDESC] = "OnRspQryLimitOrderByID";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}


///����ƽ�ֵ�ID����ȡƽ����Ϣ�ر�
///@param pClosePosition��ƽ����Ϣ��
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspQryClosePositionByID(const CXClosePositionInfo* pClosePosition, int errCode)
{
	try{
		Json::Value jsonResps;
		jsonResps["CommodityID"] = pClosePosition->CommodityID;
		jsonResps["CommodityName"] = pClosePosition->CommodityName;
		jsonResps["ClosePositionID"] = pClosePosition->ClosePositionID;
		jsonResps["CloseDirector"] = pClosePosition->CloseDirector;
		jsonResps["OpenPrice"] = pClosePosition->OpenPrice;
		jsonResps["HoldPrice"] = pClosePosition->HoldPrice;
		jsonResps["ClosePrice"] = pClosePosition->ClosePrice;
		jsonResps["Quantity"] = pClosePosition->Quantity;
		jsonResps["OpenPositionID"] = pClosePosition->OpenPositionID;
		jsonResps["CommissionAmount"] = pClosePosition->CommissionAmount;
		jsonResps["OpenDate"] = pClosePosition->OpenDate;
		jsonResps["CloseDate"] = pClosePosition->CloseDate;
		jsonResps["MemberID"] = pClosePosition->MemberID;
		jsonResps["OpenType"] = pClosePosition->OpenType;
		jsonResps["CloseType"] = pClosePosition->CloseType;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryClosePositionByID;
		jsonRoot[RESPDESC] = "OnRspQryClosePositionByID";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}

///������ƷID����ȡ�ֲֻ�����Ϣ�ر�
///@param pTotal���ֲֻ�����Ϣ��
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspQryHoldPositionTotalByCommodityID(const CXHoldPositionTotalInfo* pTotal, int errCode)
{
	try{
		Json::Value jsonResps;
		jsonResps["CommodityID"] = pTotal->CommodityID;
		jsonResps["CommodityName"] = pTotal->CommodityName;
		jsonResps["OpenDirector"] = pTotal->OpenDirector;
		jsonResps["Quantity"] = pTotal->Quantity;
		jsonResps["OpenPriceTotal"] = pTotal->OpenPriceTotal;
		jsonResps["AvgOpenPrice"] = pTotal->AvgOpenPrice;
		jsonResps["HoldPriceTotal"] = pTotal->HoldPriceTotal;
		jsonResps["AvgHoldPrice"] = pTotal->AvgHoldPrice;
		jsonResps["ClosePrice"] = pTotal->ClosePrice;
		jsonResps["OpenProfit"] = pTotal->OpenProfit;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryHoldPositionTotalByCommodityID;
		jsonRoot[RESPDESC] = "OnRspQryHoldPositionTotalByCommodityID";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}


///������ƷID����ȡʵʱ����ر�
///@param quote��ʵʱ���顣
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspQryCommodityQuote(const CXRealTimeQuote* quote, int errCode)
{
	try{
		Json::Value jsonResps;
		jsonResps["CommodityID"] = quote->CommodityID;
		jsonResps["SellPrice"] = quote->SellPrice;
		jsonResps["BuyPrice"] = quote->BuyPrice;
		jsonResps["HighPrice"] = quote->HighPrice;
		jsonResps["LowPrice"] = quote->LowPrice;
		jsonResps["QuoteTime"] = quote->QuoteTime;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryCommodityQuote;
		jsonRoot[RESPDESC] = "OnRspQryCommodityQuote";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}


///������ƷID����ȡ���м۽��ֵ�������Ϣ�ر�
///@param pConf���м۽��ֵ�������Ϣ��
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspQryOpenMarketOrderConf(const CXOpenMarketOrderConf* pConf, int errCode)
{
	try{
		Json::Value jsonResps;
		jsonResps["CommodityID"] = pConf->CommodityID;
		jsonResps["MinQuantity"] = pConf->MinQuantity;
		jsonResps["MaxQuantity"] = pConf->MaxQuantity;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryOpenMarketOrderConf;
		jsonRoot[RESPDESC] = "OnRspQryOpenMarketOrderConf";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}

///������ƷID����ȡ���޼۽��ֵ�������Ϣ�ر�
///@param pConf���޼۽��ֵ�������Ϣ��
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspQryOpenLimitOrderConf(const CXOpenLimitOrderConf* pConf, int errCode)
{
	try{
		Json::Value jsonResps;
		jsonResps["CommodityID"] = pConf->CommodityID;
		jsonResps["MinQuantity"] = pConf->MinQuantity;
		jsonResps["MaxQuantity"] = pConf->MaxQuantity;
		jsonResps["LimitSpread"] = pConf->LimitSpread;
		jsonResps["FixSpread"] = pConf->FixSpread;
		jsonResps["TPSpread"] = pConf->TPSpread;
		jsonResps["SLSpread"] = pConf->SLSpread;
		jsonResps["MinPriceUnit"] = pConf->MinPriceUnit;
		jsonResps["AgreeUnit"] = pConf->AgreeUnit;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryOpenLimitOrderConf;
		jsonRoot[RESPDESC] = "OnRspQryOpenLimitOrderConf";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}


///������ƷID����ȡ���м�ƽ�ֵ�������Ϣ�ر�
///@param pConf���м�ƽ�ֵ�������Ϣ��
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspQryCloseMarketOrderConf(const CXCloseMarketOrderConf* pConf, int errCode)
{
	try{
		Json::Value jsonResps;
		jsonResps["CommodityID"] = pConf->CommodityID;
		jsonResps["MinQuantity"] = pConf->MinQuantity;
		jsonResps["MaxQuantity"] = pConf->MaxQuantity;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryCloseMarketOrderConf;
		jsonRoot[RESPDESC] = "OnRspQryCloseMarketOrderConf";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}

///������ƷID����ȡ�޼�ƽ�ֵ�������Ϣ�ر�
///@param pConf���޼�ƽ�ֵ�������Ϣ��
///@param errCode��������Ϣ��
void CXTradeSpiImpl::OnRspQryLimitClosePositionConf(const CXLimitClosePositionConf* pConf, int errCode)
{
	try{
		Json::Value jsonResps;
		jsonResps["CommodityID"] = pConf->CommodityID;
		jsonResps["FixedSpread"] = pConf->FixedSpread;
		jsonResps["TPSpread"] = pConf->TPSpread;
		jsonResps["SLSpread"] = pConf->SLSpread;
		jsonResps["MinPriceUnit"] = pConf->MinPriceUnit;
		jsonResps["AgreeUnit"] = pConf->AgreeUnit;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryLimitClosePositionConf;
		jsonRoot[RESPDESC] = "OnRspQryLimitClosePositionConf";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;

		//����Json�������ݽ�����
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		printf("--�����������쳣: %s\n", ex.what());
	}
}