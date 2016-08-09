#ifndef __WIZ_ADV_FUNCTION_MEMFUNC_HPP__SHANHAOBO_19800429__
#define __WIZ_ADV_FUNCTION_MEMFUNC_HPP__SHANHAOBO_19800429__

namespace Wiz
{
    namespace Function
    {
        namespace MemFunc
        {
            template <class ClassT, class ParamT> class Type;

            namespace Storage
            {
                class UnknownClass;
                typedef ::Wiz::Void::Type(UnknownClass::*tUnknownClassMemFuncPtr)(::Wiz::I::Type);
                struct Type
                {
                    Type() : m_ClassInstPtr(WIZ_NULL), m_MemFuncPtr(WIZ_NULL)
                    {
                    }
                    Type(::Wiz::Void::Ptr instPtr, tUnknownClassMemFuncPtr MemFPtr) : m_ClassInstPtr(instPtr), m_MemFuncPtr(MemFPtr)
                    {
                    }
                    ::Wiz::Void::Ptr        m_ClassInstPtr;
                    tUnknownClassMemFuncPtr m_MemFuncPtr;
                };
                WIZ_DECLARE(Type);
            } /// end of namespace Storage
        } /// end of namespace MemFunc
    } /// end of namespace Function
} /// end of namespace Wiz

#endif /// __WIZ_ADV_FUNCTION_MEMFUNC_HPP__SHANHAOBO_19800429__

#undef  WIZ_MEMFUNC_PARAM_COUNT
#define WIZ_MEMFUNC_PARAM_COUNT        WIZ_MPP_REPEAT_FILE_COUNT
//////////////////////////////////////////////////////////////////////////

#if defined(WIZ_MEMFUNC_PARAM_COUNT) && (WIZ_MEMFUNC_PARAM_COUNT >= 0) && (WIZ_MEMFUNC_PARAM_COUNT <= 255)

namespace Wiz
{
    namespace Function
    {
        namespace MemFunc
        {
            template<class ClassT, class RetT WIZ_COMMA_IF(WIZ_MEMFUNC_PARAM_COUNT) WIZ_ENUM_PARAM_X(WIZ_MEMFUNC_PARAM_COUNT, class T)>
            class Type<ClassT, RetT(WIZ_ENUM_PARAM_X(WIZ_MEMFUNC_PARAM_COUNT, T))>
            {
                typedef ClassT              tClass;
                typedef RetT                tRet;
                typedef tRet(tClass::*tMemberFPtr)(WIZ_ENUM_PARAM_X(WIZ_MEMFUNC_PARAM_COUNT, T));
                typedef tRet(tClass::*tMemberConstFPtr)(WIZ_ENUM_PARAM_X(WIZ_MEMFUNC_PARAM_COUNT, T)) const;
                typedef tMemberFPtr         tMemberPtr;
                typedef tMemberConstFPtr    tMemberConstPtr;
            public:
                Type() : m_Storage()
                {
                    WIZ_STATIC_ASSERT(sizeof(m_Storage.m_ClassInstPtr) == sizeof(m_ClassPtr));
                    WIZ_STATIC_ASSERT(sizeof(m_Storage.m_MemFuncPtr) >= sizeof(m_MemberPtr));
                }
                Type(::Wiz::Void::Ptr ClassPtr, ::Wiz::Void::Ptr MemPtr)
                {
                    WIZ_STATIC_ASSERT(sizeof(m_Storage.m_ClassInstPtr) == sizeof(m_ClassPtr));
                    WIZ_STATIC_ASSERT(sizeof(m_Storage.m_MemFuncPtr) >= sizeof(m_MemberPtr));
                    /// Don't initialize union members;
                    m_Storage.m_ClassInstPtr = ClassPtr;
                    m_Storage.m_MemFuncPtr = MemPtr;
                }
                Type(const tClass* ClassPtr, tMemberPtr MemberPtr)
                {
                    WIZ_STATIC_ASSERT(sizeof(m_Storage.m_ClassInstPtr) == sizeof(m_ClassPtr));
                    WIZ_STATIC_ASSERT(sizeof(m_Storage.m_MemFuncPtr) >= sizeof(m_MemberPtr));
                    /// Don't initialize union members;
                    m_ClassPtr = ::Wiz::Cast::Const<tClass*>(ClassPtr);
                    m_MemberPtr = MemberPtr;
                }
                Type(const tClass* ClassPtr, tMemberConstPtr MemberPtr)
                {
                    WIZ_STATIC_ASSERT(sizeof(m_Storage.m_ClassInstPtr) == sizeof(m_ClassPtr));
                    WIZ_STATIC_ASSERT(sizeof(m_Storage.m_MemFuncPtr) >= sizeof(m_MemberPtr));
                    /// Don't initialize union members;
                    m_ClassPtr = ::Wiz::Cast::Const<tClass*>(ClassPtr);
                    m_MemberConstPtr = MemberPtr;
                }
                Type(::Wiz::Function::MemFunc::Storage::In ST)
                {
                    m_Storage = ST;
                }
            public:
                /// Ö´ÐÐ
                tRet operator()(WIZ_ENUM_PARAM_XY(WIZ_MEMFUNC_PARAM_COUNT, T, A))
                {
                    return (m_ClassPtr->*m_MemberPtr)(WIZ_ENUM_PARAM_X(WIZ_MEMFUNC_PARAM_COUNT, A));
                }
                tRet operator()(WIZ_ENUM_PARAM_XY(WIZ_MEMFUNC_PARAM_COUNT, T, A)) const
                {
                    return (m_ClassPtr->*m_MemberConstPtr)(WIZ_ENUM_PARAM_X(WIZ_MEMFUNC_PARAM_COUNT, A));
                }
            public:
                ::Wiz::Void::Type Set(tClass const * ClassPtr, tMemberPtr MemberPtr)
                {
                    m_ClassPtr = ::Wiz::Cast::Const<tClass*>(ClassPtr);;
                    m_MemberPtr = MemberPtr;
                }
                ::Wiz::Void::Type Set(tClass const * ClassPtr, tMemberConstPtr MemberPtr)
                {
                    m_ClassPtr = ::Wiz::Cast::Const<tClass*>(ClassPtr);;
                    m_MemberConstPtr = MemberPtr;
                }
                ::Wiz::Void::Type SaveTo(::Wiz::Function::MemFunc::Storage::Out ST)
                {
                    ST = m_Storage;
                }
            protected:
                union
                {
                    struct
                    {
                        ::Wiz::Function::MemFunc::Storage::Type     m_Storage;
                    };
                    struct
                    {
                        tClass*                                     m_ClassPtr;
                        union
                        {
                            tMemberPtr                              m_MemberPtr;
                            tMemberConstPtr                         m_MemberConstPtr;
                        };
                    };
                };
            };
        } /// end of namespace MemFunc
    } /// end of namespace Function
} /// end of namespace Wiz

#endif /*WIZ_MEMFUNC_PARAM_COUNT*/
