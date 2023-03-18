/**
 * @file conform_compiler.h
 * @author (csz@whu.edu.cn)
 * @brief
 * @version 0.1
 * @date 2023-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef CONFORM_COMPILER_H
#define CONFORM_COMPILER_H

#ifdef __GNUC__
#pragma push_macro("GCC_VERSION")
#undef GCC_VERSION
#define GCC_VERSION                                                            \
    (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
/* Test for GCC > 3.2.0 */
/* #if GCC_VERSION > 30200 */
/* #endif */
#endif

#define CONFORM_COMPILER_CONCAT_AS_STR(a, b) #a #b

#if !defined(__STDC_VERSION__)
#define __STDC_VERSION__ 198912L
#endif

#define STDC94 199409L
#define STDC95 STDC94
#define STDC99 199901L
#define STDC11 201112L
#define STDC17 201710L
#define STDC18 STDC17

#define STDCPP98 199711L
#define STDCPP03 STDCPP98
#define STDCPP11 201103L
#define STDCPP14 201402L
#define STDCPP17 201703L
#define STDCPP20 202002L

#ifdef __cplusplus
#define FOO_INLINE inline
#else
#if __STDC_VERSION >= STDC99
#define FOO_INLINE inline
#endif
#endif

#ifndef FOO_INLINE
#ifdef _MSC_VER
#define FOO_INLINE __inline
#else
#define FOO_INLINE __inline__
#endif
#endif

#if defined(__cplusplus)
#if __cplusplus >= STDCPP11
#define THREAD_LOCAL thread_local
#endif
#else
#if __STDC_VERSION__ >= STDC11
#if !defined(__STDC_NO_THREADS__) || !__STDC_NO_THREADS__
#if __STDC_VERSION__ > STDC17
#define THREAD_LOCAL thread_local
#else
#define THREAD_LOCAL _Thread_local
#endif
#endif
#endif
#endif

#ifndef THREAD_LOCAL
#ifdef _MSC_VER
#define THREAD_LOCAL __declspec(thread)
#else
#define THREAD_LOCAL __thread
#endif
#endif

#if defined(__cplusplus)
#if __cplusplus >= STDCPP11
#define FOO_NORETURN [[noreturn]]
#endif
#else
#if __STDC_VERSION__ > STDC17
#define FOO_NORETURN [[noreturn]]
#elif __STDC_VERSION >= STDC11
#define FOO_NORETURN _Noreturn
#endif
#endif

#ifndef FOO_NORETURN
#ifdef _MSC_VER
#define FOO_NORETURN __declspec(noreturn)
#else
#define FOO_NORETURN __attribute__((noreturn))
#endif
#endif

#if defined(__cplusplus)
#if __cplusplus >= STDCPP11
#define ALIGNAS(n) alignas(n)
#endif
#else
#if __STDC_VERSION__ > STDC17
#define ALIGNAS(n) alignas(n)
#elif __STDC_VERSION__ >= STDC11
#define ALIGNAS(n) _Alignas(n)
#endif
#endif

#ifndef ALIGNAS
#ifdef _MSC_VER
#define ALIGNAS(n) __declspec(align(n))
#else
#define ALIGNAS(n) __attribute__((aligned(n)))
#endif
#endif

#if defined(__cplusplus)
#if __cplusplus >= STDCPP11
#define STATIC_ASSERT(n, ...)                                                  \
    static_assert(n, CONFORM_COMPILER_CONCAT_AS_STR(, __VA_ARGS__))
#endif
#else
#if __STDC_VERSION__ > STDC17
#define STATIC_ASSERT(n, ...) static_assert(n, #__VA_ARGS__)
#elif __STDC_VERSION__ >= STDC11
#define STATIC_ASSERT(n, ...) _Static_assert(n, #__VA_ARGS__)
#endif
#endif

#ifndef STATIC_ASSERT
#define _CSTATIC_ASSERT_CONCAT(msg, line, counter)                             \
    static_assert_##line##_##counter##_failed_##msg
