#ifndef __WHIMSY_RPG_ACTOR_HPP__ 
#define __WHIMSY_RPG_ACTOR_HPP__

#include "./WMSRPGFwdDclr.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace RPG
    {
        namespace Actor
        {
            WMS_CLASS: public ::wms::Actor::type
            {
            private:
                typedef ::wms::Actor::type tSuper;

            public:
                type() {};
                virtual ~type() {};

            public:
            };
        } /// end of namespace Actor
    }
} /// end of namespace wms

#endif /// __WHIMSY_RPG_ACTOR_HPP__
