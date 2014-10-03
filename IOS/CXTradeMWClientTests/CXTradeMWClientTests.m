//
//  CXTradeMWClientTests.m
//  CXTradeMWClientTests
//
//  Created by MagicStudio on 14-10-2.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#import "CXTradeMWClientTests.h"

@implementation CXTradeMWClientTests

- (void)setUp
{
    [super setUp];
    
    // Set-up code here.
    client = [[CXTradeMWClient alloc] init];
    [client connect: @"182.254.133.20" andPort:7190];
}

- (void)tearDown
{
    // Tear-down code here.
    [NSThread sleepForTimeInterval:10];
    
    NSLog(@"Exit...");
    [client close];
    
    NSLog(@"Done!");
    [super tearDown];
}

- (void)testExample
{
    
    NSLog(@"Login...");
    [client login: @"003098765432103" andPassword:@"123456"];
    
    [NSThread sleepForTimeInterval:4];
    NSLog(@"Qry Commodity ...");
    [client reqQryCommodity];
}

@end
