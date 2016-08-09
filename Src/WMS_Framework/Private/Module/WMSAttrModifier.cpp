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
                tRequestList::tSize i;

                for (i = 0; i < m_RequestList.Size(); ++i)
                {
                    if (m_RequestList[i].LayerID == inLayerID)
                    {
                        return m_RequestList[i].LayerPtr;
                    }
                }

                ///未找到
                tRequestLayerPtr lResultPtr = WMS_NEW_T(tRequestLayer, EWMS_OBJ_CAT::eWOC_General);
                if (::Wiz::IsValidPtr(lResultPtr))
                {
                    m_RequestList.PushBack(tRequestLayerItem(inLayerID, lResultPtr));
                    if (m_RequestList.Size() >= 2)
                    {
                        tRequestLayer::tSize const tLastIdx = m_RequestList.Size() - 1;

                        /// Sort()
                        /// 从倒数第二个开始与倒数第一个(inLayerID, tResultPtr)比较
                        for (i = tLastIdx - 1; i >= 0; ++i)
                        {
                            /// 大的排到后面去
                            if (m_RequestList[i].LayerID > inLayerID)
                            {
                                m_RequestList[i + 1].LayerID  = m_RequestList[i].LayerID;
                                m_RequestList[i + 1].LayerPtr = m_RequestList[i].LayerPtr;

                                m_RequestList[i].LayerID      = inLayerID;
                                m_RequestList[i].LayerPtr     = lResultPtr;
                            }
                        }
                    }
                }

                return lResultPtr;
            }

            ID32::type type::ReceiveRequest(Attr::Request::ptr inNewReqPtr)
            {
                tRequestLayerPtr lArrayPtr = FindOrCreateRequestLayer(inNewReqPtr->m_LayerID);
                if (::Wiz::IsValidPtr(lArrayPtr))
                {
                    lArrayPtr->PushBack(inNewReqPtr);
                    inNewReqPtr->m_ID = GenReqID();
                    return inNewReqPtr->m_ID;
                }

                return ID32::Invalid;
            }


            ID32::type type::GenReqID()
            {
                return m_RequestID++;
            }


            Void::type type::RemoveRequest(ID32::in inReqID)
            {
                tRequestList::tSize     i, j;
                tRequestLayerPtr        lLayerPtr;

                for (i = 0; i < m_RequestList.Size(); ++i)
                {
                    lLayerPtr = m_RequestList[i].LayerPtr;
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
                                return;
                            }
                        }
                    }
                }
            }

            Void::type type::RemoveRequest(tRequestLayerPtr inLayerPtr, Attr::Request::ptr inReqPtr)
            {
                if (inLayerPtr->Size() >= 1)
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
                    }
                }
            }
        } /// end of namespace Modifier
    } /// end of namespace Attr
} /// end of namespace wms
