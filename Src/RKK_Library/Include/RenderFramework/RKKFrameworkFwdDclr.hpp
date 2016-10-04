#ifndef __RENDERKINGKONG_FRAMEWORK_FORWARD_DELCARE_HPP__
#define __RENDERKINGKONG_FRAMEWORK_FORWARD_DELCARE_HPP__

#include "../../../WMS_Base/Include/WMSBase.hpp"
#include "../../../WMS_Core/Include/WMSCore.hpp"

namespace rkk
{
    namespace ERKK_OBJ_CAT
    {
        namespace Framework
        {
            WIZ_ACD(eROC_General);

            WIZ_ACD(eROC_RenderCmd);
        } /// end of namespace Framework
    } /// end of namespace ERKK_OBJ_CAT

    namespace Allocator
    {
        namespace Framework
        {
            namespace General
            {
                typedef ::Wiz::Allocator::Categorized<ERKK_OBJ_CAT::Framework::eROC_General>::Type   type;
            }
            namespace RenderCmd
            {
                typedef ::Wiz::Allocator::Categorized<ERKK_OBJ_CAT::Framework::eROC_RenderCmd>::Type   type;
            }
        } /// end of namespace Framework
    } /// end of namespace Allocator

    namespace Obj
    {
        namespace Framework
        {
            namespace General
            {
                WMS_DECLARE(::wms::Obj::type<::rkk::Allocator::Framework::General::type>);
            }
            namespace RenderCmd
            {
                WMS_DECLARE(::wms::Obj::type<::rkk::Allocator::Framework::RenderCmd::type>);
            }
        } /// end of namespace Framework
    } /// end of namespace ANN

	namespace Root
	{
		class type;
		WMS_DECLARE_PTR(type);
	} /// namespace RenderFlow

	////////////////////////////////////////////

	namespace Renderer
	{
		WMS_FORWARD_DECLARE_CLASS;
	} /// end of namespace Renderer;

	namespace RenderPass
	{
		WMS_FORWARD_DECLARE_CLASS;
	} /// end of namespace RenderPass;

	namespace RenderFlow
	{
		WMS_FORWARD_DECLARE_CLASS;
	} /// end of namespace RenderFlow;

    namespace Renderer
    {
        class type;
        WMS_DECLARE_PTR(type);
    } /// namespace RenderFlow
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_FRAMEWORK_FORWARD_DELCARE_HPP__
