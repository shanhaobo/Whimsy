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


    namespace EWMS_OBJ_CAT
    {
        namespace Framework
        {
            WIZ_ACD(eWOC_General);
        } /// end of namespace Framework

        namespace Allocator
        {
            namespace Framework
            {
                typedef ::Wiz::Allocator::Categorized<EWMS_OBJ_CAT::Framework::eWOC_General>::Type   type;
            } /// end of namespace Framework
        } /// end of namespace Allocator
    } /// end of namespace EWMS_OBJ_CAT

} /// end of namespace wms

#endif /// __WHIMSY_FRAMEWORK_COMPONENT_HPP__
