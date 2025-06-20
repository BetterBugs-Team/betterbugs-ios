/*
 * Author: Landon Fuller <landonf@plausiblelabs.com>
 *
 * Copyright (c) 2013 Plausible Labs Cooperative, Inc.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef PLCRASH_CONSTANTS_H
#define PLCRASH_CONSTANTS_H

#include <assert.h>
#include <TargetConditionals.h>

#if defined(__cplusplus)
#   define PLCR_EXPORT extern "C"
#   define PLCR_C_BEGIN_DECLS extern "C" {
#   define PLCR_C_END_DECLS }
#else
#   define PLCR_EXPORT extern
#   define PLCR_C_BEGIN_DECLS
#   define PLCR_C_END_DECLS
#endif

#if defined(__cplusplus)
#  define NO_OTHER_MACRO_STARTS_WITH_THIS_NAME_
#  define IS_EMPTY_(name) defined(NO_OTHER_MACRO_STARTS_WITH_THIS_NAME_ ## name)
#  define IS_EMPTY(name) IS_EMPTY_(name)
#  if defined(PLCRASHREPORTER_PREFIX) && !IS_EMPTY(PLCRASHREPORTER_PREFIX)
     /** @internal Define the plcrash namespace, automatically inserting an inline namespace containing the configured PLCRASHREPORTER_PREFIX, if any. */
#    define PLCR_CPP_BEGIN_NS namespace plcrash { inline namespace PLCRASHREPORTER_PREFIX {

    /** @internal Close the definition of the `plcrash` namespace (and the PLCRASHREPORTER_PREFIX inline namespace, if any). */
#    define PLCR_CPP_END_NS }}
#  else
#   define PLCR_CPP_BEGIN_NS namespace plcrash {
#   define PLCR_CPP_END_NS }
#  endif
#endif

#ifdef __clang__
#  define PLCR_PRAGMA_CLANG(_p) _Pragma(_p)
#else
#  define PLCR_PRAGMA_CLANG(_p)
#endif

#ifdef __clang__
#  define PLCR_DEPRECATED __attribute__((deprecated))
#else
#  define PLCR_DEPRECATED
#endif

#if defined(__clang__) || defined(__GNUC__)
#  define PLCR_UNUSED __attribute__((unused))
#else
#  define PLCR_UNUSED
#endif

#ifdef PLCR_PRIVATE
/**
 * Marks a definition as deprecated only for for external clients, allowing
 * uses of it internal fo the framework.
 */
#  define PLCR_EXTERNAL_DEPRECATED

/**
 * @internal
 * A macro to put above a definition marked PLCR_EXTERNAL_DEPRECATED that will
 * silence warnings about there being a deprecation documentation marker but the
 * definition not being marked deprecated.
 */
#  define PLCR_EXTERNAL_DEPRECATED_NOWARN_PUSH() \
      PLCR_PRAGMA_CLANG("clang diagnostic push"); \
      PLCR_PRAGMA_CLANG("clang diagnostic ignored \"-Wdocumentation-deprecated-sync\"")

/**
 * @internal
 * A macro to put below a definition marked PLCR_EXTERNAL_DEPRECATED that will
 * silence warnings about there being a deprecation documentation marker but the
 * definition not being marked deprecated.
 */
#  define PLCR_EXTERNAL_DEPRECATED_NOWARN_POP() PLCR_PRAGMA_CLANG("clang diagnostic pop")

#else

#  define PLCR_EXTERNAL_DEPRECATED PLCR_DEPRECATED
#  define PLCR_EXTERNAL_DEPRECATED_NOWARN_PUSH()
#  define PLCR_EXTERNAL_DEPRECATED_NOWARN_PUSH()

#endif /* PLCR_PRIVATE */

#ifdef PLCR_PRIVATE

#endif

#ifdef PLCR_PRIVATE
/**
 * @internal
 * Static compile-time assertion.
 *
 * @param name The assertion name; must be valid for use within a C identifier.
 * @param cond Assertion condition
 */
#  define PLCR_ASSERT_STATIC(name, cond) PLCR_ASSERT_STATIC_(name, cond, __LINE__)
/*
 * C++11 and C11 both provide a static_assert().
 *
 * Otherwise, we have to use typedef-based static assertions.
 */
#  if (defined(__cplusplus) && __cplusplus >= 201103L) || (!defined(__cplusplus) && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)
#    define PLCR_ASSERT_STATIC_(name, cond, line) PLCR_ASSERT_STATIC__(#name, cond)
#    define PLCR_ASSERT_STATIC__(name, cond) static_assert(cond, #name)
#  else
#    define PLCR_ASSERT_STATIC_(name, cond, line) PLCR_ASSERT_STATIC__(name, cond, line)
#    define PLCR_ASSERT_STATIC__(name, cond, line) typedef int plcf_static_assert_##name##_##line [(cond) ? 1 : -1] PLCR_UNUSED
#  endif
#endif /* PLCR_PRIVATE */

#endif /* PLCRASH_CONSTANTS_H */


#ifndef PLCR_FALLTHROUGH
#  if defined(__clang__)
     // Use Clang-specific fallthrough attribute
#    define PLCR_FALLTHROUGH [[clang::fallthrough]]
#  elif defined(__GNUC__) && __GNUC__ >= 7
     // Use GCC-specific fallthrough attribute (requires GCC 7+)
#    define PLCR_FALLTHROUGH __attribute__((fallthrough))
#  else
     // If not supported, define it as empty
#    define PLCR_FALLTHROUGH
#  endif
#endif

#define PLCR_ASSERT_STATIC(name, cond) \
    typedef int plcf_static_assert_##name[(cond) ? 1 : -1]

#ifndef PLCR_LOG
#define PLCR_LOG(...) fprintf(stderr, __VA_ARGS__)
#endif
