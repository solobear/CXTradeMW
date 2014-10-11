#pragma once
#include "api\TradeApi.h"

class CMyTradeSpi : public CTradeSpi
{
public:

	CMyTradeSpi(CTradeApi* api):m_pTradeApi(api),m_bObMD(false){};

	///登录响应推送
	///@param pLoginEvent：用户登录信息。
	//virtual void OnRtnUserLogin(const TLoginEvent* pLoginEvent) ;
	virtual void OnRtnUserLogin(const CXProcessResult *ProcResult) ;

	///实时行情推送
	///@param Quote：行情信息。
	//virtual void OnRtnQuote(const TQuoteEvent *pQuoteEvent) ;
	virtual void OnRtnQuote(const CXRealTimeQuote *Quote) ;

	///市价单开仓回报信息推送
	///@param pOpenMarketOrder：市价单开仓回报信息。
	//virtual void OnRtnOpenMarketOrder(const TOpenMarketOrderEvent *pOpenMarketOrder) ;
	///@param HoldPositionID：持仓标识
	///@param ProcResult：响应信息
	virtual void OnRtnOpenMarketOrder(long long HoldPositionID,const CXProcessResult *ProcResult) ;

	///市价单平仓回报信息推送
	///@param pCloseMarketOrder：市价单平仓回报信息。
	//virtual void OnRtnCloseMarketOrder(const TCloseMarketOrderEvent *pCloseMarketOrder) ;
	///@param HoldPositionID：持仓标识
	///@param ProcResult：响应信息
	virtual void OnRtnCloseMarketOrder(long long HoldPositionID,const CXProcessResult *ProcResult) ;

	///限价单开仓回报信息推送
	///@param pOpenLimitOrder：限价单开仓回报信息。
	//virtual void OnRtnOpenLimitOrder(const TOpenLimitOrderEvent *pOpenLimitOrder) ;
	///@param LimitOrderID：报单标识
	///@param ProcResult：响应信息
	virtual void OnRtnOpenLimitOrder(long long LimitOrderID,const CXProcessResult *ProcResult) ;

	///限价单平仓回报信息推送
	///@param pOpenLimitOrder：限价单平仓回报信息。
	//virtual void OnRtnLimitClosePosition(const TLimitClosePositionEvent *pLimitClosePosition) ;
	virtual void OnRtnLimitClosePosition(long long HoldPositionID,const CXProcessResult *ProcResult) ;

	///限价单撤单回报信息推送
	///@param pRevokeLimitOrder：限价单撤单回报信息。
	//virtual void OnRtnRevokeLimitOrder(const TRevokeLimitOrderEvent *pRevokeLimitOrder) ;
	///@param HoldPositionID：持仓标识
	///@param ProcResult：响应信息
	virtual void OnRtnRevokeLimitOrder(long long LimitOrderID,const CXProcessResult *ProcResult) ;

	///系统通知信息推送
	///@param pSysBulletin：系统通知信息。
	//virtual void OnRtnSysBulletin(const TSysBulletinEvent *pSysBulletin) ;
	virtual void OnRtnSysBulletin(const CXSysBulletinInfo *pSysBulletInfo) ;

	///用户登录回报
	///@param pszLoginAccount：账户。
	///@param errCode：出错信息。
	virtual void OnRspUserLogin(const char* pszLoginAccount, int errCode, bool isLast) ;

	///市价单开仓回报
	///@param pOnRspOpenMarketOrderField：市价单开仓结构。
	///@param errCode：出错信息。
	virtual void OnRspOpenMarketOrder(const CXOpenMarketOrderParam *pOnRspOpenMarketOrderField, int errCode, bool isLast) ;

	///市价单平仓回报
	///@param pOnRspCloseMarketOrderField：市价单平仓结构。
	///@param errCode：出错信息。
	virtual void OnRspCloseMarketOrder(const CXCloseMarketOrderParam *pOnRspCloseMarketOrderField, int errCode, bool isLast) ;

	///限价单开仓回报
	///@param pOnRspOpenLimitOrderField：限价单开仓结构。
	///@param errCode：出错信息。
	virtual void OnRspOpenLimitOrder(const CXOpenLimitOrderParam *pOnRspOpenLimitOrderField, int errCode, bool isLast) ;

	///限价单平仓回报
	///@param pOnRspCloseLimitOrderField：限价单平仓结构。
	///@param errCode：出错信息。
	virtual void OnRspLimitClosePosition(const CXCloseLimitOrderParam *pOnRspCloseLimitOrderField, int errCode, bool isLast) ;

	///撤单回报
	///@param pOnRspLimitRevokeField：撤单结构。
	///@param errCode：出错信息。
	virtual void OnRspLimitRevoke(const CXLimitRevokeParam *pOnRspLimitRevokeField, int errCode, bool isLast) ;

	///市价单批量平仓回报
	///@param pOnRspCloseMarketOrderManyField：市价单批量平仓结构。
	///@param errCode：出错信息。
	virtual void OnRspCloseMarketOrderMany(const CXCloseMarketOrderManyParam *pOnRspCloseMarketOrderManyField, int errCode, bool isLast) ;

	///查询账户信息回报
	///@param account：账户信息。
	///@param errCode：出错信息。
	virtual void OnRspQryAccountInfo(const CXAccountInfo *account, int errCode, bool isLast) ;

