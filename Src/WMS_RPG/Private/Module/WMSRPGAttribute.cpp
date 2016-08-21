#include "../../Include/Module/WMSRPGAttribute.hpp"

namespace wms
{
    namespace RPG
    {
        namespace Attr
        {
            namespace Health
            {
                type::type(tValueIn inBaseVal) : tSuper(inBaseVal, RPG::Attr::Category::Health, Bool::True)
                {
                }

                type::~type()
                {
                }
            } /// end of namespace Health

            namespace HealthMax
            {
                type::type(tValueIn inBaseVal) : tSuper(inBaseVal, RPG::Attr::Category::HealthMax)
                {
                }

                type::~type()
                {
                }
            } /// end of namespace HealthMax
        } /// end of namespace Attr
    } /// end of namespace RPG
} /// end of namespace wms
