#import <Foundation/Foundation.h>

#import "DSL+CPPBridge.h"

NS_ASSUME_NONNULL_BEGIN

#if __cplusplus
#define NIMBLE_OVERLOADABLE
#else
#define NIMBLE_OVERLOADABLE __attribute__((overloadable))
#endif

#define NIMBLE_EXPORT FOUNDATION_EXPORT
#define NIMBLE_EXPORT_INLINE FOUNDATION_STATIC_INLINE

#define NIMBLE_VALUE_OF(VAL) ({ \
    __typeof__((VAL)) val = (VAL); \
    [NSValue valueWithBytes:&val objCType:@encode(__typeof__((VAL)))]; \
})

#ifdef NIMBLE_DISABLE_SHORT_SYNTAX
#define NIMBLE_SHORT(PROTO, ORIGINAL)
#define NIMBLE_SHORT_OVERLOADED(PROTO, ORIGINAL)
#else
#define NIMBLE_SHORT(PROTO, ORIGINAL) FOUNDATION_STATIC_INLINE PROTO { return (ORIGINAL); }
#define NIMBLE_SHORT_OVERLOADED(PROTO, ORIGINAL) FOUNDATION_STATIC_INLINE NIMBLE_OVERLOADABLE PROTO { return (ORIGINAL); }
#endif



#define DEFINE_NMB_EXPECT_OVERLOAD(TYPE, EXPR) \
        NIMBLE_EXPORT_INLINE NIMBLE_OVERLOADABLE \
        NMBExpectationImpl *NMB_expect(TYPE(^actualBlock)(), NSString *file, NSUInteger line) { \
            return NMB_expect_impl(^id { return EXPR; }, file, line); \
        }

    NIMBLE_EXPORT
    NMBExpectationImpl *NMB_expect_impl(id(^actualBlock)(), NSString *file, NSUInteger line);

    // overloaded dispatch for nils - expect(nil)
    DEFINE_NMB_EXPECT_OVERLOAD(id, actualBlock());
    DEFINE_NMB_EXPECT_OVERLOAD(void*, nil)
    DEFINE_NMB_EXPECT_OVERLOAD(NSRange, NIMBLE_VALUE_OF(actualBlock()))
    DEFINE_NMB_EXPECT_OVERLOAD(long, @(actualBlock()))
    DEFINE_NMB_EXPECT_OVERLOAD(unsigned long, @(actualBlock()))
    DEFINE_NMB_EXPECT_OVERLOAD(int, @(actualBlock()))
    DEFINE_NMB_EXPECT_OVERLOAD(unsigned int, @(actualBlock()))
    DEFINE_NMB_EXPECT_OVERLOAD(float, @(actualBlock()))
    DEFINE_NMB_EXPECT_OVERLOAD(double, @(actualBlock()))
    DEFINE_NMB_EXPECT_OVERLOAD(long long, @(actualBlock()))
    DEFINE_NMB_EXPECT_OVERLOAD(unsigned long long, @(actualBlock()))
    DEFINE_NMB_EXPECT_OVERLOAD(char, @(actualBlock()))
    DEFINE_NMB_EXPECT_OVERLOAD(unsigned char, @(actualBlock()))
    // bool doesn't get the compiler to dispatch to BOOL types, but using BOOL here seems to allow
    // the compiler to dispatch to bool.
    DEFINE_NMB_EXPECT_OVERLOAD(BOOL, @(actualBlock()))
    DEFINE_NMB_EXPECT_OVERLOAD(char *, @(actualBlock()))


#undef DEFINE_NMB_EXPECT_OVERLOAD



NIMBLE_EXPORT NMBExpectationImpl *NMB_expectAction(void(^actualBlock)(), NSString *file, NSUInteger line);



