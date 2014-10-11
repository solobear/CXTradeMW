#include "MyTradeSpi.h"
#include <iostream>

#define Event_Ret_Success 99999
#define Order_Ret_Success 0

#define TS_1970_TO_1900  2208988800

void CMyTradeSpi::OnRtnUserLogin(const CXProcessResult *result)
{
	if(Event_Ret_Success != result->RetCode)
	{
		printf("[TE] Login Fail! Ret:%d, Msg:%s\n",result->RetCode, result->Message);
	}
	m_pTradeApi->ReqQryAccountInfo();
}

void CMyTradeSpi::OnRtnQuote( const CXRealTimeQuote *Quote )
{
	if (m_bObMD)
	{
		printf("[T] QUOTE: %d,%f,%f,%f,%f,%l\n",Quote->CommodityID,Quote->BuyPrice,Quote->SellPrice,Quote->HighPrice,Quote->LowPrice,Quote->QuoteTime);
	}
}

void CMyTradeSpi::OnRtnOpenMarketOrder(long long HoldPositionID,const CXProcessResult *ProcResult )
{
	printf("get OpenMarketOrder retSignal !\n");
	if(Event_Ret_Success != ProcResult->RetCode)
	{
		printf("[TE] OnRtnOpenMarketOrder ERROR! result code = %d, msg = %s\n",ProcResult->RetCode, ProcResult->Message);
	}
	else
	{
		printf("[TE] OnRtnOpenMarketOrder SUCCESS! result HoldPositionID = %I64d\n",HoldPositionID);
	}
}

void CMyTradeSpi::OnRtnCloseMarketOrder(long long HoldPositionID,const CXProcessResult *ProcResult)
{
	printf("get CloseMarketOrder retSignal !\n");
	if(Event_Ret_Success != ProcResult->RetCode)
	{
		printf("[TE] OnRtnCloseMarketOrder ERROR! result code = %d, msg = %s\n",ProcResult->RetCode, ProcResult->Message);
	}
	else
	{
		printf("[TE] OnRtnCloseMarketOrder SUCCESS! result HoldPositionID = %I64d\n",HoldPositionID);
	}
}

void CMyTradeSpi::OnRtnOpenLimitOrder( long long LimitOrderID,const CXProcessResult *ProcResult )
{
	printf("get OpenLimitOrder retSignal !\n");
	if(Event_Ret_Success != ProcResult->RetCode)
	{
		printf("[TE] OnRtnOpenLimitOrder ERROR! result code = %d, msg = %s\n",ProcResult->RetCode, ProcResult->Message);
	}
	else
	{
		printf("[TE] OnRtnOpenLimitOrder SUCCESS! result HoldPositionID = %I64d\n",LimitOrderID);
	}
}

void CMyTradeSpi::OnRtnLimitClosePosition( long long HoldPositionID,const CXProcessResult *ProcResult)
{
	printf("get LimitClosePosition retSignal !\n");
	if(Event_Ret_Success != ProcResult->RetCode)
	{
		printf("[TE] OnRtnLimitClosePosition ERROR! result code = %d, msg = %s\n",ProcResult->RetCode, ProcResult->Message);
	}
	else
	{
		printf("[TE] OnRtnLimitClosePosition SUCCESS! result HoldPositionID = %I64d\n",HoldPositionID);
	}
}

void CMyTradeSpi::OnRtnRevokeLimitOrder( long long LimitOrderID,const CXProcessResult *ProcResult)
{
	printf("get RevokeLimitOrder retSignal !\n");
	if(Event_Ret_Success != ProcResult->RetCode)
	{
		printf("[TE] OnRtnRevokeLimitOrder ERROR! result code = %d, msg = %s\n",ProcResult->RetCode, ProcResult->Message);
	}
	else
	{
		printf("[TE] OnRtnRevokeLimitOrder SUCCESS! result HoldPositionID = %I64d\n",LimitOrderID);
	}
}

void CMyTradeSpi::OnRtnSysBulletin( const CXSysBulletinInfo *pSysBulletin )
{
}

void CMyTradeSpi::OnRspUserLogin( const char* pszLoginAccount, int errCode, bool isLast)
{
	if (0 != errCode)
	{
		printf("[TE] Login Fail! ret:%d\n",errCode);
	}
	if (pszLoginAccount == NULL)
	{
		printf("[TE] OnRspUserLogin return null! ret: %d\n",errCode);
		return;
	}
}

