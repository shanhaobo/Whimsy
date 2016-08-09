#ifndef __CORE_ENUM_MULTISAMPLE_HPP__SHANHAOBO_19800429__
#define __CORE_ENUM_MULTISAMPLE_HPP__SHANHAOBO_19800429__

#include "../../../WMS_Base/Include/WMSBase.hpp"

namespace rkk
{
    namespace Enum
    {
        /// MultiSample
        namespace MultiSample
        {
            enum ____
            {
                eNone       = 0,
                e01         = 1,
                e02         = 2,
                e03         = 3,
                e04         = 4,
                e05         = 5,
                e06         = 6,
                e07         = 7,
                e08         = 8,
                e09         = 9,
                e10         = 10,
                e11         = 11,
                e12         = 12,
                e13         = 13,
                e14         = 14,
                e15         = 15,
                e16         = 16,
            }; /// end of namespace ____
            typedef ::Wiz::Enum<::rkk::Enum::MultiSample::____, ::wms::U8::type>::Type Type;
            WMS_DECLARE(::rkk::Enum::MultiSample::Type);
        } /// end of namespace MultiSample
    } /// end of namespace Enum
} /// end of namespace rkk

#endif /*__CORE_ENUM_MULTISAMPLE_HPP__SHANHAOBO_19800429__*/
