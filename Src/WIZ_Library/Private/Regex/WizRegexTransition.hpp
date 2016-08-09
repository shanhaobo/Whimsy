#ifndef __WIZ_REGEX_TRANSITION_HPP__SHANHAOBO_19800429__
#define __WIZ_REGEX_TRANSITION_HPP__SHANHAOBO_19800429__

#include "./WizRegexBaseType.hpp"

namespace Wiz
{
    namespace Regex
    {
        namespace Transition
        {
            namespace Epsilon
            {
                class Type : public MemObj::Type<Allocator::Transition::Type, ::Wiz::Graph::Link::Type>
                {
                public:
                    Type()
                    {

                    }
                public:

                protected:
                };
            } /// end of namespace Epsilon

            class Type : public Epsilon::Type
            {
            protected:
                typedef Epsilon::Type tSuper;
            public:
                Type() : tSuper()
                {

                }
            public:

            protected:
            };
        } /// end of namespace Transition
    } /// end of namespace Regex
} /// end of namespace Wiz

#endif /// __WIZ_REGEX_TRANSITION_HPP__SHANHAOBO_19800429__
