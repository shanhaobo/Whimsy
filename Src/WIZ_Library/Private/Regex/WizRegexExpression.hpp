#ifndef __WIZ_REGEX_EXPRESSION_HPP__SHANHAOBO_19800429__
#define __WIZ_REGEX_EXPRESSION_HPP__SHANHAOBO_19800429__

#include "./WizRegexExpressionBase.hpp"

namespace Wiz
{
    namespace Regex
    {
        namespace Expression
        {
            ////////////////////////////////////////////
            ////////////////////////////////////////////
            ////////////////////////////////////////////

            namespace CharSet
            {
                class Type : public Terminal::Type<Type>
                {
                protected:
                    typedef Terminal::Type<Type> tSuper;
                public:
                    Type() : tSuper()
                    {

                    }
                };
            } /// end of namespace CharSet

            namespace Sequence
            {
                class Type : public Binary::Type<Type>
                {
                protected:
                    typedef Binary::Type<Type> tSuper;
                public:
                    Type() : tSuper()
                    {

                    }
                };
            } /// end of namespace Sequence

            namespace Alternative
            {
                class Type : public Binary::Type<Type>
                {
                protected:
                    typedef Binary::Type<Type> tSuper;
                public:
                    Type() : tSuper()
                    {

                    }
                };
            } /// end of namespace Alternative

            namespace Repeat
            {
                class Type : public Unary::Type<Type>
                {
                protected:
                    typedef Unary::Type<Type> tSuper;
                public:
                    Type() : tSuper()
                    {

                    }
                };
            } /// end of namespace Repeat

            ////////////////////////////////////////////
            ////////////////////////////////////////////
            ////////////////////////////////////////////
        } /// end of namespace Expression
    } /// end of namespace Regex
} /// end of namespace Wiz

#endif /// __WIZ_REGEX_EXPRESSION_HPP__SHANHAOBO_19800429__
