#include "../../Include/Core/WMSFrmwrkActor.hpp"

namespace wms
{
    namespace Actor
    {
        type::type()
        {
        }

        type::~type()
        {
        }

        Void::type type::Tick(F32::in inDeltaTime)
        {
            tSuper::Tick(inDeltaTime);
        }
    } /// end of namespace Cmpnt
} /// end of namespace wms
