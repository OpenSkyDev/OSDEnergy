/*!
 * OSDEngineLogger.m
 * OSDEngine
 *
 * Copyright (c) 2014 OpenSky, LLC
 *
 * Created by Skylar Schipper on 11/24/14
 */

#import "OSDEngineLogger.h"

@interface OSDEngineLogger ()

@end

@implementation OSDEngineLogger

+ (void)log:(NSString *)fmt, ... {
    va_list arguments;
    va_start(arguments, fmt);
    NSString *message = [[NSString alloc] initWithFormat:fmt arguments:arguments];
    va_end(arguments);
    [self logMessage:message];
}
+ (void)logMessage:(NSString *)message {
    printf("OSDEngine: %s\n",[message UTF8String]);
}

@end
