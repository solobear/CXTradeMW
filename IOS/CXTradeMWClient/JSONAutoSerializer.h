//
//  JSONAutoSerializer.h
//  CXTradeMWClient
//
//  Created by MagicStudio on 14-10-4.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JSONAutoSerializer : NSObject

+ (JSONAutoSerializer *)serializer;
- (NSString*) SerializeObject: (id)theObject;

@end
