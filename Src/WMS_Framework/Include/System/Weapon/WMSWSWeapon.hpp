#ifndef __WHIMSY_WEAPON_SYSTEM_WEAPON_HPP__ 
#define __WHIMSY_WEAPON_SYSTEM_WEAPON_HPP__

#include "../../Core/WMSFrmwrkComponent.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace WeapSys
    {
        namespace Weapon
        {
            WMS_CLASS: public ::wms::CmpntArray::type
            {
            private:
                typedef ::wms::CmpntArray::type tSuper;

            public:
                type();
                type(::wms::Size::in);
                virtual ~type();
            };
        }
    } /// end of namespace BhvrModule
} /// end of namespace wms

#endif /// __WHIMSY_WEAPON_SYSTEM_WEAPON_HPP__
