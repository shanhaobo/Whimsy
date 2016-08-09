#ifndef __RENDERKINGKONG_RENDERDEVICELAYER_SW_DEVICE_HPP__
#define __RENDERKINGKONG_RENDERDEVICELAYER_SW_DEVICE_HPP__

#include "../../RKK_Library/Include/RenderDeviceLayer/RKKRenderDeviceLayer.hpp"

namespace rkk
{
    namespace RenderDeviceLayer
    {
        namespace SW
        {
            namespace Device
            {
                ::wms::Bool::type Create();
            } /// end of namespace Device

            namespace Factory
            {
                ::wms::Bool::type Create();
            } /// end of namespace Factory

        } /// end of namespace SW
    } /// namespace RenderDeviceLayer
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_RENDERDEVICELAYER_SW_DEVICE_HPP__