#define DEFINE_OVERLOAD(TYPE, EXPR) \
        NIMBLE_EXPORT_INLINE NIMBLE_OVERLOADABLE \
        id<NMBMatcher> NMB_equal(TYPE expectedValue) { \
            return NMB_equal_impl((EXPR)); \
        } \
        NIMBLE_SHORT_OVERLOADED(id<NMBMatcher> equal(TYPE expectedValue), NMB_equal(expectedValue));


    NIMBLE_EXPORT
    id<NMBMatcher> NMB_equal_impl(__nullable id expectedValue);

    // overloaded dispatch for nils - expect(nil)
    DEFINE_OVERLOAD(id, expectedValue)
    DEFINE_OVERLOAD(void*__nullable, (id)nil)
    DEFINE_OVERLOAD(NSRange, NIMBLE_VALUE_OF(expectedValue))
    DEFINE_OVERLOAD(long, @(expectedValue))
    DEFINE_OVERLOAD(unsigned long, @(expectedValue))
    DEFINE_OVERLOAD(int, @(expectedValue))
    DEFINE_OVERLOAD(unsigned int, @(expectedValue))
    DEFINE_OVERLOAD(float, @(expectedValue))
    DEFINE_OVERLOAD(double, @(expectedValue))
    DEFINE_OVERLOAD(long long, @(expectedValue))
    DEFINE_OVERLOAD(unsigned long long, @(expectedValue))
    DEFINE_OVERLOAD(char, @(expectedValue))
    DEFINE_OVERLOAD(unsigned char, @(expectedValue))
    // bool doesn't get the compiler to dispatch to BOOL types, but using BOOL here seems to allow
    // the compiler to dispatch to bool.
    DEFINE_OVERLOAD(BOOL, @(expectedValue))
    DEFINE_OVERLOAD(char *, @(expectedValue))

#undef DEFINE_OVERLOAD


#define DEFINE_OVERLOAD(TYPE, EXPR) \
        NIMBLE_EXPORT_INLINE NIMBLE_OVERLOADABLE \
        id<NMBMatcher> NMB_haveCount(TYPE expectedValue) { \
            return NMB_haveCount_impl((EXPR)); \
        } \
        NIMBLE_SHORT_OVERLOADED(id<NMBMatcher> haveCount(TYPE expectedValue), \
            NMB_haveCount(expectedValue));


    NIMBLE_EXPORT
    id<NMBMatcher> NMB_haveCount_impl(id expectedValue);

    DEFINE_OVERLOAD(id, expectedValue);
    DEFINE_OVERLOAD(long, @(expectedValue))
    DEFINE_OVERLOAD(unsigned long, @(expectedValue))
    DEFINE_OVERLOAD(int, @(expectedValue))
    DEFINE_OVERLOAD(unsigned int, @(expectedValue))
    DEFINE_OVERLOAD(long long, @(expectedValue))
    DEFINE_OVERLOAD(unsigned long long, @(expectedValue))
    DEFINE_OVERLOAD(char, @(expectedValue))
    DEFINE_OVERLOAD(unsigned char, @(expectedValue))

#undef DEFINE_OVERLOAD

#define DEFINE_OVERLOAD(TYPE, EXPR) \
        NIMBLE_EXPORT_INLINE NIMBLE_OVERLOADABLE \
        NMBObjCBeCloseToMatcherImpl *NMB_beCloseTo(TYPE expectedValue) { \
            return NMB_beCloseTo_impl((NSNumber *)(EXPR)); \
        } \
        NIMBLE_SHORT_OVERLOADED(NMBObjCBeCloseToMatcherImpl *beCloseTo(TYPE expectedValue), \
            NMB_beCloseTo(expectedValue));

    NIMBLE_EXPORT
    NMBObjCBeCloseToMatcherImpl *NMB_beCloseTo_impl(NSNumber *expectedValue);

    DEFINE_OVERLOAD(id, expectedValue)
    // it would be better to only overload float & double, but zero becomes ambigious
    DEFINE_OVERLOAD(long, @(expectedValue))
    DEFINE_OVERLOAD(unsigned long, @(expectedValue))
    DEFINE_OVERLOAD(int, @(expectedValue))
    DEFINE_OVERLOAD(unsigned int, @(expectedValue))
    DEFINE_OVERLOAD(float, @(expectedValue))
    DEFINE_OVERLOAD(double, @(expectedValue))
    DEFINE_OVERLOAD(long long, @(expectedValue))
    DEFINE_OVERLOAD(unsigned long long, @(expectedValue))
    DEFINE_OVERLOAD(char, @(expectedValue))
    DEFINE_OVERLOAD(unsigned char, @(expectedValue))

