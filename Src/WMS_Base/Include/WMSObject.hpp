#ifndef __WHIMSY_OBJECT_HPP__
#define __WHIMSY_OBJECT_HPP__

#include "../../WIZ_Library/include/01_Basic/05_Mem/WizBasicMemObj.hpp"

#include "./WMSAllocator.hpp"

#include "./WMSType.hpp"

//////////////////////////////////////////////////////////////////////////

#define WMS_NEW                                         WIZ_NEW
#define WMS_DEL                                         WIZ_DEL

#define WMS_MALLOC(SizeInByte, inCat)                   WIZ_MALLOC_CAT(SizeInByte, inCat)
#define WMS_FREE(MemPtr, inCat)                         WIZ_FREE_CAT(MemPtr, inCat)
#define WMS_MALLOC_T(inType, inCat)                     WIZ_MALLOC_T_CAT(inType, inCat)
#define WMS_MALLOC_ARRAY_T(inType, inCnt, inCat)        WIZ_MALLOC_ARRAY_T_CAT(inType, inCnt, inCat)

#define WMS_NEW_T(inType, inCat)                        WIZ_NEW_T_CAT(inType, inCat)
#define WMS_DEL_T(MemPtr, inType, inCat)                WIZ_DEL_T_CAT(MemPtr, inType, inCat)

#define WMS_NEW_ARRAY_T(inType, inCnt, inCat)           WIZ_NEW_ARRAY_T_CAT(inType, inCnt, inCat)
#define WMS_DEL_ARRAY_T(MemPtr, inType, inCnt, inCat)   WIZ_DEL_ARRAY_T_CAT(MemPtr, inType, inCnt, inCat)

//////////////////////////////////////////////////////////////////////////

namespace wms
{
    //////////////////////////////////////////////////////////////////////////

    namespace Obj
    {

        template <class AllocatorT>
        class WIZ_EXPORT type : public ::Wiz::MemObj::Type<AllocatorT>
        {
        public:
            explicit type()
            { }

            ~type()
            { }

        protected:
            Name::type m_ObjName;
        };

        namespace General
        {
            WMS_DECLARE(::wms::Obj::type<Allocator::General::type>);
        } /// end of namespace Animation

        /// Render King Kong
        namespace Animation
        {
            WMS_DECLARE(::wms::Obj::type<Allocator::Animation::type>);
        } /// end of namespace Animation

        namespace Texture
        {
            WMS_DECLARE(::wms::Obj::type<Allocator::Resource::type>);
        } /// end of namespace Texture

        namespace Plugin
        {
            WMS_DECLARE(::wms::Obj::type<Allocator::General::type>);
        } /// end of namespace Plugin

        namespace RDL
        {
            WMS_DECLARE(::wms::Obj::type<Allocator::RDL::type>);
        } /// end of namespace RDL

        /// Framework
        namespace Cmpnt
        {
            WMS_DECLARE(::wms::Obj::type<Allocator::Cmpnt::type>);

			namespace MetaPrprty
			{
				WMS_DECLARE(::wms::Obj::type<Allocator::Cmpnt::MetaPrprty::type>);
			} /// end of namespace Property
        } /// end of namespace Cmpnt
    } /// end of namespace Obj

    //////////////////////////////////////////////////////////////////////////

} /// end of namespace wms

//////////////////////////////////////////////////////////////////////////

#endif /*__WHIMSY_OBJECT_HPP__*/
