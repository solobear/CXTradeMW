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

void CMyTradeSpi::OnRtnQuote(const CXRealTimeQuote *ProcResult)
{
	printf("OnRtnQuote: %d\n", ProcResult->QuoteTime);
}

void CMyTradeSpi::OnRtnOpenMarketOrder(long long HoldPositionID,const CXProcessResult *ProcResult )
{
	printf("get OPENMARKETORDER retSignal !\n");
	if(Event_Ret_Success != ProcResult->RetCode)
	{
		printf("[TE] OnRtnOpenMarketOrder ERROR! result code = %d\n",ProcResult->RetCode);
	}
	else
	{
		m_pTradeApi->ReqQryPositionOrder();
		m_pTradeApi->ReqQryHoldPositionTotal();
	}
}

void CMyTradeSpi::OnRtnCloseMarketOrder(long long HoldPositionID,const CXProcessResult *ProcResult)
{
}

void CMyTradeSpi::OnRtnOpenLimitOrder( long long LimitOrderID,const CXProcessResult *ProcResult )
{
}

void CMyTradeSpi::OnRtnLimitClosePosition( long long HoldPositionID,const CXProcessResult *ProcResult)
{
}

void CMyTradeSpi::OnRtnRevokeLimitOrder( long long LimitOrderID,const CXProcessResult *ProcResult)
{
}

void CMyTradeSpi::OnRtnSysBulletin( const CXSysBulletinInfo *pSysBulletin )
{
}

void CMyTradeSpi::OnRspUserLogin( const char* pszLoginAccount, int errCode )
{
	if (0 != errCode)
	{
		printf("[TE] Login Fail! ret:%d\n",errCode);
	}
}

void CMyTradeSpi::OnRspOpenMarketOrder( const CXOpenMarketOrderParam *pRspOpenMarketOrderField, int errCode )
{
	if (0 != errCode)
	{
		printf("[TE] OpenMarketOrder Fail! ret:%d\n",errCode);
	}
}

void CMyTradeSpi::OnRspCloseMarketOrder( const CXCloseMarketOrderParam *pOnRspCloseMarketOrderField, int errCode )
{
	if (0 != errCode)
	{
		printf("[TE] CloseMarketOrder Fail! ret:%d\n",errCode);
	}
}

void CMyTradeSpi::OnRspOpenLimitOrder( const CXOpenLimitOrderParam *pOnRspOpenLimitOrderField, int errCode )
{
	if (0 != errCode)
	{
		printf("[TE] OpenLimitOrder Fail! ret:%d\n",errCode);
	}
}

void CMyTradeSpi::OnRspLimitClosePosition( const CXCloseLimitOrderParam *pOnRspCloseLimitOrderField, int errCode )
{
	if (0 != errCode)
	{
		printf("[TE] LimitClosePosition Fail! ret:%d\n",errCode);
	}
}

void CMyTradeSpi::OnRspLimitRevoke( const CXLimitRevokeParam *pOnRspLimitRevokeField, int errCode )
{
	if (0 != errCode)
	{
		printf("[TE] LimitRevoke Fail! ret:%d\n",errCode);
	}
}

void CMyTradeSpi::OnRspCloseMarketOrderMany(const CXCloseMarketOrderManyParam *pOnRspCloseMarketOrderManyField, int errCode)
{
	if (0 != errCode)
	{
		printf("[TE] CloseMarketOrderMany Fail! ret:%d\n",errCode);
	}
}

void CMyTradeSpi::OnRspQryAccountInfo(const CXAccountInfo *pAccount, int errCode )
{
	printf("[T] Account=%s\nLoginAccount=%s\nCustomerName=%s\n\
Amount:%f\nOpenProfit:%f\nFrozenReserve:%f\tRiskRate:%f\n\
NAVPrice:%f\nPerformanceReserve:%f\n", \
		   pAccount->Account, pAccount->LoginAccount, pAccount->CustomerName,  \
		   pAccount->Amount, pAccount->OpenProfit, pAccount->FrozenReserve, pAccount->RiskRate,  \
		   pAccount->NAVPrice, pAccount->PerformanceReserve);
	m_pTradeApi->ReqQryMarketStatus();
}

