//
//  CXTradeMWSocket.m
//  CXTradeMWClient
//
//  Created by MagicStudio on 14-10-2.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#import "CXTradeMWSocket.h"

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
- (void)connect{
    CFReadStreamRef readStream;
    CFWriteStreamRef writeStream;
    
    CFStreamCreatePairWithSocketToHost(kCFAllocatorDefault, (CFStringRef)@"182.254.133.20", 7190, &readStream, &writeStream);
    
    inputStream = (NSInputStream *)readStream; // ivar
    [inputStream setDelegate:self];
    [inputStream scheduleInRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    [inputStream open];
    
    outputStream = (NSOutputStream *)writeStream; // ivar
    [outputStream setDelegate:self];
    [outputStream scheduleInRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    [outputStream open];
    
    NSLog(@"Connectting...");

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
    
    [self notifyDisConnected];
}

//发送命令给Server
- (BOOL)sendCommand:(NSString *)jsonMsg {
    while (true) {
        if ([outputStream hasSpaceAvailable]){
            NSData *data = [[NSData alloc] initWithData:[jsonMsg dataUsingEncoding:NSASCIIStringEncoding]];
            [outputStream write:[data bytes] maxLength:[data length]];
            NSLog(@"write command to dv: %@", jsonMsg);
            return YES;
        }
    }
    
    return NO;
}

//Socket回调，可以知道Socket的连接状态，收到Server端发来的数据等
- (void)stream:(NSStream *)theStream handleEvent:(NSStreamEvent)streamEvent {
    switch (streamEvent) {
        case NSStreamEventNone:
            [self notifyConnectedFailed];
            NSLog(@"can not connect to socket");
            break;
        case NSStreamEventOpenCompleted:
            if (theStream == inputStream)
            {
                [self notifyConnected];
            }
            NSLog(@"Stream opened");
            break;
        case NSStreamEventHasSpaceAvailable: {
            break;
        }
        case NSStreamEventHasBytesAvailable:
            if (theStream == inputStream) {
                uint8_t buffer[1024];
                int len;
                
                while ([inputStream hasBytesAvailable]) {
                    len = [inputStream read:buffer maxLength:sizeof(buffer)];
                    
                    if (len > 0) {
                        //一行作位一次会话传给外边解析 Iterator buff.
                        uint8_t tmp_buffer[1024];
                        int tmp_buffer_start = 0;
                        for (int i = 0; i < len; ++i)
                        {
                            if ('\n' == buffer[i])
                            {
                                for (int j = tmp_buffer_start; j < i + 1; ++j)
                                {
                                    tmp_buffer[j - tmp_buffer_start] = buffer[j];
                                }
                                NSString *output = [[NSString alloc] initWithBytes:tmp_buffer length:(i - tmp_buffer_start + 1) encoding:NSASCIIStringEncoding];
                                
                                if (nil != output) {
                                    [self notifyNewMessage:output];
                                    NSLog(@"s: %@", output);
                                }
                                
                                [output release];
                                
                                memset(tmp_buffer, 0, sizeof(uint8_t) * 1024);
                                tmp_buffer_start = i + 1;
                            }
                        }
                    }
                }
                
            }
            break;
        case NSStreamEventErrorOccurred:
            NSLog(@"Can not connect to the host!");
            //            [self notifyConnectedFailed];
            break;
        case NSStreamEventEndEncountered:
            NSLog(@"Closing stream...");
            [theStream close];
            [theStream removeFromRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
            [theStream release];
            theStream = nil;
            break;
        default:
            NSLog(@"Unknown event");
    }
}

@end
