#ifndef __WHIMSY_RPG_ATTRIBUTE_MANAGER_HPP__ 
#define __WHIMSY_RPG_ATTRIBUTE_MANAGER_HPP__

#include "../Core/WMSRPGFwdDclr.hpp"
#include "../../../WMS_Framework/Include/Module/WMSAttrManager.hpp"

#include "./WMSRPGAttribute.hpp"

namespace wms
{
    namespace RPG
    {
        namespace Attr
        {
            namespace Manager
            {
            WMS_CLASS: public ::wms::Attr::Manager::type
            {
                typedef ::wms::Attr::Manager::type tSuper;
            public:
                type();
                type(::wms::Size::in);

                virtual ~type();

            public:
                virtual ::wms::Attr::ptr  NewAttr(Attr::Category::in inCate) const;

            protected:
                virtual Attr::Health::ptr NewAttr_Health()        const = WMS_NULLPTR;
                virtual Attr::HealthMax::ptr NewAttr_HealthMax()  const = WMS_NULLPTR;
            };
            } /// end of namespace Manager
        } /// end of namespace Attr
    } /// end of namespace RPG
} /// end of namespace wms

#endif /// __WHIMSY_RPG_ATTRIBUTE_MANAGER_HPP__
