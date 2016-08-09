#include "./WizRegexExpressionVisitor.hpp"

namespace Wiz
{
    namespace Regex
    {
        namespace Expression
        {
            namespace Traverse
            {
                Bool::Type Type::Visit(CharSet::Ref ioExpRef, Expression::Ptr inParentPtr)
                {
                    return Bool::True;
                }
                Bool::Type Type::Visit(Sequence::Ref ioExpRef, Expression::Ptr inParentPtr)
                {
                    if (::Wiz::IsValidPtr(ioExpRef.m_LeftChildPtr))
                    {
                        ioExpRef.m_LeftChildPtr->Accept(*this, &ioExpRef);
                    }
                    if (::Wiz::IsValidPtr(ioExpRef.m_RightChildPtr))
                    {
                        ioExpRef.m_RightChildPtr->Accept(*this, &ioExpRef);
                    }

                    return Bool::True;
                }
                Bool::Type Type::Visit(Alternative::Ref ioExpRef, Expression::Ptr inParentPtr)
                {
                    if (::Wiz::IsValidPtr(ioExpRef.m_LeftChildPtr))
                    {
                        if (ioExpRef.m_LeftChildPtr->Accept(*this, &ioExpRef))
                        {
                            return Bool::True;
                        }
                    }
                    if (::Wiz::IsValidPtr(ioExpRef.m_RightChildPtr))
                    {
                        return ioExpRef.m_RightChildPtr->Accept(*this, &ioExpRef);
                    }

                    return Bool::False;
                }
                Bool::Type Type::Visit(Repeat::Ref ioExpRef, Expression::Ptr inParentPtr)
                {
                    if (::Wiz::IsValidPtr(ioExpRef.m_OnlyChildPtr))
                    {
                        ioExpRef.m_OnlyChildPtr->Accept(*this, &ioExpRef);
                    }

                    return Bool::True;
                }
            } /// end of namespace ThompsonConstruction
        } /// end of namespace State
    } /// end of namespace Regex
} /// end of namespace Wiz
