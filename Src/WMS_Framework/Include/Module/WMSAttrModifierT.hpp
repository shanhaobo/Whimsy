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
            protected:
                typedef T                               tValue;
                typedef tValue &                        tValueRef;
                typedef tValueRef                       tValueOut;
                typedef tValueRef const                 tValueIn;

                typedef Attr::Request::Type<tValue>     tRequest;
                typedef tRequest*                       tRequestPtr;

            protected:
                virtual Bool::type CheckBreak(tValueIn inCurrValue) = 0;

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
                                if (CheckBreak(ioValue))
                                {
                                    lReqPtr->BreakCallBack();
                                    break;
                                }
                            }
                        }
                    }
                }

            public:
                tValue Calc(tValueIn inBaseVal)
                {
                    tRequestList::tSize i;

                    tValue              lBaseVal   = inBaseVal;
                    tValue              lResultVal = inBaseVal;

                    for (i = 0; i < m_RequestList.Size(); ++i)
                    {
                        CalcCurrLayer(lResultVal, m_RequestList[i].LayerPtr, lBaseVal);

                        lBaseVal = lResultVal;
                    }

                    return lResultVal;
                }
            };
        } /// end of namespace Modifier
    } /// end of namespace Attr
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_MODIFIER_T_HPP__
