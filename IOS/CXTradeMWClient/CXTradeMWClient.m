//
//  CXTradeMWClient.m
//  CXTradeMWClient
//
//  daokui.wang@gmail.com
//
//  Created by MagicStudio on 14-10-2.
//  Copyright 2014年 dhb.studio, All rights reserved.

#import "CXTradeMWClient.h"
#import "CXTradeMWReqStruct.h"
#import "JSONKit.h"
#import "JSONAutoSerializer.h"

// 中间件连接接口
@implementation CXTradeMWClient

//Init
- (id)init
{
    self = [super init];
    if (self) {
        //
    }
    
    return self;
}

// Register Spi
-(void) SetSpi:(CXTradeMWSpi*)spi{
    cxTradeSpi = spi;
}

// 连接中间件
-(void) Connect:(NSString*) host andPort:(int)port{
    socket = [[CXTradeMWSocket alloc] init];
    
    // Set Spi
    [socket SetSpiDelegate:cxTradeSpi];
    
    // Connect
    [socket Connect: host andPort:port];   
}

// 断开中间件连接
-(void) Close{
    // 发送退出交易请求
    [socket SendCommand:Req_Close];
    
    // 断开连接
    [socket DisConnect];
}


// CXTrade Call
///用户登录请求
///@param username：登录账户。
///@param password：登录密码。
-(void) Login:(NSString*) username andPassword:(NSString*)password{
    NSMutableDictionary *jsonDic = [NSMutableDictionary dictionary];
    [jsonDic setValue:username forKey:@"username"];
    [jsonDic setValue:password forKey:@"password"];
    NSString *jsonReq = [jsonDic JSONString];
    
    [socket SendCommand:Req_UserLogin andJsonReq:jsonReq];
}

///市价单开仓请求
///@param pReqOpenMarketOrderField：市价单开仓结构。 参见TradeStruct.h
-(void) ReqOpenMarketOrder:(CXOpenMarketOrderParam*) param{
    NSMutableDictionary *jsonDic = [NSMutableDictionary dictionary];
    [jsonDic setValue:[NSNumber numberWithInt:param->nCommodityID] forKey:@"nCommodityID"];
    [jsonDic setValue:[NSNumber numberWithInt:param->nOpenDirector] forKey:@"nOpenDirector"];
    [jsonDic setValue:[NSNumber numberWithDouble:param->dbPrice] forKey:@"dbPrice"];
    [jsonDic setValue:[NSNumber numberWithDouble:param->dbTradeRange] forKey:@"dbTradeRange"];
    [jsonDic setValue:[NSNumber numberWithInt:param->nQuantity] forKey:@"nQuantity"];
    [jsonDic setValue:[NSNumber numberWithInt:param->nOrderType] forKey:@"nOrderType"];
    NSString *jsonReq = [jsonDic JSONString];
    
    [socket SendCommand:Req_OpenMarketOrder andJsonReq:jsonReq];
}

///市价单平仓请求
///@param pReqCloseMarketOrderField：市价单平仓结构。 参见TradeStruct.h
-(void) ReqCloseMarketOrder:(CXCloseMarketOrderParam*)param{
    NSMutableDictionary *jsonDic = [NSMutableDictionary dictionary];
    [jsonDic setValue:[NSNumber numberWithInt:param->nCommodityID] forKey:@"nCommodityID"];
    [jsonDic setValue:[NSNumber numberWithLongLong:param->nHoldPositionID] forKey:@"nHoldPositionID"];
    [jsonDic setValue:[NSNumber numberWithDouble:param->dbPrice] forKey:@"dbPrice"];
    [jsonDic setValue:[NSNumber numberWithInt:param->nTradeRange] forKey:@"nTradeRange"];
    [jsonDic setValue:[NSNumber numberWithInt:param->nQuantity] forKey:@"nQuantity"];
    [jsonDic setValue:[NSNumber numberWithInt:param->nClosePositionType] forKey:@"nClosePositionType"];
    NSString *jsonReq = [jsonDic JSONString];
    
    [socket SendCommand:Req_CloseMarketOrder andJsonReq:jsonReq];
}

///限价单开仓请求
///@param pReqOpenLimitOrderField：限价单开仓结构。 参见TradeStruct.h
-(void) ReqOpenLimitOrder : (CXOpenLimitOrderParam*) param{
    NSMutableDictionary *jsonDic = [NSMutableDictionary dictionary];
    [jsonDic setValue:[NSNumber numberWithInt:param->nCommodityID] forKey:@"nCommodityID"];
    [jsonDic setValue:[NSNumber numberWithInt:param->nExpireType] forKey:@"nExpireType"];
    [jsonDic setValue:[NSNumber numberWithInt:param->nOpenDirector] forKey:@"nOpenDirector"];
    [jsonDic setValue:[NSNumber numberWithInt:param->nQuantity] forKey:@"nQuantity"];
    [jsonDic setValue:[NSNumber numberWithInt:param->nOrderType] forKey:@"nOrderType"];
    [jsonDic setValue:[NSNumber numberWithDouble:param->dbOrderPrice] forKey:@"dbOrderPrice"];
    [jsonDic setValue:[NSNumber numberWithDouble:param->dbTPPrice] forKey:@"dbTPPrice"];
    [jsonDic setValue:[NSNumber numberWithDouble:param->dbSLPrice] forKey:@"dbSLPrice"];
    NSString *jsonReq = [jsonDic JSONString];
    
    [socket SendCommand:Req_OpenLimitOrder andJsonReq:jsonReq];
}