void CMyTradeSpi::OnRspQryCommodity( std::vector<CXCommodityInfo> &vCommodity, int errCode )
{
	if(CX_MSG_STATUS_UPDATED != errCode )
	{
		printf("[TE] requestQuote Fail! ret: %d\n",errCode);
	}

	std::vector<CXCommodityInfo>::iterator it;
	//printf("============== Commoditys =======================\n");
	for(it=vCommodity.begin();it!=vCommodity.end();it++)
	{
		printf("[T] OneQUOTE: %d,%s,%f,%f,%f,%f\n",it->CommodityID,it->CommodityName,it->BuyPrice,it->SellPrice,it->HighPrice,it->LowPrice);
	}

	CXOpenMarketOrderParam mOrder1;
	mOrder1.nCommodityID = 10001;
	mOrder1.nOrderType = 1;
	mOrder1.nOpenDirector = CX_OPENDIRECTOR_BUY;
	mOrder1.nQuantity = 5;
	mOrder1.dbPrice = 3.410;
	m_pTradeApi->ReqOpenMarketOrder(&mOrder1);

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

void CMyTradeSpi::OnRspQryPositionOrder( std::vector<CXHoldPositionInfo>& vHoldPosition, int errCode )
{
	if(CX_MSG_STATUS_UPDATED != errCode )
	{
		printf("[TE] requestHoldPosition Fail! ret: %d\n",errCode);
	}

	std::vector<CXHoldPositionInfo>::iterator it;
	printf("============== HoldPositions =======================\n");
	for(it=vHoldPosition.begin();it!=vHoldPosition.end();it++)
	{
		printf("[T] HoldPositionID:%d, CommodityID:%d\n", it->HoldPositionID,it->CommodityID);
		printf("\t CommodityName:%s,  openType:%d,  openDirect:%s\n",it->CommodityName,it->OpenType,it->OpenDirector==1?"1买入":"2卖出");
		printf("\t Quantity:%d, OpenPrice:%6.3f, HoldPositionPrice:%6.3f\n",it->Quantity,it->OpenPrice,it->HoldPositionPrice);
		printf("\t SLLimitOrderID:%d, SLPrice:%6.3f, TPLimitOrderID:%d, TPPrice:%6.3f\n",it->SLLimitOrderID,it->SLPrice, it->TPLimitOrderID,it->TPPrice);
		printf("\t OpenProfit:%6.3f, CommissionAmount:%6.3f\n", it->OpenProfit, it->CommissionAmount);
		printf("\t AgreeMargin:%6.3f, Freezemargin:%6.3f, OverdueFindFund:%6.3f\n", it->AgreeMargin, it->Freezemargin, it->OverdueFindFund);
		printf("------------------------------------\n");
	}
}

void CMyTradeSpi::OnRspQryLimitOrder( std::vector<CXLimitOrderInfo>& vLimitOrder, int errCode )
{
}

void CMyTradeSpi::OnRspQryClosePosition( std::vector<CXClosePositionInfo>& vClosePosition, int errCode )
{
}

void CMyTradeSpi::OnRspQryHoldPositionTotal( std::vector<CXHoldPositionTotalInfo>& vTotal, int errCode )
{
	if(CX_MSG_STATUS_UPDATED != errCode )
	{
		printf("[TE] requestHoldPositionTotal Fail! ret: %d\n",errCode);
	}

	std::vector<CXHoldPositionTotalInfo>::iterator it;
	printf("============== HoldPositionTotal =======================\n");
	for(it=vTotal.begin();it!=vTotal.end();it++)
	{
		printf("[T] CommodityID:%d, CommodityName:%s\n", it->CommodityID,it->CommodityName);
		printf("\t OpenDirector:%s,Quantity:%d, \n",it->OpenDirector==1?"1买入":"2卖出", it->Quantity);
		printf("\t OpenPriceTotal:%6.3f, AvgOpenPrice:%6.3f, HoldPriceTotal:%6.3f, AvgHoldPrice:%6.3f\n",it->OpenPriceTotal,it->AvgOpenPrice,it->HoldPriceTotal,it->AvgHoldPrice );
		printf("\t ClosePrice:%6.3f, OpenProfit:%6.3f\n",it->ClosePrice, it->OpenProfit);
		printf("------------------------------------\n");
	}
}

void CMyTradeSpi::OnRspQryMarketStatus( int nMarketStatus, int errCode )
{
	//if(CX_MARKET_STATUS_OPEN == nMarketStatus){
	if(CX_MARKET_STATUS_OPEN == nMarketStatus){
		printf("[T] *********** Welcome to our Market! ***********\n");
		m_pTradeApi->ReqQryCommodity();
	}else{
		printf("[TE] Market is not yeah open! ret: %d \n", nMarketStatus);
	}
}

void CMyTradeSpi::OnRspQryHoldPositionByID( const CXHoldPositionInfo* pHoldPosition, int errCode )
{
}

void CMyTradeSpi::OnRspQryLimitOrderByID( const CXLimitOrderInfo* pLimitOrder, int errCode )
{
}

void CMyTradeSpi::OnRspQryClosePositionByID( const CXClosePositionInfo* pClosePosition, int errCode )
{
}

void CMyTradeSpi::OnRspQryHoldPositionTotalByCommodityID( const CXHoldPositionTotalInfo* pTotal, int errCode )
{
}

void CMyTradeSpi::OnRspQryCommodityQuote( const CXRealTimeQuote* quote, int errCode )
{
}

void CMyTradeSpi::OnRspQryOpenMarketOrderConf( const CXOpenMarketOrderConf* pConf, int errCode )
{
}

void CMyTradeSpi::OnRspQryOpenLimitOrderConf( const CXOpenLimitOrderConf* pConf, int errCode)
{
}

void CMyTradeSpi::OnRspQryCloseMarketOrderConf( const CXCloseMarketOrderConf* pConf, int errCode)
{
}

void CMyTradeSpi::OnRspQryLimitClosePositionConf( const CXLimitClosePositionConf* pConf, int errCode)
{
}