#include "../Include/WMSCoreComponentMetaProperty.hpp"

namespace wms
{
	namespace Cmpnt
	{
		namespace MetaPrprty
		{
			type::type(::wms::Cmpnt::ptr inOwnerPtr, ::wms::Name::in inName)
				: m_OwnerPtr(inOwnerPtr)
				, m_Name(inName)
			{
			}

			type::~type()
			{
			}
		} /// end of namespace MetaPrcsr
	} /// end of namespace Cmpnt
} /// end of namespace wms
