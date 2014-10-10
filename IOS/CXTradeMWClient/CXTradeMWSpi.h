//
//  CXTradeMWSpi.h
//
//  daokui.wang@gmail.com
//
//  Created by MagicStudio on 14-10-2.
//  Copyright 2014年 dhb.studio, All rights reserved.

#import <Foundation/Foundation.h>

// 消息回传接口
@interface CXTradeMWSpi : NSObject

// 连接结果
-(void) ConnectionResult : (Boolean) success;

//此处为交易所回传的消息： 成交回报／行情信息等。
-(void) ReceiveJsonMessage : (NSString*) jsonMsg;

@end
