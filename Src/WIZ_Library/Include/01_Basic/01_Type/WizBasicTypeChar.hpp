#ifndef __WIZ_BASIC_TYPE_CHAR_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TYPE_CHAR_HPP__SHANHAOBO_19800429__

#include "./WizBasicTypeDeclareUtils.hpp"

namespace Wiz
{
    ///////////////////////////////////////////////////
    namespace Char
    {
        WIZ_DECLARE_SIMPLE(char);
        static TypeC Terminator = '\0';

        static TypeC Digit_0 = '0';
        static TypeC Digit_1 = '1';
        static TypeC Digit_2 = '2';
        static TypeC Digit_3 = '3';
        static TypeC Digit_4 = '4';
        static TypeC Digit_5 = '5';
        static TypeC Digit_6 = '6';
        static TypeC Digit_7 = '7';
        static TypeC Digit_8 = '8';
        static TypeC Digit_9 = '9';
    } /// end of namespace Char

    namespace WChar
    {
        WIZ_DECLARE_SIMPLE(wchar_t);
        static TypeC Terminator = L'\0';

        static TypeC Digit_0 = L'0';
        static TypeC Digit_1 = L'1';
        static TypeC Digit_2 = L'2';
        static TypeC Digit_3 = L'3';
        static TypeC Digit_4 = L'4';
        static TypeC Digit_5 = L'5';
        static TypeC Digit_6 = L'6';
        static TypeC Digit_7 = L'7';
        static TypeC Digit_8 = L'8';
        static TypeC Digit_9 = L'9';
    } /// end of namespace WChar

    namespace MBChar
    {
        WIZ_DECLARE_SIMPLE(unsigned char);
        static TypeC Terminator = '\0';

        static TypeC Digit_0 = '0';
        static TypeC Digit_1 = '1';
        static TypeC Digit_2 = '2';
        static TypeC Digit_3 = '3';
        static TypeC Digit_4 = '4';
        static TypeC Digit_5 = '5';
        static TypeC Digit_6 = '6';
        static TypeC Digit_7 = '7';
        static TypeC Digit_8 = '8';
        static TypeC Digit_9 = '9';
    } /// end of namespace MBChar
    ///////////////////////////////////////////////////
} /// end of namespace Wiz

#endif /*__WIZ_BASIC_TYPE_CHAR_HPP__SHANHAOBO_19800429__*/
