#ifndef __WIZ_MATH_UTILS_INTERPOLATE_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_UTILS_INTERPOLATE_HPP__SHANHAOBO_19800429__

#include "../../00_Config/WizConfig.hpp"

namespace Wiz
{
    //////////////////////////////////////////////////////////////////////////
    /// LERP
    template<class T, class U>
    WIZ_INLINE T Lerp(const T& a_v, const T& b_v, const U& t)
    {
        return a_v + t * (b_v - a_v);
    }

    template<class T, class U>
    WIZ_INLINE T Bilerp(const T& p00, const T& p01, const T& p10, const T& p11, const U& t1, const U& t2)
    {
        return ::Wiz::Lerp<T, U>(::Wiz::Lerp<T, U>(p00, p01, t1), ::Wiz::Lerp<T, U>(p10, p11, t1), t2);
    }
    //////////////////////////////////////////////////////////////////////////
    /// 
    template<class T>
    WIZ_INLINE T MakeLerpT(T begin, T end, T t)
    {
        return (t - begin) / (end - begin);
    }

    template<class T>
    WIZ_INLINE T MakeHermiteT(T begin, T end, T t)
    {
        T v1 = ::Wiz::MakeLerpT(begin, end, t);
        T v2 = v1 * v1;
        T v3 = v2 * v1;
        return -2 * v3 + 3 * v2;
    }
    //////////////////////////////////////////////////////////////////////////
    /// inTERPOLATE 一次多项式
    template<class T, class U>
    WIZ_INLINE T interpolate1(const U& t, const T& a, const T& b)
    {
        /// (1 - t) * a + t * b     => a + t * (b - a)
        return  a + (b - a) * t;
    }

    // 二次多项式
    template<class T, class U>
    WIZ_INLINE T interpolate2(const U& t, const T& a, const T& b, const T& c)
    {
        /// pow((1 - t), 2) * a + 2 * t * ( 1 - t) * b +  pow(t, 2) * c
        return  a + 2 * (b - a) * t + (c - 2 * b + a) * t * t;
    }

    /// 三次多项式
    template<class T, class U>
    WIZ_INLINE T interpolate3(const U& t, const T& a, const T& b, const T& c, const T& d)
    {
        /// pow((1 - t), 3) * a + 3 * pow((1 - t), 2) * t * b + 3 * (1 - t) * pow(t, 2) * c + pow(t, 3) * d
        return  a + 3 * (b - a) * t + 3 * (c - 2 * b + a) * t * t + (d - 3 * c + 3 * b - a) * t * t * t;
    }
    //////////////////////////////////////////////////////////////////////////
} /// end of namespace Wiz

#endif /*__WIZ_MATH_UTILS_INTERPOLATE_HPP__SHANHAOBO_19800429__*/
