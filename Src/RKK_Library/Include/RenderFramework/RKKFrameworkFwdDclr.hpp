#ifndef __RENDERKINGKONG_FRAMEWORK_FORWARD_DELCARE_HPP__
#define __RENDERKINGKONG_FRAMEWORK_FORWARD_DELCARE_HPP__

#include "../../../WMS_Base/Include/WMSBase.hpp"

namespace rkk
{
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
