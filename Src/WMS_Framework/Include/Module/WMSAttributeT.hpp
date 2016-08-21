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

            Type(tValueIn inBaseVal, Bool::type inVariable = Bool::False)
                : tSuper(WMS_NEW tModifier(), inVariable)
                , m_BaseValue(inBaseVal)
            {
            }

        protected:
            virtual Void::type Calc()
            {
                if (m_BeModified)
                {
                    tModifierPtr lModifierPtr = (tModifierPtr)(m_ModifierPtr);
                    if (::Wiz::IsValidPtr(lModifierPtr))
                    {
                        tMoidifierValue const lBase     = ::Wiz::Cast::Static<tMoidifierValue>(m_BaseValue);
                        tMoidifierValue const lResult   = lModifierPtr->Calc(lBase);

                        m_CurrValue  = ::Wiz::Cast::Static<tValue>(lResult);
                        m_BeModified = Bool::False;

                        if (m_Variable)
                        {
                            m_BaseValue = m_CurrValue;
                        }
                    }
                }
            }

        public:
            tValue GetCurrValue(F32::in inCurrTime)
            {
                Calc();
                return m_CurrValue;
            }

            Void::type SetBaseValue(tValueIn inValue)
            {
                m_BaseValue     = inValue;
                m_BeModified    = Bool::True;

                if (m_Variable)
                {
                    m_CurrValue = m_BaseValue;
                }
            }

            tValue GetBaseValue()
            {
                return m_BaseValue;
            }
        };
    } /// end of namespace Attribute
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_T_HPP__
