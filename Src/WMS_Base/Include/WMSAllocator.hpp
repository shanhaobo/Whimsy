#ifndef __WHIMSY_ALLOCATOR_HPP__
#define __WHIMSY_ALLOCATOR_HPP__

#include "../../WIZ_Library/include/01_Basic/05_Mem/WizBasicMemAllocator.hpp"

//////////////////////////////////////////////////////////////////////////

namespace wms
{
    namespace EWMS_OBJ_CAT
    {
        WIZ_ACD(eWOC_General);

        WIZ_ACD(eWOC_Geometry);
        WIZ_ACD(eWOC_Animation);
        WIZ_ACD(eWOC_Resource);
        WIZ_ACD(eWOC_RDL);

		WIZ_ACD(eWOC_Component);
		WIZ_ACD(eWOC_ComponentProperty);

        WIZ_ACD(eWOC_ArtificialNeuralNetwork);
    } /// end of namespace EWMS_OBJ_CAT

    namespace Allocator
    {
        //////////////////////////////////////////////////////////////////////////
        namespace General
        {
            typedef ::Wiz::Allocator::Categorized<EWMS_OBJ_CAT::eWOC_General>::Type     type;
        } /// end of namespace General

        //////////////////////////////////////////////////////////////////////////
        /// RKK
        namespace Geometry
        {
            typedef ::Wiz::Allocator::Categorized<EWMS_OBJ_CAT::eWOC_Geometry>::Type    type;
        } /// end of namespace Geometry

        namespace Animation
        {
            typedef ::Wiz::Allocator::Categorized<EWMS_OBJ_CAT::eWOC_Animation>::Type   type;
        } /// end of namespace Animation

        namespace Resource
        {
            typedef ::Wiz::Allocator::Categorized<EWMS_OBJ_CAT::eWOC_Resource>::Type    type;
        } /// end of namespace Texture

        namespace RDL
        {
            typedef ::Wiz::Allocator::Categorized<EWMS_OBJ_CAT::eWOC_RDL>::Type         type;
        } /// end of namespace RDL


        //////////////////////////////////////////////////////////////////////////
        /// Whimsy
        namespace Cmpnt
        {
            typedef ::Wiz::Allocator::Categorized<EWMS_OBJ_CAT::eWOC_Component>::Type   type;

			namespace MetaPrprty
			{
				typedef ::Wiz::Allocator::Categorized<EWMS_OBJ_CAT::eWOC_ComponentProperty>::Type   type;
			}
        } /// end of namespace Cmpnt

        //////////////////////////////////////////////////////////////////////////
        /// AI
        namespace ANN
        {
            typedef ::Wiz::Allocator::Categorized<EWMS_OBJ_CAT::eWOC_ArtificialNeuralNetwork>::Type   type;
        } /// end of namespace ANN
    } /// end of namespace Allocator
} /// end of namespace wms

//////////////////////////////////////////////////////////////////////////

#endif /*__WHIMSY_ALLOCATOR_HPP__*/
