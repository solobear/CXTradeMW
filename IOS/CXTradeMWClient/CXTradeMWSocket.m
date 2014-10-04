//
//  CXTradeMWSocket.m
//  CXTradeMWClient
//
//  daokui.wang@gmail.com
//
//  Created by MagicStudio on 14-10-2.
//  Copyright 2014年 dhb.studio, All rights reserved.

#import "CXTradeMWSocket.h"
#import "JSONKit.h"

//中间件Socket连接，不可直接调用。
@implementation CXTradeMWSocket

- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
        ENC = CFStringConvertEncodingToNSStringEncoding(kCFStringEncodingGB_18030_2000);
    }
    
    return self;
}

// Delegate
- (void)SetSpiDelegate:(CXTradeMWSpi*) mwSpi{
    spi = mwSpi;
}


//调用此接口与socket连接
-(void) Connect:(NSString*) host andPort:(int)port{  
    CFReadStreamRef readStream;
    CFWriteStreamRef writeStream;
    
    // 连接
    CFStreamCreatePairWithSocketToHost(kCFAllocatorDefault, (CFStringRef)host, port, &readStream, &writeStream);
    inputStream = (NSInputStream *)readStream; // 输入流
    outputStream = (NSOutputStream *)writeStream; // 输出流
    
    // 启动线程
    backgroundThread = [[NSThread alloc] initWithTarget:self selector:@selector(StartStreamThread) object:nil];
    [backgroundThread start];
    
    // Log
    NSLog(@"Connectting...");
}



//启动单独的线程处理输入流
- (void)StartStreamThread{
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
- (void)DisConnect{
    if (inputStream){
        [inputStream close];
        inputStream = nil;
    }
    
    if (outputStream){
        [outputStream close];
        outputStream = nil;
    }
    
    if (backgroundThread) {
        [backgroundThread release];
        backgroundThread = nil;
    }
}



//发送命令给Server
- (void)SendCommand:(int)commandID {
    [self SendCommand: commandID andJsonReq:nil];    
}


//发送命令给Server
- (void)SendCommand:(int)commandID andJsonReq:(NSString *)jsonReq {
    while (true) {
        if ([outputStream hasSpaceAvailable]){
            NSMutableDictionary *jsonDic = [NSMutableDictionary dictionary];
            [jsonDic setValue:[NSNumber numberWithInt:commandID] forKey:@"commandID"];
            if(jsonReq!=nil){
                [jsonDic setObject:jsonReq forKey:@"jsonParams"];
            }
            NSString *jsonReqMsg = [jsonDic JSONString];
            
            //
            NSData *data = [[NSData alloc] initWithData:[jsonReqMsg dataUsingEncoding:NSUTF8StringEncoding]];
            [outputStream write:[data bytes] maxLength:[data length]];
            NSLog(@"Write command to MW: %@", jsonReqMsg);
            
            [data release];
            break;
        }
    }
}




//Socket回调，可以知道Socket的连接状态，收到Server端发来的数据等
- (void)stream:(NSStream *)theStream handleEvent:(NSStreamEvent)streamEvent {
    switch (streamEvent) {
        case NSStreamEventHasBytesAvailable:
            if (theStream == inputStream) {
                while ([inputStream hasBytesAvailable]) {
                    uint8_t buffer[4096];
                    int actuallyRead;
                    actuallyRead = [inputStream read:buffer maxLength:sizeof(buffer)];
                    
                    if (actuallyRead > 0) {
                        NSString *output = [[NSString alloc] initWithBytes:buffer length:actuallyRead encoding:ENC];
                        if (nil != output) {
                            //NSLog(@"返回: %@", output);
                            [spi ReceiveJsonMessage:output];
                        }
                        [output release];
                        output = nil;
                    }
                    
                }
            }
            break;
        case NSStreamEventOpenCompleted:
            break;
        case NSStreamEventErrorOccurred:
            NSLog(@"Can not connect to the host!");
            [self CleanUpStream:theStream];
            break;
        case NSStreamEventEndEncountered:
            NSLog(@"Closing stream...");
            [self CleanUpStream:theStream];
            break;
        default:
            break;
    }
}

// CleanUp
- (void)CleanUpStream:(NSStream *)stream
{
    [stream removeFromRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    [stream close];
    stream = nil;
}

@end
