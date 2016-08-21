#ifndef __ANN_CORE_FORWORDDECLARE_HPP__ 
#define __ANN_CORE_FORWORDDECLARE_HPP__

#include "../../../WMS_Base/Include/WMSBase.hpp"
#include "../../../WMS_Core/Include/WMSCore.hpp"

namespace ann
{
    namespace EWMS_OBJ_CAT
    {
        WIZ_ACD(eWOC_General);

        /// Artificial Neural Network
    } /// end of namespace EWMS_OBJ_CAT

    namespace Allocator
    {
        typedef ::Wiz::Allocator::Categorized<EWMS_OBJ_CAT::eWOC_General>::Type   type;
    } /// end of namespace Allocator

    namespace Obj
    {
        WMS_DECLARE(::wms::Obj::type<::ann::Allocator::type>);
    } /// end of namespace ANN
} /// end of namespace ann

#endif /// __ANN_CORE_FORWORDDECLARE_HPP__
