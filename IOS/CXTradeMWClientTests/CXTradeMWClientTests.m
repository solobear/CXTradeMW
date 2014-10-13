//
//  CXTradeMWClientTests.m
//  CXTradeMWClientTests
//
//  daokui.wang@gmail.com
//
//  Created by MagicStudio on 14-10-2.
//  Copyright 2014年 dhb.studio, All rights reserved.


#import "CXTradeMWClientTests.h"
#import "CXTradeSpiImpl.h"
#import "CXTradeMWReqStruct.h"

// Test
@implementation CXTradeMWClientTests

- (void)setUp
{
    [super setUp];
    
    // 初始化
    client = [[CXTradeMWClient alloc] init];
    
    // 注册行情接口和回报Spi
    spi = [[CXTradeSpiImpl alloc] init];
    [client SetSpi:spi];
    
    // 连接
    [client Connect: @"182.254.133.20" andPort:7190];
    
    [NSThread sleepForTimeInterval:2]; 
}

- (void)tearDown
{
    // 断开连接
    [NSThread sleepForTimeInterval:3];
    NSLog(@"Exit...");
    [client Close];
    NSLog(@"Done!");
    
    [super tearDown];
}

- (void)testExample
{   
    //登陆
    NSLog(@"Login...");
    [client Login: @"003098765432109" andPassword:@"123456"];
    
    //开始查询
    [NSThread sleepForTimeInterval:5]; 
    NSLog(@"Qry Commodity ...");
    [client ReqQryCommodity];
    
    [NSThread sleepForTimeInterval:3]; 
    NSLog(@"Qry MarketStatus ...");
    [client ReqQryMarketStatus];
    
    // 
    [NSThread sleepForTimeInterval:10]; 
    CXOpenMarketOrderParam omop = {
        .nQuantity = 1,
        .nOrderType = 1,
        .nOpenDirector = 0,
        .nCommodityID = 1,
        .dbPrice = 112.10,
        .dbTradeRange = 112.20
    };
    //[client ReqOpenMarketOrder:&omop];
}

@end
