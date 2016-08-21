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
            type(Attr::Modifier::ptr inModifierPtr, Bool::type inVariable = Bool::False);
            virtual ~type();
            virtual Void::type Tick(F32::in inDeltaTime);

            ID32::type ReceiveRequest(Attr::Request::ptr);
            Void::type RemoveRequest(ID32::in);

            virtual Void::type SetBaseValue(Void::ptr inValue) = WIZ_NULLPTR;
            virtual Void::type GetBaseValue(Void::ptr outValue) = WIZ_NULLPTR;

            virtual Void::type GetCurrValue(Void::ptr outValue, F32::in inTime) = WIZ_NULLPTR;

        protected:
            virtual Void::type Calc();

        protected:
            Attr::Modifier::ptr m_ModifierPtr;

            Bool::type          m_BeModified;
            Bool::type          m_Variable;     /// Bool::True   : example : HPMax
                                                /// Bool::False  : example : HP
        };
    } /// end of namespace Attribute
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_HPP__
