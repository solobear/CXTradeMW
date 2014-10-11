#pragma once

#include <vector>

#define  CX_MAX_CUSTOMERNAME_LEN             128
#define  CX_MAX_COMMODITYNAME_LEN            128
#define  CX_MAX_COMMODITYCODE_LEN            16
#define  CX_MAX_COMMODITYTYPE_LEN            16
#define  CX_MAX_LOGINACCONT_LEN              32
#define  CX_MAX_MESSAGE_LEN                  512

#define  CX_MAX_BULLETIN_HEADER_LEN          128
#define  CX_MAX_BULLETIN_CONTENT_LEN         4000
#define  CX_MAX_PUBLISHERNAME_LEN            64

enum MARKET_STATUS
{
	CX_MARKET_STATUS_CLOSE = 0,
	CX_MARKET_STATUS_OPEN  = 1,
};

enum
{
	CX_MSG_STATUS_NO_UPDATE      = 1,
	CX_MSG_STATUS_UPDATED        = 2,
	CX_MSG_STATUS_NO_PERMISSION  = 3,
	CX_MSG_STATUS_NOT_EXIST      = 4,
	CX_MSG_STATUS_INIT_FAILED    = 5,
};

enum
{
	CX_LIMITTYPE_OPENLIMIT  = 1,
	CX_LIMITTYPE_SL_CLOSE   = 3,
	CX_LIMITTYPE_TP_CLOSE   = 2,
};

enum
{
	CX_OPENDIRECTOR_BUY    = 1,
	CX_OPENDIRFCTOR_SELL   = 2,
};

enum
{
	CX_INIT_MESSAGE_START  = 1,
	CX_INIT_MESSAGE_END    = 2,
};

/// 处理结果结构体
struct CXProcessResult
{
	int  RetCode;				///< 返回码
	char Message[CX_MAX_MESSAGE_LEN];		///< 返回信息
};

/// 实时行情结构体
struct CXRealTimeQuote
{
	int       CommodityID;	///< 商品ID
	double    SellPrice;	///< 卖出价
	double    BuyPrice;		///< 买入价
	double    HighPrice;	///< 最高价
	double    LowPrice;		///< 最低价
	long long QuoteTime;	///< 时刻点
};

/// 公告结构体
struct CXSysBulletinInfo
{
	int       LoginID;		///< 登录ID
	long long BulletinID;   ///< 公告ID
	int       TradeMode;		///< 交易模式
	int       BulletinType;		///< 公告类型
	int       BulletinPriorty;  ///< 优先级
	char      BulletinHeader[CX_MAX_BULLETIN_HEADER_LEN];		///< 公告消息头
	char      BulletinContent[CX_MAX_BULLETIN_CONTENT_LEN];		///< 公告消息正文
	char      PublisherName[CX_MAX_PUBLISHERNAME_LEN];		///< 发布方名
	int       BulletinMethod;		///< 公告方式
};

/// 市价单建仓
struct CXOpenMarketOrderParam
{
	int nCommodityID;		///< 商品ID
	int nOpenDirector;		///< 建仓方向
	double dbPrice;			///< 建仓单价
	int nQuantity;			///< 建仓数量
	double dbTradeRange;	///< 交易范围
	int nOrderType;			///< 下单类型
};

/// 市价平仓单入参结构体
struct CXCloseMarketOrderParam
{
	long long nHoldPositionID;		///< 持仓ID
	int nCommodityID;				///< 商品ID
	int nQuantity;					///< 平仓数量
	int nTradeRange;				///< 交易范围 允许的点差范围
	double dbPrice;					///< 平仓价格
	int nClosePositionType;			///< 平仓类型
};

/// 限价单建仓入参结构体
struct CXOpenLimitOrderParam
{
	int nCommodityID;			///< 商品ID
	int nExpireType;			///< 过期类型
	int nOpenDirector;			///< 建仓方向
	int nQuantity;				///< 建仓数量
	int nOrderType;				///< 下单类型
	double dbOrderPrice;		///< 建仓单价
	double dbTPPrice;			///< 止盈价格
	double dbSLPrice;			///< 止损价格
};

/// 限价单平仓入参结构体
struct CXCloseLimitOrderParam
{
	int nCommodityID;			///< 商品ID
	double dbClosePrice;		///< 平仓单价
	int nExpireType;			///< 过期类型
	long long nHoldPositionID;	///< 持仓ID
	int nOrderType;				///< 下单类型
	int nQuantity;				///< 平仓数量
	double dbSLPrice;			///< 止盈价格
	double dbTPPrice;			///< 止损价格
};

/// 限价单撤销入参结构体
struct CXLimitRevokeParam
{
	long long nLimitOrderID;	///< 限价单ID
	int nCommodityID;			///< 商品ID
	int nOrderType;				///< 下单类型
	int nLimitType;				///< 限价单类型
};

/// 批量平仓入参结构体
struct CXCloseMarketOrderManyParam
{
	int nCommodityID;			///< 商品ID
	int nQuantity;				///< 平仓数量
	int nTradeRange;			///< 交易范围
	double dbPrice;				///< 平仓价格
	int nClosePositionType;		///< 平仓类型
	int nCloseDirector;			///< 平仓方向
};

/// 账户信息结构体
struct CXAccountInfo
{
	char   Account[CX_MAX_LOGINACCONT_LEN];	///< 账户名
	char   LoginAccount[CX_MAX_LOGINACCONT_LEN];	///< 登录名
	char   CustomerName[CX_MAX_CUSTOMERNAME_LEN];	///< 客户名称
	double NAVPrice;            ///< 净值
	double Amount;              ///< 余额
	double OpenProfit;          ///< 浮动盈亏
	double ExchangeReserve;     ///< 交易准备金
	double PerformanceReserve;  ///< 履约准备金
	double FrozenReserve;       ///< 冻结准备金
	double RiskRate;            ///< 风险率
};

