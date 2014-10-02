#pragma once
#include "api\TradeApi.h"

class CMyTradeSpi : public CTradeSpi
{
public:

	CMyTradeSpi(CTradeApi* api):m_pTradeApi(api){};

	virtual void OnRtnUserLogin(const CXProcessResult *ProcResult);

	virtual void OnRtnQuote(const CXRealTimeQuote *ProcResult);

	//virtual void OnRtnOpenMarketOrder(const TOpenMarketOrderEvent *pOpenMarketOrder);
	virtual void OnRtnOpenMarketOrder(long long HoldPositionID,const CXProcessResult *ProcResult);

	//virtual void OnRtnCloseMarketOrder(const TCloseMarketOrderEvent *pCloseMarketOrder);
	virtual void OnRtnCloseMarketOrder(long long HoldPositionID,const CXProcessResult *ProcResult);

	//virtual void OnRtnOpenLimitOrder(const TOpenLimitOrderEvent *pOpenLimitOrder);
	virtual void OnRtnOpenLimitOrder(long long LimitOrderID,const CXProcessResult *ProcResult);

	//virtual void OnRtnLimitClosePosition(const TLimitClosePositionEvent *pLimitClosePosition);
	virtual void OnRtnLimitClosePosition(long long HoldPositionID,const CXProcessResult *ProcResult);

	//virtual void OnRtnRevokeLimitOrder(const TRevokeLimitOrderEvent *pRevokeLimitOrder);
	virtual void OnRtnRevokeLimitOrder(long long LimitOrderID,const CXProcessResult *ProcResult);

	//virtual void OnRtnSysBulletin(const TSysBulletinEvent *pSysBulletin);
	virtual void OnRtnSysBulletin(const CXSysBulletinInfo *pSysBulletin);

	virtual void OnRspUserLogin(const char* pszLoginAccount, int errCode);

	virtual void OnRspOpenMarketOrder(const CXOpenMarketOrderParam *pOnRspOpenMarketOrderField, int errCode);

	virtual void OnRspCloseMarketOrder(const CXCloseMarketOrderParam *pOnRspCloseMarketOrderField, int errCode);

	virtual void OnRspOpenLimitOrder(const CXOpenLimitOrderParam *pOnRspOpenLimitOrderField, int errCode);

	virtual void OnRspLimitClosePosition(const CXCloseLimitOrderParam *pOnRspCloseLimitOrderField, int errCode);

	virtual void OnRspLimitRevoke(const CXLimitRevokeParam *pOnRspLimitRevokeField, int errCode);

	virtual void OnRspCloseMarketOrderMany(const CXCloseMarketOrderManyParam *pOnRspCloseMarketOrderManyField, int errCode);

	virtual void OnRspQryAccountInfo(const CXAccountInfo *pAccount, int errCode);

	virtual void OnRspQryCommodity(std::vector<CXCommodityInfo> &vCommodity, int errCode);

	virtual void OnRspQryPositionOrder(std::vector<CXHoldPositionInfo>& vHoldPosition, int errCode);

	virtual void OnRspQryLimitOrder(std::vector<CXLimitOrderInfo>& vLimitOrder, int errCode);

	virtual void OnRspQryClosePosition(std::vector<CXClosePositionInfo>& vClosePosition, int errCode);

	virtual void OnRspQryHoldPositionTotal(std::vector<CXHoldPositionTotalInfo>& vTotal, int errCode);

	virtual void OnRspQryMarketStatus(int nMarketStatus, int errCode);

	virtual void OnRspQryHoldPositionByID(const CXHoldPositionInfo* pHoldPosition, int errCode);

	virtual void OnRspQryLimitOrderByID(const CXLimitOrderInfo* pLimitOrder, int errCode);

	virtual void OnRspQryClosePositionByID(const CXClosePositionInfo* pClosePosition, int errCode);

	virtual void OnRspQryHoldPositionTotalByCommodityID(const CXHoldPositionTotalInfo* pTotal, int errCode);

	virtual void OnRspQryCommodityQuote(const CXRealTimeQuote* quote, int errCode);

	virtual void OnRspQryOpenMarketOrderConf(const CXOpenMarketOrderConf* pConf, int errCode);

	virtual void OnRspQryOpenLimitOrderConf(const CXOpenLimitOrderConf* pConf, int errCode);

	virtual void OnRspQryCloseMarketOrderConf(const CXCloseMarketOrderConf* pConf, int errCode);

	virtual void OnRspQryLimitClosePositionConf(const CXLimitClosePositionConf* pConf, int errCode);

private:
	CTradeApi *m_pTradeApi;
};

