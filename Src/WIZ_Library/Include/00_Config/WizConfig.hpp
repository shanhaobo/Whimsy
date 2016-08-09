#ifndef __WIZ_CONFIG_HPP__SHANHAOBO_19800429__
#define __WIZ_CONFIG_HPP__SHANHAOBO_19800429__

////////////////////////////////////////////////////////////////////////////////
#if !defined(__cplusplus)
#   error C++ compiler required.
#endif /*#if !defined(__cplusplus)*/
////////////////////////////////////////////////////////////////////////////////

#define WIZ_CFG_TRUE                1
#define WIZ_CFG_FALSE               2

#define WIZ_CFG_COMPILER_MSVC       1
#define WIZ_CFG_COMPILER_GNUC       2

#define WIZ_CFG_PLATFORM_WINDOWS    1
#define WIZ_CFG_PLATFORM_LINUX      2

#define WIZ_CFG_ARCH_IA32           1
#define WIZ_CFG_ARCH_IA64           2

#define WIZ_CFG_ENDIAN_LITTLE       1
#define WIZ_CFG_ENDIAN_BIG          2

#define WIZ_CFG_LIB_TYPE_STATIC     1
#define WIZ_CFG_LIB_TYPE_DYNAMIC    2

//////////////////////////////////////////////////////////////////////////
/// C++ 特性 （C++11）

/// template... Variadic template 可变参数模板 (CPP11)
#define WIZ_CFG_CPP_VARIADIC_TEMPLATE   WIZ_CFG_FALSE

/// static_assert 编译期间断言
#define WIZ_CFG_CPP_STATIC_ASSERT       WIZ_CFG_FALSE

/// nullptr 空指针
#define WIZ_CFG_CPP_NULLPTR             WIZ_CFG_FALSE

/// final 不可重载
#define WIZ_CFG_CPP_FINAL               WIZ_CFG_FALSE

////////////////////////////////////////////////////////////////////////////////
/// compiler
#if defined(_MSC_VER)
#   define WIZ_CFG_COMPILER         WIZ_CFG_COMPILER_MSVC
/// warning C4127: conditional expression is constant /// http://msdn.microsoft.com/zh-cn/library/6t66728h%28v=vs.80%29.aspx/html
/// warning C4146: unary minus operator applied to unsigned Type, result still unsigned
/// warning C4200: nonstandard extension used : zero-sized array in struct/union
/// warning C4201: nonstandard extension used : nameless struct/union /// http://msdn.microsoft.com/zh-cn/library/c89bw853%28v=vs.90%29.aspx
/// warning C4251: AAA needs to have dll-interface to be used by clients of BBB
/// warning C4275: non dll-interface class AAA used as base for dll-interface class BBB
/// Warning C4355: 'this' : used in base member initializer list /// http://connect.microsoft.com/VisualStudio/feedback/details/718050
/// warning C4503: 超出修饰名的长度，名称被截断 /// http://msdn.microsoft.com/zh-cn/library/074af4b6%28v=vs.90%29.aspx
/// warning C4996: 'AAAA': This function or variable may be unsafe. Consider using BBBB instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
#   pragma warning(disable: 4127 4146 4200 4201 4251 4275 4355 4503 4996)
#elif defined(__GNUC__)
#   define WIZ_CFG_COMPILER         WIZ_CFG_COMPILER_GNUC
#else
#   error  MSVC or GNUC compiler required.
#endif 

#if (WIZ_CFG_COMPILER == WIZ_CFG_COMPILER_MSVC)
#elif (WIZ_CFG_COMPILER == WIZ_CFG_COMPILER_GNUC)
#else
#error Illegal compiler
#endif /*#if (WIZ_COMPILER == WIZ_COMPILER_MSVC)*/
////////////////////////////////////////////////////////////////////////////////

