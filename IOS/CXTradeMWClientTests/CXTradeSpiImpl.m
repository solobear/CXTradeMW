//
//  CXTradeSpiImpl.m
//  CXTradeMWClient
//
//  Created by MagicStudio on 14-10-4.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#import "CXTradeSpiImpl.h"

// 消息回传接口
@implementation CXTradeSpiImpl

//此处为交易所回传的消息： 成交回报／行情信息等。
-(void) receiveJsonMessage : (NSString*) jsonMsg{
    
    //此处为交易所回传的消息： 成交回报／行情信息等。
    //请自行处理，此方法可自行编写。
    
    NSLog(@"[返回]: %@", jsonMsg);
}

@end
