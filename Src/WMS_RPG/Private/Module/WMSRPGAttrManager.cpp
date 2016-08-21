#include "../../Include/Module/WMSRPGAttrManager.hpp"

namespace wms
{
    namespace RPG
    {
        namespace Attr
        {
            namespace Manager
            {
                type::type() : tSuper()
                {
                }


                type::type(::wms::Size::in inSize) : tSuper(inSize)
                {

                }

                type::~type()
                {
                }

                ::wms::Attr::ptr  type::NewAttr(Attr::Category::in inCate) const
                {
                    switch (inCate)
                    {
                    case Attr::Category::Health:
                        return NewAttr_Health();
                    case Attr::Category::HealthMax:
                        return NewAttr_HealthMax();
                    }

                    return WMS_NULLPTR;
                }
            } /// end of namespace Health
        } /// end of namespace Attr
    } /// end of namespace RPG
} /// end of namespace wms
