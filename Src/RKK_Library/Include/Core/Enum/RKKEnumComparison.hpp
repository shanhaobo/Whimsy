#ifndef __CORE_ENUM_COMPARISON_HPP__SHANHAOBO_19800429__
#define __CORE_ENUM_COMPARISON_HPP__SHANHAOBO_19800429__

#include "../../../WMS_Base/Include/WMSBase.hpp"

namespace rkk
{
    namespace Enum
    {
        namespace Comparison
        {
            enum ____
            {
                eNever	            = 0,
                eAlways             = 1,
                eEqual	            = 2,
                eNotEqual	        = 3,
                eLess	            = 4,
                eLessEqual	        = 5,
                eGreater	        = 6,
                eGreaterEqual       = 7,
            }; /// end of enum ____
            typedef ::Wiz::Enum<::rkk::Enum::Comparison::____, ::wms::U8::type>::Type Type;
            WMS_DECLARE(::rkk::Enum::Comparison::Type);
        } /// end of namespace Comparison
    } /// end of namespace Enum
} /// end of namespace rkk

#endif /*__CORE_ENUM_COMPARISON_HPP__SHANHAOBO_19800429__*/