void CMyTradeSpi::OnRspOpenMarketOrder( const CXOpenMarketOrderParam *pRspOpenMarketOrderField, int errCode, bool isLast)
{
	if (0 != errCode)
	{
		printf("[TE] OpenMarketOrder Fail! ret:%d\n",errCode);
	}
	if (pRspOpenMarketOrderField == NULL)
	{
		printf("[TE] OnRspOpenMarketOrder return null! ret: %d\n",errCode);
		return;
	}
}

void CMyTradeSpi::OnRspCloseMarketOrder( const CXCloseMarketOrderParam *pOnRspCloseMarketOrderField, int errCode, bool isLast)
{
	if (0 != errCode)
	{
		printf("[TE] CloseMarketOrder Fail! ret:%d\n",errCode);
	}
	if (pOnRspCloseMarketOrderField == NULL)
	{
		printf("[TE] OnRspCloseMarketOrder return null! ret: %d\n",errCode);
		return;
	}
}

void CMyTradeSpi::OnRspOpenLimitOrder( const CXOpenLimitOrderParam *pOnRspOpenLimitOrderField, int errCode, bool isLast)
{
	if (0 != errCode)
	{
		printf("[TE] OpenLimitOrder Fail! ret:%d\n",errCode);
	}
	if (pOnRspOpenLimitOrderField == NULL)
	{
		printf("[TE] OnRspOpenLimitOrder return null! ret: %d\n",errCode);
		return;
	}
}

void CMyTradeSpi::OnRspLimitClosePosition( const CXCloseLimitOrderParam *pOnRspCloseLimitOrderField, int errCode, bool isLast)
{
	if (0 != errCode)
	{
		printf("[TE] LimitClosePosition Fail! ret:%d\n",errCode);
	}
	if (pOnRspCloseLimitOrderField == NULL)
	{
		printf("[TE] OnRspLimitClosePosition return null! ret: %d\n",errCode);
		return;
	}
}

void CMyTradeSpi::OnRspLimitRevoke( const CXLimitRevokeParam *pOnRspLimitRevokeField, int errCode, bool isLast)
{
	if (0 != errCode)
	{
		printf("[TE] LimitRevoke Fail! ret:%d\n",errCode);
	}
	if (pOnRspLimitRevokeField == NULL)
	{
		printf("[TE] OnRspLimitRevoke return null! ret: %d\n",errCode);
		return;
	}
}

void CMyTradeSpi::OnRspCloseMarketOrderMany(const CXCloseMarketOrderManyParam *pOnRspCloseMarketOrderManyField, int errCode, bool isLast)
{
	if (0 != errCode)
	{
		printf("[TE] CloseMarketOrderMany Fail! ret:%d\n",errCode);
	}
	if (pOnRspCloseMarketOrderManyField == NULL)
	{
		printf("[TE] OnRspCloseMarketOrderMany return null! ret: %d\n",errCode);
		return;
	}
}

void CMyTradeSpi::OnRspQryAccountInfo(const CXAccountInfo *pAccount, int errCode, bool isLast)
{
	if (pAccount == NULL)
	{
		printf("[TE] OnRspQryAccountInfo return null! ret: %d\n",errCode);
		return;
	}
	printf("[T] Account=%s\nLoginAccount=%s\nCustomerName=%s\n\
Amount:%f\nOpenProfit:%f\nFrozenReserve:%f\tRiskRate:%f\n\
NAVPrice:%f\nPerformanceReserve:%f\n", \
		   pAccount->Account, pAccount->LoginAccount, pAccount->CustomerName,  \
		   pAccount->Amount, pAccount->OpenProfit, pAccount->FrozenReserve, pAccount->RiskRate,  \
		   pAccount->NAVPrice, pAccount->PerformanceReserve);
	//m_pTradeApi->ReqQryMarketStatus();
}

