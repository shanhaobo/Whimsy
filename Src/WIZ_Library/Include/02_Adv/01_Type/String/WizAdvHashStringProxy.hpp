#ifndef __WIZ_ADV_HASHSTRINGTPROXY_HPP__SHANHAOBO_19800429__
#define __WIZ_ADV_HASHSTRINGTPROXY_HPP__SHANHAOBO_19800429__

#include "../../../01_Basic/01_Type/WizBasicType.hpp"

namespace Wiz
{
    namespace HashString
    {
        namespace Proxy
        {
            namespace Category
            {
                enum Type
                {
                    eBKDR,
                    eSDBM,
                    eAP,
                    eJS,
                    eNoName,
                };
            } /// end of namespace Category

            namespace Functor
            {
                template<class DerivedT>
                struct Base
                {
                    typedef DerivedT                        tDerived;

                    typedef typename tDerived::tChar        tChar;

                    struct CharSameFunctor
                    {
                        WIZ_INLINE tChar operator()(tChar inChar) const
                        {
                            return inChar;
                        }
                    };

                    struct CharToUpperFunctor
                    {
                        WIZ_INLINE tChar operator()(tChar inChar) const
                        {
                            return ToUpper(inChar);
                        }

                        WIZ_INLINE char ToUpper(char c) const
                        {
                            return toupper(c);
                        }

                        WIZ_INLINE wchar_t ToUpper(wchar_t c) const
                        {
                            return towupper(c);
                        }
                    };

                    static U32::Type Calc(tChar const * inStr)
                    {
                        typedef TT::If<tDerived::CaseSensitiveT, CharSameFunctor, CharToUpperFunctor>::tType tCharFunctor;

                        return tDerived::CalcImpl<tCharFunctor>(inStr);
                    }

                    U32::Type operator()(tChar const * inStr) const
                    {
                        return Calc(inStr);
                    }
                };

                template<typename CharT, bool CaseSensitiveT = true, int MaxIterationsT = 256>
                struct BKDR : public Proxy::Functor::Base< BKDR<CharT, CaseSensitiveT, MaxIterationsT> >
                {
                    typedef CharT tChar;

                    static const bool CaseSensitiveT = CaseSensitiveT;
                    static const int  iMaxIterations = MaxIterationsT;

                    /// Case sensitive
                    template<class CharFuncT>
                    U32::Type CalcImpl(CharT const * inStr) const
                    {
                        CharFuncT const             inCharFunc;

                        register ::Wiz::U32::Type   Hash = 0;
                        register ::Wiz::U32::Type   CurrChar;
                        register int                i = 0;

                        for (; (CurrChar = inCharFunc(inStr[i])) && (iMaxIterations > i); i++)
                        {
                            /// 31 131 1313 13131 131313 etc..
                            static ::Wiz::U32::TypeC Seed = 131;

                            Hash = Hash * Seed + CurrChar;
                        }

                        return Hash;
                    }
                };

                template<typename CharT, bool CaseSensitiveT = true, int MaxIterationsT = 256>
                struct SDBM : public Proxy::Functor::Base< SDBM<CharT, CaseSensitiveT, MaxIterationsT> >
                {
                    typedef CharT tChar;

                    static const bool CaseSensitiveT = CaseSensitiveT;
                    static const int  iMaxIterations = MaxIterationsT;

                    template<class CharFuncT>
                    U32::Type CalcImpl(CharT const * inStr)
                    {
                        CharFuncT const             inCharFunc;

                        register ::Wiz::U32::Type   Hash = 0;
                        register ::Wiz::U32::Type   CurrChar;
                        register int                i = 0;

                        for (; (CurrChar = inCharFunc(inStr[i])) && (iMaxIterations > i); i++)
                        {
                            /// equivalent to: hash = 65599*hash + (*str++);
                            Hash = (Hash << 6) + (Hash << 16) - Hash + CurrChar;
                        }

                        return Hash;
                    }
                };

                template<typename CharT, bool CaseSensitiveT = true, int MaxIterationsT = 256>
                struct AP : public Proxy::Functor::Base< AP<CharT, CaseSensitiveT, MaxIterationsT> >
                {
                    typedef CharT tChar;

                    static const bool CaseSensitiveT = CaseSensitiveT;
                    static const int  iMaxIterations = MaxIterationsT;

                    template<class CharFuncT>
                    U32::Type CalcImpl(CharT const * inStr)
                    {
                        CharFuncT const inCharFunc;

                        register ::Wiz::U32::Type Hash = 0;
                        register ::Wiz::U32::Type CurrChar;
                        register int i = 0;

                        for (; (CurrChar = inCharFunc(inStr[i])) && (iMaxIterations > i); i++)
                        {
                            if ((i & 1) == 0)
                            {
                                Hash ^= ((Hash << 7) ^ CurrChar ^ (Hash >> 3));
                            }
                            else
                            {
                                Hash ^= (~((Hash << 11) ^ CurrChar ^ (Hash >> 5)));
                            }
                        }

                        return Hash;
                    }
                };

                template<typename CharT, bool CaseSensitiveT = true, int MaxIterationsT = 256>
                struct JS : public Proxy::Functor::Base< JS<CharT, CaseSensitiveT, MaxIterationsT> >
                {
                    typedef CharT tChar;

                    static const bool CaseSensitiveT = CaseSensitiveT;
                    static const int  iMaxIterations = MaxIterationsT;

