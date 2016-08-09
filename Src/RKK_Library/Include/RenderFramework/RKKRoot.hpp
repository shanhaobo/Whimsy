#ifndef __RENDERKINGKONG_ROOT_HPP__
#define __RENDERKINGKONG_ROOT_HPP__

#include "./RKKRenderer.hpp"

namespace rkk
{
    namespace Root
    {
        class type
        {
        public:
            type(){}

        protected:
            friend class Plugin::RenderDeviceLayer::type;
            ::rkk::Renderer::ptr m_RendererPtr;
        };

        WIZ_SINGLETON_DECLARE(::rkk::Root::type);
    } /// namespace Root
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_ROOT_HPP__
