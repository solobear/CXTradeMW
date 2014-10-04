//
//  CXTradeMWClient.h
//  CXTradeMWClient
//
//  daokui.wang@gmail.com
//
//  Created by MagicStudio on 14-10-2.
//  Copyright 2014年 dhb.studio, All rights reserved.

#import <Foundation/Foundation.h>
#import "CXTradeMWSocket.h"
#import "CXTradeMWSpi.h"
#import "CXTradeMWReqStruct.h"


// MW Client
@interface CXTradeMWClient : NSObject{
    CXTradeMWSocket* socket;
    CXTradeMWSpi* cxTradeSpi;
}

// Register
-(void) SetSpi:(CXTradeMWSpi*)spi;

// Connect
-(void) Connect:(NSString*) host andPort:(int)port;
-(void) Close;


// CXTrade Call
///用户登录请求
///@param pszLoginAccount：登录账户。
///@param pszPwd：登录密码。
-(void) Login:(NSString*) username andPassword:(NSString*)password;

///市价单开仓请求
///@param pReqOpenMarketOrderField：市价单开仓结构。 参见TradeStruct.h
-(void) ReqOpenMarketOrder:(CXOpenMarketOrderParam*)pReqOpenMarketOrderField;

///市价单平仓请求
///@param pReqCloseMarketOrderField：市价单平仓结构。 参见TradeStruct.h
-(void) ReqCloseMarketOrder:(CXCloseMarketOrderParam*)pReqCloseMarketOrderField;

///限价单开仓请求
///@param pReqOpenLimitOrderField：限价单开仓结构。 参见TradeStruct.h
-(void) ReqOpenLimitOrder : (CXOpenLimitOrderParam*) pReqOpenLimitOrderField;

///限价单平仓请求
///@param pReqCloseLimitOrderField：限价单平仓结构。 参见TradeStruct.h
-(void) ReqLimitClosePosition: (CXCloseLimitOrderParam*) pReqCloseLimitOrderField;

///限价单撤单请求
///@param pReqLimitRevokeField：限价单撤单结构。 参见TradeStruct.h
-(void) ReqLimitRevoke:(CXLimitRevokeParam*) pReqLimitRevokeField;

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
-(void) ReqQryCommodityQuote:(int) nCommodityID;

///根据商品ID，获取其市价建仓的配置信息
///@param nCommodityID：商品ID。
-(void) ReqQryOpenMarketOrderConf:(int) nCommodityID;

///根据商品ID，获取其限价建仓的配置信息
///@param nCommodityID：商品ID。
-(void) ReqQryOpenLimitOrderConf:(int) nCommodityID;

///根据商品ID，获取其市价平仓的配置信息
///@param nCommodityID：商品ID。
-(void) ReqQryCloseMarketOrderConf:(int) nCommodityID;

///根据商品ID，获取限价平仓的配置信息
///@param nCommodityID：商品ID。
-(void) ReqQryLimitClosePositionConf:(int) nCommodityID;

@end
