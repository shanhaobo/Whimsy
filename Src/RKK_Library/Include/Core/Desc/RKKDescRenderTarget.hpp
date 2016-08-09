#ifndef __CORE_DESC_RENDERTARGET_HPP__SHANHAOBO_19800429__
#define __CORE_DESC_RENDERTARGET_HPP__SHANHAOBO_19800429__

#include "../../../WMS_Base/Include/WMSBase.hpp"

#include "./RKKDescRenderTarget.hpp"
#include "./RKKDescClear.hpp"

namespace rkk
{
    namespace Desc
    {
        namespace RenderTarget
        {
            WMS_STRUCT
            {
                //////////////////////////////////////////////////////////////////////////
                //////////////////////////////////////////////////////////////////////////

                type(
                    ::wms::Size::in                 Width,
                    ::wms::Size::in                 Height,
                    ::rkk::Enum::PixelFormat::in    ColorFormat             = ::rkk::Enum::PixelFormat::eRGBA_16F_16F_16F_16F,
                    ::rkk::Enum::PixelFormat::in    DepthFormat             = ::rkk::Enum::PixelFormat::eDS_24UN_8U,
                    ::rkk::Enum::PixelFormat::in    StencilFormat           = ::rkk::Enum::PixelFormat::eDS_24UN_8U,
                    ::wms::U::in                    index                   = 0,
                    ::wms::Bool::in                 ClearColorEnable        = ::wms::Bool::False,
                    ::wms::Color::in                ClearColorValue         = ::wms::Color::Black,
                    ::wms::Bool::in                 ClearDepthEnable        = ::wms::Bool::False,
                    ::wms::F32::in                  ClearDepthValue         = 0,
                    ::wms::Bool::in                 ClearStencilEnable      = ::wms::Bool::False,
                    ::wms::U::in                    ClearStencilValue       = 0,
                    ::rkk::Enum::MultiSample::in    MultiSample             = ::rkk::Enum::MultiSample::eNone,
                    ::wms::U::in                    MultiSampleQuality      = 0
                    )
                    : m_Width(Width)
                    , m_Height(Height)
                    , m_ColorPixelFormat(ColorFormat)
                    , m_DepthPixelFormat(DepthFormat)
                    , m_StencilPixelFormat(StencilFormat)
                    , m_Index(index)
                    , Clear(ClearColorEnable, ClearColorValue, ClearDepthEnable, ClearDepthValue, ClearStencilEnable, ClearStencilValue)
                    , m_MultiSample(MultiSample, MultiSampleQuality)
                {

                }

                //////////////////////////////////////////////////////////////////////////
                //////////////////////////////////////////////////////////////////////////

                ::wms::Size::type                       m_Width;
                ::wms::Size::type                       m_Height;

                ::rkk::Enum::PixelFormat::type          m_ColorPixelFormat;
                ::rkk::Enum::PixelFormat::type          m_DepthPixelFormat;
                ::rkk::Enum::PixelFormat::type          m_StencilPixelFormat;
                ::wms::U::type                          m_Index;

                ::rkk::Desc::Clear::type                Clear;

                ::rkk::Desc::MultiSample::type          m_MultiSample;

            };
        } /// end of namespace RenderTarget
    } /// end of namespace Desc
} /// end of namespace rkk

#endif /*__CORE_DESC_RENDERTARGET_HPP__SHANHAOBO_19800429__*/

