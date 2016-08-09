#include "../Include/WMSCoreComponentContainer.hpp"

namespace wms
{
    namespace CmpntMap
    {
        type::type()
        {
        }

        type::~type()
        {
        }

        Void::type type::Tick(F32::in inDeltaTime)
        {
            auto const lItrEnd = m_Children.End();
            for (auto lItr = m_Children.Begin(); lItr != lItrEnd; ++lItr)
            {
                auto lChildPtr = lItr.Value();
                if (::Wiz::IsValidPtr(lChildPtr))
                {
                    lChildPtr->Tick(inDeltaTime);
                }
            }
        }
    } /// end of namespace CmpntMap

    namespace CmpntArray
    {
        type::type()
        {
        }

        type::type(::wms::Size::in inSize) : m_Children(inSize)
        {
        }

        type::~type()
        {
        }

        Void::type type::Tick(F32::in inDeltaTime)
        {
            ::wms::Size::typec lChildCount = m_Children.Size();
            for (::wms::Size::type i = 0; i < lChildCount; ++i)
            {
                auto lChildPtr = m_Children[i];
                if (::Wiz::IsValidPtr(lChildPtr))
                {
                    lChildPtr->Tick(inDeltaTime);
                }
            }
        }
    } /// end of namespace CmpntArray
} /// end of namespace wms
