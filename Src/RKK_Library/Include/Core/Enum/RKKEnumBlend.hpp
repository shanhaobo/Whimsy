#ifndef __CORE_ENUM_BLEND_HPP__SHANHAOBO_19800429__
#define __CORE_ENUM_BLEND_HPP__SHANHAOBO_19800429__

#include "../../../WMS_Base/Include/WMSBase.hpp"

namespace rkk
{
    namespace Enum
    {
        /// Blend
        namespace Blend
        {
            namespace Usage
            {
                enum ____
                {
                    eOpaque             = 0,
                    eAdditive           = 1,
                    eAdditiveColor      = 2,
                    eLight              = 3,
                    eModulate           = 4,
                    eTranslucency       = 5,
                    eTranslucencyColor  = 6,
                }; /// end of enum ____
                typedef ::Wiz::Enum<::rkk::Enum::Blend::Usage::____, ::wms::U8::type>::Type Type;
                WMS_DECLARE(::rkk::Enum::Blend::Usage::Type);
            } /// end of namespace Usage

            namespace Factor
            {
                enum ____
                {
                    eZero               = 0,        /// (0, 0, 0, 0)
                    eOne                = 1,        /// (1, 1, 1, 1)
                    eSrcColor           = 2,        /// (Rs, Gs, Bs, As)
                    eSrcColorInv        = 3,        /// (1 - Rs, 1 - Gs, 1 - Bs, 1 - As)
                    eSrcAlpha           = 4,        /// (As, As, As, As)
                    eSrcAlphaInv        = 5,        /// (1 - As, 1 - As, 1 - As, 1 - As)
                    eDestColor          = 6,        /// (Rd, Gd, Bd, Ad)
                    eDestColorInv       = 7,        /// (1 - Rd, 1 - Gd, 1 - Bd, 1 - Ad)
                    eDestAlpha          = 8,        /// (Ad, Ad, Ad, Ad)
                    eDestAlphaInv       = 9,        /// (1 - Ad, 1 - Ad, 1 - Ad, 1 - Ad)
                }; /// end of enum ____
                typedef ::Wiz::Enum<::rkk::Enum::Blend::Factor::____, ::wms::U8::type>::Type Type;
                WMS_DECLARE(::rkk::Enum::Blend::Factor::Type);
            } /// end of namespace Factor

            /// Blend Operation
            namespace Op
            {
                enum ____
                {
                    eAdd                = 0,        /// Result = Source + Destination
                    eSubtract           = 1,        /// Result = Source - Destination
                    eRevSubtract        = 2,        /// Result = Destination - Source
                    eMin                = 3,        /// Result = MIN(Source, Destination)
                    eMax                = 4,        /// Result = MAX(Source, Destination)
                }; /// end of enum ____
                typedef ::Wiz::Enum<::rkk::Enum::Blend::Op::____, ::wms::U8::type>::Type Type;
                WMS_DECLARE(::rkk::Enum::Blend::Op::Type);
            } /// end of namespace Op

            namespace Test
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
                typedef ::Wiz::Enum<::rkk::Enum::Blend::Test::____, ::wms::U8::type>::Type Type;
                WMS_DECLARE(::rkk::Enum::Blend::Test::Type);
            } /// end of namespace Test
        } /// end of namespace Blend
    } /// end of namespace Enum
} /// end of namespace rkk

#endif /*__CORE_ENUM_BLEND_HPP__SHANHAOBO_19800429__*/
