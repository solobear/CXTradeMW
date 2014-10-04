//
//  CXTradeSpiImpl.m
//  CXTradeMWClient
//
//  daokui.wang@gmail.com
//
//  Created by MagicStudio on 14-10-2.
//  Copyright 2014年 dhb.studio, All rights reserved.

#import "CXTradeSpiImpl.h"
#import "CXTradeMWRespStruct.h"
#import "JSONKit.h"

// 消息回传接口
@implementation CXTradeSpiImpl

//此处为交易所回传的消息： 成交回报／行情信息等。
-(void) ReceiveJsonMessage : (NSString*) jsonMsg{
    
    //此处为交易所回传的消息: 成交回报／行情信息等。
    //请自行处理，此方法可自行编写。
    NSLog(@"[返回]: %@", jsonMsg);
    
    NSDictionary *data = [jsonMsg objectFromJSONString];
    NSLog(@"json.respID:%@", [data objectForKey:@"respID"]);        //返回代码编号
    NSLog(@"json.respDesc:%@", [data objectForKey:@"respDesc"]);    //Description
    NSLog(@"json.respErr:%@", [data objectForKey:@"respErr"]);      //Error Code, can be NULL
    NSLog(@"json.respJsons:%@", [data objectForKey:@"respJsons"]);  // 该内容需要二次解析。
    
    
}

@end
