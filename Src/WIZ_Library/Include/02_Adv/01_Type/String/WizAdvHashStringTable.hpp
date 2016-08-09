#ifndef __WIZ_ADV_HASHSTRINGTABLE_HPP__SHANHAOBO_19800429__
#define __WIZ_ADV_HASHSTRINGTABLE_HPP__SHANHAOBO_19800429__

#include "../Container/WizAdvContainer.hpp"

#include "./WizAdvFixedString.hpp"
#include "./WizAdvHashStringProxy.hpp"

namespace Wiz
{
    namespace HashString
    {
        namespace Table
        {
            /// Reserved[0, ReservedNumT)
            /// NonReserved[ReservedNumT, Max)
            template<class ProxyT, int TotalNumT, int ReservedNumT, class AllocatorT>
            struct Type
            {
            public:
                typedef ProxyT                                                      tProxy;
                typedef typename tProxy::tCharPtrConst                              tString;
                typedef typename tProxy::tIndex                                     tIndex;

            private:

                typedef typename Type<ProxyT, TotalNumT, ReservedNumT, AllocatorT>  tThis;

                typedef const tIndex                                                tIndexConst;
                typedef tIndex &                                                    tIndexOut;

				/// new:The C++ Standard forbids containers of const elements
				/// tIndexConst forbidden!
                typedef Array::Type<tIndex, AllocatorT>								tIndexArray;

            private:
                typedef tString const                                               tStringConst;
                typedef tString&                                                    tStringRef;
                typedef tStringConst&                                               tStringRefConst;
                typedef tString*                                                    tStringPtr;
                typedef tStringConst*                                               tStringPtrConst;

                typedef Array::Type<tString, AllocatorT>                            tStringArray;

            public:
                enum
                {
                    eTotalCapacity = TotalNumT,
                    eReservedNum = ReservedNumT,
                    eNonReservedIndex = ReservedNumT,
                    eInvalidHashCode = eTotalCapacity,
                };

                WIZ_DECLARE_IN_STDCLASS(tThis);

            public:
                tIndex AddString(tStringRefConst inStr, tIndex inReservedIndex = eNonReservedIndex)
                {
                    tIndexConst HashCode = CalcHashCode(inStr);

                    tIndex FndIndex;

                    if (FindString(inStr, HashCode, FndIndex))
                    {
                        return FndIndex;
                    }

                    if (inReservedIndex < eReservedNum)
                    {
                        if (AddReserved(inStr, HashCode, inReservedIndex))
                        {
                            return inReservedIndex;
                        }

                        /// Conflict
                        return ::std::numeric_limits<tIndex>::(max)();
                    }

                    return AddNonReserved(inStr, HashCode);
                }

                Bool::Type FindString(tStringRefConst inStr, tIndexOut outIdx)
                {
                    tIndexConst HashCode = CalcHashCode(inStr);

                    if (FindString(inStr, HashCode, outIdx))
                    {
                        return Bool::True;
                    }

                    return Bool::False;
                }


                Bool::Type TestString(tStringRefConst inStr)
                {
                    tIndex DummyIdx;

                    return TestString(inStr, DummyIdx);
                }

            public:
                tStringPtrConst GetStringPtr(tIndex inIdx) const
                {
                    if (inIdx < eReservedNum)
                    {
                        return &(m_ReservedStringTab[inIdx]);
                    }
                    else if (IsValidIndex(inIdx))
                    {
                        return &(m_StringArray[inIdx]);
                    }

                    return WIZ_NULL;
                }

            public:
                ::Wiz::Bool::Type IsValidIndex(tIndex inIdx) const
                {
                    const tIndex StrArrayLen = m_StringArray.Size();
                    return inIdx < (StrArrayLen + eReservedNum);
                }

            private:
                ::Wiz::Bool::Type IsValidHashCode(tIndex inHashCode) const
                {
                    return (inHashCode >= 0) && (inHashCode < eTotalCapacity);
                }

                tIndexConst CalcHashCode(tStringRefConst inStr) const
                {
                    const tIndex iHashCode = tProxy::CalcHashCode(inStr) % eTotalCapacity;
                    return iHashCode;
                }

            private:

                Bool::Type FindString(tStringRefConst inStr, tIndex inHashCode, tIndexOut outIndex)
                {
                    WIZ_ASSERT(IsValidHashCode(inHashCode));

                    tIndexArray&                    HashIndexArray = m_HashTab[inHashCode];

                    tIndexArray::tIterator          Itr = HashIndexArray.Begin();
                    tIndexArray::tIteratorConst     ItrEnd = HashIndexArray.End();
                    for (; Itr != ItrEnd; ++Itr)
                    {
                        tIndex const StrIdx = *Itr;

                        if (StrIdx < eReservedNum)
                        {
                            if (inStr == m_ReservedStringTab[StrIdx])
                            {
                                outIndex = StrIdx;
                                return Bool::True;
                            }
                        }
                        else if (inStr == m_StringArray[StrIdx - eReservedNum])
                        {
                            outIndex = StrIdx;
                            return Bool::True;
                        }
                    }

                    return Bool::False;
                }

                Bool::Type AddReserved(tStringRefConst inStr, tIndex inHashCode, tIndex inReservedIndex)
                {
                    WIZ_ASSERT((inStr.Size() > 0) && IsValidHashCode(inHashCode) && (inReservedIndex < eReservedNum));

                    if (m_ReservedStringTab[inReservedIndex].Size() > 0)
                    {
                        /// Conflict
                        return Bool::False;
                    }

                    m_ReservedStringTab[inReservedIndex] = inStr;

                    m_HashTab[inHashCode].PushBack(inReservedIndex);

                    return Bool::True;
                }

                tIndexConst AddNonReserved(tStringRefConst inStr, tIndex inHashCode)
                {
                    WIZ_ASSERT((inStr.Size() > 0) && IsValidHashCode(inHashCode));

                    tIndex const ResultIdx = m_StringArray.Size() + eReservedNum;
                    m_StringArray.PushBack(inStr);
                    m_HashTab[inHashCode].PushBack(ResultIdx);

                    return ResultIdx;
                }

            private:
                /// m_HashTab可以通过字符串找到索引, 
                tIndexArray         m_HashTab[eTotalCapacity];
                /// m_StringArray可以通过索引立即找到字符串
                tString             m_ReservedStringTab[eReservedNum];

                tStringArray        m_StringArray;
            };
        } /// end of namespace Table
    } /// end of namespace HashString
} /// end of namespace Wiz

#endif /*__WIZ_ADV_HASHSTRINGTABLE_HPP__SHANHAOBO_19800429__*/
