//
//  OSDErrorHandler.h
//  OSDEngine
//
//  Created by Skylar Schipper on 11/24/14.
//  Copyright (c) 2014 OpenSky, LLC. All rights reserved.
//

#ifndef OSDEngine_OSDErrorHandler_h
#define OSDEngine_OSDErrorHandler_h

@import Foundation;

@protocol OSDErrorHandler <NSObject>

- (void)object:(id)object raisedError:(NSError *)error;

@end

FOUNDATION_EXTERN
NSString *const OSDEngineErrorDomain;

typedef NS_ENUM(NSInteger, OSDEngineError) {
    OSDEngineErrorCodeUnknown = 'unkn'
};

#endif
