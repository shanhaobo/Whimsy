#ifndef __RENDERKINGKONG_RENDERER_HPP__
#define __RENDERKINGKONG_RENDERER_HPP__

#include "../RenderDeviceLayer/RKKRenderDeviceLayer.hpp"

#include "./RKKPlugin_RenderDeviceLayer.hpp"

#include "./RKKRenderFlow.hpp"

namespace rkk
{
    namespace Renderer
    {
        class type
        {
        public:
            type();
            ~type();

        public:
            ::wms::Bool::type RegisterRDL(::wms::Name::in, Plugin::RenderDeviceLayer::ptr);
            ::wms::Void::type UnregisterRDL(::wms::Name::in);

            ::wms::Bool::type ActiveRDL(::wms::Name::in);
            ::wms::Bool::type ActiveRDL(Plugin::RenderDeviceLayer::ptr);

            ::wms::Void::type DeactiveRDL(::wms::Name::in);
            ::wms::Void::type DeactiveRDL(Plugin::RenderDeviceLayer::ptr);

        protected:
            Plugin::RenderDeviceLayer::ptr GetRDL(::wms::Name::in);

            /// RDL
        protected:
            typedef ::wms::Map<::wms::Name::type, Plugin::RenderDeviceLayer::ptr>::type tMapRDLPlugin;
            tMapRDLPlugin                   m_mapRDLPlugin;

            ::wms::Name::type               m_ActivedRDLName;
            RenderDeviceLayer::ptr          m_ActivedRDLPtr;
        };
    } /// namespace Renderer
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_RENDERER_HPP__
