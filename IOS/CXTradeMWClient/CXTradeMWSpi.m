//
//  CXTradeMWSpi.m
//  CXTradeMWClient
//
//  Created by MagicStudio on 14-10-4.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#import "CXTradeMWSpi.h"

// 消息回传接口
@implementation CXTradeMWSpi

// 连接结果
-(void) ConnectionResult : (Boolean) success{
    
}

//此处为交易所回传的消息： 成交回报／行情信息等。
-(void) ReceiveJsonMessage : (NSString*) jsonMsg{
     NSLog(@"返回: %@", jsonMsg);
}

@end
