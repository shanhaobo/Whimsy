#include "../../Include/Module/WMSAttrModule.hpp"

namespace wms
{
    namespace Attr
    {
        type::type(Attr::Modifier::ptr inMoidifierPtr) : m_MoidifierPtr(inMoidifierPtr), m_LastTime(0)
        {
        }

        type::~type()
        {
        }

        Void::type type::Tick(F32::in inDeltaTime)
        {

        }

        ID32::type type::ReceiveRequest(Attr::Request::ptr inReqPtr)
        {
            if (::Wiz::IsValidPtr(m_MoidifierPtr) && ::Wiz::IsValidPtr(inReqPtr))
            {
                return m_MoidifierPtr->ReceiveRequest(inReqPtr);
            }

            return ID32::Invalid;
        }

        Void::type type::RemoveRequest(ID32::in inReqID)
        {
            if (::Wiz::IsValidPtr(m_MoidifierPtr) && (inReqID != ID32::Invalid))
            {
                m_MoidifierPtr->RemoveRequest(inReqID);
            }
        }
    } /// end of namespace Attr
} /// end of namespace wms
