#ifndef __WIZ_BASIC_TYPE_ID_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TYPE_ID_HPP__SHANHAOBO_19800429__

#include "./WizBasicTypeInt.hpp"

namespace Wiz
{
    namespace ID8
    {
        WIZ_DECLARE_SIMPLE(U8::Type);
        static TypeC invalid    = ::Wiz::U8::Max;
        static TypeC Min        = 0;
        static TypeC Max        = ::Wiz::U8::Max - 1;
    } /// end of namespace Size8

    namespace ID16
    {
        WIZ_DECLARE_SIMPLE(U16::Type);
        static TypeC invalid    = ::Wiz::U16::Max;
        static TypeC Min        = 0;
        static TypeC Max        = ::Wiz::U16::Max - 1;
    } /// end of namespace Size16

    namespace ID32
    {
        WIZ_DECLARE_SIMPLE(U32::Type);
        static TypeC invalid    = ::Wiz::U32::Max;
        static TypeC Min        = 0;
        static TypeC Max        = ::Wiz::U32::Max - 1;
    } /// end of namespace Size32

    namespace ID64
    {
        WIZ_DECLARE_SIMPLE(U64::Type);
        static TypeC invalid    = ::Wiz::U64::Max;
        static TypeC Min        = 0;
        static TypeC Max        = ::Wiz::U64::Max - 1;
    } /// end of namespace Size64

} /// end of namespace Wiz

#endif /*__WIZ_BASIC_TYPE_ID_HPP__SHANHAOBO_19800429__*/
