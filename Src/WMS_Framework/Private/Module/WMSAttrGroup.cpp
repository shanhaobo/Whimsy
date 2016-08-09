#include "../../Include/Module/WMSAttrGroup.hpp"

namespace wms
{
    namespace AttrGroup
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

        Attr::ptr type::GetAttrByIdx(::wms::Size::in inIdx)
        {
            if ((inIdx >= 0) && (inIdx < m_Children.Size()))
            {
                return m_Children[inIdx];
            }

            return WIZ_NULLPTR;
        }
    } /// end of namespace AttrGroup
} /// end of namespace wms
