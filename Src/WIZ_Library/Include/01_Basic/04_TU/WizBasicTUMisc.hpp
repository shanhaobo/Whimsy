#ifndef __WIZ_BASIC_TU_MISC_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TU_MISC_HPP__SHANHAOBO_19800429__

#include "../01_Type/WizBasicType.hpp"
#include "../02_MU/WizBasicMU.hpp"

namespace Wiz
{
    //////////////////////////////////////////////////////////////////////////
    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type IsNull(const T& ptr)
    {
        return (ptr == WIZ_NULLPTR);
    }

    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type NotNull(const T& ptr)
    {
        return !::Wiz::IsNull(ptr);
    }

    template<class T>
#if (WIZ_CFG_CPP_NULLPTR == WIZ_CFG_TRUE)
    WIZ_INLINE ::Wiz::Bool::Type IsValidPtr(T const * const ptr)
#else
    WIZ_INLINE ::Wiz::Bool::Type IsValidPtr(const T& ptr)
#endif /// WIZ_CFG_CPP_NULLPTR == WIZ_CFG_TRUE
    {
        return (ptr == WIZ_NULLPTR);
    }

    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type NotValidPtr(const T& ptr)
    {
        return !::Wiz::IsValidPtr(ptr);
    }

    //////////////////////////////////////////////////////////////////////////

    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type IsValid(const T& inDT)
    {
        return inDT != T::invalid;
    }
    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type NotValid(const T& inDT)
    {
        return ::Wiz::IsValid<T>(inDT) == ::Wiz::Bool::False;
    }

    //////////////////////////////////////////////////////////////////////////
    template<class PTR>
    WIZ_INLINE ::Wiz::Void::Type Delete(PTR ptr)
    {
        if (::Wiz::IsValidPtr(ptr))
        {
            /// 检查完整性
            typedef ::Wiz::Byte::Type TypeMustBeComplete[sizeof(ptr[0])];

            /// 删除
            delete ptr;
        }
    }

    template<class RPTR, class PTR>
    WIZ_INLINE ::Wiz::Void::Type Delete2(PTR ptr)
    {
        ::Wiz::Delete(reinterpret_cast<RPTR>(ptr));
    }

    template<class PTR>
    WIZ_INLINE ::Wiz::Void::Type SafeDelete(PTR& ptr)
    {
        if (::Wiz::IsValidPtr(ptr))
        {
            /// 检查完整性
            typedef ::Wiz::Byte::Type TypeMustBeComplete[sizeof(ptr[0])];

            /// 删除
            delete ptr;
            ptr = WIZ_NULLPTR;
        }
    }

    template<class RPTR, class PTR>
    WIZ_INLINE ::Wiz::Void::Type SafeDelete2(PTR& ptr)
    {
        ::Wiz::SafeDelete(reinterpret_cast<RPTR&>(ptr));
    }

    //////////////////////////////////////////////////////////////////////////
    template<class T>
    WIZ_INLINE ::Wiz::Void::Type Swap(T& left, T& right)
    {
        const T tmp = left;
        left  = right;
        right = tmp;
    }

    //////////////////////////////////////////////////////////////////////////

    namespace ScopedValue
    {
        template<class T>
        class Type
        {
            const T OldVal;
            T&      RealVal;
        public:
            Type(T& Val) : RealVal(Val), OldVal(Val)
            {}
            ~Type()
            {
                RealVal = OldVal;
            }
        };
    } /// end of namespace ScopedValue

    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
} /// end of namespace Wiz

#endif /*__WIZ_BASIC_TU_MISC_HPP__SHANHAOBO_19800429__*/
