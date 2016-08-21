#ifndef __WHIMSY_RPG_ATTRIBUTE_MANAGER_AGENT_HPP__ 
#define __WHIMSY_RPG_ATTRIBUTE_MANAGER_AGENT_HPP__

#include "../Core/WMSRPGFwdDclr.hpp"
#include "../../../WMS_Framework/Include/Module/WMSAttrManager.hpp"

#include "./WMSRPGAttribute.hpp"
#include "./WMSRPGAttrManager.hpp"

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
                    WMS_CLASS : public ::wms::Obj::Framework::General::type
                    {
                        typedef ::wms::Obj::Framework::General::type tSuper;
                    public:
                        type(Attr::Manager::ptr inMgrPtr);

                        virtual ~type();

                    protected:
                        Attr::Manager::ptr  m_MgrPtr;
                    };

                    namespace Health
                    {
                        WMS_CLASS : public Agent::type
                        {
                            typedef  Agent::type tSuper;
                        public:
                            type(Attr::Manager::ptr inMgrPtr);

                            virtual ~type();
                        };
                    } /// end of namespace Health;
                } /// end of namespace Agent;
            } /// end of namespace Manager
        } /// end of namespace Attr
    } /// end of namespace RPG
} /// end of namespace wms

#endif /// __WHIMSY_RPG_ATTRIBUTE_MANAGER_AGENT_HPP__
