#ifndef __WHIMSY_ATTRIBUTE_MODIFIER_T_HPP__ 
#define __WHIMSY_ATTRIBUTE_MODIFIER_T_HPP__

#include "../Core/WMSFrmwrkFwdDclr.hpp"
#include "./WMSAttrModifier.hpp"
#include "./WMSAttrRequestT.hpp"

namespace wms
{
    namespace Attr
    {
        namespace Modifier
        {
            template<class T>
            class Type : public Modifier::type
            {
                typedef Modifier::type                  tSuper;

            protected:
                typedef T                               tValue;
                typedef tValue &                        tValueRef;
                typedef tValueRef                       tValueOut;
                typedef tValue const                    tValueIn;

                typedef Attr::Request::Type<tValue>     tRequest;
                typedef tRequest*                       tRequestPtr;

            protected:
                Void::type CalcCurrLayer(tValueOut ioValue, tRequestLayerPtr inLayerPtr, tValueIn inLastBaseVal)
                {
                    if (::Wiz::IsValidPtr(inLayerPtr))
                    {
                        tRequestLayer::tSize i;
                        for (i = 0; i < inLayerPtr->Size(); ++i)
                        {
                            tRequestPtr lReqPtr = (tRequestPtr)((*inLayerPtr)[i]);
                            if (::Wiz::IsValidPtr(lReqPtr))
                            {
                                lReqPtr->Calc(ioValue, inLastBaseVal);
                                if (lReqPtr->m_Disposable)
                                {
                                    (*inLayerPtr)[i] = WIZ_NULLPTR;
                                }
                            }
                        }
                    }
                }

            public:
                Type() : tSuper()
                {

                }

                virtual tValue Calc(tValueIn inBaseVal)
                {
                    tRequestLayerList::tSize i;

                    tValue              lBaseVal = inBaseVal;
                    tValue              lResultVal = inBaseVal;

                    for (i = 0; i < m_RequestLayerList.Size(); ++i)
                    {
                        CalcCurrLayer(lResultVal, m_RequestLayerList[i].LayerPtr, lBaseVal);

                        lBaseVal = lResultVal;
                    }

                    return lResultVal;
                }
            };
        } /// end of namespace Modifier
    } /// end of namespace Attr
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_MODIFIER_T_HPP__
