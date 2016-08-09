#ifndef __WHIMSY_PLUGINMGR_HPP__
#define __WHIMSY_PLUGINMGR_HPP__

#include "./WMSPlugin.hpp"

namespace wms
{
    namespace PluginMgr
    {
        class type : public ::wms::Obj::General::type
        {
        public:
            type(){}

        public:
            ::wms::Bool::type LoadPlugin(::wms::Str::in inPluginFileName, ::wms::Name::in inPluginName);
            ::wms::Void::type UnloadPlugin(::wms::Name::in inPluginName);

        public:
            ::wms::Bool::type ActivePlugin(::wms::Name::in inRDLName);

        protected:
            ::wms::Plugin::ptr GetPlugin(::wms::Name::in inPluginName);

        protected:
            typedef ::wms::Map<::wms::Name::type, ::wms::Plugin::ptr>::type tMapPlugin;
            tMapPlugin  m_mapPlugin;
        };

        WIZ_SINGLETON_DECLARE(::wms::PluginMgr::type);
    } /// namespace PluginMgr
} /// namespace wms

#endif /// #ifndef __WHIMSY_PLUGINMGR_HPP__
