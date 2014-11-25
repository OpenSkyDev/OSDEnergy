/*!
 * OSDEngineLogger.h
 * OSDEngine
 *
 * Copyright (c) 2014 OpenSky, LLC
 *
 * Created by Skylar Schipper on 11/24/14
 */

#ifndef OSDEngine_OSDEngineLogger_h
#define OSDEngine_OSDEngineLogger_h

@import Foundation;

@interface OSDEngineLogger : NSObject

+ (void)log:(NSString *)fmt, ... NS_FORMAT_FUNCTION(1, 2);

@end

#ifndef OSD_ENGINE_LOGGER_ENABLED
    #define OSD_ENGINE_LOGGER_ENABLED 1
#endif

#if OSD_ENGINE_LOGGER_ENABLED
    #define OSDEngineLog(fmt, ...) [OSDEngineLogger log:fmt, ##__VA_ARGS__]
#else
    #define OSDEngineLog(fmt, ...)
#endif

#endif
