#ifndef __WIZ_BASIC_TEMPLATE_MINMAX_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TEMPLATE_MINMAX_HPP__SHANHAOBO_19800429__

#include "./WizMathUtilsCompare.hpp"

namespace Wiz
{
    ////////////////////////////////////////////////////////////////////////
    namespace Absolute
    {
        /// MIN MAX
        template<class T>
        WIZ_INLINE T Min2(const T& t1, const T& t2)
        {
            return ::Wiz::Absolute::Less(t1, t2) ? t1 : t2;
        }
        template<class T>
        WIZ_INLINE T Max2(const T& t1, const T& t2)
        {
            return ::Wiz::Absolute::Greater(t1, t2) ? t1 : t2;
        }

        template<class T>
        WIZ_INLINE T Min3(const T& t1, const T& t2, const T& t3)
        {
            return ::Wiz::Absolute::Less<T>(t1, t2) ? ::Wiz::Absolute::Min2<T>(t1, t3) : ::Wiz::Absolute::Min2<T>(t2, t3);
        }
        template<class T>
        WIZ_INLINE T Max3(const T& t1, const T& t2, const T& t3)
        {
            return ::Wiz::Absolute::Greater<T>(t1, t2) ? ::Wiz::Absolute::Max2<T>(t1, t3) : ::Wiz::Absolute::Max2<T>(t2, t3);
        }

        template<class T>
        WIZ_INLINE T Min4(const T& t1, const T& t2, const T& t3, const T& t4)
        {
            return ::Wiz::Absolute::Less<T>(t1, t2) ? ::Wiz::Absolute::Min3<T>(t1, t3, t4) : ::Wiz::Absolute::Min3<T>(t2, t3, t4);
        }
        template<class T>
        WIZ_INLINE T Max4(const T& t1, const T& t2, const T& t3, const T& t4)
        {
            return ::Wiz::Absolute::Greater<T>(t1, t2) ? ::Wiz::Absolute::Max3<T>(t1, t3, t4) : ::Wiz::Absolute::Max3<T>(t2, t3, t4);
        }
    } /// end of namespace Absolute

    ////////////////////////////////////////////////////////////////////////

    /// MIN MAX
    template<class T>
    WIZ_INLINE T Min2(const T& t1, const T& t2)
    {
        return ::Wiz::Absolute::Min2(t1, t2);
    }
    template<class T>
    WIZ_INLINE T Max2(const T& t1, const T& t2)
    {
        return ::Wiz::Absolute::Max2(t1, t2);
    }

    template<class T>
    WIZ_INLINE T Min3(const T& t1, const T& t2, const T& t3)
    {
        return ::Wiz::Absolute::Min3(t1, t2, t3);
    }
    template<class T>
    WIZ_INLINE T Max3(const T& t1, const T& t2, const T& t3)
    {
        return ::Wiz::Absolute::Max3(t1, t2, t3);
    }

    template<class T>
    WIZ_INLINE T Min4(const T& t1, const T& t2, const T& t3, const T& t4)
    {
        return ::Wiz::Absolute::Min4(t1, t2, t3, t4);
    }

    template<class T>
    WIZ_INLINE T Max4(const T& t1, const T& t2, const T& t3, const T& t4)
    {
        return ::Wiz::Absolute::Max4(t1, t2, t3, t4);
    }
    ////////////////////////////////////////////////////////////////////////
} /// end of namespace Wiz

#endif /*__WIZ_BASIC_TEMPLATE_MINMAX_HPP__SHANHAOBO_19800429__*/
