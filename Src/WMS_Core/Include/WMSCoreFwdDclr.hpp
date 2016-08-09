#ifndef __WHIMSY_CORE_FORWORDDECLARE_HPP__ 
#define __WHIMSY_CORE_FORWORDDECLARE_HPP__

#include "../../WMS_Base/Include/WMSBase.hpp"

namespace wms
{
    namespace Plugin
    {
        class type;
        WMS_DECLARE_TYPE(::wms::Plugin::type);
    } /// end of namespace Plugin

    namespace PluginMgr
    {
        class type;
        WMS_DECLARE_PTR(::wms::PluginMgr::type);
    } /// end of namespace PluginMgr

	namespace Cmpnt
	{
		class type;
		WMS_DECLARE_PTR(::wms::Cmpnt::type);

		namespace MetaMntr
		{
			class type;
			WMS_DECLARE_PTR(::wms::Cmpnt::MetaMntr::type);
		} /// end of namespace MetaMntr

		namespace MetaPrcsr
		{
			class type;
			WMS_DECLARE_PTR(::wms::Cmpnt::MetaPrcsr::type);
		} /// end of namespace MetaPrcsr
	} /// end of namespace Cmpnt

} /// end of namespace wms

#endif /// __WHIMSY_FRAMEWORK_COMPONENT_HPP__