void CMyTradeSpi::OnRspQryCommodity(const CXCommodityInfo* vCommodity, int errCode , bool isLast)
{
	if(CX_MSG_STATUS_UPDATED != errCode )
	{
		printf("[TE] requestQuote Fail! ret: %d\n",errCode);
	}
	if (vCommodity == NULL)
	{
		printf("[TE] OnRspQryCommodity return null! ret: %d\n",errCode);
		return;
	}

	printf("[T] OnRspQryCommodity: %d,%s,%f,%f,%f,%f\n",vCommodity->CommodityID,vCommodity->CommodityName,vCommodity->BuyPrice,vCommodity->SellPrice,vCommodity->HighPrice,vCommodity->LowPrice);
	if (isLast)
	{
		printf("[T] OnRspQryCommodity end");
	}


	/*CXOpenMarketOrderParam mOrder1;
	mOrder1.nCommodityID = 10001;
	mOrder1.nOrderType = 1;
	mOrder1.nOpenDirector = CX_OPENDIRECTOR_BUY;
	mOrder1.nQuantity = 5;
	mOrder1.dbPrice = 3.410;
	m_pTradeApi->ReqOpenMarketOrder(&mOrder1);*/

	//OpenLimitOrderParam mOrder2;
	//mOrder2.nCommodityID = 10001;
	//mOrder2.dbOrderPrice = 3.410;
	//mOrder2.nOpenDirector = OPENDIRECTOR_BUY;
	//mOrder2.nOrderType = 1;
	//mOrder2.dbSLPrice = 3.200;
	//mOrder2.dbTPPrice = 3.700;
	//mOrder2.nExpireType = 0;
	//m_pTradeApi->ReqOpenLimitOrder(&mOrder2);
}

void CMyTradeSpi::OnRspQryPositionOrder(const CXHoldPositionInfo* vHoldPosition, int errCode, bool isLast )
{
	if(CX_MSG_STATUS_UPDATED != errCode )
	{
		printf("[TE] requestHoldPosition Fail! ret: %d\n",errCode);
	}

	if (vHoldPosition == NULL)
	{
		printf("[TE] OnRspQryPositionOrder return null! ret: %d\n",errCode);
		return;
	}

	printf("============== HoldPositions =======================\n");
	{
		printf("[T] HoldPositionID:%d, CommodityID:%d\n", vHoldPosition->HoldPositionID,vHoldPosition->CommodityID);
		printf("\t CommodityName:%s,  openType:%d,  openDirect:%s\n",vHoldPosition->CommodityName,vHoldPosition->OpenType,vHoldPosition->OpenDirector==1?"1买入":"2卖出");
		printf("\t Quantity:%d, OpenPrice:%6.3f, HoldPositionPrice:%6.3f\n",vHoldPosition->Quantity,vHoldPosition->OpenPrice,vHoldPosition->HoldPositionPrice);
		printf("\t SLLimitOrderID:%d, SLPrice:%6.3f, TPLimitOrderID:%d, TPPrice:%6.3f\n",vHoldPosition->SLLimitOrderID,vHoldPosition->SLPrice, vHoldPosition->TPLimitOrderID,vHoldPosition->TPPrice);
		printf("\t OpenProfit:%6.3f, CommissionAmount:%6.3f\n", vHoldPosition->OpenProfit, vHoldPosition->CommissionAmount);
		printf("\t AgreeMargin:%6.3f, Freezemargin:%6.3f, OverdueFindFund:%6.3f\n", vHoldPosition->AgreeMargin, vHoldPosition->Freezemargin, vHoldPosition->OverdueFindFund);
		printf("------------------------------------\n");
	}
	if (isLast)
	{
		printf("[T] OnRspQryPositionOrder end");
	}
}

