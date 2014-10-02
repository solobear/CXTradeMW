#pragma once

#include "TradeApiStruct.h"

#ifdef LIB_USER_API_EXPORT
#define USER_API_EXPORT __declspec(dllexport)
#else
#define USER_API_EXPORT __declspec(dllimport)
#endif

class CTradeSpi
{
public:
	///登录响应推送
	///@param pLoginEvent：用户登录信息。
	//virtual void OnRtnUserLogin(const TLoginEvent* pLoginEvent) {};
	virtual void OnRtnUserLogin(const CXProcessResult *ProcResult) {};

	///实时行情推送
	///@param pQuoteEvent：行情信息。
	//virtual void OnRtnQuote(const TQuoteEvent *pQuoteEvent) {};
	virtual void OnRtnQuote(const CXRealTimeQuote *Quote) {};

	///市价单开仓回报信息推送
	///@param pOpenMarketOrder：市价单开仓回报信息。
	//virtual void OnRtnOpenMarketOrder(const TOpenMarketOrderEvent *pOpenMarketOrder) {};
	virtual void OnRtnOpenMarketOrder(long long HoldPositionID,const CXProcessResult *ProcResult) {};

	///市价单平仓回报信息推送
	///@param pCloseMarketOrder：市价单平仓回报信息。
	//virtual void OnRtnCloseMarketOrder(const TCloseMarketOrderEvent *pCloseMarketOrder) {};
	virtual void OnRtnCloseMarketOrder(long long HoldPositionID,const CXProcessResult *ProcResult) {};

	///限价单开仓回报信息推送
	///@param pOpenLimitOrder：限价单开仓回报信息。
	//virtual void OnRtnOpenLimitOrder(const TOpenLimitOrderEvent *pOpenLimitOrder) {};
	virtual void OnRtnOpenLimitOrder(long long LimitOrderID,const CXProcessResult *ProcResult) {};

	///限价单平仓回报信息推送
	///@param pOpenLimitOrder：限价单平仓回报信息。
	//virtual void OnRtnLimitClosePosition(const TLimitClosePositionEvent *pLimitClosePosition) {};
	virtual void OnRtnLimitClosePosition(long long HoldPositionID,const CXProcessResult *ProcResult) {};

	///限价单撤单回报信息推送
	///@param pRevokeLimitOrder：限价单撤单回报信息。
	//virtual void OnRtnRevokeLimitOrder(const TRevokeLimitOrderEvent *pRevokeLimitOrder) {};
	virtual void OnRtnRevokeLimitOrder(long long LimitOrderID,const CXProcessResult *ProcResult) {};

	///系统通知信息推送
	///@param pSysBulletin：系统通知信息。
	//virtual void OnRtnSysBulletin(const TSysBulletinEvent *pSysBulletin) {};
	virtual void OnRtnSysBulletin(const CXSysBulletinInfo *pSysBulletInfo) {};

	///用户登录回报
	///@param pszLoginAccount：账户。
	///@param errCode：出错信息。
	virtual void OnRspUserLogin(const char* pszLoginAccount, int errCode) {};

	///市价单开仓回报
	///@param pOnRspOpenMarketOrderField：市价单开仓结构。
	///@param errCode：出错信息。
	virtual void OnRspOpenMarketOrder(const CXOpenMarketOrderParam *pOnRspOpenMarketOrderField, int errCode) {};

	///市价单平仓回报
	///@param pOnRspCloseMarketOrderField：市价单平仓结构。
	///@param errCode：出错信息。
	virtual void OnRspCloseMarketOrder(const CXCloseMarketOrderParam *pOnRspCloseMarketOrderField, int errCode) {};

	///限价单开仓回报
	///@param pOnRspOpenLimitOrderField：限价单开仓结构。
	///@param errCode：出错信息。
	virtual void OnRspOpenLimitOrder(const CXOpenLimitOrderParam *pOnRspOpenLimitOrderField, int errCode) {};

	///限价单平仓回报
	///@param pOnRspCloseLimitOrderField：限价单平仓结构。
	///@param errCode：出错信息。
	virtual void OnRspLimitClosePosition(const CXCloseLimitOrderParam *pOnRspCloseLimitOrderField, int errCode) {};

	///撤单回报
	///@param pOnRspLimitRevokeField：撤单结构。
	///@param errCode：出错信息。
	virtual void OnRspLimitRevoke(const CXLimitRevokeParam *pOnRspLimitRevokeField, int errCode) {};

	///市价单批量平仓回报
	///@param pOnRspCloseMarketOrderManyField：市价单批量平仓结构。
	///@param errCode：出错信息。
	virtual void OnRspCloseMarketOrderMany(const CXCloseMarketOrderManyParam *pOnRspCloseMarketOrderManyField, int errCode) {};

