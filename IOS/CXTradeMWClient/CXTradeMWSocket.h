//
//  CXTradeMWSocket.h
//  CXTradeMWClient
//
//  Created by MagicStudio on 14-10-2.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//  

#import <Foundation/Foundation.h>

@interface CXTradeMWSocket : NSObject<NSStreamDelegate>{
    NSInputStream *inputStream;
    NSOutputStream *outputStream;
}

- (void)connect:(NSString*) host andPort:(int)port;
- (void)disConnect;

- (BOOL)sendCommand:(NSString *)jsonMsg;  //发送命令给Server

@end
