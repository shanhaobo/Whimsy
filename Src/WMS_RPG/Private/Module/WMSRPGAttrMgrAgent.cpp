#include "../../Include/Module/WMSRPGAttrManager.hpp"
#include "../../Include/Module/WMSRPGAttrMgrAgent.hpp"

namespace wms
{
    namespace RPG
    {
        namespace Attr
        {
            namespace Manager
            {
                namespace Agent
                {
                    type::type(Attr::Manager::ptr inMgrPtr) : m_MgrPtr(inMgrPtr)
                    {
                    }

                    type::~type()
                    {
                    }

                    namespace Health
                    {
                        type::type(Attr::Manager::ptr inMgrPtr) : tSuper(inMgrPtr)
                        {
                            if (::Wiz::IsValidPtr(m_MgrPtr))
                            {
                                m_MgrPtr->NewAttr(Attr::Category::Health);
                                m_MgrPtr->NewAttr(Attr::Category::HealthMax);
                            }
                        }

                        type::~type()
                        {
                        }
                    }  /// end of namespace Health
                } /// end of namespace Agent
            } /// end of namespace Manager
        } /// end of namespace Attr
    } /// end of namespace RPG
} /// end of namespace wms
