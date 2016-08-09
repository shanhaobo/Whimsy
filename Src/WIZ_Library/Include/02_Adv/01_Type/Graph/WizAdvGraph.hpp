#ifndef __WIZ_GRAPH_HPP__SHANHAOBO_19800429__
#define __WIZ_GRAPH_HPP__SHANHAOBO_19800429__

#include "./WizAdvGraphNode.hpp"
#include "./WizAdvGraphLink.hpp"

namespace Wiz
{
    namespace Graph
    {
        class Type
        {
        protected:
            typedef Set::Type<Link::Ptr> tLinkSet;
            typedef Set::Type<Node::Ptr> tNodeSet;

        public:
            Type()
            {

            }

            virtual ~Type()
            {

            }
        public:
            static Bool::Type LinkNode(Link::Ptr inLinkPtr, Node::Ptr inBeginNodePtr, Node::Ptr inEndNodePtr)
            {
                if (::Wiz::IsValidPtr(inLinkPtr) && ::Wiz::IsValidPtr(inBeginNodePtr) && ::Wiz::IsValidPtr(inEndNodePtr))
                {
                    inLinkPtr->m_BeginNodePtr = inBeginNodePtr;
                    inLinkPtr->m_EndNodePtr = inEndNodePtr;

                    inBeginNodePtr->m_OutputSet.insert(inLinkPtr);
                    inEndNodePtr->m_InputSet.insert(inLinkPtr);

                    return Bool::True;
                }

                return Bool::False;
            }

            Void::Type insertLink(Link::Ptr inLinkPtr)
            {
                LinkSet.insert(inLinkPtr);
            }

            Void::Type insertNode(Node::Ptr inNodePtr)
            {
                NodeSet.insert(inNodePtr);
            }

        protected:
            tNodeSet NodeSet;
            tLinkSet LinkSet;
        };
    } /// end of namespace Graph
} /// end of namespace Wiz

#endif /// __WIZ_GRAPH_HPP__SHANHAOBO_19800429__
