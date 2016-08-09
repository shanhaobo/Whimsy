#ifndef __WHIMSY_CORE_COMPONENT_CONTAINER_HPP__ 
#define __WHIMSY_CORE_COMPONENT_CONTAINER_HPP__

#include "./WMSCoreFwdDclr.hpp"

#include "./WMSCoreComponent.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace CmpntMap
    {
        class type: public ::wms::Cmpnt::type
        {
        public:
            type();
            virtual ~type();

        public:
            virtual Void::type Tick(F32::in inDeltaTime);

        public:
            typedef Map<::wms::Name::type, ::wms::Cmpnt::ptr>::type tMap;

        protected:
            tMap        m_Children;
        };
    } /// end of namespace CmpntMap

    namespace CmpntArray
    {
        WMS_CLASS: public ::wms::Cmpnt::type
        {
        private:
            typedef ::wms::Cmpnt::type tSuper;

        public:
            type();
            type(::wms::Size::in);
            virtual ~type();

        public:
            virtual Void::type Tick(F32::in inDeltaTime);

        public:
            typedef Array<::wms::Cmpnt::ptr>::type tArray;

        protected:
            tArray      m_Children;
        };
    } /// end of namespace CmpntArray
} /// end of namespace wms

#endif /// __WHIMSY_CORE_COMPONENT_CONTAINER_HPP__
