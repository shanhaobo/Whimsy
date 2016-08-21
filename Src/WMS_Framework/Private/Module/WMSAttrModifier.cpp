#include "../../Include/Module/WMSAttrModifier.hpp"

namespace wms
{
    namespace Attr
    {
        namespace Modifier
        {
            type::type() : m_RequestID(0)
            {
            }

            type::~type()
            {

            }

            /// 创建LAYER
            type::tRequestLayerPtr type::FindOrCreateRequestLayer(ID32::in inLayerID)
            {
                tRequestLayerList::tSize i;

                for (i = 0; i < m_RequestLayerList.Size(); ++i)
                {
                    if (m_RequestLayerList[i].LayerID == inLayerID)
                    {
                        return m_RequestLayerList[i].LayerPtr;
                    }
                }

                ///未找到
                tRequestLayerPtr lResultPtr = WMS_NEW_T(tRequestLayer, EWMS_OBJ_CAT::Framework::eWOC_Attribute);
                if (::Wiz::IsValidPtr(lResultPtr))
                {
                    m_RequestLayerList.PushBack(tRequestLayerItem(inLayerID, lResultPtr));
                    if (m_RequestLayerList.Size() >= 2)
                    {
                        tRequestLayer::tSize const tLastIdx = m_RequestLayerList.Size() - 1;

                        /// Sort()
                        /// 从倒数第二个开始与倒数第一个(inLayerID, tResultPtr)比较
                        for (i = tLastIdx - 1; i >= 0; ++i)
                        {
                            /// 大的排到后面去
                            if (m_RequestLayerList[i].LayerID > inLayerID)
                            {
                                m_RequestLayerList[i + 1].LayerID  = m_RequestLayerList[i].LayerID;
                                m_RequestLayerList[i + 1].LayerPtr = m_RequestLayerList[i].LayerPtr;

                                m_RequestLayerList[i].LayerID      = inLayerID;
                                m_RequestLayerList[i].LayerPtr     = lResultPtr;
                            }
                        }
                    }
                }

                return lResultPtr;
            }

            ID32::type type::ReceiveRequest(Attr::Request::ptr inNewReqPtr)
            {
                tRequestLayer::tSize    i;
                tRequestLayerPtr        lLayerPtr = FindOrCreateRequestLayer(inNewReqPtr->m_LayerID);
                if (::Wiz::IsValidPtr(lLayerPtr))
                {
                    for (i = 0; i < lLayerPtr->Size(); ++i)
                    {
                        if (::Wiz::NotValidPtr((*lLayerPtr)[i]))
                        {
                            (*lLayerPtr)[i] = inNewReqPtr;
                            break;
                        }
                    }
                    if (i == lLayerPtr->Size())
                    {
                        lLayerPtr->PushBack(inNewReqPtr);
                    }
                    inNewReqPtr->m_ID = GenReqID();
                    return inNewReqPtr->m_ID;
                }

                return ID32::Invalid;
            }

            ID32::type type::GenReqID()
            {
                return m_RequestID++;
            }

            Bool::type type::RemoveRequest(ID32::in inReqID)
            {
                tRequestLayerList::tSize     i;
                tRequestLayer::tSize    j;
                tRequestLayerPtr        lLayerPtr;

                for (i = 0; i < m_RequestLayerList.Size(); ++i)
                {
                    lLayerPtr = m_RequestLayerList[i].LayerPtr;
                    if (::Wiz::IsValidPtr(lLayerPtr))
                    {
                        for (j = 0; j < lLayerPtr->Size(); ++j)
                        {
                            Attr::Request::ptr lReqPtr = (*lLayerPtr)[j];
                            if (::Wiz::IsValidPtr(lReqPtr) && (lReqPtr->m_ID == inReqID))
                            {
                                tRequestLayer::tSize const tReqLastIdx = lLayerPtr->Size() - 1;
                                if (tReqLastIdx == 0)
                                {
                                    lLayerPtr->Clear();
                                }
                                else
                                {
                                    if (j < tReqLastIdx)
                                    {
                                        (*lLayerPtr)[j] = (*lLayerPtr)[tReqLastIdx];
                                    }

                                    lLayerPtr->PopBack();
                                }
                                return Bool::True;
                            }
                        }
                    }
                }

                return Bool::False;
            }

            Bool::type type::RemoveRequest(tRequestLayerPtr inLayerPtr, Attr::Request::ptr inReqPtr)
            {
                if (inLayerPtr->Size() > 0)
                {
                    tRequestLayer::tSize const lReqLastIdx  = inLayerPtr->Size() - 1;

                    tRequestLayer::tSize i = 0;
                    for (; i < lReqLastIdx; ++i)
                    {
                        Attr::Request::ptr tReqPtr = (*inLayerPtr)[i];
                        if (inReqPtr == tReqPtr)
                        {
                            (*inLayerPtr)[i] = (*inLayerPtr)[lReqLastIdx];
                            break;
                        }
                    }

                    if ((i < lReqLastIdx) || (inReqPtr == (*inLayerPtr)[lReqLastIdx]))
                    {
                        inLayerPtr->PopBack();
                        return Bool::True;
                    }
                }

                return Bool::False;
            }

            Void::type type::ClearAllRequests()
            {
                tRequestLayerList::tSize     i;
                tRequestLayerPtr        lLayerPtr;

                for (i = 0; i < m_RequestLayerList.Size(); ++i)
                {
                    lLayerPtr = m_RequestLayerList[i].LayerPtr;
                    if (::Wiz::IsValidPtr(lLayerPtr))
                    {
                        lLayerPtr->Clear();
                    }
                }
            }
        } /// end of namespace Modifier
    } /// end of namespace Attr
} /// end of namespace wms
