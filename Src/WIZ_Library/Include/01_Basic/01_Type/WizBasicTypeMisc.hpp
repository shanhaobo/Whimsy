#ifndef __WIZ_BASIC_TYPE_MISC_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TYPE_MISC_HPP__SHANHAOBO_19800429__

#include "./WizBasicTypeBool.hpp"

#include "./WizBasicTypeDeclareUtils.hpp"

namespace Wiz
{
    namespace Void
    {
        WIZ_DECLARE_TYPE_STDNAME(void);
        WIZ_DECLARE_PTR(void);
    } /// end of namespace Void

    namespace Null
    {
        WIZ_CLASS
        {
        public:
            Type() {}
            Type(In, In) {}

            typedef Type tHead;
            typedef Type tTail;
        };

        template<typename ElementT>
        struct IsA
        {
            static ::Wiz::Bool::TypeC Value = ::Wiz::Bool::False;
        };

        template<>
        struct IsA<::Wiz::Null::Type>
        {
            static ::Wiz::Bool::TypeC Value = ::Wiz::Bool::True;
        };
    } /// end of namespace Null

    namespace PtrDiff
    {
        typedef ptrdiff_t  Type;
    } /// end of namespace PtrDiff
} /// end of namespace Wiz

#endif /*__WIZ_BASIC_TYPE_MISC_HPP__SHANHAOBO_19800429__*/
