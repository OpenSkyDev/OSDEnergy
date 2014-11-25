/*!
 * OSDScript.m
 * OSDEngine
 *
 * Copyright (c) 2014 OpenSky, LLC
 *
 * Created by Skylar Schipper on 11/24/14
 */

#import "OSDScript.h"
#import "OSDErrorHandler.h"
#import "OSDEngineLogger.h"

@interface OSDScript ()

@property (nonatomic, strong, readwrite) NSString *javascript;
@property (nonatomic, strong, readwrite) JSContext *context;

@end

@implementation OSDScript

+ (instancetype)newScriptWithFile:(NSURL *)fileURL {
    return [[self alloc] initWithScript:[NSString stringWithContentsOfURL:fileURL encoding:NSUTF8StringEncoding error:nil]];
}
- (instancetype)initWithScript:(NSString *)javascript {
    self = [super init];
    if (self) {
        self.javascript = javascript;
    }
    return self;
}

// MARK: - Context
- (JSContext *)context {
    if (!_context) {
        _context = [[JSContext alloc] initWithVirtualMachine:[self.class sharedVirtualMachine]];
        
        [self prepareContext:_context];
        
        [_context evaluateScript:self.javascript];
    }
    return _context;
}
- (void)prepareContext:(JSContext *)context {
    [context evaluateScript:[self.class sharedScriptFile]];
    
    context[@"OSD"][@"log"] = ^ (NSString *msg) {
        OSDEngineLog(@"<JS> %@",msg);
    };
}

// MARK: - Eval
- (JSValue *)evaluate:(NSString *)eval {
    return [self.context evaluateScript:eval];
}
- (JSValue *)evaluateFunction:(NSString *)function {
    return [self evaluateFunction:function withArguments:nil];
}
- (JSValue *)evaluateFunction:(NSString *)function withArguments:(NSArray *)args {
    JSValue *func = [self.context evaluateScript:function];
    return [func callWithArguments:args];
}

// MARK: - JavaScript
+ (JSVirtualMachine *)sharedVirtualMachine {
    static JSVirtualMachine *vm;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        vm = [[JSVirtualMachine alloc] init];
    });
    return vm;
}
+ (NSString *)sharedScriptFile {
    static NSString *script = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        NSBundle *bundle = [NSBundle bundleForClass:self.class];
        NSURL *fileURL = [bundle URLForResource:@"OSDScript" withExtension:@"js"];
        script = [NSString stringWithContentsOfURL:fileURL encoding:NSUTF8StringEncoding error:NULL];
    });
    return script;
}

@end
