//
//  CXTradeMWClient.m
//  CXTradeMWClient
//
//  Created by MagicStudio on 14-10-2.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#import "CXTradeMWClient.h"
#import "JSONKit.h"

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


// Connect
-(void) connect:(NSString*) host andPort:(int)port{
    socket = [[CXTradeMWSocket alloc] init];
    [socket connect: host andPort:port];   
}

// Close
-(void) close{
    // Close 
    [socket sendCommand:Req_Close];
    
    // disConnect
    [socket disConnect];
}

// SendMsg


// Login
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
