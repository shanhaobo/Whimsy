#include "../../RKK_Library/include/RenderFramework/RKKPlugin_RenderDeviceLayer.hpp"

#include "./RKKRDL_SW.hpp"

namespace rkk
{
    namespace Plugin
    {
        namespace RDL
        {
            namespace SW
            {
                WMS_CLASS : public ::rkk::Plugin::RenderDeviceLayer::type
                {
                public:
                    typedef ::rkk::Plugin::RenderDeviceLayer::type tSuper;

                public:
                    type() : tSuper(), m_SWRDLPtr(WMS_NULLPTR)
                    {

                    }

                public:

                    virtual ::rkk::RenderDeviceLayer::ptr CreateRDL()
                    {
                        /// TODO Create RDL;

                        m_SWRDLPtr = WMS_NEW ::rkk::RenderDeviceLayer::SW::type;

                        return m_SWRDLPtr;
                    }

                    virtual ::wms::Void::type DestroyRDL(::rkk::RenderDeviceLayer::ptr inRDLPtr)
                    {
                        if (inRDLPtr == m_SWRDLPtr)
                        {
                            /// TODO Destroy RDL

                            WMS_DEL m_SWRDLPtr;
                        }

                        m_SWRDLPtr = WMS_NULLPTR;
                    }

                protected:
                    ::rkk::RenderDeviceLayer::SW::ptr  m_SWRDLPtr;
                };
            } /// end of namespace SW
        } /// namespace RenderDeviceLayer
    } /// end of namespace Plugin
} /// namespace rkk
