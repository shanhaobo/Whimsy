#ifndef __WHIMSY_FRAMEWORK_FORWORDDECLARE_HPP__ 
#define __WHIMSY_FRAMEWORK_FORWORDDECLARE_HPP__

#include "../../../WMS_Base/Include/WMSBase.hpp"
#include "../../../WMS_Core/Include/WMSCore.hpp"

namespace wms
{
    namespace EWMS_OBJ_CAT
    {
        namespace Framework
        {
            WIZ_ACD(eWOC_General);

            WIZ_ACD(eWOC_Attribute);
        } /// end of namespace Framework
    } /// end of namespace EWMS_OBJ_CAT

    namespace Allocator
    {
        namespace Framework
        {
            namespace General
            {
                typedef ::Wiz::Allocator::Categorized<EWMS_OBJ_CAT::Framework::eWOC_General>::Type   type;
            }
            namespace Attribute
            {
                typedef ::Wiz::Allocator::Categorized<EWMS_OBJ_CAT::Framework::eWOC_Attribute>::Type   type;
            }
        } /// end of namespace Framework
    } /// end of namespace Allocator

    namespace Obj
    {
        namespace Framework
        {
            namespace General
            {
                WMS_DECLARE(::wms::Obj::type<::wms::Allocator::Framework::General::type>);
            }
            namespace Attribute
            {
                WMS_DECLARE(::wms::Obj::type<::wms::Allocator::Framework::Attribute::type>);
            }
        } /// end of namespace Framework
    } /// end of namespace ANN

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
