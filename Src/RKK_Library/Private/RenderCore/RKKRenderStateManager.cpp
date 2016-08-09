#include "./RKKRenderStateManager.hpp"

namespace rkk
{
    namespace RenderState
    {
        namespace Manager
        {
            type::type()
            {
            }

            type::~type()
            {
            }

            ::wms::Bool::type type::Update(RenderState::in inNewState)
            {

                m_WorkingState = inNewState;

                return ::wms::Bool::True;
            }
        } /// end of namespace Manager
    } /// namespace RenderState
} /// namespace rkk
