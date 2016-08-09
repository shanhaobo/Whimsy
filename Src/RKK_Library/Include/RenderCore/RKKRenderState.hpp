#ifndef __RENDERKINGKONG_RENDERSTATE_HPP__
#define __RENDERKINGKONG_RENDERSTATE_HPP__

#include "../Core/RKKCore.hpp"

namespace rkk
{
    namespace RenderState
    {
        WMS_CLASS
        {
        public:
            type() : m_KeepLastSetting(::wms::Bool::True)
            {

            }
            type(in inOther);
            ~type();

            ::wms::Bool::type  m_KeepLastSetting;
        };
    } /// namespace RenderState
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_RENDERSTATE_HPP__