#undef DEFINE_OVERLOAD

NIMBLE_EXPORT id<NMBMatcher> NMB_beAnInstanceOf(Class expectedClass);
NIMBLE_EXPORT_INLINE id<NMBMatcher> beAnInstanceOf(Class expectedClass) {
    return NMB_beAnInstanceOf(expectedClass);
}

NIMBLE_EXPORT id<NMBMatcher> NMB_beAKindOf(Class expectedClass);
NIMBLE_EXPORT_INLINE id<NMBMatcher> beAKindOf(Class expectedClass) {
    return NMB_beAKindOf(expectedClass);
}

NIMBLE_EXPORT id<NMBMatcher> NMB_beginWith(id itemElementOrSubstring);
NIMBLE_EXPORT_INLINE id<NMBMatcher> beginWith(id itemElementOrSubstring) {
    return NMB_beginWith(itemElementOrSubstring);
}

#define DEFINE_OVERLOAD(TYPE, EXPR) \
        NIMBLE_EXPORT_INLINE NIMBLE_OVERLOADABLE \
        id<NMBMatcher> NMB_beGreaterThan(TYPE expectedValue) { \
            return NMB_beGreaterThan_impl((EXPR)); \
        } \
        NIMBLE_SHORT_OVERLOADED(id<NMBMatcher> beGreaterThan(TYPE expectedValue), NMB_beGreaterThan(expectedValue));

    NIMBLE_EXPORT
    id<NMBMatcher> NMB_beGreaterThan_impl(NSNumber *expectedValue);

    DEFINE_OVERLOAD(id, expectedValue)
    DEFINE_OVERLOAD(long, @(expectedValue))
    DEFINE_OVERLOAD(unsigned long, @(expectedValue))
    DEFINE_OVERLOAD(int, @(expectedValue))
    DEFINE_OVERLOAD(unsigned int, @(expectedValue))
    DEFINE_OVERLOAD(float, @(expectedValue))
    DEFINE_OVERLOAD(double, @(expectedValue))
    DEFINE_OVERLOAD(long long, @(expectedValue))
    DEFINE_OVERLOAD(unsigned long long, @(expectedValue))
    DEFINE_OVERLOAD(char, @(expectedValue))
    DEFINE_OVERLOAD(unsigned char, @(expectedValue))

#undef DEFINE_OVERLOAD

#define DEFINE_OVERLOAD(TYPE, EXPR) \
        NIMBLE_EXPORT_INLINE NIMBLE_OVERLOADABLE \
        id<NMBMatcher> NMB_beGreaterThanOrEqualTo(TYPE expectedValue) { \
            return NMB_beGreaterThanOrEqualTo_impl((EXPR)); \
        } \
        NIMBLE_SHORT_OVERLOADED(id<NMBMatcher> beGreaterThanOrEqualTo(TYPE expectedValue), \
            NMB_beGreaterThanOrEqualTo(expectedValue));

    NIMBLE_EXPORT
    id<NMBMatcher> NMB_beGreaterThanOrEqualTo_impl(NSNumber *expectedValue);

    DEFINE_OVERLOAD(id, expectedValue)
    DEFINE_OVERLOAD(long, @(expectedValue))
    DEFINE_OVERLOAD(unsigned long, @(expectedValue))
    DEFINE_OVERLOAD(int, @(expectedValue))
    DEFINE_OVERLOAD(unsigned int, @(expectedValue))
    DEFINE_OVERLOAD(float, @(expectedValue))
    DEFINE_OVERLOAD(double, @(expectedValue))
    DEFINE_OVERLOAD(long long, @(expectedValue))
    DEFINE_OVERLOAD(unsigned long long, @(expectedValue))
    DEFINE_OVERLOAD(char, @(expectedValue))
    DEFINE_OVERLOAD(unsigned char, @(expectedValue))


#undef DEFINE_OVERLOAD