/// 商品信息结构体
struct CXCommodityInfo
{
	int       CommodityID;	///< 商品ID
	char      CommodityName[CX_MAX_COMMODITYNAME_LEN];		///< 商品名称
	long long CommodityRight;	///< 商品权限
	long long TradeRight;	///< 交易权限
	double    AgreeUnit;	///< 合约单位
	int       Currency;		///< 货币种类
	double    MinQuoteChangeUnit;	///< 最小行情变动单位
	double    MinPriceUnit;	///< 最小价格单位
	double    FixedSpread;	///< 固定点差
	double    BuyPrice;		///< 买入价
	double    SellPrice;	///< 卖出价
	double    HighPrice;	///< 最高价
	double    LowPrice;		///< 最低价
	long long QuoteTime;	///< 时刻点
};

/// 持仓单信息结构体
struct CXHoldPositionInfo
{
	long long HoldPositionID;	///< 持仓单ID
	int       CommodityID;		///< 商品ID
	char      CommodityName[CX_MAX_COMMODITYNAME_LEN];	///< 商品名称
	int       OpenType;			///< 建仓类型
	int       OpenDirector;		///< 建仓方向
	int       Quantity;			///< 持仓数量
	double    OpenPrice;		///< 建仓价格
	double    HoldPositionPrice;	///< 持仓价
	double    ClosePrice;		///< 平仓价
	long long SLLimitOrderID;	///< 止损单ID
	double    SLPrice;			///< 止损价
	long long TPLimitOrderID;	///< 止盈单ID
	double    TPPrice;			///< 止盈价
	double    OpenProfit;		///< 浮动盈亏
	double    CommissionAmount;	///< 佣金
	long long OpenDate;			///< 建仓时间
	double    AgreeMargin;		///< 履约保证金
	double    Freezemargin;		///< 冻结保证金
	double    OverdueFindFund;	///< 滞纳金
};

/// 限价单信息结构体
struct CXLimitOrderInfo
{
	long long LimitOrderID;		///< 限价单ID
	int       CommodityID;		///< 商品ID
	char      CommodityName[CX_MAX_COMMODITYNAME_LEN];		///< 商品名称
	int       LimitType;		///< 限价单类型
	int       OrderType;		///< 建仓类型
	int       OpenDirector;		///< 建仓方向
	double    OrderPrice;		///< 建仓价
	double    SLPrice;			///< 止损价
	double    TPPrice;			///< 止盈价
	int       OpenQuantity;		///< 持仓数量
	long long CreateDate;		///< 建仓时间
	long long ExpireType;		///< 失效类型
	long long UpdateDate;		///< 更新时间
	double    FreeszMargin;		///< 冻结保证金
};

/// 平仓单信息结构体
struct CXClosePositionInfo
{
	long long ClosePositionID;	///< 平仓单ID
	int       CommodityID;		///< 商品ID
	char      CommodityName[CX_MAX_COMMODITYNAME_LEN];	///< 商品名称
	int       CloseDirector;	///< 平仓方向
	double    OpenPrice;		///< 建仓价
	double    HoldPrice;		///< 持仓价
	double    ClosePrice;		///< 平仓价
	int       Quantity;			///< 持仓数量
	long long OpenPositionID;	///< 建仓单ID
	double    CommissionAmount;	///< 佣金
	long long OpenDate;			///< 建仓时间
	long long CloseDate;		///< 平仓时间
	int       MemberID;			///< 成员ID
	int       OpenType;			///< 建仓类型
	int       CloseType;		///< 平仓类型
};

/// 持仓汇总单信息结构体
struct CXHoldPositionTotalInfo
{
	int    CommodityID;			///< 商品ID
	char   CommodityName[CX_MAX_COMMODITYNAME_LEN];	///<  商品名称
	int    OpenDirector;		///< 建仓方向
	int    Quantity;			///< 持仓数量
	double OpenPriceTotal;		///< 建仓总值
	double AvgOpenPrice;		///< 建仓均价
	double HoldPriceTotal;		///< 持仓总值
	double AvgHoldPrice;		///< 持仓均价
	double ClosePrice;			///< 平仓价
	double OpenProfit;			///< 浮动盈亏
};

///  市价单建仓配置信息结构体
struct CXOpenMarketOrderConf
{
	int       CommodityID;		///< 商品ID
	double    MinQuantity;		///< 最大交易量
	double    MaxQuantity;		///< 最小交易量
};

/// 限价单建仓配置信息结构体
struct CXOpenLimitOrderConf
{
	int    CommodityID;			///< 商品ID
	double MinQuantity;			///< 最小交易量
	double MaxQuantity;			///< 最大交易量
	double LimitSpread;			///< 限价点差
	double FixSpread;			///< 固定点差
	double TPSpread;			///< 止盈点差
	double SLSpread;			///< 止损点差
	double MinPriceUnit;		///< 最小价格单位
	double AgreeUnit;			///< 合约单位
};

/// 市价单平仓配置信息结构体
struct CXCloseMarketOrderConf
{
	int       CommodityID;		///< 商品ID
	double    MinQuantity;		///< 最小交易量
	double    MaxQuantity;		///< 最大交易量
};

/// 限价单平仓配置信息结构体
struct CXLimitClosePositionConf
{
	int    CommodityID;			///< 商品ID
	double FixedSpread;			///< 固定点差
	double TPSpread;			///< 止盈点差
	double SLSpread;			///< 止损点差
	double MinPriceUnit;		///< 最小价格单位
	double AgreeUnit;			///< 合约单位
};
