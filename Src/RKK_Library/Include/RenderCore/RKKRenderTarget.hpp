#ifndef __RENDERKINGKONG_RENDERTARGET_HPP__
#define __RENDERKINGKONG_RENDERTARGET_HPP__

#include "./RKKRenderCoreFwdDclr.hpp"

namespace rkk
{
    namespace RenderTarget
    {
        WMS_CLASS
        {
        public:
            type(Desc::RenderTarget::in inDesc);
            ~type();

            Desc::RenderTarget::type m_Description;
        };
    } /// namespace RenderTarget
} /// namespace rkk

#endif /// __RENDERKINGKONG_RENDERTARGET_HPP__