	///查询账户信息回报
	///@param account：账户信息。
	///@param errCode：出错信息。
	virtual void OnRspQryAccountInfo(const CXAccountInfo *account, int errCode) {};

	///查询商品信息回报
	///@param vCommodity：商品信息。
	///@param errCode：出错信息。
	virtual void OnRspQryCommodity(std::vector<CXCommodityInfo> &vCommodity, int errCode) {};

	///查询持仓单信息回报
	///@param vHoldPosition：持仓单信息。
	///@param errCode：出错信息。
	virtual void OnRspQryPositionOrder(std::vector<CXHoldPositionInfo>& vHoldPosition, int errCode) {};

	///查询限价单信息回报
	///@param vLimitOrder：限价单信息。
	///@param errCode：出错信息。
	virtual void OnRspQryLimitOrder(std::vector<CXLimitOrderInfo>& vLimitOrder, int errCode) {};

	///查询平仓信息回报
	///@param vClosePosition：平仓信息。
	///@param errCode：出错信息。
	virtual void OnRspQryClosePosition(std::vector<CXClosePositionInfo>& vClosePosition, int errCode) {};

	///查询持仓单总量回报
	///@param vTotal：持仓单总量。
	///@param errCode：出错信息。
	virtual void OnRspQryHoldPositionTotal(std::vector<CXHoldPositionTotalInfo>& vTotal, int errCode) {};

	///查询市场开休市状态回报
	///@param nMarketStatus：市场开休市状态。 MARKET_STATUS_OPEN：0 MARKET_STATUS_CLOSE：1
	///@param errCode：出错信息。
	virtual void OnRspQryMarketStatus(int nMarketStatus, int errCode) {};

	///根据持仓单ID，获取持仓单信息回报
	///@param pHoldPosition：持仓单信息。
	///@param errCode：出错信息。
	virtual void OnRspQryHoldPositionByID(const CXHoldPositionInfo* pHoldPosition, int errCode) {};

	///根据限价单ID，获取限价单信息回报
	///@param pLimitOrder：限价单信息。
	///@param errCode：出错信息。
	virtual void OnRspQryLimitOrderByID(const CXLimitOrderInfo* pLimitOrder, int errCode) {};

	///根据平仓单ID，获取平仓信息回报
	///@param pClosePosition：平仓信息。
	///@param errCode：出错信息。
	virtual void OnRspQryClosePositionByID(const CXClosePositionInfo* pClosePosition, int errCode) {};

	///根据商品ID，获取持仓汇总信息回报
	///@param pTotal：持仓汇总信息。
	///@param errCode：出错信息。
	virtual void OnRspQryHoldPositionTotalByCommodityID(const CXHoldPositionTotalInfo* pTotal, int errCode) {};

	///根据商品ID，获取实时行情回报
	///@param quote：实时行情。
	///@param errCode：出错信息。
	virtual void OnRspQryCommodityQuote(const CXRealTimeQuote* quote, int errCode) {};

	///根据商品ID，获取其市价建仓的配置信息回报
	///@param pConf：市价建仓的配置信息。
	///@param errCode：出错信息。
	virtual void OnRspQryOpenMarketOrderConf(const CXOpenMarketOrderConf* pConf, int errCode) {};

	///根据商品ID，获取其限价建仓的配置信息回报
	///@param pConf：限价建仓的配置信息。
	///@param errCode：出错信息。
	virtual void OnRspQryOpenLimitOrderConf(const CXOpenLimitOrderConf* pConf, int errCode) {};

	///根据商品ID，获取其市价平仓的配置信息回报
	///@param pConf：市价平仓的配置信息。
	///@param errCode：出错信息。
	virtual void OnRspQryCloseMarketOrderConf(const CXCloseMarketOrderConf* pConf, int errCode) {};

	///根据商品ID，获取限价平仓的配置信息回报
	///@param pConf：限价平仓的配置信息。
	///@param errCode：出错信息。
	virtual void OnRspQryLimitClosePositionConf(const CXLimitClosePositionConf* pConf, int errCode) {};
};

class USER_API_EXPORT CTradeApi
{
public:
	///创建UserApi
	///@param pszFlowPath 存贮订阅信息文件的目录，默认为当前目录
	///@param pszUserApiType TradeApi类型
	///@return 创建出的TradeApi
	static CTradeApi *CreateTradeApi(const char *pszLogPath = "");

	///删除接口对象本身
	///@remark 不再使用本接口对象时,调用该函数删除接口对象
	virtual void Release() = 0;

	///初始化
	///@remark 初始化运行环境,只有调用后,接口才开始工作
	virtual int Init() = 0;

	///等待接口线程结束运行
	///@return 线程退出代码
	virtual int Join() = 0;

