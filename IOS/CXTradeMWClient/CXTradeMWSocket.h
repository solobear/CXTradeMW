//
//  CXTradeMWSocket.h
//  CXTradeMWClient
//
//  daokui.wang@gmail.com
//
//  Created by MagicStudio on 14-10-2.
//  Copyright 2014年 dhb.studio, All rights reserved.

#import <Foundation/Foundation.h>
#import "CXTradeMWSpi.h"

@interface CXTradeMWSocket : NSObject<NSStreamDelegate>{
    CXTradeMWSpi* spi;
    
    NSInputStream *inputStream;
    NSOutputStream *outputStream;
    
    NSThread* backgroundThread;
    
    NSStringEncoding ENC;
}


// Delegate
- (void)SetSpiDelegate:(CXTradeMWSpi*) mwSpi;

// Connect
- (void)StartStreamThread;
- (void)Connect:(NSString*) host andPort:(int)port;
- (void)DisConnect;

// 发送命令给Server
- (void)SendCommand:(int)commandID andJsonReq:(NSString *)jsonReq; 
- (void)SendCommand:(int)commandID;

// CleanUP
- (void)CleanUpStream:(NSStream *)stream;

@end
