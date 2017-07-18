#import <Nimble/DSL+CPPBridge.h>
#import <Nimble/Nimble-Swift.h>

@class NMBExpectation;
@class NMBObjCBeCloseToMatcher;
@class NMBObjCRaiseExceptionMatcher;
@protocol NMBMatcher;

@implementation NMBExpectationCPPBridge
- (nonnull instancetype)initWithActualBlock:(NSObject * _Null_unspecified (^ _Nonnull)(void))actualBlock
                                   negative:(BOOL)negative
                                       file:(NSString * _Nonnull)file
                                       line:(NSUInteger)line
{
    return (self = [super init]);
}

+ (void)failWithMessage:(NSString * _Nonnull)message file:(NSString * _Nonnull)file line:(NSUInteger)line
{
    [NMBExpectation failWithMessage:message file:file line:line];
}

- (NMBExpectationCPPBridge * _Nonnull (^)(NSTimeInterval))withTimeout
{
    return nil;
}

@end


@implementation NMBObjCBeCloseToMatcherCPPBridge

- (instancetype)init
{
    return (self = [super init]);
}

- (BOOL)matches:(NSObject * _Null_unspecified (^)(void))actualExpression failureMessage:(FailureMessage *)failureMessage location:(SourceLocation *)location
{
    return NO;
}

- (BOOL)doesNotMatch:(NSObject * _Null_unspecified (^)(void))actualExpression failureMessage:(FailureMessage *)failureMessage location:(SourceLocation *)location
{
    return NO;
}

- (NMBObjCBeCloseToMatcherCPPBridge * _Nonnull (^)(double))within
{
    return nil;
}

@end

@implementation NMBObjCRaiseExceptionMatcherCPPBridge

- (nonnull instancetype)init
{
    return (self = [super init]);
}

- (BOOL)matches:(NSObject * _Null_unspecified (^)(void))actualBlock failureMessage:(FailureMessage *)failureMessage location:(SourceLocation *)location
{
    return NO;
}

- (BOOL)doesNotMatch:(NSObject * _Null_unspecified (^)(void))actualBlock failureMessage:(FailureMessage *)failureMessage location:(SourceLocation *)location
{
    return NO;
}

- (NMBObjCRaiseExceptionMatcherCPPBridge * _Nonnull (^)(NSString * _Nonnull))named
{
    return nil;
}

- (NMBObjCRaiseExceptionMatcherCPPBridge * _Nonnull (^)(NSString * _Nullable))reason
{
    return nil;
}

- (NMBObjCRaiseExceptionMatcherCPPBridge * _Nonnull (^)(NSDictionary * _Nullable))userInfo
{
    return nil;
}

-(NMBObjCRaiseExceptionMatcherCPPBridge * _Nonnull (^)(void (^ _Nullable)(NSException * _Nonnull)))satisfyingBlock
{
    return nil;
}

@end
