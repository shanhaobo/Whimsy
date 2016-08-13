#include "../../Include/Module/WMSRPGAttribute.hpp"

namespace wms
{
    namespace RPG
    {
        namespace Attr
        {
            namespace Health
            {
                type::type(tValueIn inBaseVal) : tSuper(inBaseVal, RPG::Attr::Category::Health)
                {
                }

                type::~type()
                {
                }
            } /// end of namespace Health
        } /// end of namespace Attr
    } /// end of namespace RPG
} /// end of namespace wms
