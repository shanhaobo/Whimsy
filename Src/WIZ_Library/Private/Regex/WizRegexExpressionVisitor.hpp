#ifndef __WIZ_REGEX_EXPRESSION_VISITOR_HPP__SHANHAOBO_19800429__
#define __WIZ_REGEX_EXPRESSION_VISITOR_HPP__SHANHAOBO_19800429__

#include "./WizRegexExpression.hpp"

namespace Wiz
{
    namespace Regex
    {
        namespace Expression
        {
            ////////////////////////////////////////////
            ////////////////////////////////////////////
            ////////////////////////////////////////////
            /// Visitor
            namespace Visitor
            {
                struct Type : public ::Wiz::DP::Visitor::Type<EnumParamWrapper(CharSet::Type, Sequence::Type, Alternative::Type, Repeat::Type)>
                {
                    virtual Bool::Type Visit(CharSet::Ref ioExpRef, Expression::Ptr) = 0;
                    virtual Bool::Type Visit(Sequence::Ref ioExpRef, Expression::Ptr) = 0;
                    virtual Bool::Type Visit(Alternative::Ref ioExpRef, Expression::Ptr) = 0;
                    virtual Bool::Type Visit(Repeat::Ref ioExpRef, Expression::Ptr) = 0;
                };
            } /// end of namespace Visitor

            namespace Traverse
            {
                struct Type : Expression::Visitor::Type
                {
                    Type() : m_AutomatonPtr(WIZ_NULLPTR)
                    {
                    }

                    Automaton::Ptr m_AutomatonPtr;

                    virtual Bool::Type Visit(CharSet::Ref ioExpRef, Expression::Ptr inParentPtr);

                    virtual Bool::Type Visit(Sequence::Ref ioExpRef, Expression::Ptr inParentPtr);

                    virtual Bool::Type Visit(Alternative::Ref ioExpRef, Expression::Ptr inParentPtr);

                    virtual Bool::Type Visit(Repeat::Ref ioExpRef, Expression::Ptr inParentPtr);
                };
            } /// end of namespace Traverse
        } /// end of namespace Expression
    } /// end of namespace Regex
} /// end of namespace Wiz

#endif /// __WIZ_REGEX_EXPRESSION_VISITOR_HPP__SHANHAOBO_19800429__
