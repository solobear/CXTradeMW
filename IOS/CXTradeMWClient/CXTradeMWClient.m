//
//  CXTradeMWClient.m
//  CXTradeMWClient
//
//  Created by MagicStudio on 14-10-2.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#import "CXTradeMWClient.h"
#import "CXTradeMWReqCommand.h"

@implementation CXTradeMWClient

//Init
- (id)init
{
    self = [super init];
    if (self) {
        //
    }
    
    return self;
}


// Connect
-(void) connect:(NSString*) host andPort:(int)port{
    socket = [[CXTradeMWSocket alloc] init];
    [socket connect: host andPort:port];   
}

// Close
-(void) close{
    // Close 
    [socket sendCommand:@"asfddasdf"];
    
    // disConnect
    [socket disConnect];
}

// SendMsg


// Login
-(void) login:(NSString*) username andPassword:(NSString*)password{
    [socket sendCommand:@"asfddasdf"];
}

// Req QryCommodity
-(void) reqQryCommodity{
    
}

@end