/// align
#if (WIZ_CFG_COMPILER == WIZ_CFG_COMPILER_MSVC)
#   define WIZ_ALIGN_MSVC(n)    __declspec(align(n))
#   define WIZ_ALIGN_GNUC(n)
#elif (WIZ_CFG_COMPILER == WIZ_CFG_COMPILER_GNUC)
#   define WIZ_ALIGN_MSVC(n)
#   define WIZ_ALIGN_GNUC(n)    __attribute__((aligned(n)))
#endif /*#if (WIZ_CFG_COMPILER == WIZ_CFG_COMPILER_MSVC)*/

#define  WIZ_ALIGN(n, t)  WIZ_ALIGN_MSVC(n) t WIZ_ALIGN_GNUC(n)
#define  WIZ_ALIGN_16(t)  WIZ_ALIGN(16, t)

////////////////////////////////////////////////////////////////////////////////
/// platform
#if defined(__WIN32__) || defined(_WIN32)
#   include <windows.h>
#   include <xmmintrin.h>
#   define WIZ_CFG_PLATFORM         WIZ_CFG_PLATFORM_WINDOWS
#else
#   include <xmmintrin.h>
#   define WIZ_CFG_PLATFORM         WIZ_CFG_PLATFORM_LINUX
#endif /*#if defined(__WIN32__) || defined(_WIN32)*/
////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
#define WIZ_FILE                        __FILE__                        
#define WIZ_LINE                        __LINE__
#define WIZ_FUNC                        __FUNCTION__
#ifdef __COUNTER__
#   define WIZ_COUNTER                  __COUNTER__
#else
#   define WIZ_COUNTER                  WIZ_LINE
#endif //// #ifndef __COUNTER__
//////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// architecture
#if defined(__x86_64__) || defined(_M_X64)
#   define WIZ_CFG_ARCHITECTURE     WIZ_CFG_ARCH_IA64
#else
#   define WIZ_CFG_ARCHITECTURE     WIZ_CFG_ARCH_IA32
#endif /*#if defined(__x86_64__) || defined(_M_X64)*/
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// KEY WOARD (inLINE RESTRICT)
#if (WIZ_CFG_COMPILER == WIZ_CFG_COMPILER_MSVC)
#       define WIZ_INLINE __forceinline
#       define WIZ_RESTRICT __restrict
#elif (WIZ_CFG_COMPILER == WIZ_CFG_COMPILER_GNUC)
#       define WIZ_INLINE __inline
#       define WIZ_RESTRICT __restrict__
#else
#   error illegal compiler
#endif /*#if (WIZ_CFG_COMPILER == WIZ_CFG_COMPILER_MSVC)*/

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// PLATFORM
#if (WIZ_CFG_COMPILER == WIZ_CFG_COMPILER_MSVC)
#   define WIZ_EXPORT   __declspec(dllexport)
#   define WIZ_PRIVATE
/// DEBUG MODE
#   ifndef WIZ_DEBUG_MODE
#       ifdef _DEBUG
#           define WIZ_DEBUG_MODE  WIZ_CFG_TRUE
#       else
#           define WIZ_DEBUG_MODE  WIZ_CFG_FALSE
#       endif /*DEBUG MODE*/
#   endif /*WIZ_DEBUG_MODE*/
#elif (WIZ_CFG_COMPILER == WIZ_CFG_COMPILER_GNUC)
#   define WIZ_EXPORT   __attribute__((visibility("default")))
#   define WIZ_PRIVATE  __attribute__((visibility("hidden")))
/// DEBUG MODE
#   ifndef WIZ_DEBUG_MODE
#       ifdef DEBUG
#           define WIZ_DEBUG_MODE  WIZ_CFG_TRUE
#       else
#           define WIZ_DEBUG_MODE  WIZ_CFG_FALSE
#       endif /*DEBUG MODE*/
#   endif /*WIZ_DEBUG_MODE*/
#else
#   error illegal compiler
#endif /*#if (WIZ_CFG_PLATFORM == WIZ_CFG_PLATFORM_LINUX)*/

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
#define WIZ_STDCALL         __stdcall
#define WIZ_CDECL           __cdecl

