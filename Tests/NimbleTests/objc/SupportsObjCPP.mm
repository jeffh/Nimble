#import <XCTest/XCTest.h>
#import "NimbleSpecHelper.h"

@interface SupportsObjCPPTest : XCTestCase

@end

@implementation SupportsObjCPPTest

- (void)testBasicExpectationsCanLinkToCPPCompliationUnit {
    expect(1).to(equal(1));
    expect(1).to(beLessThan(2));
    expect(1).to(beGreaterThan(0));
    expect(0).to(beLessThanOrEqualTo(0));
    expect(0).to(beGreaterThanOrEqualTo(0));
    expect(1).toNot(beFalse());
    expect(1).to(beTrue());
    expect(0).to(beFalsy());
    expect(1).to(beTruthy());
    expect(1).toEventually(equal(1));
    expect(1).toEventuallyNot(equal(2));
    NSObject *instance = [NSObject new];
    expect(instance).to(be(instance));
    expect(instance).toNot(beNil());
    expect(@"hello").to(contain(@"ll"));
    expect(instance).to(beIdenticalTo(instance));
    expect(instance).to(beAnInstanceOf([NSObject class]));
    expect(instance).to(beAKindOf([NSObject class]));
    expect(@"hello").to(endWith(@"llo"));
    expect(@"hello").to(beginWith(@"hel"));
    expect(@[@1, @2]).to(contain(@1));
    expect(@[@1, @2]).to(containElementSatisfying(^BOOL(id _Nonnull value) {
        return [value isEqual:@2];
    }));

    expect(@[@1, @2]).to(allPass(beGreaterThan(0)));
    expect(@[@1, @2]).to(haveCount(2));
    expect(@"11:14").to(match(@"\\d{2}:\\d{2}"));

    expectFailureMessage(@"fail() always fails", ^{
        fail();
    });

    expectFailureMessage(@"This always fails", ^{
        failWithMessage(@"This always fails");
    });
}


- (void)testBeCloseToCanLinkToCPPCompliationUnit {
    expect(@1.2).to(beCloseTo(@1.2001));
    expect(@1.2).to(beCloseTo(@2).within(10));
    expect(@2).toNot(beCloseTo(@1));
    expect(@1.00001).toNot(beCloseTo(@1).within(0.00000001));

    expect(1.2).to(beCloseTo(1.2001));
    expect(1.2).to(beCloseTo(2).within(10));
    expect(2).toNot(beCloseTo(1));
    expect(1.00001).toNot(beCloseTo(1).within(0.00000001));
}

- (void)testRaiseExceptionCanLinkToCPPCompliationUnit {
    __block NSException *exception = [NSException exceptionWithName:NSInvalidArgumentException
                                                             reason:@"No food"
                                                           userInfo:@{@"key": @"value"}];
    expectAction(^{ @throw exception; }).to(raiseException());
    expectAction(^{ [exception raise]; }).to(raiseException());
    expectAction(^{ [exception raise]; }).to(raiseException().named(NSInvalidArgumentException));
    expectAction(^{ [exception raise]; }).to(raiseException().
                                             named(NSInvalidArgumentException).
                                             reason(@"No food"));
    expectAction(^{ [exception raise]; }).to(raiseException().
                                             named(NSInvalidArgumentException).
                                             reason(@"No food").
                                             userInfo(@{@"key": @"value"}));

    expectAction(^{ }).toNot(raiseException());
}

@end
