#ifndef __WIZ_GRAPH_NODE_HPP__SHANHAOBO_19800429__
#define __WIZ_GRAPH_NODE_HPP__SHANHAOBO_19800429__

#include "./WizAdvGraphForwardDeclare.hpp"

namespace Wiz
{
    namespace Graph
    {
        namespace Node
        {
            class Type
            {
                friend class ::Wiz::Graph::Type;
            protected:
                typedef Set::Type<Link::Ptr> tLinkSet;
            public:
                Type() : m_InputSet()
                {

                }

                virtual ~Type()
                {

                }
            public:
            protected:
                tLinkSet m_InputSet;
                tLinkSet m_OutputSet;
            };
        } /// end of namespace Node
    } /// end of namespace Graph
} /// end of namespace Wiz

#endif /// __WIZ_GRAPH_NODE_HPP__SHANHAOBO_19800429__
