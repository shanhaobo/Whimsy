#ifndef __RENDERKINGKONG_DES_CLEAR_HPP__SHANHAOBO_19800429__
#define __RENDERKINGKONG_DES_CLEAR_HPP__SHANHAOBO_19800429__

#include "../../../WMS_Base/Include/WMSColor.hpp"

namespace rkk
{
    namespace Desc
    {
        namespace Clear
        {
            WMS_STRUCT
            {
                //////////////////////////////////////////////////////////////////////////
                //////////////////////////////////////////////////////////////////////////

                struct tColorDesc
                {
                public:
                    tColorDesc(
                        ::wms::Bool::in    Enable   = ::wms::Bool::False,
                        ::wms::Color::in   Value    = ::wms::Color::Black
                        )
                        : m_Enable(Enable)
                        , m_Value(Value)
                    {

                    }
                    ::wms::Void::type Set(
                        ::wms::Bool::in    Enable   = ::wms::Bool::False,
                        ::wms::Color::in   Value    = ::wms::Color::Black
                        )
                    {
                        m_Enable        = Enable;
                        m_Value         = Value;
                    }

                    ::wms::Void::type Set(
                        tColorDesc const &  inDesc
                        )
                    {
                        m_Enable        = inDesc.m_Enable;
                        m_Value         = inDesc.m_Value;
                    }
                public:
                    ::wms::Bool::type       m_Enable;
                    ::wms::Color::type      m_Value;
                };

                struct tDepthDesc
                {
                public:
                    tDepthDesc(
                        ::wms::Bool::in     Enable = ::wms::Bool::False,
                        ::wms::F32::in      Value = 0
                        )
                        : m_Enable(Enable)
                        , m_Value(Value)
                    {

                    }
                    ::wms::Void::type Set(
                        ::wms::Bool::in    Enable = ::wms::Bool::False,
                        ::wms::F32::in      Value = 0
                        )
                    {
                        m_Enable        = Enable;
                        m_Value         = Value;
                    }

                    ::wms::Void::type Set(
                        tDepthDesc const &  inDesc
                        )
                    {
                        m_Enable        = inDesc.m_Enable;
                        m_Value         = inDesc.m_Value;
                    }
                public:
                    ::wms::Bool::type      m_Enable;
                    ::wms::F32::type       m_Value;
                };

                struct tStencilDesc
                {
                public:
                    tStencilDesc(
                        ::wms::Bool::in     Enable  = ::wms::Bool::False,
                        ::wms::U::in        Value   = 0
                        )
                        : m_Enable(Enable)
                        , m_Value(Value)
                    {

                    }
                    ::wms::Void::type Set(
                        ::wms::Bool::in     Enable  = ::wms::Bool::False,
                        ::wms::U::in        Value   = 0
                        )
                    {
                        m_Enable        = Enable;
                        m_Value         = Value;
                    }

                    ::wms::Void::type Set(
                        tStencilDesc const &    inDesc
                        )
                    {
                        m_Enable        = inDesc.m_Enable;
                        m_Value         = inDesc.m_Value;
                    }
                public:
                    ::wms::Bool::type      m_Enable;
                    ::wms::U::type         m_Value;
                };

                //////////////////////////////////////////////////////////////////////////
                //////////////////////////////////////////////////////////////////////////

                type(
                    ::wms::Bool::in    ColorEnable      = ::wms::Bool::False,
                    ::wms::Color::in   ColorValue       = ::wms::Color::Black,
                    ::wms::Bool::in    DepthEnable      = ::wms::Bool::False,
                    ::wms::F32::in     DepthValue       = 0,
                    ::wms::Bool::in    StencilEnable    = ::wms::Bool::False,
                    ::wms::U::in       StencilValue     = 0
                    )
                    : Color(ColorEnable, ColorValue)
                    , Depth(DepthEnable, DepthValue)
                    , Stencil(StencilEnable, StencilValue)
                {

                }

                tColorDesc              Color;
                tDepthDesc              Depth;
                tStencilDesc            Stencil;
            };
        } /// end of namespace Clear
    } /// end of namespace Desc
} /// end of namespace rkk

#endif /*__RENDERKINGKONG_DES_CLEAR_HPP__SHANHAOBO_19800429__*/

