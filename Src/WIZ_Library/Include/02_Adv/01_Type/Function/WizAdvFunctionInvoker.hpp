#undef  WIZ_FUNCTION_PARAM_COUNT
#define WIZ_FUNCTION_PARAM_COUNT  WIZ_MPP_REPEAT_FILE_COUNT

#if defined(WIZ_FUNCTION_PARAM_COUNT) && (WIZ_FUNCTION_PARAM_COUNT >= 0) && (WIZ_FUNCTION_PARAM_COUNT < 255)

namespace Wiz
{
    namespace Function
    {
        namespace WIZ_MPP_COMBINE(invoker, WIZ_FUNCTION_PARAM_COUNT)
        {
            template <class RetT WIZ_COMMA_IF(WIZ_FUNCTION_PARAM_COUNT) WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, class T)>
            struct Type
            {
                typedef Type                                        tThis;
                typedef tThis&                                      tThisRef;
                typedef tThisRef const                              tThisIn;

                typedef RetT                                        tRet;
                typedef tRet(*tFuncPtr)(WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, T));
                union
                {
                    struct
                    {
                        tFuncPtr                                    m_FuncPtr;
                        ::Wiz::Void::Ptr                            m_Dummy01;
                    };
                    struct 
                    {
                        ::Wiz::Void::Ptr                            m_Functor;
                        ::Wiz::Void::Ptr                            m_Dummy02;
                    };
                    struct 
                    {
                        ::Wiz::Function::MemFunc::Storage::Type     m_MemFunc;
                    };
                };
            public:
                WIZ_INLINE ::Wiz::Void::Type SetFuncPtr(const tFuncPtr FP)
                {
                    m_FuncPtr = ::Wiz::Cast::Const<tFuncPtr>(FP);
                    m_Dummy01 = WIZ_NULL;
                }
                WIZ_INLINE tRet invokeFuncPtr(WIZ_ENUM_PARAM_XY(WIZ_FUNCTION_PARAM_COUNT, T, A))
                {
                    return m_FuncPtr(WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, A));
                }
            public:
                template<class U>
                WIZ_INLINE ::Wiz::Void::Type SetFunctor(const U* UPtr)
                {
                    m_Functor = ::Wiz::Cast::Reinterpret<::Wiz::Void::Ptr>(::Wiz::Cast::Const<U*>(UPtr));
                    m_Dummy02 = WIZ_NULL;
                }
                template<class U>
                WIZ_INLINE tRet invokeFunctor(WIZ_ENUM_PARAM_XY(WIZ_FUNCTION_PARAM_COUNT, T, A))
                {
                    U* Ftor = ::Wiz::Cast::Reinterpret<U*>(m_Functor);
                    return (*Ftor)(WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, A));
                }
            public:
                template<class U>
                WIZ_INLINE ::Wiz::Void::Type SetMemFunc(const U* u, tRet(U::*FP)(WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, T)))
                {
                    ::Wiz::Function::MemFunc::Type<U, tRet(WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, T))> TempMemFunc(u, FP);
                    TempMemFunc.SaveTo(m_MemFunc);
                }
                template<class U>
                WIZ_INLINE ::Wiz::Void::Type SetMemFunc(const U* u, tRet(U::*FP)(WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, T)) const)
                {
                    ::Wiz::Function::MemFunc::Type<U, tRet(WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, T))> TempMemFunc(u, FP);
                    TempMemFunc.SaveTo(m_MemFunc);
                }
                template<class U>
                WIZ_INLINE tRet invokeMemFunc(WIZ_ENUM_PARAM_XY(WIZ_FUNCTION_PARAM_COUNT, T, A))
                {
                    ::Wiz::Function::MemFunc::Type<U, tRet(WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, T))> TempMemFunc(m_MemFunc);

                    return TempMemFunc(WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, A));
                }
            public:
                ::Wiz::Bool::Type operator==(tThisIn R) const
                {
                    return (m_FuncPtr == R.m_FuncPtr) && (m_Dummy01 == R.m_Dummy01);
                }

                ::Wiz::Bool::Type operator<(tThisIn R) const
                {
                    if (m_FuncPtr == R.m_FuncPtr)
                    {
                        return m_Dummy01 < R.m_Dummy01;
                    }

                    return m_FuncPtr < R.m_FuncPtr;
                }
            };

            template <class tRet WIZ_COMMA_IF(WIZ_FUNCTION_PARAM_COUNT) WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, class T)>
            class FuncPtr : public ::Wiz::Function::WIZ_MPP_COMBINE(invoker, WIZ_FUNCTION_PARAM_COUNT)::Type<tRet WIZ_COMMA_IF(WIZ_FUNCTION_PARAM_COUNT) WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, T)>
            {
                typedef tRet(*tFuncPtr)(WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, T));
            public:
                static tRet invoke(::Wiz::Function::WIZ_MPP_COMBINE(invoker, WIZ_FUNCTION_PARAM_COUNT)::Type<tRet WIZ_COMMA_IF(WIZ_FUNCTION_PARAM_COUNT) WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, T)>* IT WIZ_COMMA_IF(WIZ_FUNCTION_PARAM_COUNT) WIZ_ENUM_PARAM_XY(WIZ_FUNCTION_PARAM_COUNT, T, A))
                {
                    return IT->invokeFuncPtr(WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, A));
                }
            };

            template <class tRet WIZ_COMMA_IF(WIZ_FUNCTION_PARAM_COUNT) WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, class T)>
            class Functor : public ::Wiz::Function::WIZ_MPP_COMBINE(invoker, WIZ_FUNCTION_PARAM_COUNT)::Type<tRet WIZ_COMMA_IF(WIZ_FUNCTION_PARAM_COUNT) WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, T)>
            {
            public:
                template<class U>
                static tRet invoke(::Wiz::Function::WIZ_MPP_COMBINE(invoker, WIZ_FUNCTION_PARAM_COUNT)::Type<tRet WIZ_COMMA_IF(WIZ_FUNCTION_PARAM_COUNT) WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, T)>* IT WIZ_COMMA_IF(WIZ_FUNCTION_PARAM_COUNT) WIZ_ENUM_PARAM_XY(WIZ_FUNCTION_PARAM_COUNT, T, A))
                {
                    return IT->invokeFunctor<U>(WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, A));
                }
            };

            template <class tRet WIZ_COMMA_IF(WIZ_FUNCTION_PARAM_COUNT) WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, class T)>
            class MemFunc : public ::Wiz::Function::WIZ_MPP_COMBINE(invoker, WIZ_FUNCTION_PARAM_COUNT)::Type<tRet WIZ_COMMA_IF(WIZ_FUNCTION_PARAM_COUNT) WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, T)>
            {
            public:
                template<class U>
                static tRet invoke(::Wiz::Function::WIZ_MPP_COMBINE(invoker, WIZ_FUNCTION_PARAM_COUNT)::Type<tRet WIZ_COMMA_IF(WIZ_FUNCTION_PARAM_COUNT) WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, T)>* IT WIZ_COMMA_IF(WIZ_FUNCTION_PARAM_COUNT) WIZ_ENUM_PARAM_XY(WIZ_FUNCTION_PARAM_COUNT, T, A))
                {
                    return IT->invokeMemFunc<U>(WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, A));
                }
            };
        } /// end of namespace invoker
    } /// end of namespace Function
} /// end of namespace Wiz

#endif /*#if defined(WIZ_FUNCTION_PARAM_COUNT) && (WIZ_FUNCTION_PARAM_COUNT > 0) && (WIZ_FUNCTION_PARAM_COUNT < 255)*/
