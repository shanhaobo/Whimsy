#ifndef __CORE_ENUM_STENCIL_HPP__SHANHAOBO_19800429__
#define __CORE_ENUM_STENCIL_HPP__SHANHAOBO_19800429__

#include "../../../WMS_Base/Include/WMSBase.hpp"

namespace rkk
{
    namespace Enum
    {
        namespace Stencil
        {
            /// Operation
            namespace Op
            {
                enum ____
                {
                    eKeep               = 0,
                    eZero               = 1,
                    eReplace            = 2,
                    eInvert             = 3,
                    eIncrementClamp     = 4,    /// clamping to the maximum value.
                    eDecrementClamp     = 5,    /// clamping to zero
                    eIncrementWrap      = 6,    /// wrapping to zero if the new value exceeds the maximum value.
                    eDecrementWrap      = 7,    /// wrapping to the maximum value if the new value is less than zero. 
                }; /// end of enum ____
                typedef ::Wiz::Enum<::rkk::Enum::Stencil::Op::____, ::wms::U8::type>::Type Type;
                WMS_DECLARE(::rkk::Enum::Stencil::Op::Type);
            } /// end of namespace Op

            namespace Compare
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
                typedef ::Wiz::Enum<::rkk::Enum::Stencil::Compare::____, ::wms::U8::type>::Type Type;
                WMS_DECLARE(::rkk::Enum::Stencil::Compare::Type);
            } /// end of namespace Compare 
        } /// end of namespace Stencil
    } /// end of namespace Enum
} /// end of namespace rkk

#endif /*__CORE_ENUM_STENCIL_HPP__SHANHAOBO_19800429__*/
