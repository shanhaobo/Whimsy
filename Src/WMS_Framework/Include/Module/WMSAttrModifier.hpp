#ifndef __WHIMSY_ATTRIBUTE_MODIFIER_HPP__ 
#define __WHIMSY_ATTRIBUTE_MODIFIER_HPP__

#include "../Core/WMSFrmwrkFwdDclr.hpp"
#include "./WMSAttrRequest.hpp"

namespace wms
{
    namespace Attr
    {
        namespace Modifier
        {
            WMS_CLASS : public wms::Obj::Framework::Attribute::type
            {
            protected:
                typedef Array<Attr::Request::ptr>::type     tRequestLayer;
                typedef tRequestLayer*                      tRequestLayerPtr;

                struct tRequestLayerItem
                {
                    ID32::type          LayerID;
                    tRequestLayerPtr    LayerPtr;

                    tRequestLayerItem(ID32::in inLayerID, tRequestLayerPtr inLayerPtr) : LayerID(inLayerID), LayerPtr(inLayerPtr)
                    {

                    }
                };
                typedef Array<tRequestLayerItem>::type       tRequestLayerList;

            public:
                type();
                virtual ~type();

                ID32::type ReceiveRequest(Attr::Request::ptr);
                Bool::type RemoveRequest(ID32::in);

                Void::type ClearAllRequests();

            protected:
                tRequestLayerPtr FindOrCreateRequestLayer(ID32::in inLayerID);
                Bool::type RemoveRequest(tRequestLayerPtr, Attr::Request::ptr);

                ID32::type GenReqID();

            protected:
                tRequestLayerList                m_RequestLayerList;

                ID32::type                  m_RequestID;
            };
        } /// end of namespace Modifier
    } /// end of namespace Attr
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_MODIFIER_HPP__