	///查询商品信息回报
	///@param vCommodity：商品信息。
	///@param errCode：出错信息。
	virtual void OnRspQryCommodity(const CXCommodityInfo* vCommodity, int errCode, bool isLast) ;

	///查询持仓单信息回报
	///@param vHoldPosition：持仓单信息。
	///@param errCode：出错信息。
	virtual void OnRspQryPositionOrder(const CXHoldPositionInfo* vHoldPosition, int errCode, bool isLast) ;

	///查询限价单信息回报
	///@param vLimitOrder：限价单信息。
	///@param errCode：出错信息。
	virtual void OnRspQryLimitOrder(const CXLimitOrderInfo* vLimitOrder, int errCode, bool isLast) ;

	///查询平仓信息回报
	///@param vClosePosition：平仓信息。
	///@param errCode：出错信息。
	virtual void OnRspQryClosePosition(const CXClosePositionInfo* vClosePosition, int errCode, bool isLast) ;

	///查询持仓单总量回报
	///@param vTotal：持仓单总量。
	///@param errCode：出错信息。
	virtual void OnRspQryHoldPositionTotal(const CXHoldPositionTotalInfo* vTotal, int errCode, bool isLast) ;

	///查询市场开休市状态回报
	///@param nMarketStatus：市场开休市状态。 MARKET_STATUS_OPEN：0 MARKET_STATUS_CLOSE：1
	///@param errCode：出错信息。
	virtual void OnRspQryMarketStatus(int nMarketStatus, int errCode, bool isLast) ;

	///根据持仓单ID，获取持仓单信息回报
	///@param pHoldPosition：持仓单信息。
	///@param errCode：出错信息。
	virtual void OnRspQryHoldPositionByID(const CXHoldPositionInfo* pHoldPosition, int errCode, bool isLast) ;

	///根据限价单ID，获取限价单信息回报
	///@param pLimitOrder：限价单信息。
	///@param errCode：出错信息。
	virtual void OnRspQryLimitOrderByID(const CXLimitOrderInfo* pLimitOrder, int errCode, bool isLast) ;

	///根据平仓单ID，获取平仓信息回报
	///@param pClosePosition：平仓信息。
	///@param errCode：出错信息。
	virtual void OnRspQryClosePositionByID(const CXClosePositionInfo* pClosePosition, int errCode, bool isLast) ;

	///根据商品ID，获取持仓汇总信息回报
	///@param pTotal：持仓汇总信息。
	///@param errCode：出错信息。
	virtual void OnRspQryHoldPositionTotalByCommodityID(const CXHoldPositionTotalInfo* pTotal, int errCode, bool isLast) ;

	///根据商品ID，获取实时行情回报
	///@param quote：实时行情。
	///@param errCode：出错信息。
	virtual void OnRspQryCommodityQuote(const CXRealTimeQuote* quote, int errCode, bool isLast) ;

	///根据商品ID，获取其市价建仓的配置信息回报
	///@param pConf：市价建仓的配置信息。
	///@param errCode：出错信息。
	virtual void OnRspQryOpenMarketOrderConf(const CXOpenMarketOrderConf* pConf, int errCode, bool isLast) ;

	///根据商品ID，获取其限价建仓的配置信息回报
	///@param pConf：限价建仓的配置信息。
	///@param errCode：出错信息。
	virtual void OnRspQryOpenLimitOrderConf(const CXOpenLimitOrderConf* pConf, int errCode, bool isLast) ;

	///根据商品ID，获取其市价平仓的配置信息回报
	///@param pConf：市价平仓的配置信息。
	///@param errCode：出错信息。
	virtual void OnRspQryCloseMarketOrderConf(const CXCloseMarketOrderConf* pConf, int errCode, bool isLast) ;

	///根据商品ID，获取限价平仓的配置信息回报
	///@param pConf：限价平仓的配置信息。
	///@param errCode：出错信息。
	virtual void OnRspQryLimitClosePositionConf(const CXLimitClosePositionConf* pConf, int errCode, bool isLast) ;

private:
	CTradeApi *m_pTradeApi;
	bool m_bObMD;

public:
	void ReqUserLogin(char* pszLoginAccount, char* pszPwd);

	void ReqOpenMarketOrder(CXOpenMarketOrderParam *pReqOpenMarketOrderField);

	void ReqCloseMarketOrder(CXCloseMarketOrderParam *pReqCloseMarketOrderField); 

	void ReqOpenLimitOrder(CXOpenLimitOrderParam *pReqOpenLimitOrderField);

	void ReqLimitClosePosition(CXCloseLimitOrderParam *pReqCloseLimitOrderField);

	void ReqLimitRevoke(CXLimitRevokeParam *pReqLimitRevokeField);

	void ReqCloseMarketOrderMany(CXCloseMarketOrderManyParam *pReqCloseMarketOrderManyField);

	void ReqQryAccountInfo();

	void ReqQryCommodity();

	void ReqQryPositionOrder();

	void ReqQryLimitOrder();

	void ReqQryClosePosition();

	void ReqQryHoldPositionTotal();

	void ReqQryMarketStatus();

	void SetObMD(bool bObMD)
	{
		m_bObMD = bObMD;
	}

};

