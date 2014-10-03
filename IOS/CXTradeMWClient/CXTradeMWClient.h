//
//  CXTradeMWClient.h
//  CXTradeMWClient
//
//  Created by MagicStudio on 14-10-2.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CXTradeMWSocket.h"

#define Req_UserLogin              100

#define Req_OpenMarketOrder        101
#define Req_CloseMarketOrder       102
#define Req_OpenLimitOrder         103
#define Req_LimitClosePosition     104
#define Req_LimitRevoke            105
#define Req_CloseMarketOrderMany   106

#define ReqQry_AccountInfo         107
#define ReqQry_Commodity           108
#define ReqQry_MarketStatus        109
#define ReqQry_PositionOrder       110
#define ReqQry_LimitOrder          111
#define ReqQry_ClosePosition       112
#define ReqQry_HoldPositionTotal   113
#define ReqQry_HoldPositionByID    114
#define ReqQry_LimitOrderByID      115
#define ReqQry_ClosePositionByID   116
#define ReqQry_HoldPositionTotalByCommodityID  117
#define ReqQry_CommodityQuote          118
#define ReqQry_OpenMarketOrderConf     119
#define ReqQry_OpenLimitOrderConf      120
#define ReqQry_CloseMarketOrderConf    121
#define ReqQry_LimitClosePositionConf  122

#define Req_Close                 200


@interface CXTradeMWClient : NSObject{
    CXTradeMWSocket* socket;
}

-(void) connect:(NSString*) host andPort:(int)port;
-(void) close;

// Login
-(void) login:(NSString*) username andPassword:(NSString*)password;
-(void) reqQryCommodity;

@end
