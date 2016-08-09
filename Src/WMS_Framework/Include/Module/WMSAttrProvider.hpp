#ifndef __WHIMSY_ATTRIBUTE_PROVIDER_HPP__ 
#define __WHIMSY_ATTRIBUTE_PROVIDER_HPP__

#include "../Core/WMSFrmwrkFwdDclr.hpp"
#include "./WMSAttrRequest.hpp"

namespace wms
{
    namespace Attr
    {
        namespace Provider
        {
            WMS_CLASS
            {
            protected:
                struct tIDPair
                {
                    ID32::type              m_AttrID;
                    ID32::type              m_ReqID;

                    WIZ_INLINE Bool::type operator==(tIDPair const & inOther) const
                    {
                        if (m_AttrID != inOther.m_AttrID)
                        {
                            return Bool::False;
                        }
                        return m_ReqID == inOther.m_ReqID;
                    }

                    tIDPair() : m_AttrID(ID32::Invalid), m_ReqID(ID32::Invalid)
                    {

                    }
                    tIDPair(ID32::in inAttrID, ID32::in inReqID) : m_AttrID(inAttrID), m_ReqID(inReqID)
                    {

                    }
                };
                typedef Array<tIDPair>::type           tIDPairList;

                struct tRequestItem
                {
                    ID32::type                  m_AttrID;
                    Attr::Request::ptr          m_RequestPtr;

                    tRequestItem(ID32::in inAttrID, Attr::Request::ptr inRequestPtr) : m_AttrID(inAttrID), m_RequestPtr(inRequestPtr)
                    {

                    }
                };
                typedef Array<tRequestItem>::type           tRequestList;

                struct tRequestInstantItem
                {
                    Attr::Manager::ptr          m_AttrManagerPtr;
                    tIDPairList                 m_RequestIDList;

                    WIZ_INLINE Bool::type operator==(tRequestInstantItem const & inOther) const
                    {
                        if (m_AttrManagerPtr != inOther.m_AttrManagerPtr)
                        {
                            return Bool::False;
                        }

                        return m_RequestIDList == inOther.m_RequestIDList;
                    }

                    tRequestInstantItem() : m_AttrManagerPtr(WIZ_NULLPTR)
                    {

                    }

                    Void::type AttachTo(Attr::Manager::ptr, tRequestList const &);
                    Void::type Detach();
                };
                typedef List<tRequestInstantItem>::type    tRequestInstantList;

            public:
                type();
                virtual ~type();

                Bool::type IsAttached(Attr::Manager::ptr) const;
                Bool::type Attach(Attr::Manager::ptr);
                Bool::type AttachWithoutCheck(Attr::Manager::ptr);
                Void::type Detach(Attr::Manager::ptr);
                Void::type DetachAll();
                Bool::type Reattach(Attr::Manager::ptr);

            protected:
                tRequestList                m_RequestList;
                tRequestInstantList         m_RequestInstantList;
            };
        } /// end of namespace Provider
    } /// end of namespace Attr
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_PROVIDER_HPP__
