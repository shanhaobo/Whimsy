#ifndef __WIZ_BASIC_MU_ASSERT_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_MU_ASSERT_HPP__SHANHAOBO_19800429__

#include <assert.h>

#include "../../00_Config/WizConfig.hpp"
#include "../01_Type/WizBasicTypeBool.hpp"
#include "../01_Type/WizBasicTypeInt.hpp"

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#if (WIZ_DEBUG_MODE == WIZ_CFG_TRUE)
#   define WIZ_ASSERT(b)                assert(b)
#   define WIZ_ASSERT_COMMENT(a, c)     assert(((a) && (c)))
#   define WIZ_ASSERT_ERROR(c)          assert((::Wiz::Bool::False && (c)))
#else
#   define WIZ_ASSERT(b)
#   define WIZ_ASSERT_COMMENT(a, c)
#   define WIZ_ASSERT_ERROR(c)
#endif /*WIZ_ASSERT*/

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

namespace Wiz
{
    /// WIZ_COMPILE_TIME_ASSERT_0 (boost 方法)
    /// MSVC error : 使用未定义的 struct“::Wiz::Base::CompileTimeAssert::failure<x>”
    namespace Base
    {
        namespace CompileTimeAssert
        {
            template <::Wiz::Bool::Type> struct Failure;
            template <> struct Failure<::Wiz::Bool::True> { enum{ eValue = 1 }; };
            template<int x> struct Tester{};
        } /// end of namespace CompileTimeAssert
    } /// end of namespace Base
} /// end of namespace Wiz


#define WIZ_COMPILE_TIME_ASSERT_0(x)                                           \
    typedef ::Wiz::Base::CompileTimeAssert::Tester<sizeof(::Wiz::Base::CompileTimeAssert::Failure<(::Wiz::Bool::Type)(x)>)> WIZ_MPP_COMBINE(CompileTimeAssertFailureType, WIZ_COUNTER);

/// Van Horn 1997   MSVC error : 负下标
#define WIZ_COMPILE_TIME_ASSERT_1(x)                                        \
    typedef ::Wiz::U8::Type WIZ_MPP_COMBINE(CompileTimeAssertFailure, WIZ_COUNTER)[(((::Wiz::Bool::Type)(x)) ? 1 : -1)];

///                 MSVC error : 除零  必须在函数中使用,所以不建议使用
#define WIZ_COMPILE_TIME_ASSERT_2(x)                                \
    WIZ_SAFE_MACRO_BEGIN                                            \
    1 / (((::Wiz::Bool::Type)(x)) ? 1 : 0);                           \
    WIZ_SAFE_MACRO_END

/// Jon Jagger 1999 MSVC error : "case 0"已被使用  必须在函数中使用,所以不建议使用
#define WIZ_COMPILE_TIME_ASSERT_3(x)    switch(0){case 0: case x:;}

#define WIZ_COMPILE_TIME_ASSERT(x)      WIZ_COMPILE_TIME_ASSERT_1(x)

#if (WIZ_DEBUG_MODE == WIZ_CFG_TRUE)
#   define WIZ_STATIC_ASSERT(b)         WIZ_COMPILE_TIME_ASSERT(b)
#else
#   define WIZ_STATIC_ASSERT(b)
#endif /*WIZ_ASSERT*/

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#endif /*__WIZ_BASIC_MU_ASSERT_HPP__SHANHAOBO_19800429__*/
