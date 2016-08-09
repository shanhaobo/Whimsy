#ifndef __WIZ_BASIC_TT_IS_SAME_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TT_IS_SAME_HPP__SHANHAOBO_19800429__

#include "./WizBasicTTBool.hpp"

namespace Wiz
{
    namespace TT
    {
        namespace Is
        {
            namespace _IMPL
            {
                template<class T1>
                struct Part1
                {
                    /// General Case
                    template<class T2>
                    struct Part2 : ::Wiz::TT::Bool::False
                    {
                    };

                    /// Speicalization for T1 == T2
                    template<>
                    struct Part2<T1> : ::Wiz::TT::Bool::True
                    {
                    };
                };
            } /// end of namespace

            template<typename T1, typename T2>
            struct Same
            {
                static const ::Wiz::Bool::Type bValue = _IMPL::Part1<T1>::Part2<T2>::bValue;
            };
        } /// end of namespace Is
    } /// end of namespace TypeTraits
} /// end of namespace Wiz

#endif /*__WIZ_BASIC_TT_IS_SAME_HPP__SHANHAOBO_19800429__*/
