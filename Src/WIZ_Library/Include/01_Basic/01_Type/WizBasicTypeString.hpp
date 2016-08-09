#ifndef __WIZ_BASIC_TYPE_STRING_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TYPE_STRING_HPP__SHANHAOBO_19800429__

#include "./WizBasicTypeDeclareUtils.hpp"

#include "./WizBasicTypeBool.hpp"
#include "./WizBasicTypeMisc.hpp"

#include <string>

namespace Wiz
{
    namespace Std
    {
        namespace String
        {
            typedef ::std::string                                       Type;

            namespace Char
            {
                typedef String::Type::value_type                        Type;

                namespace Traits
                {
                    typedef String::Type::traits_type                   Type;
                } /// end of namespace Traits
            } /// end of namespace Char

            namespace Allocator
            {
                typedef String::Type::allocator_type                    Type;
            } /// end of namespace Allocator

            namespace Stream
            {
                typedef ::std::basic_stringstream<String::Char::Type, String::Char::Traits::Type, String::Allocator::Type> Type;
            } /// end of namespace      Stream;
        } /// end of namespace String

        namespace WString
        {
            typedef ::std::wstring                                      Type;

            namespace Char
            {
                typedef WString::Type::value_type                       Type;

                namespace Traits
                {
                    typedef WString::Type::traits_type                  Type;
                } /// end of namespace Traits
            } /// end of namespace Char

            namespace Allocator
            {
                typedef WString::Type::allocator_type                   Type;
            } /// end of namespace Allocator

            namespace Stream
            {
                typedef ::std::basic_stringstream<WString::Char::Type, WString::Char::Traits::Type, WString::Allocator::Type> Type;
            } /// end of namespace      Stream;
        } /// end of namespace WString
    } /// end of namespace Std

    //////////////////////////////////////////////////////////////////////////////////

    namespace String
    {
        template< typename CharT, class TraitsT = ::std::char_traits<CharT>, class AllocatorT = ::std::allocator<CharT> >
        class Type : protected ::std::basic_string<CharT, TraitsT, AllocatorT>
        {
        protected:
            typedef typename Type<CharT, TraitsT, AllocatorT>                       tThis;

            typedef typename tThis &                                                tThisRef;
            typedef typename tThis const &                                          tThisConstRef;

            typedef typename tThis const &                                          tThisIn;
            typedef typename tThis &                                                tThisOut;

            typedef typename ::std::basic_string<CharT, TraitsT, AllocatorT>        tSuper;

            typedef typename tSuper const &                                         tSuperIn;
            typedef typename tSuper const &                                         tSuperConstRef;

            WIZ_DECLARE_IN_STDCLASS(tThis)

        public:
            //////////////////////////////////////////////////////////////////////////

            typedef typename tSuper::traits_type                                    tTraits;
            typedef typename tSuper::allocator_type                                 tAllocator;
            typedef typename tSuper::value_type                                     tChar;

            typedef typename tSuper::iterator                                       tIterator;
            typedef typename tSuper::const_iterator                                 tIteratorConst;

            typedef tChar const * const                                             tCharPtrFixedConst;
            typedef tChar const *                                                   tCharPtrConst;
            typedef tChar *                                                         tCharPtr;

            typedef tChar const * const                                             tStrFixedConst;
            typedef tChar const *                                                   tStrConst;
            typedef tChar *                                                         tStr;

            typedef typename tSuper::size_type                                      tSize;

        public:
            //////////////////////////////////////////////////////////////////////////

            typedef typename std::basic_string<tChar, std::char_traits<tChar>, std::allocator<tChar> >  tStdString;
            typedef typename tStdString const &                                                         tStdStringIn;
            typedef typename tStdString &                                                               tStdStringOut;

        public:
            //////////////////////////////////////////////////////////////////////////
            Type() : tSuper()
            {
            }

            Type(tCharPtrConst inPtr) : tSuper(inPtr)
            {
            }

            Type(tSuperIn inSuper) : tSuper(inSuper)
            {
            }

            Type(tThisIn inThis) : tSuper(inThis)
            {
            }

            Type(tThisIn inThis, tSize inOffSZ, tSize inCnt = npos) : tSuper(inThis, inOffSZ, inCnt)
            {
            }

            Type(tCharPtrConst inPtr, tSize inCnt) : tSuper(inPtr, inCnt)
            {
            }

