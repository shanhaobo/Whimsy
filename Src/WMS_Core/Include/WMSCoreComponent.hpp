#ifndef __WHIMSY_CORE_COMPONENT_HPP__ 
#define __WHIMSY_CORE_COMPONENT_HPP__

#include "./WMSCoreFwdDclr.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace Cmpnt
    {
        WMS_CLASS: public ::wms::Obj::Cmpnt::type
        {
        public:
            type();
            virtual ~type();

        public:
            virtual Void::type Tick(F32::in inDeltaTime) = WIZ_NULL;

            virtual Bool::type Init() = WIZ_NULL;

        protected:
            virtual Void::type InitMetaInfo();

        protected:
            ::wms::Cmpnt::MetaMntr::ptr m_MetaMntr;
        };

        template<class DerivedT>
        class Class
        {
        public:
            static ::wms::Cmpnt::ptr Construct()
            {
                ::wms::Cmpnt::ptr lCmpntPtr =  WIZ_NEW DerivedT();
                if (IsValidPtr(lCmpntPtr))
                {
                    if (lCmpntPtr->Init())
                    {
                        lCmpntPtr->InitMetaInfo();
                    }
                    else
                    {
                        WIZ_DEL lCmpntPtr;
                        lCmpntPtr = WIZ_NULLPTR;
                    }
                }
                return lCmpntPtr;
            }
        };

        ::wms::Cmpnt::ptr Construct();
    } /// end of namespace Cmpnt
} /// end of namespace wms

#endif /// __WHIMSY_CORE_COMPONENT_HPP__
