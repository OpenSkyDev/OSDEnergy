/*!
 * OSDScriptTests.m
 * OSDEngine
 *
 * Copyright (c) 2014 OpenSky, LLC
 *
 * Created by Skylar Schipper on 11/24/14
 */

@import XCTest;
@import OSDEngine;

@interface OSDScriptTests : XCTestCase

@end

@implementation OSDScriptTests

- (void)testScriptVersion {
    OSDScript *script = [[OSDScript alloc] initWithScript:@""];
    
    XCTAssertFalse([[script evaluate:@"OSD.log"] isUndefined]);
    
    [script evaluate:@"OSD.log('********** Test Log')"];
    
    XCTAssertEqualObjects([[script evaluate:@"OSD.version"] toString], @"1.0.0");
}
- (void)testScriptTestAddFunction {
    OSDScript *script = [[OSDScript alloc] initWithScript:@""];
    
    JSValue *value = [script evaluateFunction:@"OSD._testAdd" withArguments:@[@8.0, @3.0]];
    
    XCTAssertFalse([value isUndefined]);
    
    XCTAssertEqualWithAccuracy([value toDouble], 11.0, 0.001);
}

@end