	///注册前置机网络地址
	///@param pszFrontAddress：前置机网络地址。
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
	virtual void RegisterFront(const char *pszFrontAddress,int port) = 0;

	///注册回调接口
	///@param pSpi 派生自回调接口类的实例
	virtual void RegisterSpi(CTradeSpi *pSpi) = 0;

	///设置程序参数
	///@param pszAppCode：应用交易码。
	///@param pszPassword：校验密码。
	///@param pszVendorID：会员ID。
	virtual void SetAppMessage( const char *pszAppCode,const char *pszPassword,const char *pszVendorID ) = 0;

	///用户登录请求
	///@param pszLoginAccount：登录账户。
	///@param pszPwd：登录密码。
	virtual int ReqUserLogin(char* pszLoginAccount, char* pszPwd) = 0;

	///市价单开仓请求
	///@param pReqOpenMarketOrderField：市价单开仓结构。 参见TradeStruct.h
	virtual int ReqOpenMarketOrder(CXOpenMarketOrderParam *pReqOpenMarketOrderField) = 0;

	///市价单平仓请求
	///@param pReqCloseMarketOrderField：市价单平仓结构。 参见TradeStruct.h
	virtual int ReqCloseMarketOrder(CXCloseMarketOrderParam *pReqCloseMarketOrderField) = 0;

	///限价单开仓请求
	///@param pReqOpenLimitOrderField：限价单开仓结构。 参见TradeStruct.h
	virtual int ReqOpenLimitOrder(CXOpenLimitOrderParam *pReqOpenLimitOrderField) = 0;

	///限价单平仓请求
	///@param pReqCloseLimitOrderField：限价单平仓结构。 参见TradeStruct.h
	virtual int ReqLimitClosePosition(CXCloseLimitOrderParam *pReqCloseLimitOrderField) = 0;

	///限价单撤单请求
	///@param pReqLimitRevokeField：限价单撤单结构。 参见TradeStruct.h
	virtual int ReqLimitRevoke(CXLimitRevokeParam *pReqLimitRevokeField) = 0;

	///批量平市价单请求
	///@param pReqCloseMarketOrderManyField：批量平市价单结构。 参见TradeStruct.h
	virtual int ReqCloseMarketOrderMany(CXCloseMarketOrderManyParam *pReqCloseMarketOrderManyField) = 0;

	///请求查询账户信息
	virtual int ReqQryAccountInfo() = 0;

	///请求查询商品信息
	virtual int ReqQryCommodity() = 0;

	///请求查询持仓单信息
	virtual int ReqQryPositionOrder() = 0;

	///请求查询限价单信息
	virtual int ReqQryLimitOrder() = 0;

	///请求查询平仓单信息
	virtual int ReqQryClosePosition() = 0;

	///请求查询持仓单总量
	virtual int ReqQryHoldPositionTotal() = 0;

	///请求查询市场状态
	virtual int ReqQryMarketStatus() = 0;

	///根据持仓单ID，获取持仓单信息
	///@param nHoldPositionID：持仓单ID。
	virtual int ReqQryHoldPositionByID(long long nHoldPositionID) = 0;

	///根据限价单ID，获取限价单信息
	///@param nLimitOrderID：限价单ID。
	virtual int ReqQryLimitOrderByID(long long nLimitOrderID) = 0;

	///根据平仓单ID，获取平仓信息
	///@param nClosePositionID：平仓单ID。
	virtual int ReqQryClosePositionByID(long long nClosePositionID) = 0;

	///根据商品ID，获取持仓汇总信息
	///@param nCommodityID：商品ID。
	///@param nOpenDirector：建仓方向ID。
	virtual int ReqQryHoldPositionTotalByCommodityID(int nCommodityID, int nOpenDirector) = 0;

	///根据商品ID，获取实时行情
	///@param nCommodityID：商品ID。
	virtual int ReqQryCommodityQuote(int CommoditID) = 0;

	///根据商品ID，获取其市价建仓的配置信息
	///@param nCommodityID：商品ID。
	virtual int ReqQryOpenMarketOrderConf(int CommodityID) = 0;

	///根据商品ID，获取其限价建仓的配置信息
	///@param nCommodityID：商品ID。
	virtual int ReqQryOpenLimitOrderConf(int CommodityID) = 0;

	///根据商品ID，获取其市价平仓的配置信息
	///@param nCommodityID：商品ID。
	virtual int ReqQryCloseMarketOrderConf(int CommodityID) = 0;

	///根据商品ID，获取限价平仓的配置信息
	///@param nCommodityID：商品ID。
	virtual int ReqQryLimitClosePositionConf(int CommodityID) = 0;

protected:
	virtual ~CTradeApi(){};
};
