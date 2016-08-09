#ifndef __RENDERKINGKONG_RENDERDEVICELAYER_D3D11_DEVICE_HPP__
#define __RENDERKINGKONG_RENDERDEVICELAYER_D3D11_DEVICE_HPP__

#include "../../RKK_Library/include/RenderDeviceLayer/RKKRenderDeviceLayer.hpp"

#include <dxgi.h>
#include <d3d11.h>

namespace rkk
{
    namespace RenderDeviceLayer
    {
        namespace D3D11
        {
            namespace Device
            {
                ::wms::Bool::type Create();

                WIZ_SINGLETONINIT_DECLARE(ID3D11Device);
            } /// end of namespace Device

            namespace Factory
            {
                ::wms::Bool::type Create();

                WIZ_SINGLETONINIT_DECLARE(IDXGIFactory);
            } /// end of namespace Factory

        } /// end of namespace D3D11
    } /// namespace RenderDeviceLayer
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_RENDERDEVICELAYER_D3D11_DEVICE_HPP__