#define WIZ_STD_API         WIZ_STDCALL
#define WIZ_MPAPI           WIZ_CDECL
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
#ifndef WIZ_CUSTOM_CONFIG_HPP
#define WIZ_CUSTOM_CONFIG_HPP "./WizCustomConfig.hpp"
#endif /*#ifndef WIZ_CUSTOM_CONFIG_HPP*/

/// custom configuration
#ifndef __WIZ_CUSTOM_CONFIG_HPP__SHANHAOBO_19800429__
#define __WIZ_CUSTOM_CONFIG_HPP__SHANHAOBO_19800429__
#include WIZ_CUSTOM_CONFIG_HPP
#endif  /*__WIZ_CUSTOM_CONFIG_HPP__SHANHAOBO_19800429__*/
////////////////////////////////////////////////////////////////////////////////

#if (WIZ_CFG_LIB_TYPE == WIZ_CFG_LIB_TYPE_STATIC)
#   undef       WIZ_EXPORT
#   define      WIZ_EXPORT

#   undef       WIZ_PRIVATE
#   define      WIZ_PRIVATE
#endif /*WIZ_LIB_TYPE*/

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

#if (!defined(WIZ_CFG_INT_SIZE) || ((WIZ_CFG_INT_SIZE != 8) && (WIZ_CFG_INT_SIZE != 16) && (WIZ_CFG_INT_SIZE != 32) && (WIZ_CFG_INT_SIZE != 64) && (WIZ_CFG_INT_SIZE != 128)))
#   undef WIZ_CFG_INT_SIZE
#   define WIZ_CFG_INT_SIZE          32
#endif /*WIZ_INT_SIZE*/

#if (!defined(WIZ_CFG_BOOL_SIZE) || ((WIZ_CFG_BOOL_SIZE != 8) && (WIZ_CFG_BOOL_SIZE != 16) && (WIZ_CFG_BOOL_SIZE != 32) && (WIZ_CFG_BOOL_SIZE != 64)))
#   undef WIZ_CFG_BOOL_SIZE
#   define WIZ_CFG_BOOL_SIZE         32
#endif /*WIZ_BOOL_SIZE*/

#if (!defined(WIZ_CFG_REAL_SIZE) || ((WIZ_CFG_REAL_SIZE != 32) && (WIZ_CFG_REAL_SIZE != 64)))
#   undef WIZ_CFG_REAL_SIZE
#   define WIZ_CFG_REAL_SIZE         32
#endif /*WIZ_INT_SIZE*/

////////////////////////////////////////////////////////////////////////////////
/// default byte order
#if (!defined(WIZ_CFG_ENDIAN_NATIVE) || ((WIZ_CFG_ENDIAN_NATIVE != WIZ_CFG_ENDIAN_LITTLE) && (WIZ_CFG_ENDIAN_NATIVE != WIZ_CFG_ENDIAN_BIG)))
#   undef  WIZ_CFG_ENDIAN_NATIVE
#   define WIZ_CFG_ENDIAN_NATIVE         WIZ_CFG_ENDIAN_LITTLE
#endif /*default host byte order*/

#if (!defined(WIZ_CFG_ENDIAN_CRITERION) || ((WIZ_CFG_ENDIAN_CRITERION != WIZ_CFG_ENDIAN_LITTLE) && (WIZ_CFG_ENDIAN_CRITERION != WIZ_CFG_ENDIAN_BIG)))
#   undef  WIZ_CFG_ENDIAN_CRITERION
#   define WIZ_CFG_ENDIAN_CRITERION    WIZ_CFG_ENDIAN_LITTLE
#endif /*default criterion byte order*/
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
#endif /*__WIZ_CONFIG_HPP__SHANHAOBO_19800429__*/