///限价单平仓请求
///@param pReqCloseLimitOrderField：限价单平仓结构。 参见TradeStruct.h
-(void) ReqLimitClosePosition: (CXCloseLimitOrderParam*) param{
    NSMutableDictionary *jsonDic = [NSMutableDictionary dictionary];
    [jsonDic setValue:[NSNumber numberWithInt:param->nCommodityID] forKey:@"nCommodityID"];
    [jsonDic setValue:[NSNumber numberWithLongLong:param->nHoldPositionID] forKey:@"nHoldPositionID"];
    [jsonDic setValue:[NSNumber numberWithInt:param->nOrderType] forKey:@"nOrderType"];
    [jsonDic setValue:[NSNumber numberWithInt:param->nQuantity] forKey:@"nQuantity"];
    [jsonDic setValue:[NSNumber numberWithInt:param->nExpireType] forKey:@"nExpireType"];
    [jsonDic setValue:[NSNumber numberWithDouble:param->dbClosePrice] forKey:@"dbClosePrice"];
    [jsonDic setValue:[NSNumber numberWithDouble:param->dbSLPrice] forKey:@"dbSLPrice"];
    [jsonDic setValue:[NSNumber numberWithDouble:param->dbTPPrice] forKey:@"dbTPPrice"];
    NSString *jsonReq = [jsonDic JSONString];
    
    [socket SendCommand:Req_LimitClosePosition andJsonReq:jsonReq];
}

///限价单撤单请求
///@param pReqLimitRevokeField：限价单撤单结构。 参见TradeStruct.h
-(void) ReqLimitRevoke:(CXLimitRevokeParam*) param{
    NSMutableDictionary *jsonDic = [NSMutableDictionary dictionary];
    [jsonDic setValue:[NSNumber numberWithInt:param->nCommodityID] forKey:@"nCommodityID"];
    [jsonDic setValue:[NSNumber numberWithLongLong:param->nLimitOrderID] forKey:@"nLimitOrderID"];
    [jsonDic setValue:[NSNumber numberWithInt:param->nOrderType] forKey:@"nOrderType"];
    [jsonDic setValue:[NSNumber numberWithInt:param->nLimitType] forKey:@"nLimitType"];
    NSString *jsonReq = [jsonDic JSONString];
    
    [socket SendCommand:Req_LimitRevoke andJsonReq:jsonReq];
}

///批量平市价单请求
///@param pReqCloseMarketOrderManyField：批量平市价单结构。 参见TradeStruct.h
-(void) ReqCloseMarketOrderMany : (CXCloseMarketOrderManyParam*) param{
    NSMutableDictionary *jsonDic = [NSMutableDictionary dictionary];
    [jsonDic setValue:[NSNumber numberWithInt:param->nCommodityID] forKey:@"nCommodityID"];
    [jsonDic setValue:[NSNumber numberWithInt:param->nQuantity] forKey:@"nQuantity"];
    [jsonDic setValue:[NSNumber numberWithInt:param->nTradeRange] forKey:@"nTradeRange"];
        [jsonDic setValue:[NSNumber numberWithInt:param->nClosePositionType] forKey:@"nClosePositionType"];
        [jsonDic setValue:[NSNumber numberWithInt:param->nTradeRange] forKey:@"nTradeRange"];
    [jsonDic setValue:[NSNumber numberWithDouble:param->nCloseDirector] forKey:@"nCloseDirector"];
    NSString *jsonReq = [jsonDic JSONString];
    
    [socket SendCommand:Req_CloseMarketOrderMany andJsonReq:jsonReq];
}

///请求查询账户信息
-(void) ReqQryAccountInfo{
        [socket SendCommand:ReqQry_AccountInfo];
}

///请求查询商品信息
-(void) ReqQryCommodity{
    [socket SendCommand:ReqQry_Commodity];
}

///请求查询持仓单信息
-(void) ReqQryPositionOrder {
        [socket SendCommand:ReqQry_PositionOrder];
}

///请求查询限价单信息
-(void) ReqQryLimitOrder{
        [socket SendCommand:ReqQry_LimitOrder];
}

///请求查询平仓单信息
-(void) ReqQryClosePosition{
        [socket SendCommand:ReqQry_ClosePosition];
}

///请求查询持仓单总量
-(void) ReqQryHoldPositionTotal {
        [socket SendCommand:ReqQry_HoldPositionTotal];
}

///请求查询市场状态
-(void) ReqQryMarketStatus {
        [socket SendCommand:ReqQry_MarketStatus];
}

