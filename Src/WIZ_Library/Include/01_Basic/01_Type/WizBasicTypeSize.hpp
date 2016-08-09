#ifndef __WIZ_BASIC_TYPE_SIZE_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TYPE_SIZE_HPP__SHANHAOBO_19800429__

#include "./WizBasicTypeInt.hpp"

namespace Wiz
{
    namespace Size
    {
        WIZ_DECLARE_SIMPLE(size_t);
    } /// end of namespace Size

    namespace USize8
    {
        WIZ_DECLARE_SIMPLE(U8::Type);
        static TypeC Invalid    = ::Wiz::U8::Max;
        static TypeC Min        = 0;
        static TypeC Max        = ::Wiz::U8::Max - 1;
    } /// end of namespace USize8

    namespace USize16
    {
        WIZ_DECLARE_SIMPLE(U16::Type);
        static TypeC Invalid    = ::Wiz::U16::Max;
        static TypeC Min        = 0;
        static TypeC Max        = ::Wiz::U16::Max - 1;
    } /// end of namespace USize16

    namespace USize32
    {
        WIZ_DECLARE_SIMPLE(U32::Type);
        static TypeC Invalid    = ::Wiz::U32::Max;
        static TypeC Min        = 0;
        static TypeC Max        = ::Wiz::U32::Max - 1;
    } /// end of namespace USize32

    namespace USize64
    {
        WIZ_DECLARE_SIMPLE(U64::Type);
        static TypeC Invalid    = ::Wiz::U64::Max;
        static TypeC Min        = 0;
        static TypeC Max        = ::Wiz::U64::Max - 1;
    } /// end of namespace USize64

} /// end of namespace Wiz

#endif /*__WIZ_BASIC_TYPE_SIZE_HPP__SHANHAOBO_19800429__*/
