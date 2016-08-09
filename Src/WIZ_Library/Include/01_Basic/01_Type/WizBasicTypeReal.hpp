#ifndef __WIZ_BASIC_TYPE_REAL_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TYPE_REAL_HPP__SHANHAOBO_19800429__

#include <float.h>

#include "./WizBasicTypeDeclareUtils.hpp"

namespace Wiz
{
    namespace R32
    {
        WIZ_DECLARE_SIMPLE(float);
        static TypeC Epsilon    = FLT_EPSILON;
        static TypeC EpsilonSqr = ::Wiz::R32::Epsilon * ::Wiz::R32::Epsilon;
        static TypeC Zero       = 0;
        static TypeC MaxZeroEp  = 0 + ::Wiz::R32::Epsilon;
        static TypeC MinZeroEp  = 0 - ::Wiz::R32::Epsilon;
        static TypeC One        = 1;
        static TypeC MaxOneEp   = 1 + ::Wiz::R32::Epsilon;
        static TypeC MinOneEp   = 1 - ::Wiz::R32::Epsilon;
        static TypeC Max        = FLT_MAX;
        static TypeC Min        = -::Wiz::R32::Max;

        /// 用于模版类参数声明【template<float> 是不可以的】
        namespace Template
        {
            typedef R32::RefC   Type;
        } /// end of namespace Template
        namespace Tmplt = Template;
    }; /// end of namespace R32

    namespace R64
    {
        WIZ_DECLARE_SIMPLE(double);
        static TypeC Epsilon    = DBL_EPSILON;
        static TypeC EpsilonSqr = ::Wiz::R64::Epsilon * ::Wiz::R64::Epsilon;
        static TypeC Zero       = 0;
        static TypeC MaxZeroEp  = 0 + ::Wiz::R64::Epsilon;
        static TypeC MinZeroEp  = 0 - ::Wiz::R64::Epsilon;
        static TypeC One        = 1;
        static TypeC MaxOneEp   = 1 + ::Wiz::R64::Epsilon;
        static TypeC MinOneEp   = 1 - ::Wiz::R64::Epsilon;
        static TypeC Max        = DBL_MAX;
        static TypeC Min        = 0 - ::Wiz::R64::Max;

        /// 用于模版类参数声明【template<float> 是不可以的】
        namespace Template
        {
            typedef R64::RefC   Type;
        } /// end of namespace Template
        namespace Tmplt = Template;
    }; /// end of namespace R64


} /// end of namespace Wiz

#endif /*__WIZ_BASIC_TYPE_REAL_HPP__SHANHAOBO_19800429__*/
