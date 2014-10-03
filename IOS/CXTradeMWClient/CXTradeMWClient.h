//
//  CXTradeMWClient.h
//  CXTradeMWClient
//
//  Created by MagicStudio on 14-10-2.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CXTradeMWSocket.h"

@interface CXTradeMWClient : NSObject{
    CXTradeMWSocket* socket;
}

-(void) connect:(NSString*) host andPort:(int)port;
-(void) close;

// Login
-(void) login:(NSString*) username andPassword:(NSString*)password;
-(void) reqQryCommodity;

@end
