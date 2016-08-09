#include "../../RKK_Library/include/RenderFramework/RKKPlugin_RenderDeviceLayer.hpp"

#include "./RKKRDL_D3D11.hpp"

namespace rkk
{
    namespace Plugin
    {
        namespace RDL
        {
            namespace D3D11
            {
                WMS_CLASS : public ::rkk::Plugin::RenderDeviceLayer::type
                {
                public:
                    typedef ::rkk::Plugin::RenderDeviceLayer::type tSuper;

                public:
                    type() : tSuper(), m_D3D11RDLPtr(WMS_NULLPTR)
                    {

                    }

                public:

                    virtual ::rkk::RenderDeviceLayer::ptr CreateRDL()
                    {
                        /// TODO Create RDL;

                        m_D3D11RDLPtr = WMS_NEW ::rkk::RenderDeviceLayer::D3D11::type;

                        return m_D3D11RDLPtr;
                    }

                    virtual ::wms::Void::type DestroyRDL(::rkk::RenderDeviceLayer::ptr inRDLPtr)
                    {
                        if (inRDLPtr == m_D3D11RDLPtr)
                        {
                            /// TODO Destroy RDL

                            WMS_DEL m_D3D11RDLPtr;
                        }

                        m_D3D11RDLPtr = WMS_NULLPTR;
                    }

                protected:
                    ::rkk::RenderDeviceLayer::D3D11::ptr  m_D3D11RDLPtr;
                };
            } /// end of namespace D3D11
        } /// namespace RenderDeviceLayer
    } /// end of namespace Plugin
} /// namespace rkk
