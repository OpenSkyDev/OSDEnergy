//
//  OSDEngineHelper.h
//  OSDEngine
//
//  Created by Skylar Schipper on 11/24/14.
//  Copyright (c) 2014 OpenSky, LLC. All rights reserved.
//

#ifndef OSDEngine_OSDEngineHelper_h
#define OSDEngine_OSDEngineHelper_h

@import Foundation;

#if defined(__cplusplus)
    #define OSD_ENGINE_EXTERN extern "C"
#else
    #define OSD_ENGINE_EXTERN extern
#endif


OSD_ENGINE_EXTERN
NSString *const OSDEngineErrorDomain;

typedef NS_ENUM(NSInteger, OSDEngineError) {
    OSDEngineErrorCodeUnknown     = 'unkn',
    OSDEngineErrorCodeJSException = 'jexc'
};

#endif
