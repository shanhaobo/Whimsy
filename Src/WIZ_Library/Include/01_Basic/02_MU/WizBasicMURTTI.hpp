#ifndef __WIZ_BASIC_MU_RTTI_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_MU_RTTI_HPP__SHANHAOBO_19800429__

//////////////////////////////////////////////////////////////////////////

#include "./WizBasicMU.hpp"

namespace Wiz
{
    namespace RTTI
    {
        struct Type
        {
            typedef Type                    tRTTI;
            typedef tRTTI *                 tRTTIPtr;
            typedef tRTTI const *           tRTTIPtrC;
            typedef tRTTI const * const     tRTTIPtrFC;

            virtual tRTTIPtrFC GetSuper() const = WIZ_NULL;

            virtual tRTTIPtrFC Get() const = WIZ_NULL;

        public:
            ::Wiz::Bool::Type IsA(tRTTIPtrFC inRTTI) const
            {
                return inRTTI == Get();
            }

            ::Wiz::Bool::Type IsKindOf(tRTTIPtrFC inRTTI) const
            {
                return IsA(inRTTI) || ((GetSuper() != WIZ_NULLPTR) && GetSuper()->IsKindOf(inRTTI));
            }

            template<class U>
            ::Wiz::Bool::Type IsA() const
            {
                return IsA(U::GetRTTI());
            }

            template<class U>
            ::Wiz::Bool::Type IsKindOf() const
            {
                return IsKindOf(U::GetRTTI());
            }
        };

        namespace Base
        {
            template<class DerivedT>
            class Type : public RTTI::Type
            {
                typedef Type<DerivedT>          tThis;
            public:
                static tRTTIPtrFC StaticGet()
                {
                    static tThis s_RTTI;

                    return &s_RTTI;
                }

            public:
                virtual tRTTIPtrFC GetSuper() const
                {
                    return WIZ_NULLPTR;
                }

                virtual tRTTIPtrFC Get() const
                {
                    return tThis::StaticGet();
                }
            };
        } /// end of namespace Base


        namespace Derived
        {
            template<class DerivedT, class BaseT>
            class Type : public RTTI::Type
            {
                typedef Type<DerivedT, BaseT>   tThis;
            public:
                Type(tRTTIPtrFC inSuperPtr) : m_SuperPtr(inSuperPtr)
                {
                }

            public:
                static tRTTIPtrFC StaticGet()
                {
                    static tThis s_RTTI(BaseT::GetRTTI());

                    return &s_RTTI;
                }

            public:
                virtual tRTTIPtrFC GetSuper() const
                {
                    return m_SuperPtr;
                }

                virtual tRTTIPtrFC Get() const
                {
                    return tThis::StaticGet();
                }
            protected:
                tRTTIPtrFC                      m_SuperPtr;
            };
        }
    } /// end of namespace RTTI
} /// end of namespace Wiz


#define WIZ_DECLARE_RTTI_BASE(MPThis)       \
    WIZ_INLINE static ::Wiz::RTTI::Type const * const GetRTTI(){ return ::Wiz::RTTI::Base::Type<MPThis>::StaticGet(); };

#define WIZ_DECLARE_RTTI(MPThis, MPBase)    \
    WIZ_INLINE static ::Wiz::RTTI::Type const * const GetRTTI(){ return ::Wiz::RTTI::Derived::Type<MPThis, MPBase>::StaticGet(); };

//////////////////////////////////////////////////////////////////////////

#endif /*__WIZ_BASIC_MU_RTTI_HPP__SHANHAOBO_19800429__*/
