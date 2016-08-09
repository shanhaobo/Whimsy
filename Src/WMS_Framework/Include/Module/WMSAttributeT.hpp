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
        template<class T>
        class Type : public Attr::type
        {
        protected:
            typedef T                                       tValue;
            typedef tValue &                                tValueRef;
            typedef tValueRef                               tValueOut;
            typedef tValueRef const                         tValueIn;

            typedef ::Wiz::TT::If<::Wiz::TT::Is::Same<T, F64::type>::bValue, F64::type, F32::type> tMoidifierValue;

            typedef Attr::Modifier::Type<tMoidifierValue>   tModifier;
            typedef tModifier*                              tModifierPtr;

        protected:
            tValue                  m_BaseValue;
            tValue                  m_CurrValue;

        public:
            virtual Void::type Calc(F32::in inCurrTime)
            {
                if (m_LastTime < inCurrTime)
                {
                    tModifierPtr lMoidifierPtr = (tModifierPtr)(m_MoidifierPtr);
                    if (::Wiz::IsValidPtr(lMoidifierPtr))
                    {
                        tMoidifierValue const lResult =
                            lMoidifierPtr->Calc(
                                ::Wiz::Cast::Static<tMoidifierValue>(m_BaseValue)
                                );

                        m_CurrValue = ::Wiz::Cast::Static<tValue>(lResult);
                        m_LastTime = inCurrTime;
                    }
                }
            }

        public:
            tValue GetCurrValue()
            {
                Calc(m_LastTime + F32::Epsilon);
                return m_CurrValue;
            }
        };
    } /// end of namespace Attribute
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_T_HPP__
