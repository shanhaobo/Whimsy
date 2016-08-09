#include "./RKKRDL_D3D11_Device.hpp"

namespace rkk
{
    namespace RenderDeviceLayer
    {
        namespace D3D11
        {
            namespace Factory
            {
                ::wms::Bool::type Create()
                {
                    IDXGIFactory* lDXGIFactoryPtr = WMS_NULLPTR;

                    ::CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&lDXGIFactoryPtr);

                    Factory::init(lDXGIFactoryPtr);

                    return ::wms::Bool::True;
                }
            } /// end of namespace Factory

            namespace Device
            {
                IDXGIAdapter* EnumAdapter(DXGI_ADAPTER_DESC& outAdapterDesc)
                {
                    IDXGIAdapter* lEnumAdapterPtr = WMS_NULLPTR;
                    ::wms::U32::type lCurrentAdapter = 0;
                    while (Factory::instance().EnumAdapters(lCurrentAdapter, &lEnumAdapterPtr) != DXGI_ERROR_NOT_FOUND)
                    {
                        if (::Wiz::IsValidPtr(lEnumAdapterPtr))
                        {
                            if (SUCCEEDED(lEnumAdapterPtr->GetDesc(&outAdapterDesc)))
                            {
                                return lEnumAdapterPtr;
                            }
                        }
                    }

                    return WMS_NULLPTR;
                }

                ::wms::Bool::type Create()
                {
                    ID3D11Device* lDirect3DDevicePtr = WMS_NULLPTR;

                    DXGI_ADAPTER_DESC lAdapterDesc = {0};

                    ID3D11DeviceContext* lContextPtr = WMS_NULLPTR;

                    IDXGIAdapter* lEnumAdapterPtr = EnumAdapter(lAdapterDesc);
                    if (::Wiz::IsValidPtr(lEnumAdapterPtr))
                    {
                        D3D_DRIVER_TYPE DriverType = D3D_DRIVER_TYPE_UNKNOWN;

                        UINT DeviceFlags = 0;

                        D3D_FEATURE_LEVEL ActualFeatureLevel = (D3D_FEATURE_LEVEL)0;
                        D3D_FEATURE_LEVEL LevelsWanted[] = { D3D_FEATURE_LEVEL_11_0 };

                        ::D3D11CreateDevice(
                            lEnumAdapterPtr,
                            DriverType,
                            NULL,
                            DeviceFlags,
                            LevelsWanted,
                            1,
                            D3D11_SDK_VERSION,
                            &lDirect3DDevicePtr,
                            &ActualFeatureLevel,
                            &lContextPtr
                        );

                        Device::init(lDirect3DDevicePtr);

                        return ::wms::Bool::True;
                    }
                    return ::wms::Bool::False;
                }
            } /// end of namespace Device

        } /// end of namespace D3D11
    } /// namespace RenderDeviceLayer
} /// namespace rkk
