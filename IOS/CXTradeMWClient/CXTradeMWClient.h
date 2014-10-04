//
//  CXTradeMWClient.h
//  CXTradeMWClient
//
//  Created by MagicStudio on 14-10-2.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CXTradeMWSocket.h"
#import "CXTradeMWSpi.h"

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


//
@interface CXTradeMWClient : NSObject{
    CXTradeMWSocket* socket;
    CXTradeMWSpi* cxTradeSpi;
}

// Register
-(void) setSpi:(CXTradeMWSpi*)spi;

// Connect
-(void) connect:(NSString*) host andPort:(int)port;
-(void) close;

// CXTrade Call

	///用户登录请求
	///@param pszLoginAccount：登录账户。
	///@param pszPwd：登录密码。
	-(void) ReqUserLogin:(NSString*) username andPassword:(NSString*)password;

	///市价单开仓请求
	///@param pReqOpenMarketOrderField：市价单开仓结构。 参见TradeStruct.h
	-(void) ReqOpenMarketOrder:(CXOpenMarketOrderParam *)pReqOpenMarketOrderField;

	///市价单平仓请求
	///@param pReqCloseMarketOrderField：市价单平仓结构。 参见TradeStruct.h
	-(void) ReqCloseMarketOrder:(CXCloseMarketOrderParam *)pReqCloseMarketOrderField;

	///限价单开仓请求
	///@param pReqOpenLimitOrderField：限价单开仓结构。 参见TradeStruct.h
	-(void) ReqOpenLimitOrder : (CXOpenLimitOrderParam *) pReqOpenLimitOrderField;

	///限价单平仓请求
	///@param pReqCloseLimitOrderField：限价单平仓结构。 参见TradeStruct.h
	-(void) ReqLimitClosePosition: (CXCloseLimitOrderParam * ) pReqCloseLimitOrderField;

	///限价单撤单请求
	///@param pReqLimitRevokeField：限价单撤单结构。 参见TradeStruct.h
	-(void) ReqLimitRevoke:(CXLimitRevokeParam *) pReqLimitRevokeField;

	///批量平市价单请求
	///@param pReqCloseMarketOrderManyField：批量平市价单结构。 参见TradeStruct.h
	-(void) ReqCloseMarketOrderMany : (CXCloseMarketOrderManyParam*) pReqCloseMarketOrderManyField;

	///请求查询账户信息
	-(void) ReqQryAccountInfo ;

	///请求查询商品信息
	-(void) ReqQryCommodity ;

	///请求查询持仓单信息
	-(void) ReqQryPositionOrder ;

	///请求查询限价单信息
	-(void) ReqQryLimitOrder ;

	///请求查询平仓单信息
	-(void) ReqQryClosePosition ;

	///请求查询持仓单总量
	-(void) ReqQryHoldPositionTotal ;

	///请求查询市场状态
	-(void) ReqQryMarketStatus ;

	///根据持仓单ID，获取持仓单信息
	///@param nHoldPositionID：持仓单ID。
	-(void) ReqQryHoldPositionByID:(long long) nHoldPositionID;

	///根据限价单ID，获取限价单信息
	///@param nLimitOrderID：限价单ID。
	-(void) ReqQryLimitOrderByID:(long long) nLimitOrderID;

	///根据平仓单ID，获取平仓信息
	///@param nClosePositionID：平仓单ID。
	-(void) ReqQryClosePositionByID: (long long) nClosePositionID;

	///根据商品ID，获取持仓汇总信息
	///@param nCommodityID：商品ID。
	///@param nOpenDirector：建仓方向ID。
	-(void) ReqQryHoldPositionTotalByCommodityID:(int) nCommodityID andOpenDirector:(int) nOpenDirector;

	///根据商品ID，获取实时行情
	///@param nCommodityID：商品ID。
	-(void) ReqQryCommodityQuote:(int) CommoditID;

	///根据商品ID，获取其市价建仓的配置信息
	///@param nCommodityID：商品ID。
	-(void) ReqQryOpenMarketOrderConf:(int) CommodityID;

	///根据商品ID，获取其限价建仓的配置信息
	///@param nCommodityID：商品ID。
	-(void) ReqQryOpenLimitOrderConf:(int) CommodityID;

	///根据商品ID，获取其市价平仓的配置信息
	///@param nCommodityID：商品ID。
	-(void) ReqQryCloseMarketOrderConf:(int) CommodityID;

	///根据商品ID，获取限价平仓的配置信息
	///@param nCommodityID：商品ID。
	-(void) ReqQryLimitClosePositionConf:(int) CommodityID;

@end
