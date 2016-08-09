#ifndef __WIZ_REGEX_EXPRESSION_BASE_HPP__SHANHAOBO_19800429__
#define __WIZ_REGEX_EXPRESSION_BASE_HPP__SHANHAOBO_19800429__

#include "./WizRegexBaseType.hpp"

namespace Wiz
{
    namespace Regex
    {
        namespace Expression
        {
            ////////////////////////////////////////////
            ////////////////////////////////////////////
            ////////////////////////////////////////////
            /// ::Wiz::DP::Visitable::Base::Type
            class Type : public ::Wiz::DP::Visitable::Base::Type< Visitor::Type, Bool::Type, Expression::Ptr, ::Wiz::MemObj::Type<Allocator::Expression::Type> >
            {
            protected:
                typedef ::Wiz::DP::Visitable::Base::Type< Visitor::Type, Bool::Type, Expression::Ptr, ::Wiz::MemObj::Type<Allocator::Expression::Type> > tSuper;

            public:
                Type() : tSuper(), m_Final(Bool::False)
                {

                }

            public:
                WIZ_INLINE Bool::Type IsFinal()
                {
                    return m_Final;
                };

            protected:
                Bool::Type m_Final;
            };

            ////////////////////////////////////////////
            ////////////////////////////////////////////
            ////////////////////////////////////////////
            /// ::Wiz::DP::Visitable::Type
            namespace Terminal
            {
                template<class DerivedT>
                class Type : public ::Wiz::DP::Visitable::Type<DerivedT, Expression::Type>
                {
                protected:
                    Type()
                    {

                    }
                protected:

                };
            } /// end of namespace Terminal

            namespace Unary
            {
                template<class DerivedT>
                class Type : public ::Wiz::DP::Visitable::Type<DerivedT, Expression::Type>
                {
                protected:
                    Type() : m_OnlyChildPtr(WIZ_NULLPTR)
                    {

                    }
                public:
                    Expression::Ptr m_OnlyChildPtr;
                };
            } /// end of namespace Unary

            namespace Binary
            {
                template<class DerivedT>
                class Type : public ::Wiz::DP::Visitable::Type<DerivedT, Expression::Type>
                {
                protected:
                    Type() : m_LeftChildPtr(WIZ_NULLPTR), m_RightChildPtr(WIZ_NULLPTR)
                    {

                    }
                public:
                    Expression::Ptr m_LeftChildPtr;
                    Expression::Ptr m_RightChildPtr;
                };
            } /// end of namespace Binary

            ////////////////////////////////////////////
            ////////////////////////////////////////////
            ////////////////////////////////////////////
        } /// end of namespace Expression
    } /// end of namespace Regex
} /// end of namespace Wiz

#endif /// __WIZ_REGEX_EXPRESSION_BASE_HPP__SHANHAOBO_19800429__