///根据持仓单ID，获取持仓单信息
///@param nHoldPositionID：持仓单ID。
-(void) ReqQryHoldPositionByID:(long long) nHoldPositionID{
    NSMutableDictionary *jsonDic = [NSMutableDictionary dictionary];
    [jsonDic setValue:[NSNumber numberWithLongLong:nHoldPositionID] forKey:@"nHoldPositionID"];
    NSString *jsonReq = [jsonDic JSONString];
    
    [socket SendCommand:ReqQry_HoldPositionByID andJsonReq:jsonReq];
}

///根据限价单ID，获取限价单信息
///@param nLimitOrderID：限价单ID。
-(void) ReqQryLimitOrderByID:(long long) nLimitOrderID{
    NSMutableDictionary *jsonDic = [NSMutableDictionary dictionary];
    [jsonDic setValue:[NSNumber numberWithLongLong:nLimitOrderID] forKey:@"nLimitOrderID"];
    NSString *jsonReq = [jsonDic JSONString];
    
    [socket SendCommand:ReqQry_LimitOrderByID andJsonReq:jsonReq];
}

///根据平仓单ID，获取平仓信息
///@param nClosePositionID：平仓单ID。
-(void) ReqQryClosePositionByID: (long long) nClosePositionID{
    NSMutableDictionary *jsonDic = [NSMutableDictionary dictionary];
    [jsonDic setValue:[NSNumber numberWithLongLong:nClosePositionID] forKey:@"nClosePositionID"];
    NSString *jsonReq = [jsonDic JSONString];
    
    [socket SendCommand:ReqQry_ClosePositionByID andJsonReq:jsonReq];
}

///根据商品ID，获取持仓汇总信息
///@param nCommodityID：商品ID。
///@param nOpenDirector：建仓方向ID。
-(void) ReqQryHoldPositionTotalByCommodityID:(int) nCommodityID andOpenDirector:(int) nOpenDirector{
    NSMutableDictionary *jsonDic = [NSMutableDictionary dictionary];
    [jsonDic setValue:[NSNumber numberWithInt:nCommodityID] forKey:@"nCommodityID"];
        [jsonDic setValue:[NSNumber numberWithInt:nOpenDirector] forKey:@"nOpenDirector"];
    NSString *jsonReq = [jsonDic JSONString];
    
    [socket SendCommand:ReqQry_HoldPositionTotalByCommodityID andJsonReq:jsonReq];
}

///根据商品ID，获取实时行情
///@param nCommodityID：商品ID。
-(void) ReqQryCommodityQuote:(int) nCommodityID{
    NSMutableDictionary *jsonDic = [NSMutableDictionary dictionary];
    [jsonDic setValue:[NSNumber numberWithInt:nCommodityID] forKey:@"nCommodityID"];
    NSString *jsonReq = [jsonDic JSONString];
    
    [socket SendCommand:ReqQry_CommodityQuote andJsonReq:jsonReq];
}

///根据商品ID，获取其市价建仓的配置信息
///@param nCommodityID：商品ID。
-(void) ReqQryOpenMarketOrderConf:(int) nCommodityID{
    NSMutableDictionary *jsonDic = [NSMutableDictionary dictionary];
    [jsonDic setValue:[NSNumber numberWithInt:nCommodityID] forKey:@"nCommodityID"];
    NSString *jsonReq = [jsonDic JSONString];
    
    [socket SendCommand:ReqQry_OpenMarketOrderConf andJsonReq:jsonReq];
}

///根据商品ID，获取其限价建仓的配置信息
///@param nCommodityID：商品ID。
-(void) ReqQryOpenLimitOrderConf:(int) nCommodityID{
    NSMutableDictionary *jsonDic = [NSMutableDictionary dictionary];
    [jsonDic setValue:[NSNumber numberWithInt:nCommodityID] forKey:@"nCommodityID"];
    NSString *jsonReq = [jsonDic JSONString];
    
    [socket SendCommand:ReqQry_OpenLimitOrderConf andJsonReq:jsonReq];
}

///根据商品ID，获取其市价平仓的配置信息
///@param nCommodityID：商品ID。
-(void) ReqQryCloseMarketOrderConf:(int) nCommodityID{
    NSMutableDictionary *jsonDic = [NSMutableDictionary dictionary];
    [jsonDic setValue:[NSNumber numberWithInt:nCommodityID] forKey:@"nCommodityID"];
    NSString *jsonReq = [jsonDic JSONString];
    
    [socket SendCommand:ReqQry_CloseMarketOrderConf andJsonReq:jsonReq];
}

///根据商品ID，获取限价平仓的配置信息
///@param nCommodityID：商品ID。
-(void) ReqQryLimitClosePositionConf:(int) nCommodityID{
    NSMutableDictionary *jsonDic = [NSMutableDictionary dictionary];
    [jsonDic setValue:[NSNumber numberWithInt:nCommodityID] forKey:@"nCommodityID"];
    NSString *jsonReq = [jsonDic JSONString];
    
    [socket SendCommand:ReqQry_LimitClosePositionConf andJsonReq:jsonReq];
}


@end
