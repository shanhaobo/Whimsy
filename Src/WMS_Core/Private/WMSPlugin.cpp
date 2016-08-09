#include "../Include/WMSPlugin.hpp"

namespace wms
{
    namespace Plugin
    {
        type::type() : m_MgrPtr(WMS_NULLPTR)
        {

        }

        ::wms::Bool::type type::Register(::wms::PluginMgr::ptr inMgrPtr, ::wms::Name::in inName)
        {
            if (::Wiz::IsValidPtr(inMgrPtr) && inName.IsValid())
            {
                m_MgrPtr = inMgrPtr;

                m_PluginName = inName;

                return ::wms::Bool::True;
            }

            return ::wms::Bool::False;
        }
    } /// end of namespace Plugin
} /// namespace rkk
