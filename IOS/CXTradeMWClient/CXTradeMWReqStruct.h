//
//  CXTradeMWReqStuct.h
//  交易所请求代码和结构体
//
//  daokui.wang@gmail.com
//
//  Created by MagicStudio on 14-10-2.
//  Copyright 2014年 dhb.studio, All rights reserved.

#define Req_UserLogin              100
#define Req_OpenMarketOrder        101
#define Req_CloseMarketOrder       102
#define Req_OpenLimitOrder         103
#define Req_LimitClosePosition     104
#define Req_LimitRevoke            105
#define Req_CloseMarketOrderMany   106
#define ReqQry_AccountInfo         107
#define ReqQry_Commodity           108
#define ReqQry_MarketStatus        109
#define ReqQry_PositionOrder       110
#define ReqQry_LimitOrder          111
#define ReqQry_ClosePosition       112
#define ReqQry_HoldPositionTotal   113
#define ReqQry_HoldPositionByID    114
#define ReqQry_LimitOrderByID      115
#define ReqQry_ClosePositionByID   116
#define ReqQry_HoldPositionTotalByCommodityID  117
#define ReqQry_CommodityQuote          118
#define ReqQry_OpenMarketOrderConf     119
#define ReqQry_OpenLimitOrderConf      120
#define ReqQry_CloseMarketOrderConf    121
#define ReqQry_LimitClosePositionConf  122
#define Req_Close                 200



/// 市价单建仓
typedef struct CXOpenMarketOrderParam
{
	int nCommodityID;		///< 商品ID
	int nOpenDirector;		///< 建仓方向
	double dbPrice;			///< 建仓单价
	int nQuantity;			///< 建仓数量
	double dbTradeRange;	///< 交易范围
	int nOrderType;			///< 下单类型
} CXOpenMarketOrderParam;



/// 市价平仓单入参结构体
typedef struct CXCloseMarketOrderParam
{
	long long nHoldPositionID;		///< 持仓ID
	int nCommodityID;				///< 商品ID
	int nQuantity;					///< 平仓数量
	int nTradeRange;				///< 交易范围
	double dbPrice;					///< 持仓单价
	int nClosePositionType;			///< 平仓类型
} CXCloseMarketOrderParam;

/// 限价单建仓入参结构体
typedef struct CXOpenLimitOrderParam
{
	int nCommodityID;			///< 商品ID
	int nExpireType;			///< 过期类型
	int nOpenDirector;			///< 建仓方向
	int nQuantity;				///< 建仓数量
	int nOrderType;				///< 下单类型
	double dbOrderPrice;		///< 建仓单价
	double dbTPPrice;			///< 止盈价格
	double dbSLPrice;			///< 止损价格
} CXOpenLimitOrderParam;

/// 限价单平仓入参结构体
typedef struct CXCloseLimitOrderParam
{
	int nCommodityID;			///< 商品ID
	double dbClosePrice;		///< 平仓单价
	int nExpireType;			///< 过期类型
	long long nHoldPositionID;	///< 持仓ID
	int nOrderType;				///< 下单类型
	int nQuantity;				///< 平仓数量
	double dbSLPrice;			///< 止盈价格
	double dbTPPrice;			///< 止损价格
} CXCloseLimitOrderParam;

/// 限价单撤销入参结构体
typedef struct CXLimitRevokeParam
{
	long long nLimitOrderID;	///< 限价单ID
	int nCommodityID;			///< 商品ID
	int nOrderType;				///< 下单类型
	int nLimitType;				///< 限价单类型
} CXLimitRevokeParam;

/// 批量平仓入参结构体
typedef struct CXCloseMarketOrderManyParam
{
	int nCommodityID;			///< 商品ID
	int nQuantity;				///< 平仓数量
	int nTradeRange;			///< 交易范围
	double dbPrice;				///< 平仓价格
	int nClosePositionType;		///< 平仓类型
	int nCloseDirector;			///< 平仓方向
} CXCloseMarketOrderManyParam;