void CMyTradeSpi::OnRspQryLimitOrder(const CXLimitOrderInfo* vLimitOrder, int errCode, bool isLast) 
{
	if(CX_MSG_STATUS_UPDATED != errCode )
	{
		printf("[TE] requestLimitOrders Fail! ret: %d\n",errCode);
		return;
	}
	if (vLimitOrder == NULL)
	{
		printf("[TE] OnRspQryLimitOrder return null! ret: %d\n",errCode);
		return;
	}
	printf("============== LimitOrders =======================\n");
	{
		printf("[T] LimitOrderID:%d, CommodityID:%d\n", vLimitOrder->LimitOrderID,vLimitOrder->CommodityID);
		printf("\t CommodityName:%s,  LimitType:%d, OrderType:%d, openDirect:%s\n",vLimitOrder->CommodityName,vLimitOrder->LimitType,vLimitOrder->OrderType,vLimitOrder->OpenDirector==1?"1买入":"2卖出");
		printf("\t Quantity:%d, OrderPrice:%6.3f, HoldPositionPrice:%s\n",vLimitOrder->OpenQuantity,vLimitOrder->OrderPrice,vLimitOrder->CreateDate);
		printf("\t SLPrice:%6.3f, TPPrice:%6.3f, UpdateDate:%s\n",vLimitOrder->SLPrice, vLimitOrder->TPPrice, vLimitOrder->UpdateDate);
		printf("\t ExpireType:%ld, FreeszMargin:%6.3f\n", vLimitOrder->ExpireType, vLimitOrder->FreeszMargin);
		printf("------------------------------------\n");
	}
	if (isLast)
	{
		printf("[T] OnRspQryLimitOrder end");
	}
}

void CMyTradeSpi::OnRspQryClosePosition(const CXClosePositionInfo* vClosePosition, int errCode, bool isLast)
{
	if(CX_MSG_STATUS_UPDATED != errCode )
	{
		printf("[TE] OnRspQryClosePosition Fail! ret: %d\n",errCode);
		return ;
	}

	if (vClosePosition == NULL)
	{
		printf("[TE] OnRspQryClosePosition return null! ret: %d\n",errCode);
		return;
	}

	printf("============== ClosePositions =======================\n");
	{
		printf("[T] ClosePositionID:%d, CommodityID:%d, MemberID:%d\n", vClosePosition->ClosePositionID,vClosePosition->CommodityID, vClosePosition->MemberID);
		printf("\t CommodityName:%s,  OpenType:%d, CloseType:%d, CloseDirector:%s\n",vClosePosition->CommodityName,vClosePosition->OpenType,vClosePosition->CloseType,vClosePosition->CloseDirector==1?"1买入":"2卖出");
		printf("\t Quantity:%d, OpenPrice:%6.3f, HoldPrice:%6.3f, OpenPositionID:%ld\n",vClosePosition->Quantity,vClosePosition->OpenPrice,vClosePosition->HoldPrice,vClosePosition->OpenPositionID);
		printf("\t ClosePrice:%6.3f, CommissionAmount:%6.3f, OpenDate:%s, CloseDate:%s\n",vClosePosition->ClosePrice, vClosePosition->CommissionAmount, vClosePosition->OpenDate, vClosePosition->CloseDate);
		printf("------------------------------------\n");
	}
	if (isLast)
	{
		printf("[T] OnRspQryClosePosition end");
	}
}

void CMyTradeSpi::OnRspQryHoldPositionTotal(const CXHoldPositionTotalInfo* vTotal, int errCode, bool isLast)
{
	if(CX_MSG_STATUS_UPDATED != errCode )
	{
		printf("[TE] OnRspQryHoldPositionTotal Fail! ret: %d\n",errCode);
	}

	if (vTotal == NULL)
	{
		printf("[TE] OnRspQryHoldPositionTotal return null! ret: %d\n",errCode);
		return;
	}
	printf("============== HoldPositionTotal =======================\n");
	{
		printf("[T] CommodityID:%d, CommodityName:%s\n", vTotal->CommodityID,vTotal->CommodityName);
		printf("\t OpenDirector:%s,Quantity:%d, \n",vTotal->OpenDirector==1?"1买入":"2卖出", vTotal->Quantity);
		printf("\t OpenPriceTotal:%6.3f, AvgOpenPrice:%6.3f, HoldPriceTotal:%6.3f, AvgHoldPrice:%6.3f\n",vTotal->OpenPriceTotal,vTotal->AvgOpenPrice,vTotal->HoldPriceTotal,vTotal->AvgHoldPrice );
		printf("\t ClosePrice:%6.3f, OpenProfit:%6.3f\n",vTotal->ClosePrice, vTotal->OpenProfit);
		printf("------------------------------------\n");
	}
	if (isLast)
	{
		printf("[T] OnRspQryHoldPositionTotal end");
	}
}

