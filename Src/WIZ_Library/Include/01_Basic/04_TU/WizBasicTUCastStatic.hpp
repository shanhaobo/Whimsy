#ifndef __WIZ_BASIC_TU_CAST_STATIC_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TU_CAST_STATIC_HPP__SHANHAOBO_19800429__

#include "../01_Type/WizBasicType.hpp"

namespace Wiz
{
    namespace Cast
    {
        ////////////////////////////////////////////////////////////////////////
        template<class Ret, class Arg>
        WIZ_INLINE Ret Static(Arg rSrc)
        {
            return static_cast<Ret>(rSrc);
        }

        template<class Ret, class Arg>
        WIZ_INLINE Ret Static(Arg const * const rSrc)
        {
            return static_cast<Ret>(static_cast<void const * const>(rSrc));
        }

        template<class Ret, class Arg>
        WIZ_INLINE Ret Static(Arg * const rSrc)
        {
            return static_cast<Ret>(static_cast<void * const>(rSrc));
        }

//         template<class Ret, class Arg>
//         WIZ_INLINE Ret Static(Arg const * rSrc)
//         {
//             return static_cast<Ret>(static_cast<void const *>(rSrc));
//         }
        ////////////////////////////////////////////////////////////////////////
    } /// end of namespace Cast
} /// end of namespace Wiz

#define WIZ_DEFCAST_STATIC(T, Dest, Src)	T Dest = ::Wiz::Cast::Static<T>(Src)

#endif /*__WIZ_BASIC_TU_CAST_STATIC_HPP__SHANHAOBO_19800429__*/
