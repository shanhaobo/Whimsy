#ifndef __WHIMSY_BEHAVIOR_HPP__ 
#define __WHIMSY_BEHAVIOR_HPP__

#include "../Core/WMSFrmwrkFwdDclr.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace Bhvr
    {
        WMS_CLASS : public ::wms::Cmpnt::type
        {
        private:
            typedef ::wms::Cmpnt::type tSuper;

        public:
            type();
            virtual ~type();
            virtual Void::type Tick(F32::in inDeltaTime);

        protected:
        };
    } /// end of namespace Behavior
} /// end of namespace wms

#endif /// __WHIMSY_BEHAVIOR_HPP__
