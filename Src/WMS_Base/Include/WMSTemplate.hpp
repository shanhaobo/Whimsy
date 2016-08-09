#ifndef __WHIMSY_BASETEMPLATE_HPP__
#define __WHIMSY_BASETEMPLATE_HPP__

#include "../../WIZ_Library/include/01_Basic/04_TU/WizBasicTU.hpp"

//////////////////////////////////////////////////////////////////////////

namespace wms
{
    template<class T>
    inline Bool::type IsValidPtr(T const * const ptr)
    {
        return ::Wiz::IsValidPtr(ptr);
    }

} /// end of namespace wms

//////////////////////////////////////////////////////////////////////////

#endif /*__WHIMSY_BASETEMPLATE_HPP__*/
