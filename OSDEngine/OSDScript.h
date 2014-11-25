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

#import "OSDEngineHelper.h"

@protocol OSDErrorHandler;


/**
 *  OSDScript is the general JavaScript runner for OSDEngine
 *
 *  Each script will have an `OSD` object injected into it.
 */
@interface OSDScript : NSObject

/**
 *  Create a new script object with the file located at the URL
 *
 *  @param fileURL The URL of the file to open.  Should be UTF-8 encoded
 *
 *  @return A new script object
 */
+ (instancetype)newScriptWithFile:(NSURL *)fileURL;

/**
 *  Create a new script object with the JavaScript string
 *
 *  @param javascript The JavaScript to use.
 *
 *  @return A new script object
 */
- (instancetype)initWithScript:(NSString *)javascript NS_DESIGNATED_INITIALIZER;

/**
 *  The JavaScript that's in the context.
 */
@property (nonatomic, strong, readonly) NSString *javascript;

/**
 *  The context that will be evaluated.
 */
@property (nonatomic, strong, readonly) JSContext *context;

/**
 *  Inject the OSD object into the context.
 *
 *  Must call super if overridden.  Should not be called directly
 *
 *  @param context The JSContext
 */
- (void)prepareContext:(JSContext *)context NS_REQUIRES_SUPER;

/**
 *  Instance of `OSDErrorHandler` to pass errors to.
 */
@property (nonatomic, assign) id<OSDErrorHandler> errorHandler;

/**
 *  Evaluate the passed string in the JS context
 *
 *  @param eval The string to evaluate.
 *
 *  @return The JSValue returned by the evaluated string.
 */
- (JSValue *)evaluate:(NSString *)eval;

/**
 *  Evaluate the function and return the results
 *
 *  @param function The name of the function to call.
 *
 *  @return The value returned from the function.
 */
- (JSValue *)evaluateFunction:(NSString *)function;

/**
 *  Evaluate the function and return the results
 *
 *  @param function The name of the function to call.
 *  @param args     Array of arguments to pass to the function
 *
 *  @return The value retuned from the function
 */
- (JSValue *)evaluateFunction:(NSString *)function withArguments:(NSArray *)args;

@end

OSD_ENGINE_EXTERN
NSString *const kOSDScriptExceptionValue;

#endif
