#include "../../Include/Module/WMSAttrManager.hpp"

namespace wms
{
    namespace Attr
    {
        namespace Manager
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
                    return ::Wiz::Cast::Static<Attr::ptr>(m_Children[inIdx]);
                }

                return WIZ_NULLPTR;
            }
        }
    } /// end of namespace AttrGroup
} /// end of namespace wms
