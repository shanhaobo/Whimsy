#include "./RKKRDL_SW_Device.hpp"

namespace rkk
{
    namespace RenderDeviceLayer
    {
        namespace SW
        {
            namespace Factory
            {
                ::wms::Bool::type Create()
                {
                    return ::wms::Bool::True;
                }
            } /// end of namespace Factory

            namespace Device
            {
                ::wms::Bool::type Create()
                {
                    return ::wms::Bool::False;
                }
            } /// end of namespace Device

        } /// end of namespace SW
    } /// namespace RenderDeviceLayer
} /// namespace rkk
