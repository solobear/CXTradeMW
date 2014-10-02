//
//  CXTradeMWClientTests.m
//  CXTradeMWClientTests
//
//  Created by MagicStudio on 14-10-2.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#import "CXTradeMWClientTests.h"
#import "CXTradeMWSocket.h"

@implementation CXTradeMWClientTests

- (void)setUp
{
    [super setUp];
    
    // Set-up code here.
    socket = [[CXTradeMWSocket alloc] init];
    [socket connect];
}

- (void)tearDown
{
    // Tear-down code here.
    [socket disConnect];
    NSLog(@"Exit...");
    
    [super tearDown];
}

- (void)testExample
{
    
    NSLog(@"Testing...");
    [socket sendCommand:@"{\"ID\":\"Eric\"}"];
    
    [NSThread sleepForTimeInterval:6];
}

@end
