//
//  CXTradeMWClientTests.m
//  CXTradeMWClientTests
//
//  Created by MagicStudio on 14-10-2.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#import "CXTradeMWClientTests.h"
#import "CXTradeSpiImpl.h"

// Test
@implementation CXTradeMWClientTests

- (void)setUp
{
    [super setUp];
    
    // 初始化
    client = [[CXTradeMWClient alloc] init];
    
    // 注册行情接口和回报Spi
    spi = [[CXTradeSpiImpl alloc] init];
    [client setSpi:spi];
    
    // 连接
    [client connect: @"182.254.133.20" andPort:7190];
}

- (void)tearDown
{
    // 断开连接
    [NSThread sleepForTimeInterval:3];
    NSLog(@"Exit...");
    [client close];
    NSLog(@"Done!");
    
    [super tearDown];
}

- (void)testExample
{   
    //登陆
    NSLog(@"Login...");
    [client login: @"003098765432103" andPassword:@"123456"];
    
    //登陆后等待者2秒
    [NSThread sleepForTimeInterval:2]; // sleep for login only
    
    //开始查询
    NSLog(@"Qry Commodity ...");
    [client reqQryCommodity];
}

@end
