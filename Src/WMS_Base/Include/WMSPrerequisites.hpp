#ifndef __WHIMSY_PREREQUISITES_HPP__
#define __WHIMSY_PREREQUISITES_HPP__

#include "./WMSTypeDeclareUtils.hpp"

#undef  WIZ_CUSTOM_DECLARE_HELPER
#define WIZ_CUSTOM_DECLARE_HELPER                    WMS_DECLARE
#undef  WIZ_CUSTOM_DECLARE_HELPER_SIMPLE
#define WIZ_CUSTOM_DECLARE_HELPER_SIMPLE             WMS_DECLARE_SIMPLE
#undef  WIZ_CUSTOM_DECLARE_HELPER_PTR
#define WIZ_CUSTOM_DECLARE_HELPER_PTR                WMS_DECLARE_PTR

#undef  WIZ_CUSTOM_DECLARE_HELPER_CONTAINER
#define WIZ_CUSTOM_DECLARE_HELPER_CONTAINER          WMS_DECLARE
#undef  WIZ_CUSTOM_DECLARE_HELPER_ITERATOR
#define WIZ_CUSTOM_DECLARE_HELPER_ITERATOR           WMS_DECLARE_ITER
#undef  WIZ_CUSTOM_DECLARE_HELPER_ITERATOR_CONST
#define WIZ_CUSTOM_DECLARE_HELPER_ITERATOR_CONST     WMS_DECLARE_ITER_CONST

#include "../../WIZ_Library/include/WizCustomDeclareHelper.hpp"


namespace wms
{
    namespace Root
    {
        WMS_FORWARD_DECLARE_CLASS;
    } /// end of namespace Root;

    ////////////////////////////////////////////

    ////////////////////////////////////////////

    namespace Plugin
    {
        WMS_FORWARD_DECLARE_CLASS;

        namespace RenderDeviceLayer
        {
            WMS_FORWARD_DECLARE_CLASS;
        } /// end of namespace RenderDeviceLayer

    } /// end of namespace Plugin

    ////////////////////////////////////////////

} /// end of namespace wms


#endif /// __WHIMSY_PREREQUISITES_HPP__