            template<class ItrT>
            Type(ItrT inFirst, ItrT inLast) : tSuper(inFirst, inLast)
            {
            }

        public:
            //////////////////////////////////////////////////////////////////////////
            Bool::Type operator==(tThisIn inOther) const
            {
                return tSuper::compare(inOther) == 0;
            }

            Bool::Type operator!=(tThisIn inOther) const
            {
                return tSuper::compare(inOther) != 0;
            }

            Bool::Type operator==(tCharPtrConst inPtr) const
            {
                return tSuper::compare(inPtr) == 0;
            }

            Bool::Type operator!=(tCharPtrConst inPtr) const
            {
                return tSuper::compare(inPtr) != 0;
            }

            /// operator=
            tThisRef operator=(tCharPtrConst inPtr)
            {
                tSuper::operator=(inPtr);
                return *this;
            }
            tThisRef operator=(tThisIn inOther)
            {
                tSuper::operator=(inOther);
                return *this;
            }
            tThisRef operator=(tSuperIn inOther)
            {
                tSuper::operator=(inOther);
                return *this;
            }

            /// operator+=
            tThisRef operator+=(tCharPtrConst inPtr)
            {
                tSuper::operator+=(inPtr);
                return *this;
            }
            tThisRef operator+=(tChar const inCh)
            {
                tSuper::operator+=(inCh);
                return *this;
            }
            tThisRef operator+=(tThisIn inOther)
            {
                tSuper::operator+=(inOther);
                return *this;
            }

            /// operator+
            tThis operator+(tCharPtrConst inPtr)
            {
                tThis TmpStr = *this;
                return (TmpStr += inPtr);
            }
            tThis operator+(tThisIn inOther)
            {
                tThis TmpStr = *this;
                return (TmpStr += inOther);
            }

        public:
            //////////////////////////////////////////////////////////////////////////
            Void::Type Resize(tSize inNewSize)
            {
                tSuper::resize(inNewSize);
            }

            tSize Size() const
            {
                return tSuper::size();
            }

            tSize Capacity() const
            {
                return tSuper::capacity();
            }

            Bool::Type IsEmpty() const
            {
                return tSuper::empty();
            }

            Void::Type Clear()
            {
                tSuper::clear();
            }

            WIZ_INLINE static Bool::Type IsValidPos(tSize inNewSize)
            {
                return inNewSize == tSuper::npos;
            }
        public:
            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE tCharPtrConst GetBufferConst() const
            {
                return tSuper::c_str();
            }

            WIZ_INLINE tCharPtr GetBuffer() const
            {
                return const_cast<tCharPtr>(GetBufferConst());
            }

        public:
            operator tCharPtrConst() const
            {
                return GetBufferConst();
            }

        public:
            //////////////////////////////////////////////////////////////////////////
            tSize Find(tChar C, tSize Offset = 0) const
            {
                return tSuper::find(C, Offset);
            }
            tSize Find(tStrConst SubStrPtr, tSize Offset = 0) const
            {
                return tSuper::find(SubStrPtr, Offset);
            }

            /// [OffBegin, OffEnd)
            tSize Find(tChar C, tSize OffBegin, tSize OffEnd = 0) const
            {
                tStrFixedConst  StrBeginPtr = tSuper::c_str();
                tStrConst       CurrPtr = StrBeginPtr + OffBegin;
                tStrFixedConst  EndPtr = StrBeginPtr + (OffEnd == 0 ? Size() : OffEnd);
                for (; CurrPtr < EndPtr; CurrPtr++)
                {
                    if (*CurrPtr == C)
                    {
                        return CurrPtr - StrBeginPtr;
                    }
                }

                return tSuper::npos;
            }

            /// [OffBegin, OffEnd)
            tSize Find(tStrConst, tSize SubLen, tSize OffBegin, tSize OffEnd = 0) const
            {
                tStrFixedConst StrBeginPtr = tSuper::c_str();

                tStrConst CurrPtr = StrBeginPtr + OffBegin;

                tStrFixedConst EndPtr = StrBeginPtr + (OffEnd == 0 ? Size() : OffEnd);
                for (; CurrPtr < EndPtr; CurrPtr++)
                {
                    if (::memcmp(CurrPtr, SubStrPtr, SubLen) == 0)
                    {
                        return CurrPtr - StrBeginPtr;
                    }
                }

                return tSuper::npos;
            }

