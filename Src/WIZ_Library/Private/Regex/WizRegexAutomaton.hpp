#ifndef __WIZ_REGEX_AUTOMATON_HPP__SHANHAOBO_19800429__
#define __WIZ_REGEX_AUTOMATON_HPP__SHANHAOBO_19800429__

#include "./WizRegexBaseType.hpp"

#include "./WizRegexState.hpp"
#include "./WizRegexTransition.hpp"

namespace Wiz
{
    namespace Regex
    {
        namespace Automaton
        {
            class Type : public ::Wiz::MemObj::Type<Allocator::Automaton::Type, ::Wiz::Graph::Type>
            {
            protected:
                typedef ::Wiz::Graph::Type tSuper;

            public:
                Type()
                {

                }
            public:

                Transition::Ptr StateTransition(State::Ptr inBeginStatePtr, State::Ptr inEndStatePtr);

                Transition::Epsilon::Ptr EpsilonTransition(State::Ptr inBeginStatePtr, State::Ptr inEndStatePtr);

            protected:

                State::Ptr  m_StartState;
            };
        } /// end of namespace Automaton
    } /// end of namespace Regex
} /// end of namespace Wiz

#endif /// __WIZ_REGEX_AUTOMATON_HPP__SHANHAOBO_19800429__
