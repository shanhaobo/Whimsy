#ifndef __WIZ_BASIC_TU_CAST_FORCE_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TU_CAST_FORCE_HPP__SHANHAOBO_19800429__

#include "../01_Type/WizBasicType.hpp"

namespace Wiz
{
    namespace Cast
    {
        ////////////////////////////////////////////////////////////////////////
        // general case
        template<class Ret, class Arg>
        WIZ_INLINE Ret& Force(Arg & rSrc)
        {
            return(*reinterpret_cast<Ret *>(&rSrc));
        }

        // specialization for const
        template<class Ret, class Arg>
        WIZ_INLINE Ret const & Force(Arg const & rSrc)
        {
            return(*reinterpret_cast<Ret const *>(&rSrc));
        }
        ////////////////////////////////////////////////////////////////////////
    } /// end of namespace Cast
} /// end of namespace Wiz

#define WIZ_DEFCAST_FORCE(T, Dest, Src)	T Dest = ::Wiz::Cast::Force<T>(Src)

#endif /*__WIZ_BASIC_TU_CAST_FORCE_HPP__SHANHAOBO_19800429__*/
