#ifndef __WIZ_BASIC_TYPE_INT_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TYPE_INT_HPP__SHANHAOBO_19800429__

////////////////////////////////////////////////////////////////////////////

#include "./WizBasicTypeDeclareUtils.hpp"

namespace Wiz
{
    ///====================================///

    namespace I
    {
        WIZ_DECLARE_SIMPLE(int);
    }

    namespace U
    {
        WIZ_DECLARE_SIMPLE(unsigned int);
    }

    ///====================================///
#   if (WIZ_CFG_COMPILER == WIZ_CFG_COMPILER_MSVC)
    namespace I8
    {
        WIZ_DECLARE_SIMPLE(__int8);
    }

    namespace U8
    {
        WIZ_DECLARE_SIMPLE(unsigned __int8);
    }

    namespace I16
    {
        WIZ_DECLARE_SIMPLE(__int16);
    }

    namespace U16
    {
        WIZ_DECLARE_SIMPLE(unsigned __int16);
    }

    namespace I32
    {
        WIZ_DECLARE_SIMPLE(__int32);
    }

    namespace U32
    {
        WIZ_DECLARE_SIMPLE(unsigned __int32);
    }

    namespace I64
    {
        WIZ_DECLARE_SIMPLE(__int64);
    }

    namespace U64
    {
        WIZ_DECLARE_SIMPLE(unsigned __int64);
    }
#   elif (WIZ_CFG_COMPILER == WIZ_CFG_COMPILER_GNUC)
#   include <inttypes.h>
    namespace I8
    {
        WIZ_DECLARE_SIMPLE(::int8_t);
    }

    namespace U8
    {
        WIZ_DECLARE_SIMPLE(::uint8_t);
    }

    namespace I16
    {
        WIZ_DECLARE_SIMPLE(::int16_t);
    }

    namespace U16
    {
        WIZ_DECLARE_SIMPLE(::uint16_t);
    }

    namespace I32
    {
        WIZ_DECLARE_SIMPLE(::int32_t);
    }

    namespace U32
    {
        WIZ_DECLARE_SIMPLE(::uint32_t);
    }

    namespace I64
    {
        WIZ_DECLARE_SIMPLE(::int64_t);
    }

    namespace U64
    {
        WIZ_DECLARE_SIMPLE(::uint64_t);
    }
#   else
#       error Illegal compiler
#   endif /*#if (WIZ_COMPILER == WIZ_COMPILER_MSVC)*/
    ///====================================///

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

#   define WIZ_MIN_INT(t) ((t)(((t)1) << ((sizeof(t) << 3) - 1)))
#   define WIZ_MAX_INT(t) ((t)(~(WIZ_MIN_INT(t))))
#   define WIZ_MIN_UINT(t) ((t)0)
#   define WIZ_MAX_UINT(t) ((t)(~(WIZ_MIN_UINT(t))))

#   define WIZ_MINMAX_INT(t)                   \
    static const t Min = WIZ_MIN_INT(t);       \
    static const t Max = WIZ_MAX_INT(t);

#   define WIZ_MINMAX_UINT(t)                   \
    static const t Min = WIZ_MIN_UINT(t);       \
    static const t Max = WIZ_MAX_UINT(t);

///====================================///

    namespace I
    {
        WIZ_MINMAX_INT(Type);
    } /// end of namespace I

    namespace U
    {
        WIZ_MINMAX_UINT(Type);
    } /// end of namespace U

    namespace I8
    {
        WIZ_MINMAX_INT(Type);
    } /// end of namespace I8
    namespace U8
    {
        WIZ_MINMAX_UINT(Type);
    } /// end of namespace U8

    namespace I16
    {
        WIZ_MINMAX_INT(Type);
    } /// end of namespace I16
    namespace U16
    {
        WIZ_MINMAX_UINT(Type);
    } /// end of namespace U16

    namespace I32
    {
        WIZ_MINMAX_INT(Type);
    } /// end of namespace I32
    namespace U32
    {
        WIZ_MINMAX_UINT(Type);
    } /// end of namespace U32

    namespace I64
    {
        WIZ_MINMAX_INT(Type);
    } /// end of namespace I64
    namespace U64
    {
        WIZ_MINMAX_UINT(Type);
    } /// end of namespace U64
    ///====================================///

#   undef WIZ_MINMAX_INT
#   undef WIZ_MINMAX_UINT

#   undef WIZ_MIN_INT
#   undef WIZ_MIN_UINT

#   undef WIZ_MAX_INT
#   undef WIZ_MAX_UINT

} /// end of namespace Wiz

////////////////////////////////////////////////////////////////////////////

#endif /*__WIZ_BASIC_TYPE_INT_HPP__SHANHAOBO_19800429__*/
