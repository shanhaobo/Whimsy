#include "../../Include/Module/WMSAttrModule.hpp"

namespace wms
{
    namespace Attr
    {
        type::type(Attr::Modifier::ptr inModifierPtr, Bool::type inVariable) : m_ModifierPtr(inModifierPtr), m_Variable(inVariable)
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
            ID32::type tResultID(ID32::Invalid);

            if (::Wiz::IsValidPtr(m_ModifierPtr) && ::Wiz::IsValidPtr(inReqPtr))
            {
                tResultID = m_ModifierPtr->ReceiveRequest(inReqPtr);
                if (tResultID != ID32::Invalid)
                {
                    m_BeModified = Bool::True;

                    return tResultID;
                }
            }

            return tResultID;
        }

        Void::type type::RemoveRequest(ID32::in inReqID)
        {
            if (::Wiz::IsValidPtr(m_ModifierPtr) && (inReqID != ID32::Invalid))
            {
                if (m_ModifierPtr->RemoveRequest(inReqID))
                {
                    m_BeModified = Bool::True;
                }
            }
        }
    } /// end of namespace Attr
} /// end of namespace wms
