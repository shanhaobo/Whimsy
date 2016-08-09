#ifndef __WHIMSY_PLUGIN_HPP__
#define __WHIMSY_PLUGIN_HPP__

#include "./WMSCoreFwdDclr.hpp"

namespace wms
{
    namespace Plugin
    {
        WMS_CLASS : public ::wms::Obj::Plugin::type
        {
        public:
            type();

        public:
            virtual ::wms::Bool::type Register(::wms::PluginMgr::ptr, ::wms::Name::in);
            virtual ::wms::Void::type Unregister() = 0;

        public:
            virtual ::wms::Bool::type Active() = 0;
            virtual ::wms::Void::type Deactive() = 0;

        protected:
            ::wms::PluginMgr::ptr           m_MgrPtr;

            ::wms::Name::type               m_PluginName;
        };
    } /// namespace Plugin
} /// namespace wms

#endif /// #ifndef __WHIMSY_PLUGIN_HPP__