                    template<class CharFuncT>
                    U32::Type CalcImpl(CharT const * inStr)
                    {
                        CharFuncT const             inCharFunc;

                        register ::Wiz::U32::Type   Hash = 0x4E67C6A7;
                        register ::Wiz::U32::Type   CurrChar;
                        register int                i = 0;

                        for (; (CurrChar = inCharFunc(inStr[i])) && (iMaxIterations > i); i++)
                        {
                            Hash ^= ((Hash << 5) + CurrChar + (Hash >> 2));
                        }

                        return Hash;
                    }
                };

                template<typename CharT, bool CaseSensitiveT = true, int MaxIterationsT = 256>
                struct NoName : public Proxy::Functor::Base< NoName<CharT, CaseSensitiveT, MaxIterationsT> >
                {
                    typedef CharT tChar;

                    static const bool CaseSensitiveT = CaseSensitiveT;
                    static const int  iMaxIterations = MaxIterationsT;

                    template<class CharFuncT>
                    U32::Type CalcImpl(CharT const * inStr)
                    {
                        CharFuncT const             inCharFunc;

                        register ::Wiz::U32::Type   Hash = 0;
                        register ::Wiz::U32::Type   CurrChar;
                        register int                i = 0;

                        for (; (CurrChar = inCharFunc(inStr[i])) && (iMaxIterations > i); i++)
                        {
                            Hash ^= CurrChar << (i & 0x07); /// 0111
                        }

                        return Hash;
                    }
                };
            } /// end of namespace Functor

            template< class CharT, Category::Type CatT = Category::eSDBM, bool CaseSensitiveT = true, int MaxIterationsT = 128 >
            struct Type
            {
                static U32::TypeC                       invalidHashCode = U32::Max;
                static U32::TypeC                       invalidIndex    = U32::Max;

                typedef CharT                           tChar;
                typedef tChar const *                   tCharPtrConst;

                typedef U32::Type                       tIndex;

                static U32::Type CalcHashCode(tCharPtrConst inStr)
                {
                    return 0;
                }
            };

            template< class CharT, bool CaseSensitiveT, int MaxIterationsT >
            struct Type<CharT, Category::eBKDR, CaseSensitiveT, MaxIterationsT>
            {
                static U32::TypeC                       invalidHashCode = U32::Max;
                static U32::TypeC                       invalidIndex = U32::Max;

                typedef CharT                           tChar;
                typedef tChar const *                   tCharPtrConst;

                typedef U32::Type                       tIndex;

                static U32::Type CalcHashCode(tCharPtrConst inStr)
                {
                    typedef Proxy::Functor::BKDR<tChar, CaseSensitiveT, MaxIterationsT> tFunctor;

                    return tFunctor::Calc(inStr);
                }
            };

            template< class CharT, bool CaseSensitiveT, int MaxIterationsT >
            struct Type<CharT, Category::eSDBM, CaseSensitiveT, MaxIterationsT>
            {
                static U32::TypeC                       invalidHashCode = U32::Max;
                static U32::TypeC                       invalidIndex = U32::Max;

                typedef CharT                           tChar;
                typedef tChar const *                   tCharPtrConst;

                typedef U32::Type                       tIndex;

                static U32::Type CalcHashCode(tCharPtrConst inStr)
                {
                    typedef Proxy::Functor::SDBM<tChar, CaseSensitiveT, MaxIterationsT> tFunctor;

                    return tFunctor::Calc(inStr);
                }
            };

            template< class CharT, bool CaseSensitiveT, int MaxIterationsT >
            struct Type<CharT, Category::eAP, CaseSensitiveT, MaxIterationsT>
            {
                static U32::TypeC                       invalidHashCode = U32::Max;
                static U32::TypeC                       invalidIndex = U32::Max;

                typedef CharT                           tChar;
                typedef tChar const *                   tCharPtrConst;

                typedef U32::Type                       tIndex;

                static U32::Type CalcHashCode(tCharPtrConst inStr)
                {
                    typedef Proxy::Functor::AP<tChar, CaseSensitiveT, MaxIterationsT> tFunctor;

                    return tFunctor::Calc(inStr);
                }
            };

            template< class CharT, bool CaseSensitiveT, int MaxIterationsT >
            struct Type<CharT, Category::eJS, CaseSensitiveT, MaxIterationsT>
            {
                static U32::TypeC                       invalidHashCode = U32::Max;
                static U32::TypeC                       invalidIndex = U32::Max;

                typedef CharT                           tChar;
                typedef tChar const *                   tCharPtrConst;

                typedef U32::Type                       tIndex;

                static U32::Type CalcHashCode(tCharPtrConst inStr)
                {
                    typedef Proxy::Functor::JS<tChar, CaseSensitiveT, MaxIterationsT> tFunctor;

                    return tFunctor::Calc(inStr);
                }
            };

            template< class CharT, bool CaseSensitiveT, int MaxIterationsT >
            struct Type<CharT, Category::eNoName, CaseSensitiveT, MaxIterationsT>
            {
                static U32::TypeC                       invalidHashCode = U32::Max;
                static U32::TypeC                       invalidIndex = U32::Max;

                typedef CharT                           tChar;
                typedef tChar const *                   tCharPtrConst;

                typedef U32::Type                       tIndex;

                static U32::Type CalcHashCode(tCharPtrConst inStr)
                {
                    typedef Proxy::Functor::NoName<tChar, CaseSensitiveT, MaxIterationsT> tFunctor;

                    return tFunctor::Calc(inStr);
                }
            };
        } /// end of namespace Proxy
    } /// end of namespace HashString
} /// end of namespace Wiz

#endif /*__WIZ_ADV_HASHSTRINGTPROXY_HPP__SHANHAOBO_19800429__*/