NIMBLE_EXPORT id<NMBMatcher> NMB_beIdenticalTo(id expectedInstance);
NIMBLE_SHORT(id<NMBMatcher> beIdenticalTo(id expectedInstance),
             NMB_beIdenticalTo(expectedInstance));

NIMBLE_EXPORT id<NMBMatcher> NMB_be(id expectedInstance);
NIMBLE_SHORT(id<NMBMatcher> be(id expectedInstance),
             NMB_be(expectedInstance));


#define DEFINE_OVERLOAD(TYPE, EXPR) \
        NIMBLE_EXPORT_INLINE NIMBLE_OVERLOADABLE \
        id<NMBMatcher> NMB_beLessThan(TYPE expectedValue) { \
            return NMB_beLessThan_impl((EXPR)); \
        } \
        NIMBLE_SHORT_OVERLOADED(id<NMBMatcher> beLessThan(TYPE expectedValue), \
            NMB_beLessThan(expectedValue));

    NIMBLE_EXPORT
    id<NMBMatcher> NMB_beLessThan_impl(NSNumber *expectedValue);

    DEFINE_OVERLOAD(id, expectedValue)
    DEFINE_OVERLOAD(long, @(expectedValue))
    DEFINE_OVERLOAD(unsigned long, @(expectedValue))
    DEFINE_OVERLOAD(int, @(expectedValue))
    DEFINE_OVERLOAD(unsigned int, @(expectedValue))
    DEFINE_OVERLOAD(float, @(expectedValue))
    DEFINE_OVERLOAD(double, @(expectedValue))
    DEFINE_OVERLOAD(long long, @(expectedValue))
    DEFINE_OVERLOAD(unsigned long long, @(expectedValue))
    DEFINE_OVERLOAD(char, @(expectedValue))
    DEFINE_OVERLOAD(unsigned char, @(expectedValue))

#undef DEFINE_OVERLOAD


#define DEFINE_OVERLOAD(TYPE, EXPR) \
    NIMBLE_EXPORT_INLINE NIMBLE_OVERLOADABLE \
    id<NMBMatcher> NMB_beLessThanOrEqualTo(TYPE expectedValue) { \
        return NMB_beLessThanOrEqualTo_impl((EXPR)); \
    } \
    NIMBLE_SHORT_OVERLOADED(id<NMBMatcher> beLessThanOrEqualTo(TYPE expectedValue), \
        NMB_beLessThanOrEqualTo(expectedValue));


    NIMBLE_EXPORT
    id<NMBMatcher> NMB_beLessThanOrEqualTo_impl(NSNumber *expectedValue);

    DEFINE_OVERLOAD(id, expectedValue)
    DEFINE_OVERLOAD(long, @(expectedValue))
    DEFINE_OVERLOAD(unsigned long, @(expectedValue))
    DEFINE_OVERLOAD(int, @(expectedValue))
    DEFINE_OVERLOAD(unsigned int, @(expectedValue))
    DEFINE_OVERLOAD(float, @(expectedValue))
    DEFINE_OVERLOAD(double, @(expectedValue))
    DEFINE_OVERLOAD(long long, @(expectedValue))
    DEFINE_OVERLOAD(unsigned long long, @(expectedValue))
    DEFINE_OVERLOAD(char, @(expectedValue))
    DEFINE_OVERLOAD(unsigned char, @(expectedValue))

#undef DEFINE_OVERLOAD

NIMBLE_EXPORT id<NMBMatcher> NMB_beTruthy(void);
NIMBLE_SHORT(id<NMBMatcher> beTruthy(void),
             NMB_beTruthy());

NIMBLE_EXPORT id<NMBMatcher> NMB_beFalsy(void);
NIMBLE_SHORT(id<NMBMatcher> beFalsy(void),
             NMB_beFalsy());

NIMBLE_EXPORT id<NMBMatcher> NMB_beTrue(void);
NIMBLE_SHORT(id<NMBMatcher> beTrue(void),
             NMB_beTrue());

NIMBLE_EXPORT id<NMBMatcher> NMB_beFalse(void);
NIMBLE_SHORT(id<NMBMatcher> beFalse(void),
             NMB_beFalse());

