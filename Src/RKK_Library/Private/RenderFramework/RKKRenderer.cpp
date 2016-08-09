#include "../../include/RenderFramework/RKKRenderer.hpp"
#include "../../include/RenderFramework/RKKPlugin_RenderDeviceLayer.hpp"

namespace rkk
{
    namespace Renderer
    {
        type::type()
        {
        }

        type::~type()
        {
        }

        ::wms::Bool::type type::RegisterRDL(::wms::Name::in inName, Plugin::RenderDeviceLayer::ptr inRDLPluginPtr)
        {
            return m_mapRDLPlugin.insertUnique(inName, inRDLPluginPtr);
        }

        ::wms::Void::type type::UnregisterRDL(::wms::Name::in inName)
        {
            DeactiveRDL(inName);

            m_mapRDLPlugin.Remove(inName);
        }


        Plugin::RenderDeviceLayer::ptr type::GetRDL(::wms::Name::in inName)
        {
            Plugin::RenderDeviceLayer::ptr lRDLPluginPtr = WMS_NULLPTR;
            m_mapRDLPlugin.TryGet(lRDLPluginPtr, inName);
            return lRDLPluginPtr;
        }

        ::wms::Bool::type type::ActiveRDL(::wms::Name::in inName)
        {
            return ActiveRDL(GetRDL(inName));
        }

        ::wms::Bool::type type::ActiveRDL(Plugin::RenderDeviceLayer::ptr inRDLPluginPtr)
        {
            if (::Wiz::IsValidPtr(inRDLPluginPtr))
            {
                DeactiveRDL(inRDLPluginPtr);

                if (::Wiz::IsValidPtr(inRDLPluginPtr->m_RDLPtr))
                {
                    m_ActivedRDLName = inRDLPluginPtr->m_PluginName;
                    m_ActivedRDLPtr = inRDLPluginPtr->m_RDLPtr;

                    return ::wms::Bool::True;
                }
            }

            return ::wms::Bool::False;
        }

        ::wms::Void::type type::DeactiveRDL(::wms::Name::in inName)
        {
            Plugin::RenderDeviceLayer::ptr lRDLPluginPtr = GetRDL(inName);
            if (::Wiz::IsValidPtr(lRDLPluginPtr))
            {
                DeactiveRDL(lRDLPluginPtr);
            }
        }

        ::wms::Void::type type::DeactiveRDL(Plugin::RenderDeviceLayer::ptr inRDLPluginPtr)
        {
            if (::Wiz::NotValidPtr(m_ActivedRDLPtr) || m_ActivedRDLName.NotValid())
            {
                return;
            }

            if ((m_ActivedRDLPtr == inRDLPluginPtr->m_RDLPtr) && (m_ActivedRDLName == inRDLPluginPtr->m_PluginName))
            {
                inRDLPluginPtr->Deactive();

                m_ActivedRDLName.invalid();
                m_ActivedRDLPtr = WMS_NULLPTR;
            }
        }
    } /// namespace Renderer
} /// namespace rkk