        public:
            //////////////////////////////////////////////////////////////////////////
            /// [OffBegin, OffEnd)
            I::Type FindCount(tChar C, tSize OffBegin = 0, tSize OffEnd = 0) const
            {
                tSize Temp(OffBegin);
                I::Type Cnt = -1;
                do
                {
                    Temp = Find(C, Temp, OffEnd);
                    Cnt++;
                } while (Temp != tSuper::npos);

                return Cnt;
            }

            /// [OffBegin, OffEnd)
            I::Type FindCount(tCharPtrConst SubStrPtr, tSize SubLen, tSize OffBegin = 0, tSize OffEnd = 0) const
            {
                tSize Temp(OffBegin);
                I::Type Cnt = -1;
                do
                {
                    Temp = Find(SubStrPtr, SubLen, Temp + SubLen, OffEnd);
                    Cnt++;
                } while (Temp != tSuper::npos);

                return Cnt;
            }

        public:
            //////////////////////////////////////////////////////////////////////////x

            WIZ_INLINE friend Bool::Type operator <(tThisIn l, tStdStringIn o)
            {
                return l.compare(0, l.length(), o.c_str(), o.length()) < 0;
            }
            WIZ_INLINE friend Bool::Type operator <(tStdStringIn l, tThisIn o)
            {
                return l.compare(0, l.length(), o.c_str(), o.length()) < 0;
            }
            WIZ_INLINE friend Bool::Type operator <=(tThisIn l, tStdStringIn o)
            {
                return l.compare(0, l.length(), o.c_str(), o.length()) <= 0;
            }
            WIZ_INLINE friend Bool::Type operator <=(tStdStringIn l, tThisIn o)
            {
                return l.compare(0, l.length(), o.c_str(), o.length()) <= 0;
            }
            WIZ_INLINE friend Bool::Type operator >(tThisIn l, tStdStringIn o)
            {
                return l.compare(0, l.length(), o.c_str(), o.length()) > 0;
            }
            WIZ_INLINE friend Bool::Type operator >(tStdStringIn l, tThisIn o)
            {
                return l.compare(0, l.length(), o.c_str(), o.length()) > 0;
            }
            WIZ_INLINE friend Bool::Type operator >=(tThisIn l, tStdStringIn o)
            {
                return l.compare(0, l.length(), o.c_str(), o.length()) >= 0;
            }
            WIZ_INLINE friend Bool::Type operator >=(tStdStringIn l, tThisIn o)
            {
                return l.compare(0, l.length(), o.c_str(), o.length()) >= 0;
            }

            WIZ_INLINE friend Bool::Type operator ==(tThisIn l, tStdStringIn o)
            {
                return l.compare(0, l.length(), o.c_str(), o.length()) == 0;
            }
            WIZ_INLINE friend Bool::Type operator ==(tStdStringIn l, tThisIn o)
            {
                return l.compare(0, l.length(), o.c_str(), o.length()) == 0;
            }

            WIZ_INLINE friend Bool::Type operator !=(tThisIn l, tStdStringIn o)
            {
                return l.compare(0, l.length(), o.c_str(), o.length()) != 0;
            }
            WIZ_INLINE friend Bool::Type operator !=(tStdStringIn l, tThisIn o)
            {
                return l.compare(0, l.length(), o.c_str(), o.length()) != 0;
            }

            WIZ_INLINE friend tThis operator +=(tThisIn l, tStdStringIn o)
            {
                return tThis(l) += o.c_str();
            }
            WIZ_INLINE friend tThis operator +=(tStdStringIn l, tThisIn o)
            {
                return tThis(l.c_str()) += o.c_str();
            }

            WIZ_INLINE friend tThis operator +(tThisIn l, tStdStringIn o)
            {
                return tThis(l) += o.c_str();
            }
            WIZ_INLINE friend tThis operator +(tStdStringIn l, tThisIn o)
            {
                return tThis(l.c_str()) += o.c_str();
            }

            template<typename T>
            WIZ_INLINE friend tThis operator +(const T* l, tThisIn o)
            {
                return tThis(l) += o;
            }
        };
    } /// end of namespace String
    //////////////////////////////////////////////////////////////////////////////////
} /// end of namespace Wiz

#endif /*__WIZ_BASIC_TYPE_STRING_HPP__SHANHAOBO_19800429__*/
