#ifndef __WHIMSY_RPG_OBJECT_HPP__ 
#define __WHIMSY_RPG_OBJECT_HPP__

#include "./WMSRPGFwdDclr.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace RPG
    {
        namespace Object
        {
            WMS_CLASS: public ::wms::CmpntMap::type
            {
            private:
                typedef ::wms::CmpntMap::type tSuper;

            public:
                type() {};
                virtual ~type() {};

            public:
            };
        } /// end of namespace Object
    } /// end of namespace RPG
} /// end of namespace wms

#endif /// __WHIMSY_RPG_OBJECT_HPP__
