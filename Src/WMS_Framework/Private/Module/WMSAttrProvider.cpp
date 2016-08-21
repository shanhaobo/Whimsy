#include "../../Include/Module/WMSAttrManager.hpp"
#include "../../Include/Module/WMSAttrProvider.hpp"

namespace wms
{
    namespace Attr
    {
        namespace Provider
        {

            //////////////////////////////////////////////////////
            //////////////////////////////////////////////////////
            type::tRequestInstantItem::tRequestInstantItem() : m_AttrManagerPtr(WIZ_NULLPTR)
            {

            }

            Bool::type type::tRequestInstantItem::operator==(tRequestInstantItem const & inOther) const
            {
                if (m_AttrManagerPtr != inOther.m_AttrManagerPtr)
                {
                    return Bool::False;
                }

                return m_RequestIDList == inOther.m_RequestIDList;
            }

            Void::type type::tRequestInstantItem::AttachTo(Attr::Manager::ptr inAttrManagerPtr, tRequestLayerList const & inReqList)
            {
                m_AttrManagerPtr = inAttrManagerPtr;

                tRequestLayerList::tSize i;
                for (i = 0; i < inReqList.Size(); ++i)
                {
                    tRequestItem const & tReqItem = inReqList[i];
                    Attr::ptr tAttrPtr = m_AttrManagerPtr->GetAttrByIdx(tReqItem.m_AttrID);
                    if (::Wiz::IsValidPtr(tAttrPtr))
                    {
                        ID32::typec tID = tAttrPtr->ReceiveRequest(tReqItem.m_RequestPtr);

                        m_RequestIDList.PushBack(tIDPair(tID, tReqItem.m_AttrID));
                    }
                }
            }

            Void::type type::tRequestInstantItem::Detach()
            {
                Size::type i;
                for (i = 0; i < m_RequestIDList.Size(); ++i)
                {
                    tIDPair& lIDPair = m_RequestIDList[i];

                    Attr::ptr lAttrPtr = m_AttrManagerPtr->GetAttrByIdx(lIDPair.m_AttrID);
                    if (::Wiz::IsValidPtr(lAttrPtr))
                    {
                        lAttrPtr->RemoveRequest(lIDPair.m_ReqID);
                    }
                }

                m_RequestIDList.Clear();
            }

            //////////////////////////////////////////////////////
            //////////////////////////////////////////////////////
            type::type()
            {
            }

            type::~type()
            {

            }


            Bool::type type::IsAttached(Attr::Manager::ptr inAttrManagerPtr) const
            {
                if (::Wiz::IsValidPtr(inAttrManagerPtr) && (m_RequestInstantList.Size() > 0))
                {
                    tRequestInstantList::tIteratorConst lIter;
                    for (lIter = m_RequestInstantList.Begin(); lIter != m_RequestInstantList.End(); ++lIter)
                    {
                        if (lIter->m_AttrManagerPtr == inAttrManagerPtr)
                        {
                            return Bool::True;
                        }
                    }
                }

                return Bool::False;
            }


            Bool::type type::AttachWithoutCheck(Attr::Manager::ptr inAttrManagerPtr)
            {
                if (::Wiz::IsValidPtr(inAttrManagerPtr) && (m_RequestList.Size() > 0))
                {
                    m_RequestInstantList.PushBack(tRequestInstantItem());
                    tRequestInstantItem& lInstantItem = m_RequestInstantList.Back();

                    lInstantItem.AttachTo(inAttrManagerPtr, m_RequestList);
                }

                return Bool::True;
            }

            Bool::type type::Attach(Attr::Manager::ptr inAttrManagerPtr)
            {
                if (IsAttached(inAttrManagerPtr))
                {
                    return Bool::True;
                }

                return AttachWithoutCheck(inAttrManagerPtr);
            }

            Void::type type::Detach(Attr::Manager::ptr inAttrManagerPtr)
            {
                tRequestInstantList::tIterator lIter;
                for (lIter = m_RequestInstantList.Begin(); lIter != m_RequestInstantList.End(); ++lIter)
                {
                    if (lIter->m_AttrManagerPtr == inAttrManagerPtr)
                    {
                        break;
                    }
                }

                /// Found
                lIter->Detach();

                /// Remove Instant
                m_RequestInstantList.Erase(lIter);
            }

            Void::type type::DetachAll()
            {
                tRequestInstantList::tIterator lIter;
                for (lIter = m_RequestInstantList.Begin(); lIter != m_RequestInstantList.End(); ++lIter)
                {
                    if (::Wiz::IsValidPtr(lIter->m_AttrManagerPtr))
                    {
                        lIter->Detach();
                    }
                }

                /// Remove All
                m_RequestInstantList.Clear();
            }

            Bool::type type::Reattach(Attr::Manager::ptr inAttrManagerPtr)
            {
                tRequestInstantList::tIterator lIter;
                for (lIter = m_RequestInstantList.Begin(); lIter != m_RequestInstantList.End(); ++lIter)
                {
                    if (lIter->m_AttrManagerPtr == inAttrManagerPtr)
                    {
                        break;
                    }
                }

                if (lIter != m_RequestInstantList.End())
                {
                    /// Found
                    /// Remove All Requests First;
                    lIter->Detach();

                    /// Attach All Requests Again;
                    lIter->AttachTo(inAttrManagerPtr, m_RequestList);

                    return Bool::True;
                }

                /// NO Found
                return Attach(inAttrManagerPtr);
            }
        } /// end of namespace Provider
    } /// end of namespace Attr
} /// end of namespace wms
