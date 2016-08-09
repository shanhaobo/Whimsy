#undef  WIZ_FUNCTION_PARAM_COUNT
#define WIZ_FUNCTION_PARAM_COUNT  WIZ_MPP_REPEAT_FILE_COUNT

#if defined(WIZ_FUNCTION_PARAM_COUNT) && (WIZ_FUNCTION_PARAM_COUNT >= 0) && (WIZ_FUNCTION_PARAM_COUNT < 255)

/// Maybe is included multi times : in same one file
namespace Wiz
{
    namespace Function
    {
        template<class RetT WIZ_COMMA_IF(WIZ_FUNCTION_PARAM_COUNT) WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, class T)>
        class Type<RetT(WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, T))>
        {
        public:
            typedef Type                                                            tThis;
            typedef tThis&                                                          tThisRef;
            typedef tThisRef const                                                  tThisIn;

            typedef RetT                                                            tRet;
            typedef tRet(*tFuncPtr)(WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, T));

            typedef ::Wiz::Function::WIZ_MPP_COMBINE(invoker, WIZ_FUNCTION_PARAM_COUNT)::Type<tRet WIZ_COMMA_IF(WIZ_FUNCTION_PARAM_COUNT) WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, T)>    tInvoker;
            typedef ::Wiz::Function::WIZ_MPP_COMBINE(invoker, WIZ_FUNCTION_PARAM_COUNT)::FuncPtr<tRet WIZ_COMMA_IF(WIZ_FUNCTION_PARAM_COUNT) WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, T)> tInvokerFuncPtr;
            typedef ::Wiz::Function::WIZ_MPP_COMBINE(invoker, WIZ_FUNCTION_PARAM_COUNT)::MemFunc<tRet WIZ_COMMA_IF(WIZ_FUNCTION_PARAM_COUNT) WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, T)> tInvokerMembPtr;
            typedef ::Wiz::Function::WIZ_MPP_COMBINE(invoker, WIZ_FUNCTION_PARAM_COUNT)::Functor<tRet WIZ_COMMA_IF(WIZ_FUNCTION_PARAM_COUNT) WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, T)> tInvokerFunctor;

            typedef tRet(*tDoInvoker)(tInvoker* WIZ_COMMA_IF(WIZ_FUNCTION_PARAM_COUNT) WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, T));
        public:
            Type(const tFuncPtr FP) : m_InvokerFunc(tInvokerFuncPtr::invoke)
            {
                m_Invoker.SetFuncPtr(FP);
            }
            template<class U>
            Type(const U* C, tRet(U::*FP)(WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, T))) : m_InvokerFunc(tInvokerMembPtr::invoke<U>)
            {
                m_Invoker.SetMemFunc(C, FP);
            }
            template<class U>
            Type(const U* C, tRet(U::*FP)(WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, T)) const) : m_InvokerFunc(tInvokerMembPtr::invoke<U>)
            {
                m_Invoker.SetMemFunc(C, FP);
            }
            template<class U>
            Type(const U* C) : m_InvokerFunc(tInvokerFunctor::invoke<U>)
            {
                m_Invoker.SetFunctor(C);
            }
            Type(tThisIn Other)
            {
                m_Invoker = Other.m_Invoker;
                m_InvokerFunc = Other.m_InvokerFunc;
            }
            Type() : m_InvokerFunc(WIZ_NULL)
            {
            }
        public:
            tRet operator()(WIZ_ENUM_PARAM_XY(WIZ_FUNCTION_PARAM_COUNT, T, A))
            {
                WIZ_ASSERT(m_InvokerFunc != WIZ_NULL);
                return m_InvokerFunc(&m_Invoker WIZ_COMMA_IF(WIZ_FUNCTION_PARAM_COUNT) WIZ_ENUM_PARAM_X(WIZ_FUNCTION_PARAM_COUNT, A));
            }

            ::Wiz::Bool::Type operator==(const Type& R) const
            {
                return (m_InvokerFunc == R.m_InvokerFunc)  && (m_Invoker == R.m_Invoker);
            }

            ::Wiz::Bool::Type operator<(const Type& R) const
            {
                if (m_InvokerFunc == R.m_InvokerFunc)
                {
                    return m_Invoker < R.m_Invoker;
                }
                
                return m_InvokerFunc < R.m_InvokerFunc;
            }

            ::Wiz::Bool::Type IsEmpty()
            {
                return this->m_InvokerFunc == WIZ_NULL;
            }
        protected:
            ::Wiz::Bool::Type IsClassFunc()
            {
                return (m_InvokerFunc != WIZ_NULL) && (m_InvokerFunc != tInvokerFuncPtr::invoke);
            }
        public:
            template<class U>
            U* GetClassPtr()
            {
                if (IsClassFunc())
                {
                    return ::Wiz::Cast::Static<U*>(m_Invoker.m_Functor);
                }

                return WIZ_NULL;
            }
        protected:
            tDoInvoker  m_InvokerFunc;
            tInvoker    m_Invoker;
        };
    } /// end of namespace Function
} /// end of namespace Wiz

#endif/* defined(WIZ_FUNCTION_PARAM_COUNT) && (WIZ_FUNCTION_PARAM_COUNT >= 0) && (WIZ_FUNCTION_PARAM_COUNT < 255)*/
