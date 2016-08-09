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
            type();
            virtual ~type();
            virtual Void::type Tick(F32::in inDeltaTime);

            virtual Void::type Calc(F32::in inDeltaTime) = 0;


            ID32::type ReceiveRequest(Attr::Request::ptr);
            Void::type RemoveRequest(ID32::in);

        protected:
            Attr::Modifier::ptr m_MoidifierPtr;

            F32::type           m_LastTime;
        };
    } /// end of namespace Attribute
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_HPP__
