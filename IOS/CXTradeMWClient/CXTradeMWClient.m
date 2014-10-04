//
//  CXTradeMWClient.m
//  CXTradeMWClient
//
//  Created by MagicStudio on 14-10-2.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#import "CXTradeMWClient.h"
#import "JSONKit.h"

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
-(void) setSpi:(CXTradeMWSpi*)spi{
    cxTradeSpi = spi;
}

// 连接中间件
-(void) connect:(NSString*) host andPort:(int)port{
    socket = [[CXTradeMWSocket alloc] init];
    
    // Set Spi
    [socket setSpiDelegate:cxTradeSpi];
    
    // Connect
    [socket connect: host andPort:port];   
}

// 断开中间件连接
-(void) close{
    // 发送退出交易请求
    [socket sendCommand:Req_Close];
    
    // 断开连接
    [socket disConnect];
}


// 登陆
-(void) login:(NSString*) username andPassword:(NSString*)password{
    NSMutableDictionary *jsonDic = [NSMutableDictionary dictionary];
    [jsonDic setObject:username forKey:@"username"];
    [jsonDic setObject:password forKey:@"password"];
    NSString *jsonReq = [jsonDic JSONString];
    
    [socket sendCommand:Req_UserLogin andJsonReq:jsonReq];
}

// Req QryCommodity
-(void) reqQryCommodity{
    [socket sendCommand:ReqQry_Commodity];
}

@end