NIMBLE_EXPORT id<NMBMatcher> NMB_beNil(void);
NIMBLE_SHORT(id<NMBMatcher> beNil(void),
             NMB_beNil());

NIMBLE_EXPORT id<NMBMatcher> NMB_beEmpty(void);
NIMBLE_SHORT(id<NMBMatcher> beEmpty(void),
             NMB_beEmpty());

NIMBLE_EXPORT id<NMBMatcher> NMB_containWithNilTermination(id itemOrSubstring, ...) NS_REQUIRES_NIL_TERMINATION;
#define NMB_contain(...) NMB_containWithNilTermination(__VA_ARGS__, nil)
#ifndef NIMBLE_DISABLE_SHORT_SYNTAX
#define contain(...) NMB_contain(__VA_ARGS__)
#endif

NIMBLE_EXPORT id<NMBMatcher> NMB_containElementSatisfying(BOOL(^predicate)(id));
NIMBLE_SHORT(id<NMBMatcher> containElementSatisfying(BOOL(^predicate)(id)),
             NMB_containElementSatisfying(predicate));

NIMBLE_EXPORT id<NMBMatcher> NMB_endWith(id itemElementOrSubstring);
NIMBLE_SHORT(id<NMBMatcher> endWith(id itemElementOrSubstring),
             NMB_endWith(itemElementOrSubstring));

NIMBLE_EXPORT NMBObjCRaiseExceptionMatcherImpl *NMB_raiseException(void);
NIMBLE_SHORT(NMBObjCRaiseExceptionMatcherImpl *raiseException(void),
             NMB_raiseException());

NIMBLE_EXPORT id<NMBMatcher> NMB_match(id expectedValue);
NIMBLE_SHORT(id<NMBMatcher> match(id expectedValue),
             NMB_match(expectedValue));

NIMBLE_EXPORT id<NMBMatcher> NMB_allPass(id matcher);
NIMBLE_SHORT(id<NMBMatcher> allPass(id matcher),
             NMB_allPass(matcher));

NIMBLE_EXPORT id<NMBMatcher> NMB_satisfyAnyOfWithMatchers(id matchers);
#define NMB_satisfyAnyOf(...) NMB_satisfyAnyOfWithMatchers(@[__VA_ARGS__])
#ifndef NIMBLE_DISABLE_SHORT_SYNTAX
#define satisfyAnyOf(...) NMB_satisfyAnyOf(__VA_ARGS__)
#endif

// In order to preserve breakpoint behavior despite using macros to fill in __FILE__ and __LINE__,
// define a builder that populates __FILE__ and __LINE__, and returns a block that takes timeout
// and action arguments. See https://github.com/Quick/Quick/pull/185 for details.
typedef void (^NMBWaitUntilTimeoutBlock)(NSTimeInterval timeout, void (^action)(void (^)(void)));
typedef void (^NMBWaitUntilBlock)(void (^action)(void (^)(void)));

NIMBLE_EXPORT void NMB_failWithMessage(NSString *msg, NSString *file, NSUInteger line);

NIMBLE_EXPORT NMBWaitUntilTimeoutBlock NMB_waitUntilTimeoutBuilder(NSString *file, NSUInteger line);
NIMBLE_EXPORT NMBWaitUntilBlock NMB_waitUntilBuilder(NSString *file, NSUInteger line);

#define NMB_waitUntilTimeout NMB_waitUntilTimeoutBuilder(@(__FILE__), __LINE__)
#define NMB_waitUntil NMB_waitUntilBuilder(@(__FILE__), __LINE__)

#ifndef NIMBLE_DISABLE_SHORT_SYNTAX
#define expect(...) NMB_expect(^{ return (__VA_ARGS__); }, @(__FILE__), __LINE__)
#define expectAction(BLOCK) NMB_expectAction((BLOCK), @(__FILE__), __LINE__)
#define failWithMessage(msg) NMB_failWithMessage(msg, @(__FILE__), __LINE__)
#define fail() failWithMessage(@"fail() always fails")


#define waitUntilTimeout NMB_waitUntilTimeout
#define waitUntil NMB_waitUntil

#undef NIMBLE_VALUE_OF

#endif

NS_ASSUME_NONNULL_END
