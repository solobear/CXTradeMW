#pragma once
#include <iostream>
#include "CXTradeMWCommand.h"
#include "CXTradeSpiImpl.h"
#include "libs/jsoncpp/json.h"
#include "log4z.h"

using namespace zsummer::log4z;
using namespace std;
using namespace Json;


///发送交易行情和数据到客户端
///@param：数据,json格式
void CXTradeSpiImpl::SendBack(Json::Value &jsonRoot){
	//生成Json并送数据进队列
	FastWriter writer;
	std::string outData = writer.write(jsonRoot);
	m_mwSocket->Enque(outData);
}



///登录响应推送
///@param pLoginEvent：用户登录信息。
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
		jsonRoot[RESPISLAST] = true;

		//生成Json并送数据进队列
		SendBack(jsonRoot);

		LOGI("--[TE] Login Result! Msg:" << result->Message << " , Ret:" << result->RetCode);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}

///实时行情推送
///@param pQuoteEvent：行情信息。
void CXTradeSpiImpl::OnRtnQuote(const CXRealTimeQuote *quote)
{
	if (m_bObMD)
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
			jsonRoot[RESPISLAST] = true;

			//TODO 生成Json并送数据进队列
			//SendBack(jsonRoot);
		}
		catch (std::exception &ex)
		{
			LOGE("--交易所数据异常: " << ex.what());
		}
	}
}

///市价单开仓回报信息推送
///@param pOpenMarketOrder：市价单开仓回报信息。
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
		jsonRoot[RESPISLAST] = true;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}

///市价单平仓回报信息推送
///@param pCloseMarketOrder：市价单平仓回报信息。
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
		jsonRoot[RESPISLAST] = true;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}

///限价单开仓回报信息推送
///@param pOpenLimitOrder：限价单开仓回报信息。
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
		jsonRoot[RESPISLAST] = true;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}

///限价单平仓回报信息推送
///@param pOpenLimitOrder：限价单平仓回报信息。
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
		jsonRoot[RESPISLAST] = true;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}

///限价单撤单回报信息推送
///@param pRevokeLimitOrder：限价单撤单回报信息。
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
		jsonRoot[RESPISLAST] = true;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}


