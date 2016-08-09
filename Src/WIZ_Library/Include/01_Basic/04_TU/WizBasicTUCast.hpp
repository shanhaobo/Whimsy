#ifndef __WIZ_BASE_CAST_HPP__SHANHAOBO_19800429__
#define __WIZ_BASE_CAST_HPP__SHANHAOBO_19800429__

#include "../../00_Config/WizConfig.hpp"

#include "./WizBasicTUCastForce.hpp"
#include "./WizBasicTUCastStatic.hpp"
#include "./WizBasicTUCastLexical.hpp"

namespace Wiz
{
    namespace Cast
    {
        ////////////////////////////////////////////////////////////////////////
        template<class RetT, class ArgT>
        WIZ_INLINE RetT Dynamic(ArgT rSrc)
        {
            WIZ_ASSERT(::Wiz::IsValidPtr(rSrc) ? ::Wiz::IsValidPtr(dynamic_cast<RetT>(rSrc)) : ::Wiz::Bool::True);
            return reinterpret_cast<RetT>(rSrc);
        }

        template<class RetT, class ArgT>
        WIZ_INLINE RetT Const(ArgT rSrc)
        {
            return const_cast<RetT>(rSrc);
        }

        template<class RetT, class ArgT>
        WIZ_INLINE RetT Reinterpret(ArgT rSrc)
        {
            return reinterpret_cast<RetT>(rSrc);
        }
        ////////////////////////////////////////////////////////////////////////
        namespace Tag
        {
            struct Static{};
            struct Const{};
            struct Dynamic{};
            struct Reinterpret{};
            struct Polymorphic{};
        } /// end of namespace Tag
        ////////////////////////////////////////////////////////////////////////
    } /// end of namespace Cast
} /// end of namespace Wiz

#define WIZ_DEFCAST_DYNAMIC(T, Dest, Src)		T Dest = ::Wiz::Cast::Dynamic<T>(Src)
#define WIZ_DEFCAST_CONST(T, Dest, Src)			T Dest = ::Wiz::Cast::Const<T>(Src)
#define WIZ_DEFCAST_REINTERPRET(T, Dest, Src)	T Dest = ::Wiz::Cast::Reinterpret<T>(Src)

#endif /*__WIZ_BASE_CAST_HPP__SHANHAOBO_19800429__*/
