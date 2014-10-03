//
//  CXTradeMWSocket.m
//  CXTradeMWClient
//
//  Created by MagicStudio on 14-10-2.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#import "CXTradeMWSocket.h"
#import "JSONKit.h"

//中间件Socket连接，不可直接调用。
@implementation CXTradeMWSocket

- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}


//调用此接口与socket连接
-(void) connect:(NSString*) host andPort:(int)port{  
    CFReadStreamRef readStream;
    CFWriteStreamRef writeStream;
    
    // 连接
    CFStreamCreatePairWithSocketToHost(kCFAllocatorDefault, (CFStringRef)host, port, &readStream, &writeStream);
    inputStream = (NSInputStream *)readStream; // 输入流
    outputStream = (NSOutputStream *)writeStream; // 输出流
    
    // 启动线程
    NSThread* backgroundThread = [[NSThread alloc] initWithTarget:self selector:@selector(startStreamThread) object:nil];
    [backgroundThread start];
    
    // Log
    NSLog(@"Connectting...");
}



//启动单独的线程处理输入流
- (void)startStreamThread{
    // 输入流
    [inputStream setDelegate:self];
    [inputStream scheduleInRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    [inputStream open];  
    
    // 输出流
    [outputStream setDelegate:self];
    [outputStream scheduleInRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    [outputStream open];
    
    // 启动线程
    [[NSRunLoop currentRunLoop] run];
}



//调用此接口与socket断开连接
- (void)disConnect{
    if (inputStream){
        [inputStream close];
        inputStream = nil;
    }
    
    if (outputStream){
        [outputStream close];
        outputStream = nil;
    }
}



//发送命令给Server
- (void)sendCommand:(int)commandID {
    [self sendCommand: commandID andJsonReq:nil];    
}


//发送命令给Server
- (void)sendCommand:(int)commandID andJsonReq:(NSString *)jsonReq {
    while (true) {
        if ([outputStream hasSpaceAvailable]){
            NSMutableDictionary *jsonDic = [NSMutableDictionary dictionary];
            [jsonDic setObject:[NSNumber numberWithInt:commandID] forKey:@"commandID"];
            if(jsonReq!=nil){
                [jsonDic setObject:jsonReq forKey:@"jsonParams"];
            }
            NSString *jsonReqMsg = [jsonDic JSONString];
            
            //
            NSData *data = [[NSData alloc] initWithData:[jsonReqMsg dataUsingEncoding:NSUTF8StringEncoding]];
            [outputStream write:[data bytes] maxLength:[data length]];
            NSLog(@"Write command to MW: %@", jsonReqMsg);
            break;
        }
    }
}




//Socket回调，可以知道Socket的连接状态，收到Server端发来的数据等
- (void)stream:(NSStream *)theStream handleEvent:(NSStreamEvent)streamEvent {
    
    //NSLog(@"Stream event: %i", streamEvent);  
    
    switch (streamEvent) {
        case NSStreamEventHasBytesAvailable:
            if (theStream == inputStream) {
                uint8_t buffer[4096];
                int len;
                
                while ([inputStream hasBytesAvailable]) {
                    len = [inputStream read:buffer maxLength:sizeof(buffer)];
                    
                    if (len > 0) {
                        NSStringEncoding enc = CFStringConvertEncodingToNSStringEncoding(kCFStringEncodingGB_18030_2000);
                        NSString *output = [[NSString alloc] initWithBytes:buffer length:len encoding:enc];
                        if (nil != output) {
                            NSLog(@"返回: %@", output);
                            //[self notifyNewMessage:output];
                        }
                        [output release];    
                    }
                }
            }
            break;
        case NSStreamEventOpenCompleted:
            break;
        case NSStreamEventErrorOccurred:
            NSLog(@"Can not connect to the host!");
            [self cleanUpStream:theStream];
            break;
        case NSStreamEventEndEncountered:
            NSLog(@"Closing stream...");
            [self cleanUpStream:theStream];
            break;
        default:
            break;
    }
}

// CleanUp
- (void)cleanUpStream:(NSStream *)stream
{
    [stream removeFromRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    [stream close];
    stream = nil;
}

@end
