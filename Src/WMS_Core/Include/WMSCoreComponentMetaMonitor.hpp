#ifndef __WHIMSY_CORE_COMPONENT_META_MONITOR_HPP__ 
#define __WHIMSY_CORE_COMPONENT_META_MONITOR_HPP__

#include "WMSCoreComponent.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace Cmpnt
    {
		namespace MetaMntr
		{
			WMS_CLASS: public ::wms::Cmpnt::type
			{
			public:
				type(::wms::Cmpnt::ptr inObjPtr);
				virtual ~type();

			public:
				virtual Void::type Tick(F32::in inDeltaTime) = WIZ_NULL;

			protected:
				::wms::Cmpnt::ptr m_MonitoredObjPtr;
			};
		} /// end of namespace MetaMntr
    } /// end of namespace Cmpnt
} /// end of namespace wms

#endif /// __WHIMSY_CORE_COMPONENT_META_MONITOR_HPP__