///系统通知信息推送
///@param pSysBulletin：系统通知信息。
void CXTradeSpiImpl::OnRtnSysBulletin(const CXSysBulletinInfo *pSysBulletin)
{
	try{
		if (pSysBulletin == NULL)
		{
			LOGE("--接收异常，OnRtnSysBulletin return null!");
			return;
		}

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
		jsonRoot[RESPISLAST] = true;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}

///用户登录回报
///@param pszLoginAccount：账户。
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspUserLogin(const char* pszLoginAccount, int errCode, bool isLast)
{
	try{
		Json::Value jsonResps;
		jsonResps["pszLoginAccount"] = pszLoginAccount;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspUserLogin;
		jsonRoot[RESPDESC] = "OnRspUserLogin";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}

///市价单开仓回报
///@param pOnRspOpenMarketOrderField：市价单开仓结构。
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspOpenMarketOrder(const CXOpenMarketOrderParam *pRspOpenMarketOrderField, int errCode, bool isLast)
{
	try{
		if (pRspOpenMarketOrderField == NULL)
		{
			LOGE("--接收异常，OnRspOpenMarketOrder return null! ret: " << errCode);
			return;
		}

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
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}


///市价单平仓回报
///@param pOnRspCloseMarketOrderField：市价单平仓结构。
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspCloseMarketOrder(const CXCloseMarketOrderParam *pOnRspCloseMarketOrderField, int errCode, bool isLast)
{
	try{
		if (pOnRspCloseMarketOrderField == NULL)
		{
			LOGE("--接收异常，OnRspCloseMarketOrder return null! ret: " << errCode);
			return;
		}

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
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}


///限价单开仓回报
///@param pOnRspOpenLimitOrderField：限价单开仓结构。
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspOpenLimitOrder(const CXOpenLimitOrderParam *pOnRspOpenLimitOrderField, int errCode, bool isLast)
{
	try{
		if (pOnRspOpenLimitOrderField == NULL)
		{
			LOGE("--接收异常，OnRspOpenLimitOrder return null! ret: " << errCode);
			return;
		}

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
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}


///限价单平仓回报
///@param pOnRspCloseLimitOrderField：限价单平仓结构。
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspLimitClosePosition(const CXCloseLimitOrderParam *pOnRspCloseLimitOrderField, int errCode, bool isLast)
{
	try{
		if (pOnRspCloseLimitOrderField == NULL)
		{
			LOGE("--接收异常，OnRspLimitClosePosition return null! ret: " << errCode);
			return;
		}

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
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}

///撤单回报
///@param pOnRspLimitRevokeField：撤单结构。
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspLimitRevoke(const CXLimitRevokeParam *pOnRspLimitRevokeField, int errCode, bool isLast)
{
	try{
		if (pOnRspLimitRevokeField == NULL)
		{
			LOGE("--接收异常，OnRspLimitRevoke return null! ret: " << errCode);
			return;
		}

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
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}


///市价单批量平仓回报
///@param pOnRspCloseMarketOrderManyField：市价单批量平仓结构。
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspCloseMarketOrderMany(const CXCloseMarketOrderManyParam *pOnRspCloseMarketOrderManyField, int errCode, bool isLast)
{
	try{
		if (pOnRspCloseMarketOrderManyField == NULL)
		{
			LOGE("--接收异常，OnRspCloseMarketOrderMany return null! ret: " << errCode);
			return;
		}

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
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}


///查询账户信息回报
///@param account：账户信息。
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspQryAccountInfo(const CXAccountInfo *pAccount, int errCode, bool isLast)
{
	try{
		if (pAccount == NULL)
		{
			LOGE("--接收异常，OnRspQryAccountInfo return null! ret: " << errCode);
			return;
		}

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
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}


///查询商品信息回报
///@param vCommodity：商品信息。
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspQryCommodity(const CXCommodityInfo* vCommodity, int errCode, bool isLast)
{
	try{
		if (vCommodity == NULL)
		{
			LOGE("--接收异常，OnRspQryCommodity return null! ret: " << errCode);
			return;
		}

		Json::Value jsonResps;
		jsonResps["CommodityID"] = vCommodity->CommodityID;
		jsonResps["CommodityName"] = vCommodity->CommodityName;
		jsonResps["CommodityRight"] = vCommodity->CommodityRight;
		jsonResps["TradeRight"] = vCommodity->TradeRight;
		jsonResps["AgreeUnit"] = vCommodity->AgreeUnit;
		jsonResps["Currency"] = vCommodity->Currency;
		jsonResps["MinQuoteChangeUnit"] = vCommodity->MinQuoteChangeUnit;
		jsonResps["MinPriceUnit"] = vCommodity->MinPriceUnit;
		jsonResps["FixedSpread"] = vCommodity->FixedSpread;
		jsonResps["BuyPrice"] = vCommodity->BuyPrice;
		jsonResps["SellPrice"] = vCommodity->SellPrice;
		jsonResps["HighPrice"] = vCommodity->HighPrice;
		jsonResps["LowPrice"] = vCommodity->LowPrice;
		jsonResps["QuoteTime"] = vCommodity->QuoteTime;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryCommodity;
		jsonRoot[RESPDESC] = "OnRspQryCommodity";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}


///查询持仓单信息回报
///@param vHoldPosition：持仓单信息。
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspQryPositionOrder(const CXHoldPositionInfo* vHoldPosition, int errCode, bool isLast)
{
	try{
		if (vHoldPosition == NULL)
		{
			LOGE("--接收异常，OnRspQryPositionOrder return null! ret: " << errCode);
			return;
		}

		Json::Value jsonResps;
		jsonResps["CommodityID"] = vHoldPosition->CommodityID;
		jsonResps["CommodityName"] = vHoldPosition->CommodityName;
		jsonResps["HoldPositionID"] = vHoldPosition->HoldPositionID;
		jsonResps["OpenType"] = vHoldPosition->OpenType;
		jsonResps["OpenDirector"] = vHoldPosition->OpenDirector;
		jsonResps["Quantity"] = vHoldPosition->Quantity;
		jsonResps["OpenPrice"] = vHoldPosition->OpenPrice;
		jsonResps["SLLimitOrderID"] = vHoldPosition->SLLimitOrderID;
		jsonResps["TPLimitOrderID"] = vHoldPosition->TPLimitOrderID;
		jsonResps["SLPrice"] = vHoldPosition->SLPrice;
		jsonResps["TPPrice"] = vHoldPosition->TPPrice;
		jsonResps["HoldPositionPrice"] = vHoldPosition->HoldPositionPrice;
		jsonResps["ClosePrice"] = vHoldPosition->ClosePrice;
		jsonResps["OpenProfit"] = vHoldPosition->OpenProfit;
		jsonResps["CommissionAmount"] = vHoldPosition->CommissionAmount;
		jsonResps["OpenDate"] = vHoldPosition->OpenDate;
		jsonResps["AgreeMargin"] = vHoldPosition->AgreeMargin;
		jsonResps["Freezemargin"] = vHoldPosition->Freezemargin;
		jsonResps["OverdueFindFund"] = vHoldPosition->OverdueFindFund;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryPositionOrder;
		jsonRoot[RESPDESC] = "OnRspQryPositionOrder";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}



///查询限价单信息回报
///@param vLimitOrder：限价单信息。
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspQryLimitOrder(const CXLimitOrderInfo* vLimitOrder, int errCode, bool isLast)
{
	try{
		if (vLimitOrder == NULL)
		{
			LOGE("--接收异常，OnRspQryLimitOrder return null! ret: " << errCode);
			return;
		}

		Json::Value jsonResps;
		jsonResps["CommodityID"] = vLimitOrder->CommodityID;
		jsonResps["CommodityName"] = vLimitOrder->CommodityName;
		jsonResps["LimitOrderID"] = vLimitOrder->LimitOrderID;
		jsonResps["LimitType"] = vLimitOrder->LimitType;
		jsonResps["OrderType"] = vLimitOrder->OrderType;
		jsonResps["OpenDirector"] = vLimitOrder->OpenDirector;
		jsonResps["OrderPrice"] = vLimitOrder->OrderPrice;
		jsonResps["SLPrice"] = vLimitOrder->SLPrice;
		jsonResps["TPPrice"] = vLimitOrder->TPPrice;
		jsonResps["OpenQuantity"] = vLimitOrder->OpenQuantity;
		jsonResps["CreateDate"] = vLimitOrder->CreateDate;
		jsonResps["ExpireType"] = vLimitOrder->ExpireType;
		jsonResps["UpdateDate"] = vLimitOrder->UpdateDate;
		jsonResps["FreeszMargin"] = vLimitOrder->FreeszMargin;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryLimitOrder;
		jsonRoot[RESPDESC] = "OnRspQryLimitOrder";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}

///查询平仓信息回报
///@param vClosePosition：平仓信息。
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspQryClosePosition(const CXClosePositionInfo* vClosePosition, int errCode, bool isLast)
{
	try{
		if (vClosePosition == NULL)
		{
			LOGE("--接收异常，OnRspQryClosePosition return null! ret: " << errCode);
			return;
		}

		Json::Value jsonResps;
		jsonResps["CommodityID"] = vClosePosition->CommodityID;
		jsonResps["CommodityName"] = vClosePosition->CommodityName;
		jsonResps["ClosePositionID"] = vClosePosition->ClosePositionID;
		jsonResps["Quantity"] = vClosePosition->Quantity;
		jsonResps["CloseDirector"] = vClosePosition->CloseDirector;
		jsonResps["OpenPrice"] = vClosePosition->OpenPrice;
		jsonResps["HoldPrice"] = vClosePosition->HoldPrice;
		jsonResps["ClosePrice"] = vClosePosition->ClosePrice;
		jsonResps["OpenPositionID"] = vClosePosition->OpenPositionID;
		jsonResps["CommissionAmount"] = vClosePosition->CommissionAmount;
		jsonResps["OpenDate"] = vClosePosition->OpenDate;
		jsonResps["CloseDate"] = vClosePosition->CloseDate;
		jsonResps["MemberID"] = vClosePosition->MemberID;
		jsonResps["CloseType"] = vClosePosition->CloseType;
		jsonResps["OpenType"] = vClosePosition->OpenType;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryClosePosition;
		jsonRoot[RESPDESC] = "OnRspQryClosePosition";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}


///查询持仓单总量回报
///@param vTotal：持仓单总量。
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspQryHoldPositionTotal(const CXHoldPositionTotalInfo* vTotal, int errCode, bool isLast)
{
	try{
		if (vTotal == NULL)
		{
			LOGE("--接收异常，OnRspQryHoldPositionTotal return null! ret: " << errCode);
			return;
		}

		Json::Value jsonResps;
		jsonResps["CommodityID"] = vTotal->CommodityID;
		jsonResps["CommodityName"] = vTotal->CommodityName;
		jsonResps["OpenDirector"] = vTotal->OpenDirector;
		jsonResps["Quantity"] = vTotal->Quantity;
		jsonResps["OpenPriceTotal"] = vTotal->OpenPriceTotal;
		jsonResps["AvgOpenPrice"] = vTotal->AvgOpenPrice;
		jsonResps["HoldPriceTotal"] = vTotal->HoldPriceTotal;
		jsonResps["AvgHoldPrice"] = vTotal->AvgHoldPrice;
		jsonResps["ClosePrice"] = vTotal->ClosePrice;
		jsonResps["OpenProfit"] = vTotal->OpenProfit;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryHoldPositionTotal;
		jsonRoot[RESPDESC] = "OnRspQryHoldPositionTotal";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}

///查询市场开休市状态回报
///@param nMarketStatus：市场开休市状态。 MARKET_STATUS_OPEN：0 MARKET_STATUS_CLOSE：1
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspQryMarketStatus(int nMarketStatus, int errCode, bool isLast)
{
	try{
		Json::Value jsonResps;
		jsonResps["MarketStatus"] = nMarketStatus;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryMarketStatus;
		jsonRoot[RESPDESC] = "OnRspQryMarketStatus";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}

///根据持仓单ID，获取持仓单信息回报
///@param pHoldPosition：持仓单信息。
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspQryHoldPositionByID(const CXHoldPositionInfo* pHoldPosition, int errCode, bool isLast)
{
	try{
		if (pHoldPosition == NULL)
		{
			LOGE("--接收异常，OnRspQryHoldPositionByID return null! ret: " << errCode);
			return;
		}

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
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}

///根据限价单ID，获取限价单信息回报
///@param pLimitOrder：限价单信息。
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspQryLimitOrderByID(const CXLimitOrderInfo* pLimitOrder, int errCode, bool isLast)
{
	try{
		if (pLimitOrder == NULL)
		{
			LOGE("--接收异常，OnRspQryLimitOrderByID return null! ret: " << errCode);
			return;
		}

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
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}


///根据平仓单ID，获取平仓信息回报
///@param pClosePosition：平仓信息。
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspQryClosePositionByID(const CXClosePositionInfo* pClosePosition, int errCode, bool isLast)
{
	try{
		if (pClosePosition == NULL)
		{
			LOGE("--接收异常，OnRspQryClosePositionByID return null! ret: " << errCode);
			return;
		}

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
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}

///根据商品ID，获取持仓汇总信息回报
///@param pTotal：持仓汇总信息。
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspQryHoldPositionTotalByCommodityID(const CXHoldPositionTotalInfo* pTotal, int errCode, bool isLast)
{
	try{
		if (pTotal == NULL)
		{
			LOGE("--接收异常，OnRspQryHoldPositionTotalByCommodityID return null! ret: " << errCode);
			return;
		}

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
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}


///根据商品ID，获取实时行情回报
///@param quote：实时行情。
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspQryCommodityQuote(const CXRealTimeQuote* quote, int errCode, bool isLast)
{
	try{
		if (quote == NULL)
		{
			LOGE("--接收异常，OnRspQryCommodityQuote return null! ret: " << errCode);
			return;
		}

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
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}


///根据商品ID，获取其市价建仓的配置信息回报
///@param pConf：市价建仓的配置信息。
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspQryOpenMarketOrderConf(const CXOpenMarketOrderConf* pConf, int errCode, bool isLast)
{
	try{
		if (pConf == NULL)
		{
			LOGE("--接收异常，OnRspQryOpenMarketOrderConf return null! ret: " << errCode);
			return;
		}

		Json::Value jsonResps;
		jsonResps["CommodityID"] = pConf->CommodityID;
		jsonResps["MinQuantity"] = pConf->MinQuantity;
		jsonResps["MaxQuantity"] = pConf->MaxQuantity;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryOpenMarketOrderConf;
		jsonRoot[RESPDESC] = "OnRspQryOpenMarketOrderConf";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}

///根据商品ID，获取其限价建仓的配置信息回报
///@param pConf：限价建仓的配置信息。
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspQryOpenLimitOrderConf(const CXOpenLimitOrderConf* pConf, int errCode, bool isLast)
{
	try{
		if (pConf == NULL)
		{
			LOGE("--接收异常，OnRspQryOpenLimitOrderConf return null! ret: " << errCode);
			return;
		}

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
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}


///根据商品ID，获取其市价平仓的配置信息回报
///@param pConf：市价平仓的配置信息。
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspQryCloseMarketOrderConf(const CXCloseMarketOrderConf* pConf, int errCode, bool isLast)
{
	try{
		if (pConf == NULL)
		{
			LOGE("--接收异常，OnRspQryCloseMarketOrderConf return null! ret: " << errCode);
			return;
		}

		Json::Value jsonResps;
		jsonResps["CommodityID"] = pConf->CommodityID;
		jsonResps["MinQuantity"] = pConf->MinQuantity;
		jsonResps["MaxQuantity"] = pConf->MaxQuantity;

		Json::Value jsonRoot;
		jsonRoot[RESPID] = RESP_OnRspQryCloseMarketOrderConf;
		jsonRoot[RESPDESC] = "OnRspQryCloseMarketOrderConf";
		jsonRoot[RESPJSONS] = jsonResps;
		jsonRoot[RESPERRCODE] = errCode;
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}

///根据商品ID，获取限价平仓的配置信息回报
///@param pConf：限价平仓的配置信息。
///@param errCode：出错信息。
void CXTradeSpiImpl::OnRspQryLimitClosePositionConf(const CXLimitClosePositionConf* pConf, int errCode, bool isLast)
{
	try{
		if (pConf == NULL)
		{
			LOGE("--接收异常，OnRspQryLimitClosePositionConf return null! ret: " << errCode);
			return;
		}

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
		jsonRoot[RESPISLAST] = isLast;

		//生成Json并送数据进队列
		SendBack(jsonRoot);
	}
	catch (std::exception &ex)
	{
		LOGE("--交易所数据异常: " << ex.what());
	}
}