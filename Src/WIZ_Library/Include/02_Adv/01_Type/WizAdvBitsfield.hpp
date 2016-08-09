#ifndef __WIZ_ADV_BITSFIELD_HPP__SHANHAOBO_19800429__
#define __WIZ_ADV_BITSFIELD_HPP__SHANHAOBO_19800429__

#include "../../01_Basic/01_Type/WizBasicTypeInt.hpp"
#include "../../01_Basic/04_TU/WizBasicTUBit.hpp"

namespace Wiz
{
    namespace Bitsfield
    {
        template<class StorageT>
        class Type
        {
            typedef StorageT    tStorage;
        public:
            Type()
            {
                this->m_Value = 0;
            }
            ~Type(){}
            explicit Type(tStorage Val)
            {
                this->m_Value = Val;
            }
        public:
            tStorage Get()
            {
                return this->m_Value;
            }
            ::Wiz::Void::Type Reset(tStorage Val = 0)
            {
                this->m_Value = Val;
            }
            ////////////////////////////////////////////////////////////////////////
        public:
            ::Wiz::Void::Type Set(const tStorage& Val)
            {
                ::Wiz::Bit::Set(this->m_Value, Val);
            }

            tStorage TestSet(const tStorage& Val)
            {
                return ::Wiz::Bit::TestSet(this->m_Value, Val);
            }

            ::Wiz::Void::Type Unset(const tStorage& Val)
            {
                ::Wiz::Bit::Unset(this->m_Value, Val);
            }

            tStorage TestClear(const tStorage& Val)
            {
                return ::Wiz::Bit::TestClear(this->m_Value, Val);
            }

            ::Wiz::Void::Type SetN(::Wiz::I::In n)
            {
                ::Wiz::Bit::SetN(this->m_Value, n)
            }

            tStorage TestSetN(::Wiz::I::In n)
            {
                return ::Wiz::Bit::TestSetN(this->m_Value, n);
            }
            ////////////////////////////////////////////////////////////////////////
        public:
            ::Wiz::Bool::Type IsSet(const tStorage& Val) const
            {
                return ::Wiz::Bit::IsSet(this->m_Value, Val);
            }

            ::Wiz::Bool::Type IsAnySet(const tStorage& Val) const
            {
                return ::Wiz::Bit::IsAnySet(this->m_Value, Val);
            }

            ::Wiz::Bool::Type IsAllSet(const tStorage& Val) const
            {
                return ::Wiz::Bit::IsAllSet(this->m_Value, Val);
            }

            ::Wiz::Bool::Type IsOnlySet(const tStorage& Val) const
            {
                return ::Wiz::Bit::IsOnlySet(this->m_Value, Val);
            }

            ::Wiz::Bool::Type NotSet(const tStorage& Val) const
            {
                return ::Wiz::Bit::NotSet(this->m_Value, Val);
            }

            ::Wiz::Bool::Type NotAnySet(const tStorage& Val) const
            {
                return ::Wiz::Bit::NotAnySet(this->m_Value, Val);
            }

            ::Wiz::Bool::Type NotAllSet(const tStorage& Val) const
            {
                return ::Wiz::Bit::NotAllSet(this->m_Value, Val);
            }

            ::Wiz::Bool::Type NotOnlySet(const tStorage& Val) const
            {
                return ::Wiz::Bit::NotOnlySet(this->m_Value, Val);
            }

            ::Wiz::Bool::Type GetMarked(const tStorage& Val) const
            {
                return ::Wiz::Bit::GetMarked(this->m_Value, Val);
            }
            ////////////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////////////
            template<int CNT>
            tStorage GetLowBits() const
            {
                return this->m_Value & ::Wiz::Bit::MakeLowMark<tStorage, CNT>();
            }

            template<int B, int CNT> const
                tStorage GetBits()
            {
                return this->m_Value & ::Wiz::Bit::MakeMark<tStorage, B, CNT>();
            }
            template<int B, int E>
            tStorage GetRangeBits() const
            {
                return this->m_Value & ::Wiz::Bit::MakeRangeMark<tStorage, B, E>();
            }
            ////////////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////////////
            template<int B, int CNT>
            tStorage GetBitsToLow() const
            {
                return ::Wiz::Bit::GetBitsToLow<B, CNT, tStorage>(this->m_Value);
            }

            template<int B, int E>
            tStorage GetRangeBitsToLow() const
            {
                return ::Wiz::Bit::GetRangeBitsToLow<B, E, tStorage>(this->m_Value);
            }
            ////////////////////////////////////////////////////////////////////////
        private:
            tStorage m_Value;
        };
    } /// end of namespace Bitsfield
    namespace Bitsfield8
    {
        WIZ_DECLARE(::Wiz::Bitsfield::Type<::Wiz::U8::Type>);
    } /// end of namespace Bitsfield8

    namespace Bitsfield16
    {
        WIZ_DECLARE(::Wiz::Bitsfield::Type<::Wiz::U16::Type>);
    } /// end of namespace Bitsfield16

    namespace Bitsfield32
    {
        WIZ_DECLARE(::Wiz::Bitsfield::Type<::Wiz::U32::Type>);
    } /// end of namespace Bitsfield32

    namespace Bitsfield64
    {
        WIZ_DECLARE(::Wiz::Bitsfield::Type<::Wiz::U64::Type>);
    } /// end of namespace Bitsfield64
} /// end of namespace Wiz

#endif /*__WIZ_ADV_BITSFIELD_HPP__SHANHAOBO_19800429__*/
