#ifndef __CORE_ENUM_PIXELFORMAT_HPP__SHANHAOBO_19800429__
#define __CORE_ENUM_PIXELFORMAT_HPP__SHANHAOBO_19800429__

#include "../../../WMS_Base/Include/WMSBase.hpp"

namespace rkk
{
    namespace Enum
    {
        namespace PixelFormat
        {
            /// UN => UNORM : Unsigned normalized integer;
            /// which is interpreted in a resource as an unsigned integer,
            /// and is interpreted in a shader as an unsigned normalized floating-point value in the range [0, 1]. 

            /// SN => SNORM : Signed normalized integer;
            /// which is interpreted in a resource as a signed integer,
            /// and is interpreted in a shader as a signed normalized floating-point value in the range [-1, 1]. 

            /// TYPELESS : 

            /// sRGB : Standard RGB color space
            enum Type
            {
                eUnsupported                    = 0,
                /// =========================== ///
                eRGBA_32_32_32_32,              /// TypeLess
                eRGBA_32F_32F_32F_32F,          /// Float / Real
                eRGBA_32U_32U_32U_32U,          /// UInt
                eRGBA_32S_32S_32S_32S,          /// Sint / int

                eRGBA_16_16_16_16,
                eRGBA_16F_16F_16F_16F,          /// D3DDECLTYPE_FLOAT16_4(D3D9)
                eRGBA_16U_16U_16U_16U,
                eRGBA_16S_16S_16S_16S,
                eRGBA_16UN_16UN_16UN_16UN,      /// UNORM / unsigned-normalized integer 
                eRGBA_16SN_16SN_16SN_16SN,      /// SNORM

                eRGBA_10_10_10_2,
                eRGBA_10U_10U_10U_2U,
                eRGBA_10UN_10UN_10UN_2UN,

                eRGBA_8_8_8_8,
                eRGBA_8U_8U_8U_8U,
                eRGBA_8S_8S_8S_8S,
                eRGBA_8UN_8UN_8UN_8UN,
                eRGBA_8SN_8SN_8SN_8SN,
                eRGBA_8UN_8UN_8UN_8UN_sRGB,     /// In sRGB Color Space
                /// =========================== ///

                /// =========================== ///
                eRGB_32_32_32,
                eRGB_32F_32F_32F,               /// D3DDECLTYPE_FLOAT3(D3D9)
                eRGB_32U_32U_32U,
                eRGB_32S_32S_32S,

                eRGB_11F_11F_10F,

                eRGX_32_8_24,

                eRXX_32F_8_24,
                /// =========================== ///

                /// =========================== ///
                eRG_32_32,
                eRG_32F_32F,                    /// D3DDECLTYPE_FLOAT2(D3D9)
                eRG_32U_32U,
                eRG_32S_32S,

                eRG_24_8,

                eRG_16_16,
                eRG_16F_16F,                    /// D3DDECLTYPE_FLOAT16_2(D3D9)
                eRG_16U_16U,
                eRG_16S_16S,
                eRG_16UN_16UN,
                eRG_16SN_16SN,

                eRG_8_8,
                eRG_8U_8U,
                eRG_8S_8S,
                eRG_8UN_8UN,
                eRG_8SN_8SN,
                /// =========================== ///

                /// =========================== ///
                eR_32,
                eR_32F,
                eR_32U,
                eR_32S,

                eR_16,
                eR_16F,
                eR_16U,
                eR_16S,
                eR_16UN,
                eR_16SN,

                eR_8,
                eR_8U,
                eR_8S,
                eR_8UN,
                eR_8SN,
                /// ========================== ///

                /// ========================== ///
                eBC1,                           /// Block-Compression
                eBC1_UN,                        /// DXT1 / DXT2
                eBC1_UN_sRGB,

                eBC2,                           /// Block-Compression
                eBC2_UN,                        /// DXT3 / DXT4
                eBC2_UN_sRGB,

                eBC3,                           /// Block-Compression
                eBC3_UN,                        /// DXT5
                eBC3_UN_sRGB,

                eBC4,                           /// Block-Compression
                eBC4_UN,
                eBC4_SN,

                eBC5,                           /// Block-Compression
                eBC5_UN,
                eBC5_SN,
                /// =========================== ///

                /// =========================== ///
                eDSX_24F_8U_24U,

                eD_32F,

                eDS_24UN_8U,

                eD_16UN,

                eA_8UN,
                /// =========================== ///

                /// =========================== ///
                eX32_TYPELESS_G8X24_UINT,

                eR24_UNORM_X8_TYPELESS,
                eX24_TYPELESS_G8_UINT,

                eR1_UNORM,
                eR9G9B9E5_SHAREDEXP,
                eR8G8_B8G8_UNORM,
                eG8R8_G8B8_UNORM,

                eB5G6R5_UNORM,
                eB5G5R5A1_UNORM,
                eB8G8R8A8_UNORM,
                eB8G8R8X8_UNORM,
                /// ========================== ///
                eMax
            }; /// end of enum Type
            typedef ::Wiz::Enum<::rkk::Enum::PixelFormat::Type, ::wms::U8::type>::Type type;
            WMS_DECLARE(::rkk::Enum::PixelFormat::type);
        } /// end of namespace PixelFormat
    } /// end of namespace Enum
} /// end of namespace rkk

#endif /*__CORE_ENUM_PIXELFORMAT_HPP__SHANHAOBO_19800429__*/

