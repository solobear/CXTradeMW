//
//  CXTradeMWSpi.h
//  CXTradeMWClient
//
//  Created by MagicStudio on 14-10-4.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

// 消息回传接口
@interface CXTradeMWSpi : NSObject

//此处为交易所回传的消息： 成交回报／行情信息等。
-(void) receiveJsonMessage : (NSString*) jsonMsg;

@end
