#ifndef __WIZ_MATH_UTILS_MISC_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_UTILS_MISC_HPP__SHANHAOBO_19800429__

#include <math.h>

#include "../../01_Basic/01_Type/WizBasicType.hpp"
#include "../../01_Basic/04_TU/WizBasicTUCast.hpp"

namespace Wiz
{
    ////////////////////////////////////////////////////////////////////////
    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type IsPowerOfTwo(const T& Val)
    {
        return WIZ_ISPOWEROFTWO(Val);
    }

    template<int n>
    WIZ_INLINE ::Wiz::Bool::Type IsPowerOfTwo()
    {
        return WIZ_ISPOWEROFTWO(n);
    }
    //////////////////////////////////////////////////////////////////////////
    WIZ_INLINE ::Wiz::I32::Type NextPowerOfTwo(::Wiz::I32::Type x)
    {
        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16);
        return x + 1;
    }

    WIZ_INLINE ::Wiz::U32::Type NextPowerOfTwo(::Wiz::U32::Type x)
    {
        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16);
        return x + 1;
    }

    WIZ_INLINE ::Wiz::I64::Type NextPowerOfTwo(::Wiz::I64::Type x)
    {
        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16);
        x |= (x >> 32);
        return x + 1;
    }

    WIZ_INLINE ::Wiz::U64::Type NextPowerOfTwo(::Wiz::U64::Type x)
    {
        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16);
        x |= (x >> 32);
        return x + 1;
    }

    template<::Wiz::I32::Type x>
    WIZ_INLINE ::Wiz::I32::Type NextPowerOfTwo()
    {
        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16);
        return x + 1;
    }

    template<::Wiz::U32::Type x>
    WIZ_INLINE ::Wiz::U32::Type NextPowerOfTwo()
    {
        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16);
        return x + 1;
    }

    template<::Wiz::I64::Type x>
    WIZ_INLINE ::Wiz::I64::Type NextPowerOfTwo()
    {
        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16);
        x |= (x >> 32);
        return x + 1;
    }

    template<::Wiz::U64::Type x>
    WIZ_INLINE ::Wiz::U64::Type NextPowerOfTwo()
    {
        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16);
        x |= (x >> 32);
        return x + 1;
    }

    //////////////////////////////////////////////////////////////////////////
    /// ABS
    template<class T>
    WIZ_INLINE T AbsDiff(const T& t1, const T& t2)
    {
        return t1 >= t2 ? t1 - t2 : t2 - t1;
    }

    //////////////////////////////////////////////////////////////////////////

    template<class T>
    WIZ_INLINE T Abs(const T& t)
    {
        return t < 0 ? -t : t;
    }

    template<class T>
    WIZ_INLINE T Sign(const T& v)
    {
        return v < 0 ? -1 : v > 0 ? 1 : 0;
    }

    //////////////////////////////////////////////////////////////////////////
    /// CLAMP
    template<class T>
    WIZ_INLINE T Clamp(const T& v, const T& Min_v, const T& Max_v)
    {
        return v < Min_v ? Min_v : v > Max_v ? Max_v : v;
    }

    template<class T>
    WIZ_INLINE T Saturate(const T& v)
    {
        return ::Wiz::Clamp<T>(v, 0, 1);
    }

    template<class T>
    WIZ_INLINE T ConvertRange(const T& t, const T& From1, const T& From2, const T& To1, const T& To2) 
    {
        return (t - From1) * (To2 - To1) / (From2 - From1) + To1;           /// (t - From1) / (From2 - From1) = (x - To1) / (To2 - To1)
    }
    //////////////////////////////////////////////////////////////////////////
    template<typename T>
    WIZ_INLINE T Sqr(const T& r)
    {
        return r * r;
    }

    template<typename T>
    WIZ_INLINE T Sqrt(const T& v)
    {
        return static_cast<T>(::sqrt(static_cast<double>(v)));
    }
    WIZ_INLINE ::Wiz::R32::Type SqrtFast(::Wiz::R32::In v)
    {
        return static_cast<::Wiz::R32::Type>(::sqrt(static_cast<double>(v)));
    }
    WIZ_INLINE ::Wiz::R64::Type SqrtFast(::Wiz::R64::In v)
    {
        return static_cast<::Wiz::R64::Type>(::sqrt(v));
    }

    template<typename T>
    WIZ_INLINE T RecipSqrt(const T& v)
    {
        return 1 / ::Wiz::Sqrt(v);
    }
    WIZ_INLINE ::Wiz::R32::Type RecipSqrtFast(::Wiz::R32::In v)
    {
        return 1 / ::sqrt(v);
    }
    WIZ_INLINE ::Wiz::R64::Type RecipSqrtFast(::Wiz::R64::In v)
    {
        return 1 / ::sqrt(v);
    }

    //////////////////////////////////////////////////////////////////////////

    WIZ_INLINE ::Wiz::R32::Type Abs(::Wiz::R32::In v)
    {
        return static_cast<::Wiz::R32::Type>(::abs(v));
    }

    WIZ_INLINE ::Wiz::R32::Type Exp(::Wiz::R32::In v)
    {
        return static_cast<::Wiz::R32::Type>(::exp(v));
    }

    /// Not A Number
    WIZ_INLINE ::Wiz::Bool::Type IsNAN(::Wiz::R32::In v)
    {
        //return ::_isnan(v) != 0;
        // std::isnan() is C99, not supported by all compilers
        // However NaN always fails this next test, no other number does.
        return v != v;
    }

    /// -inF << v << inF
    WIZ_INLINE ::Wiz::Bool::Type IsFinite(::Wiz::R32::In v)
    {
        return ::_finite(v) != 0;
    }

    /// returns the largest integer that is not greater than the argument
    WIZ_INLINE ::Wiz::R32::Type FloorF(::Wiz::R32::In v)
    {
        return static_cast<::Wiz::R32::Type>(::floor(v));
    }

    /// 四舍五入
    WIZ_INLINE ::Wiz::I32::Type Round(::Wiz::R32::In v)
    {
        return _mm_cvt_ss2si(_mm_set_ss(v + v + 0.5f)) >> 1;
    }

    /// Returns the largest integer that is not greater than the argument.
    WIZ_INLINE ::Wiz::I32::Type Floor(::Wiz::R32::In v)
    {
        return _mm_cvt_ss2si(_mm_set_ss(v + v - 0.5f)) >> 1;
    }

    /// Returns the smallest integer that is not less than the argument.
    WIZ_INLINE ::Wiz::I32::Type Ceil(::Wiz::R32::In v)
    {
        return -(_mm_cvt_ss2si(_mm_set_ss(0.5f - (v + v))) >> 1);
    }

    /// Calculates the floating-point remainder.
    WIZ_INLINE ::Wiz::R32::Type Fmod(::Wiz::R32::In numerator, ::Wiz::R32::In denominator)
    {
        return static_cast<::Wiz::R32::Type>(::fmod(numerator, denominator));
    }

    WIZ_INLINE ::Wiz::R32::Type Log2(::Wiz::R32::In v)
    {
        /*
        ** NOTE: log_base_2(x) = log(x) / log(2)
        ** NOTE: 1.442695 = 1/log(2).
        */
        return static_cast<::Wiz::R32::Type>(::log(v) * 1.442695f);
    }

    WIZ_INLINE ::Wiz::R32::Type LogE(::Wiz::R32::In v)
    {
        return ::Wiz::Cast::Static<::Wiz::R32::Type>(::log(v));
    }

    WIZ_INLINE ::Wiz::R32::Type Log10(::Wiz::R32::In v)
    {
        return ::Wiz::Cast::Static<::Wiz::R32::Type>(::log10(v));
    }

    WIZ_INLINE ::Wiz::R32::Type Pow(::Wiz::R32::In base, ::Wiz::R32::In exponent)
    {
        return ::Wiz::Cast::Static<::Wiz::R32::Type>(::pow(base, exponent));
    }

    WIZ_INLINE ::Wiz::I32::Type Trunc(::Wiz::R32::In r)
    {
        return _mm_cvt_ss2si(_mm_set_ss(r));
    }

    WIZ_INLINE ::Wiz::R32::Type TruncF(::Wiz::R32::In r)
    {
        return ::Wiz::Cast::Static<::Wiz::R32::Type>(::Wiz::Trunc(r));
    }

    WIZ_INLINE ::Wiz::R32::Type Fract(::Wiz::R32::In r)
    {
        return r - ::Wiz::TruncF(r);
    }

    WIZ_INLINE ::Wiz::I::Type QuadraticEquationRoots(::Wiz::R32::Out Root1, ::Wiz::R32::Out Root2, ::Wiz::R32::In A, ::Wiz::R32::In B, ::Wiz::R32::In C)
    {
        if (A == 0)
        {
            if (B == 0)
            {
                return 0;
            }
            Root1 = -C / B;
            return 1;
        }

        ::Wiz::R32::TypeC t = B * B - 4 * A * C;
        if (t < 0)
        {
            return 0;
        }

        ::Wiz::R32::TypeC TempRoot = -B / (2 * A);
        if (t == 0)
        {
            Root1 = TempRoot;
            return 1;
        }

        ::Wiz::R32::TypeC TempDiff = ::Wiz::Sqrt(t) / (2 * A);

        Root1 = TempRoot + TempDiff;
        Root2 = TempRoot - TempDiff;
        return 2;
    }

    //////////////////////////////////////////////////////////////////////////

    WIZ_INLINE ::Wiz::R64::Type Abs(::Wiz::R64::In v)
    {
        return ::Wiz::Cast::Static<::Wiz::R64::Type>(::abs(v));
    }

    WIZ_INLINE ::Wiz::R64::Type Exp(::Wiz::R64::In v)
    {
        return ::Wiz::Cast::Static<::Wiz::R64::Type>(::exp(v));
    }

    WIZ_INLINE ::Wiz::R64::Type Floor(::Wiz::R64::In v)
    {
        return ::Wiz::Cast::Static<::Wiz::R64::Type>(::floor(v));
    }

    /// Calculates the floating-point remainder.
    WIZ_INLINE ::Wiz::R64::Type Fmod(::Wiz::R64::In numerator, ::Wiz::R64::In denominator)
    {
        return ::Wiz::Cast::Static<::Wiz::R64::Type>(::fmod(numerator, denominator));
    }

    WIZ_INLINE ::Wiz::R64::Type Log2(::Wiz::R64::In v)
    {
        /*
        * NOTE: log_base_2(x) = log(x) / log(2)
        * NOTE: 1.442695 = 1/log(2).
        */
        return ::Wiz::Cast::Static<::Wiz::R64::Type>(::log(v) * 1.442695f);
    }


    WIZ_INLINE ::Wiz::R64::Type LogE(::Wiz::R64::In v)
    {
        return ::Wiz::Cast::Static<::Wiz::R64::Type>(::log(v));
    }

    WIZ_INLINE ::Wiz::R64::Type Log10(::Wiz::R64::In v)
    {
        return ::Wiz::Cast::Static<::Wiz::R64::Type>(::log10(v));
    }

    WIZ_INLINE ::Wiz::R64::Type Pow(::Wiz::R64::In base, ::Wiz::R64::In exponent)
    {
        return ::Wiz::Cast::Static<::Wiz::R64::Type>(::pow(base, exponent));
    }

    WIZ_INLINE ::Wiz::I64::Type Trunc(::Wiz::R64::In r)
    {
        return ::Wiz::Cast::Static<::Wiz::I64::Type>(r);
    }

    WIZ_INLINE ::Wiz::R64::Type TruncF(::Wiz::R64::In r)
    {
        return ::Wiz::Cast::Static<::Wiz::R64::Type>(::Wiz::Trunc(r));
    }

    WIZ_INLINE ::Wiz::R64::Type Fract(::Wiz::R64::In r)
    {
        return r - ::Wiz::Cast::Static<::Wiz::R64::Type>(::Wiz::Trunc(r));
    }

    /// Quadratic 二次方程
    WIZ_INLINE ::Wiz::I::Type QuadraticEquationRoots(::Wiz::R64::Out Root1, ::Wiz::R64::Out Root2, ::Wiz::R64::In A, ::Wiz::R64::In B, ::Wiz::R64::In C)
    {
        if (A == 0)
        {
            if (B == 0)
            {
                return 0;
            }
            Root1 = -C / B;
            return 1;
        }

        ::Wiz::R64::TypeC t = B * B - 4 * A * C;
        if (t < 0)
        {
            return 0;
        }

        ::Wiz::R64::TypeC TempRoot = -B / (2 * A);

        if (t == 0)
        {
            Root1 = TempRoot;
            return 1;
        }
        ::Wiz::R64::TypeC TempDiff = ::Wiz::Sqrt(t) / (2 * A);

        Root1 = TempRoot + TempDiff;
        Root2 = TempRoot - TempDiff;
        return 2;
    }
} /// end of namespace Wiz


#endif /*__WIZ_MATH_UTILS_MISC_HPP__SHANHAOBO_19800429__*/
