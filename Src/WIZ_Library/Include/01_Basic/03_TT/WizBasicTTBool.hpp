#ifndef __WIZ_BASIC_TT_BOOL_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TT_BOOL_HPP__SHANHAOBO_19800429__

/// 只是用了::Wiz::Bool::Type
#include "../01_Type/WizBasicTypeBool.hpp"

namespace Wiz
{
    namespace TT
    {
        namespace Bool
        {
            template<::Wiz::Bool::Type bV>
            struct Value
            {
#if 0
                enum {bValue = bV};
#else
                static const ::Wiz::Bool::Type bValue = bV;
#endif
            };

            struct True : Value<::Wiz::Bool::True>
            {
            };
            struct False : Value<::Wiz::Bool::False>
            {
            };
        } /// end of namespace Bool
    } /// end of namespace TypeTraits
} /// end of namespace Wiz

#endif /*__WIZ_BASIC_TT_BOOL_HPP__SHANHAOBO_19800429__*/
