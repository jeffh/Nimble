#import <Foundation/Foundation.h>

@class NMBExpectation;
@class NMBObjCBeCloseToMatcher;
@class NMBObjCRaiseExceptionMatcher;
@class SourceLocation;
@class FailureMessage;
@protocol NMBMatcher;

// Most of this file exists to trick the ObjC++ compiler what methods can be called on Swift-bridged objects.

#if __cplusplus
@protocol NMBMatcher
- (BOOL)matches:(NSObject * _Null_unspecified (^ _Nonnull)(void))actualBlock failureMessage:(FailureMessage * _Nonnull)failureMessage location:(SourceLocation * _Nonnull)location;
- (BOOL)doesNotMatch:(NSObject * _Null_unspecified (^ _Nonnull)(void))actualBlock failureMessage:(FailureMessage * _Nonnull)failureMessage location:(SourceLocation * _Nonnull)location;
@end
#endif

@interface NMBExpectationCPPBridge : NSObject
- (nonnull instancetype)initWithActualBlock:(NSObject * _Null_unspecified (^ _Nonnull)(void))actualBlock negative:(BOOL)negative file:(NSString * _Nonnull)file line:(NSUInteger)line;
@property (nonatomic, readonly, copy) NMBExpectationCPPBridge * _Nonnull (^ _Nonnull withTimeout)(NSTimeInterval);
@property (nonatomic, readonly, copy) void (^ _Nonnull to)(id <NMBMatcher> _Nonnull);
@property (nonatomic, readonly, copy) void (^ _Nonnull toWithDescription)(id <NMBMatcher> _Nonnull, NSString * _Nonnull);
@property (nonatomic, readonly, copy) void (^ _Nonnull toNot)(id <NMBMatcher> _Nonnull);
@property (nonatomic, readonly, copy) void (^ _Nonnull toNotWithDescription)(id <NMBMatcher> _Nonnull, NSString * _Nonnull);
@property (nonatomic, readonly, copy) void (^ _Nonnull notTo)(id <NMBMatcher> _Nonnull);
@property (nonatomic, readonly, copy) void (^ _Nonnull notToWithDescription)(id <NMBMatcher> _Nonnull, NSString * _Nonnull);
@property (nonatomic, readonly, copy) void (^ _Nonnull toEventually)(id <NMBMatcher> _Nonnull);
@property (nonatomic, readonly, copy) void (^ _Nonnull toEventuallyWithDescription)(id <NMBMatcher> _Nonnull, NSString * _Nonnull);
@property (nonatomic, readonly, copy) void (^ _Nonnull toEventuallyNot)(id <NMBMatcher> _Nonnull);
@property (nonatomic, readonly, copy) void (^ _Nonnull toEventuallyNotWithDescription)(id <NMBMatcher> _Nonnull, NSString * _Nonnull);
@property (nonatomic, readonly, copy) void (^ _Nonnull toNotEventually)(id <NMBMatcher> _Nonnull);
@property (nonatomic, readonly, copy) void (^ _Nonnull toNotEventuallyWithDescription)(id <NMBMatcher> _Nonnull, NSString * _Nonnull);
+ (void)failWithMessage:(NSString * _Nonnull)message file:(NSString * _Nonnull)file line:(NSUInteger)line;
@end

@interface NMBObjCBeCloseToMatcherCPPBridge : NSObject
- (nonnull instancetype)init;
- (BOOL)matches:(NSObject * _Null_unspecified (^ _Nonnull)(void))actualExpression failureMessage:(FailureMessage * _Nonnull)failureMessage location:(SourceLocation * _Nonnull)location;
- (BOOL)doesNotMatch:(NSObject * _Null_unspecified (^ _Nonnull)(void))actualExpression failureMessage:(FailureMessage * _Nonnull)failureMessage location:(SourceLocation * _Nonnull)location;
@property (nonatomic, readonly, copy) NMBObjCBeCloseToMatcherCPPBridge * _Nonnull (^ _Nonnull within)(double);
@end

@interface NMBObjCRaiseExceptionMatcherCPPBridge : NSObject
- (BOOL)matches:(NSObject * _Null_unspecified (^ _Nonnull)(void))actualBlock failureMessage:(FailureMessage * _Nonnull)failureMessage location:(SourceLocation * _Nonnull)location;
- (BOOL)doesNotMatch:(NSObject * _Null_unspecified (^ _Nonnull)(void))actualBlock failureMessage:(FailureMessage * _Nonnull)failureMessage location:(SourceLocation * _Nonnull)location;
@property (nonatomic, readonly, copy) NMBObjCRaiseExceptionMatcherCPPBridge * _Nonnull (^ _Nonnull named)(NSString * _Nonnull);
@property (nonatomic, readonly, copy) NMBObjCRaiseExceptionMatcherCPPBridge * _Nonnull (^ _Nonnull reason)(NSString * _Nullable);
@property (nonatomic, readonly, copy) NMBObjCRaiseExceptionMatcherCPPBridge * _Nonnull (^ _Nonnull userInfo)(NSDictionary * _Nullable);
@property (nonatomic, readonly, copy) NMBObjCRaiseExceptionMatcherCPPBridge * _Nonnull (^ _Nonnull satisfyingBlock)(void (^ _Nullable)(NSException * _Nonnull));
@end

#if __cplusplus

@interface NMBObjCBeCloseToMatcherCPPBridge (Matcher) <NMBMatcher>
@end

@interface NMBObjCRaiseExceptionMatcherCPPBridge (Matcher) <NMBMatcher>
@end


typedef NMBExpectationCPPBridge NMBExpectationImpl;
typedef NMBObjCBeCloseToMatcherCPPBridge NMBObjCBeCloseToMatcherImpl;
typedef NMBObjCRaiseExceptionMatcherCPPBridge NMBObjCRaiseExceptionMatcherImpl;

#else

typedef NMBExpectation NMBExpectationImpl;
typedef NMBObjCBeCloseToMatcher NMBObjCBeCloseToMatcherImpl;
typedef NMBObjCRaiseExceptionMatcher NMBObjCRaiseExceptionMatcherImpl;
#endif
