#ifndef __WHIMSY_RPG_FORWORDDECLARE_HPP__ 
#define __WHIMSY_RPG_FORWORDDECLARE_HPP__

#include "../../../WMS_Framework/Include/Core/WMSFrmwrkFwdDclr.hpp"
#include "../../../WMS_Framework/Include/Core/WMSFrmwrkActor.hpp"

namespace wms
{
    namespace RPG
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
        } /// end of namespace Attribute
    } /// end of namespace RPG
} /// end of namespace wms

#endif /// __WHIMSY_RPG_FORWORDDECLARE_HPP__
