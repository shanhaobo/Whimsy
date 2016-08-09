#ifndef __WHIMSY_WEAPON_SYSTEM_ATTACK_MODULE_HPP__ 
#define __WHIMSY_WEAPON_SYSTEM_ATTACK_MODULE_HPP__

#include "../../Core/WMSFrmwrkFwdDclr.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace WeapSys
    {
        namespace AttMdl
        {
            WMS_CLASS: public ::wms::CmpntArray::type
            {
            private:
                typedef ::wms::CmpntArray::type tSuper;

            public:
                type();
                virtual ~type();

            protected:
                virtual Void::type Tick(F32::in inDeltaTime);

            protected:
                /// ����(Projectile, Melee, ɢ��, ����)
                /// �˺����(�˺�,˥��,��͸)
                /// ����(���, �ص�, ����)
                /// ����(ģ��, ����, ��Ч(Muzzle & Shell))
            };
        } /// end of namespace AttMdl
    } /// end of namespace WS
} /// end of namespace wms

#endif /// __WHIMSY_WEAPON_SYSTEM_ATTACK_MODULE_HPP__
