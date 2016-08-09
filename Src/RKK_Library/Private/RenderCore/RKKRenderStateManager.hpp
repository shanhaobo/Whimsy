#ifndef __RENDERKINGKONG_RENDERSTATE_MANAGER_HPP__
#define __RENDERKINGKONG_RENDERSTATE_MANAGER_HPP__

#include "../../include/RenderCore/RKKRenderState.hpp"

namespace rkk
{
    namespace RenderState
    {
        namespace Manager
        {
            WMS_CLASS
            {
            public:
                type();
                ~type();

            public:
                ::wms::Bool::type Update(RenderState::in inNewState);

            protected:
                RenderState::type           m_WorkingState;
            };
        } /// end of namespace Manager
    } /// namespace RenderState
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_RENDERSTATE_MANAGER_HPP__
