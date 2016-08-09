#include "../../Include/Module/WMSAttrModule.hpp"

namespace wms
{
    namespace Attr
    {
        namespace Module
        {
            type::type()
            {
            }


            type::type(::wms::Size::in inSize) : tSuper(inSize)
            {

            }

            type::~type()
            {
            }

            Attr::ptr type::GetAttrByIdx(::wms::ID32::in inIdx)
            {
                return WIZ_NULLPTR;
            }
        } /// end of namespace Module
    } /// end of namespace AttrModule
} /// end of namespace wms
