#ifndef __WHIMSY_ATTRIBUTE_T_HPP__ 
#define __WHIMSY_ATTRIBUTE_T_HPP__

#include "../Core/WMSFrmwrkFwdDclr.hpp"
#include "./WMSAttribute.hpp"
#include "./WMSAttrModifierT.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace Attr
    {
        template<class T, class TModifierValue = ::wms::F32::type>
        class Type : public Attr::type
        {
            typedef Attr::type                              tSuper;
        protected:
            typedef T                                       tValue;
            typedef tValue &                                tValueRef;
            typedef tValueRef                               tValueOut;
            typedef tValueRef const                         tValueIn;

            typedef TModifierValue                          tMoidifierValue;

            typedef Attr::Modifier::Type<tMoidifierValue>   tModifier;
            typedef tModifier*                              tModifierPtr;

        protected:
            tValue                  m_BaseValue;
            tValue                  m_CurrValue;

            Type(tValueIn inBaseVal) : tSuper(WMS_NEW tModifier()), m_BaseValue(inBaseVal)
            {

            }

        protected:
            virtual Void::type Calc(F32::in inCurrTime)
            {
                if (m_LastTime < inCurrTime)
                {
                    tModifierPtr lMoidifierPtr = (tModifierPtr)(m_MoidifierPtr);
                    if (::Wiz::IsValidPtr(lMoidifierPtr))
                    {
                        tMoidifierValue const lBase     = ::Wiz::Cast::Static<tMoidifierValue>(m_BaseValue);
                        tMoidifierValue const lResult   = lMoidifierPtr->Calc(lBase);

                        m_CurrValue = ::Wiz::Cast::Static<tValue>(lResult);
                        m_LastTime = inCurrTime;
                    }
                }
            }

        public:
            tValue GetCurrValue(F32::in inCurrTime)
            {
                Calc(inCurrTime);
                return m_CurrValue;
            }

            Void::type SetBaseValue(tValueIn inValue)
            {
                m_BaseValue = inValue;
            }

            tValue GetBaseValue()
            {
                return m_BaseValue;
            }
        };
    } /// end of namespace Attribute
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_T_HPP__
