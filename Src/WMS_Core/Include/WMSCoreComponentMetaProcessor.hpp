#ifndef __WHIMSY_CORE_COMPONENT_META_PROCESSOR_HPP__ 
#define __WHIMSY_CORE_COMPONENT_META_PROCESSOR_HPP__

#include "WMSCoreComponent.hpp"

/// CBD  Component-Based Development

namespace wms
{
	namespace Cmpnt
	{
		namespace MetaPrcsr
		{
			WMS_CLASS: public ::wms::Cmpnt::type
			{
			public:
				type(::wms::Cmpnt::MetaMntr::ptr inMonitorPtr);
				virtual ~type();

			public:
				virtual Void::type Tick(F32::in inDeltaTime) = WIZ_NULL;

			protected:
				::wms::Cmpnt::MetaMntr::ptr m_MonitorPtr;
			};
		} /// end of namespace MetaPrcsr
	} /// end of namespace Cmpnt
} /// end of namespace wms

#endif /// __WHIMSY_CORE_COMPONENT_META_PROCESSOR_HPP__
