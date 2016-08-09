#include "./WizRegexAutomaton.hpp"

#include "./WizRegexExpressionVisitor.hpp"
#include "./WizRegexExpression.hpp"

namespace Wiz
{
    namespace Regex
    {
        namespace Automaton
        {
            Transition::Ptr Type::StateTransition(State::Ptr inBeginStatePtr, State::Ptr inEndStatePtr)
            {
                Transition::Ptr TransPtr = WIZ_NEW Transition::Type;
                if (::Wiz::IsValidPtr(TransPtr))
                {
                    if (LinkNode(TransPtr, inBeginStatePtr, inEndStatePtr))
                    {
                        insertLink(TransPtr);
                        return TransPtr;
                    }

                    WIZ_DEL TransPtr;
                    TransPtr = WIZ_NULL;
                }

                return WIZ_NULL;
            }


            Transition::Epsilon::Ptr Type::EpsilonTransition(State::Ptr inBeginStatePtr, State::Ptr inEndStatePtr)
            {
                Transition::Epsilon::Ptr EpsilonPtr = WIZ_NEW Transition::Epsilon::Type;
                if (::Wiz::IsValidPtr(EpsilonPtr))
                {
                    if (LinkNode(EpsilonPtr, inBeginStatePtr, inEndStatePtr))
                    {
                        insertLink(EpsilonPtr);
                        return EpsilonPtr;
                    }

                    WIZ_DEL EpsilonPtr;
                    EpsilonPtr = WIZ_NULL;
                }

                return WIZ_NULL;
            }
        } /// end of namespace Automaton
    } /// end of namespace Regex
} /// end of namespace Wiz

