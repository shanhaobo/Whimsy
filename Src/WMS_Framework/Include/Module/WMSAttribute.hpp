#ifndef __WHIMSY_ATTRIBUTE_HPP__ 
#define __WHIMSY_ATTRIBUTE_HPP__

#include "../Core/WMSFrmwrkFwdDclr.hpp"
#include "./WMSAttrModifier.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace Attr
    {
        WMS_CLASS : public ::wms::Cmpnt::type
        {
        private:
            typedef ::wms::Cmpnt::type                  tSuper;

        public:
            type(Attr::Modifier::ptr inMoidifierPtr);
            virtual ~type();
            virtual Void::type Tick(F32::in inDeltaTime);

            virtual Void::type Calc(F32::in inDeltaTime) = WIZ_NULLPTR;

            ID32::type ReceiveRequest(Attr::Request::ptr);
            Void::type RemoveRequest(ID32::in);

            virtual Void::type SetBaseValue(Void::ptr inValue) = WIZ_NULLPTR;
            virtual Void::type GetBaseValue(Void::ptr outValue) = WIZ_NULLPTR;

            virtual Void::type GetCurrValue(Void::ptr outValue, F32::in inTime) = WIZ_NULLPTR;

        protected:
            Attr::Modifier::ptr m_MoidifierPtr;

            F32::type           m_LastTime;
        };
    } /// end of namespace Attribute
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_HPP__