#define CSTATIC_ASSERT_CONCAT(msg, line, counter)                              \
    _CSTATIC_ASSERT_CONCAT(msg, line, counter)
#define STATIC_ASSERT(n, ...)                                                  \
    typedef char CSTATIC_ASSERT_CONCAT(__VA_ARGS__, __LINE__,                  \
                                       __COUNTER__)[(n) ? 1 : -1]
#endif

#ifdef __cplusplus
#if __cplusplus >= STDCPP14
#define DEPRECATED(...)                                                        \
    [[deprecated(CONFORM_COMPILER_CONCAT_AS_STR(, __VA_ARGS__))]]
#endif
#else
#if __STDC_VESRION__ > STDC17
#define DEPRECATED(...)                                                        \
    [[deprecated(CONFORM_COMPILER_CONCAT_AS_STR(, __VA_ARGS__))]]
#endif
#endif

#ifndef DEPRECATED
#ifdef _MSC_VER
#define DEPRECATED(...)                                                        \
    __declspec(deprecated(CONFORM_COMPILER_CONCAT_AS_STR(, __VA_ARGS__)))
#else
#define DEPRECATED(...)                                                        \
    __attribute__((deprecated(CONFORM_COMPILER_CONCAT_AS_STR(, __VA_ARGS__))))
#endif
#endif

#ifdef __cplusplus
#if __cplusplus >= STDCPP17
#define FALLTHROUGH [[fallthrough]]
#endif
#else
#if __STDC_VESRION__ > STDC17
#define FALLTHROUGH [[fallthrough]]
#endif
#endif

#ifndef FALLTHROUGH
#ifdef _MSC_VER
#define FALLTHROUGH
#else
#define FALLTHROUGH __attribute__((fallthrough))
#endif
#endif

#ifdef __cplusplus
#if __cplusplus >= STDCPP17
#define MAYBE_UNUSED [[maybe_unused]]
#endif
#else
#if __STDC_VESRION__ > STDC17
#define MAYBE_UNUSED [[maybe_unused]]
#endif
#endif

#ifndef MAYBE_UNUSED
#ifdef _MSC_VER
#define MAYBE_UNUSED
#else
#define MAYBE_UNUSED __attribute__((unused))
#endif
#endif

#ifdef __cplusplus
#if __cplusplus >= STDCPP20
#define NODISCARD_RESULT(...)                                                  \
    [[nodiscard(CONFORM_COMPILER_CONCAT_AS_STR(, __VA_ARGS__))]]
#elif __cplusplus >= STDCPP17
#define NODISCARD_RESULT(...) [[nodiscard]]
#endif
#else
#if __STDC_VESRION__ > STDC17
#define NODISCARD_RESULT(...)                                                  \
    [[nodiscard(CONFORM_COMPILER_CONCAT_AS_STR(, __VA_ARGS__))]]
#endif
#endif

#ifndef NODISCARD_RESULT
#ifdef _MSC_VER
#include <sal.h>
#define NODISCARD_RESULT(...) _Check_return_
#else
#define NODISCARD_RESULT(...) __attribute__((warn_unused_result))
#endif
#endif

#ifdef __cplusplus
#else
#if __STDC_VESRION__ >= STDC99
#define RESTRICT restrict
#endif
#endif

#ifndef RESTRICT
#ifdef _MSC_VER
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif
#endif

#ifdef __cplusplus
#if __cplusplus >= STDCPP11
#define NULLPTR nullptr
#endif
#else
#if __STDC_VERSION__ > STDC17
#define NULLPTR nullptr
#endif
#endif

#ifndef NULLPTR
#ifdef __cplusplus
#include <cstddef>
#define NULLPTR NULL
#else
#include <stddef.h>
#define NULLPTR NULL
#endif
#endif

#ifdef __GNUC__
#undef GCC_VERSION
#pragma pop_macro("GCC_VERSION")
#endif

#endif