void CMyTradeSpi::OnRspQryMarketStatus(int nMarketStatus, int errCode, bool isLast)
{
	//if(CX_MARKET_STATUS_OPEN == nMarketStatus){
	if(CX_MARKET_STATUS_OPEN == nMarketStatus){
		printf("[T] *********** Welcome to our Market! ***********\n");
	}else{
		printf("[TE] Market is not yeah open! ret: %d \n", nMarketStatus);
	}
}

void CMyTradeSpi::OnRspQryHoldPositionByID( const CXHoldPositionInfo* pHoldPosition, int errCode, bool isLast )
{
}

void CMyTradeSpi::OnRspQryLimitOrderByID( const CXLimitOrderInfo* pLimitOrder, int errCode, bool isLast )
{
}

void CMyTradeSpi::OnRspQryClosePositionByID( const CXClosePositionInfo* pClosePosition, int errCode, bool isLast )
{
}

void CMyTradeSpi::OnRspQryHoldPositionTotalByCommodityID( const CXHoldPositionTotalInfo* pTotal, int errCode, bool isLast )
{
}

void CMyTradeSpi::OnRspQryCommodityQuote( const CXRealTimeQuote* quote, int errCode, bool isLast )
{
}

void CMyTradeSpi::OnRspQryOpenMarketOrderConf( const CXOpenMarketOrderConf* pConf, int errCode, bool isLast )
{
}

void CMyTradeSpi::OnRspQryOpenLimitOrderConf( const CXOpenLimitOrderConf* pConf, int errCode, bool isLast)
{
}

void CMyTradeSpi::OnRspQryCloseMarketOrderConf( const CXCloseMarketOrderConf* pConf, int errCode, bool isLast)
{
}

void CMyTradeSpi::OnRspQryLimitClosePositionConf( const CXLimitClosePositionConf* pConf, int errCode, bool isLast)
{
}

void CMyTradeSpi::ReqUserLogin( char* pszLoginAccount, char* pszPwd )
{
	m_pTradeApi->ReqUserLogin(pszLoginAccount, pszPwd);
}

void CMyTradeSpi::ReqOpenMarketOrder( CXOpenMarketOrderParam *pReqOpenMarketOrderField )
{
	m_pTradeApi->ReqOpenMarketOrder(pReqOpenMarketOrderField);
}

void CMyTradeSpi::ReqCloseMarketOrder( CXCloseMarketOrderParam *pReqCloseMarketOrderField )
{
	m_pTradeApi->ReqCloseMarketOrder(pReqCloseMarketOrderField);
}

void CMyTradeSpi::ReqOpenLimitOrder( CXOpenLimitOrderParam *pReqOpenLimitOrderField )
{
	m_pTradeApi->ReqOpenLimitOrder(pReqOpenLimitOrderField);
}

void CMyTradeSpi::ReqLimitClosePosition( CXCloseLimitOrderParam *pReqCloseLimitOrderField )
{
	m_pTradeApi->ReqLimitClosePosition(pReqCloseLimitOrderField);
}

void CMyTradeSpi::ReqLimitRevoke( CXLimitRevokeParam *pReqLimitRevokeField )
{
	m_pTradeApi->ReqLimitRevoke(pReqLimitRevokeField);
}

void CMyTradeSpi::ReqCloseMarketOrderMany( CXCloseMarketOrderManyParam *pReqCloseMarketOrderManyField )
{
	m_pTradeApi->ReqCloseMarketOrderMany(pReqCloseMarketOrderManyField);
}

void CMyTradeSpi::ReqQryAccountInfo()
{
	m_pTradeApi->ReqQryAccountInfo();
}

void CMyTradeSpi::ReqQryCommodity()
{
	m_pTradeApi->ReqQryCommodity();
}

void CMyTradeSpi::ReqQryPositionOrder()
{
	m_pTradeApi->ReqQryPositionOrder();
}

void CMyTradeSpi::ReqQryLimitOrder()
{
	m_pTradeApi->ReqQryLimitOrder();
}

void CMyTradeSpi::ReqQryClosePosition()
{
	m_pTradeApi->ReqQryClosePosition();
}

void CMyTradeSpi::ReqQryHoldPositionTotal()
{
	m_pTradeApi->ReqQryHoldPositionTotal();
}

void CMyTradeSpi::ReqQryMarketStatus()
{
	m_pTradeApi->ReqQryMarketStatus();
}
