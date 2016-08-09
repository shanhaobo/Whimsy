#ifndef __WHIMSY_FRAMEWORK_FORWORDDECLARE_HPP__ 
#define __WHIMSY_FRAMEWORK_FORWORDDECLARE_HPP__

#include "../../../WMS_Base/Include/WMSBase.hpp"
#include "../../../WMS_Core/Include/WMSCore.hpp"

namespace wms
{
    namespace Attr
    {
        namespace Module
        {
            class type;
            WMS_DECLARE(type);
        } /// end of namespace Modifier

        namespace Manager
        {
            class type;
            WMS_DECLARE(type);
        } /// end of namespace Manager

        namespace Modifier
        {
            class type;
            WMS_DECLARE(type);
        } /// end of namespace Modifier

        namespace Provider
        {
            class type;
            WMS_DECLARE(type);
        } /// end of namespace Provider

        class type;
        WMS_DECLARE(type);
    } /// end of namespace Attribute
} /// end of namespace wms

#endif /// __WHIMSY_FRAMEWORK_COMPONENT_HPP__
