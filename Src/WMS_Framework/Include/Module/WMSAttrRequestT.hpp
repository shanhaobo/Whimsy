#ifndef __WHIMSY_ATTRIBUTE_REQUEST_T_HPP__ 
#define __WHIMSY_ATTRIBUTE_REQUEST_T_HPP__

#include "../Core/WMSFrmwrkFwdDclr.hpp"

namespace wms
{
    namespace Attr
    {
        namespace Request
        {
            template<class T>
            class Type : public Attr::Request::type
            {
            protected:
                typedef T                               tValue;
                typedef tValue &                        tValueRef;
                typedef tValueRef                       tValueOut;
                typedef tValue const                    tValueIn;

            public:
                virtual Void::type Calc(tValueOut ioCurrVal, tValueIn inBaseValue) = 0;
            };

            namespace Percent
            {
                template<class T>
                class Type : public Request::Type<T>
                {
                public:
                    F32::type  m_Percent;

                    virtual Void::type Calc(tValueOut ioCurrVal, tValueIn inBaseValue)
                    {
                        ioCurrVal += inBaseValue * m_Percent;
                    }
                };
            }

            namespace Absolute
            {
                template<class T>
                class Type : public Request::Type<T>
                {
                public:
                    tValue  m_Value;

                    virtual Void::type Calc(tValueOut ioCurrVal, tValueIn inBaseValue)
                    {
                        ioCurrVal += m_Value;
                    }
                };
            }
        } /// end of namespace Request
    } /// end of namespace Attr
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_REQUEST_T_HPP__
