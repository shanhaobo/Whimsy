#ifndef __RENDERKINGKONG_RENDERDEVICELAYER_SW_HPP__
#define __RENDERKINGKONG_RENDERDEVICELAYER_SW_HPP__

#include "../../RKK_Library/Include/RenderDeviceLayer/RKKRenderDeviceLayer.hpp"

namespace rkk
{
    namespace RenderDeviceLayer
    {
        namespace SW
        {
            ///////////////////////////
            ///////////////////////////
            WMS_CLASS : public ::rkk::RenderDeviceLayer::type
            {
            public:
                type();
                virtual ~type();

            public:
#               undef RKK_RDL_METHOD
#               define RKK_RDL_METHOD   RKK_RDL_METHOD_DECLARE
#                   include "../../RKK_Library/Include/RenderDeviceLayer/RKKRenderDeviceLayerMethod.hpp"
#               undef RKK_RDL_METHOD
            };
            ///////////////////////////
            ///////////////////////////
        } /// end of namespace SW
    } /// namespace RenderDeviceLayer
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_RENDERDEVICELAYER_SW_HPP__
