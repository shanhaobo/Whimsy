#include "../Include/WMSPluginMgr.hpp"

namespace wms
{
    namespace PluginMgr
    {
        ::wms::Plugin::ptr type::GetPlugin(::wms::Name::in inPluginName)
        {
            ::wms::Plugin::ptr lPluginPtr = WMS_NULLPTR;
            m_mapPlugin.TryGet(lPluginPtr, inPluginName);
            return lPluginPtr;
        }

        ::wms::Bool::type type::LoadPlugin(::wms::Str::in inPluginFileName, ::wms::Name::in inPluginName)
        {
            if (m_mapPlugin.HasData(inPluginName))
            {
                return ::wms::Bool::False;
            }

            ::wms::Plugin::ptr lLoadedPluginPtr = WMS_NULLPTR;

            /// TODO Load Plugin

            if (::Wiz::IsValidPtr(lLoadedPluginPtr))
            {
                lLoadedPluginPtr->Register(this, inPluginName);

                m_mapPlugin.insert(inPluginName, lLoadedPluginPtr);

                return ::wms::Bool::True;
            }

            return ::wms::Bool::False;
        }

        ::wms::Void::type type::UnloadPlugin(::wms::Name::in inPluginName)
        {
            ::wms::Plugin::ptr lFoundPluginPtr = GetPlugin(inPluginName);
            if (::Wiz::IsValidPtr(lFoundPluginPtr))
            {
                lFoundPluginPtr->Unregister();

                m_mapPlugin.Remove(inPluginName);

                /// TODO Destroy FoundPluginPtr;
            }
        }

        ::wms::Bool::type type::ActivePlugin(::wms::Name::in inPluginName)
        {
            ::wms::Plugin::ptr lFoundPluginPtr = GetPlugin(inPluginName);
            if (::Wiz::IsValidPtr(lFoundPluginPtr))
            {
                lFoundPluginPtr->Active();

                return ::wms::Bool::True;
            }

            return ::wms::Bool::False;
        }
    } /// namespace Renderer
} /// namespace rkk
