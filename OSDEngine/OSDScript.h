/*!
 * OSDScript.h
 * OSDEngine
 *
 * Copyright (c) 2014 OpenSky, LLC
 *
 * Created by Skylar Schipper on 11/24/14
 */

#ifndef OSDEngine_OSDScript_h
#define OSDEngine_OSDScript_h

@import Foundation;
@import JavaScriptCore;

@protocol OSDErrorHandler;

@interface OSDScript : NSObject

+ (instancetype)newScriptWithFile:(NSURL *)fileURL;
- (instancetype)initWithScript:(NSString *)javascript NS_DESIGNATED_INITIALIZER;

// MARK: - Raw JavaScript
@property (nonatomic, strong, readonly) NSString *javascript;

// MARK: - JavaScript Engine
@property (nonatomic, strong, readonly) JSContext *context;

- (void)prepareContext:(JSContext *)context NS_REQUIRES_SUPER;

// MARK: - Error Handler
@property (nonatomic, assign) id<OSDErrorHandler> errorHandler;

// MARK: - Eval
- (JSValue *)evaluate:(NSString *)eval;
- (JSValue *)evaluateFunction:(NSString *)function;
- (JSValue *)evaluateFunction:(NSString *)function withArguments:(NSArray *)args;

@end

#endif
