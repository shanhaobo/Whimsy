#include "../../include/RenderFramework/RKKPlugin_RenderDeviceLayer.hpp"

#include "../../include/RenderFramework/RKKRoot.hpp"

namespace rkk
{
    namespace Plugin
    {
        namespace RenderDeviceLayer
        {
            ::wms::Bool::type type::Register(::wms::PluginMgr::ptr inPluginMgrPtr, ::wms::Name::in inName)
            {
                if (tSuper::Register(inPluginMgrPtr, inName))
                {
                    m_RendererPtr = ::rkk::Root::instancePtr()->m_RendererPtr;
                    if (::Wiz::IsValidPtr(m_RendererPtr))
                    {
                        if (m_RendererPtr->RegisterRDL(inName, this))
                        {
                            return ::wms::Bool::True;
                        }
                    }
                }

                return ::wms::Bool::False;
            }

            ::wms::Void::type type::Unregister()
            {
                if (::Wiz::IsValidPtr(m_RendererPtr))
                {
                    m_RendererPtr->UnregisterRDL(m_PluginName);
                }

                if (::Wiz::IsValidPtr(m_RDLPtr))
                {
                    DestroyRDL(m_RDLPtr);

                    m_RDLPtr = WIZ_NULL;
                }

                tSuper::Unregister();
            }

            ::wms::Bool::type type::Active()
            {
                if (tSuper::Active() && ::Wiz::IsValidPtr(m_RendererPtr))
                {
                    if (::Wiz::NotValidPtr(m_RDLPtr))
                    {
                        m_RDLPtr = CreateRDL();
                    }

                    if (::Wiz::IsValidPtr(m_RDLPtr))
                    {
                        return m_RendererPtr->ActiveRDL(m_PluginName);
                    }
                }

                return ::wms::Bool::False;
            }

            ::wms::Void::type type::Deactive()
            {
                tSuper::Deactive();
            }
        } /// namespace RenderDeviceLayer
    } /// end of namespace Plugin
} /// namespace rkk
