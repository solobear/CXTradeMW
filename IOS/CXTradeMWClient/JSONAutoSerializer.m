//
//  JSONStructSerializer.m
//  CXTradeMWClient
//
//  Created by MagicStudio on 14-10-4.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONAutoSerializer.h"
#import <objc/runtime.h>
#import "JSONKit.h"

@implementation JSONAutoSerializer

static JSONAutoSerializer *_sharedSerializer = nil;

+ (JSONAutoSerializer *)serializer
{
    if (_sharedSerializer == nil)
    {
        _sharedSerializer = [[JSONAutoSerializer alloc] init];
    }
    return _sharedSerializer;
}

///
- (NSString*) SerializeObject: (id)theObject{
    NSString *className = NSStringFromClass([theObject class]);
    
    const char *cClassName = [className UTF8String];
    
    id theClass = objc_getClass(cClassName);
    
    unsigned int outCount, i;
    objc_property_t *properties = class_copyPropertyList(theClass, &outCount);
    NSMutableArray *propertyNames = [[NSMutableArray alloc] initWithCapacity:1];
    for (i = 0; i < outCount; i++) {
        objc_property_t property = properties[i];
        NSString *propertyNameString = [[NSString alloc] initWithCString:property_getName(property) encoding:NSUTF8StringEncoding]; 
        [propertyNames addObject:propertyNameString];
        [propertyNameString release];
        NSLog(@"%s %s\n", property_getName(property), property_getAttributes(property));
        
    }
    
    // Object's properties to Dict
    NSMutableDictionary *finalDict = [[NSMutableDictionary alloc] initWithCapacity:1];
    for(NSString *key in propertyNames)
    {
        SEL selector = NSSelectorFromString(key);
        id value = [theObject performSelector:selector];
        
        if (value == nil)
        {
            value = [NSNull null];
        }
        [finalDict setObject:value forKey:key];
    }
    [propertyNames release];
    
    // Dict to Json string
    NSString *retString = [finalDict JSONString];
    [finalDict release];
    
    // Return
    return retString;
}
@end
