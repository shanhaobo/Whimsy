#include "../../Include/Module/WMSAttrManager.hpp"
#include "../../Include/Module/WMSAttrProvider.hpp"

namespace wms
{
    namespace Attr
    {
        namespace Provider
        {
            type::type()
            {
            }

            type::~type()
            {

            }


            Void::type type::AttachAllRequest(tRequestInstantItem& ioItem)
            {
                tRequestList::tSize i;
                for (i = 0; i < m_RequestList.Size(); ++i)
                {
                    tRequestItem& tReqItem = m_RequestList[i];
                    Attr::ptr tAttrPtr = ioItem.m_AttrManagerPtr->GetAttrByIdx(tReqItem.m_AttrID);
                    if (::Wiz::IsValidPtr(tAttrPtr))
                    {
                        ID32::typec tID = tAttrPtr->ReceiveRequest(tReqItem.m_RequestPtr);

                        ioItem.m_RequestIDList.PushBack(tIDPair(tID, tReqItem.m_AttrID));
                    }
                }
            }


            Void::type type::DetachAllRequest(tRequestInstantItem& ioItem)
            {
                Size::type i;
                for (i = 0; i < ioItem.m_RequestIDList.Size(); ++i)
                {
                    tIDPair& lIDPair = ioItem.m_RequestIDList[i];

                    Attr::ptr lAttrPtr = ioItem.m_AttrManagerPtr->GetAttrByIdx(lIDPair.m_AttrID);
                    if (::Wiz::IsValidPtr(lAttrPtr))
                    {
                        lAttrPtr->RemoveRequest(lIDPair.m_ReqID);
                    }
                }

                ioItem.m_RequestIDList.Clear();
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

                    /// 1) m_AttrManagerPtr
                    lInstantItem.m_AttrManagerPtr = inAttrManagerPtr;
                    /// 2) m_RequestIDList
                    AttachAllRequest(lInstantItem);
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
                DetachAllRequest(*lIter);

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
                        DetachAllRequest(*lIter);
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
                    DetachAllRequest(*lIter);

                    /// Attach All Requests Again;
                    AttachAllRequest(*lIter);

                    return Bool::True;
                }

                /// NO Found
                return Attach(inAttrManagerPtr);
            }
        } /// end of namespace Provider
    } /// end of namespace Attr
} /// end of namespace wms
