#ifndef __RENDERKINGKONG_RENDERTARGET_MANAGER_HPP__
#define __RENDERKINGKONG_RENDERTARGET_MANAGER_HPP__

#include "./RKKRenderCoreFwdDclr.hpp"

#include "./RKKRenderTarget.hpp"

namespace rkk
{
	namespace RenderTarget
	{
		enum EUsage
		{
			eSceneColor,
			eSceneDepth,
		};
	} /// end of RenderTarget

    namespace RenderTargetManager
    {
        WMS_CLASS
        {
			typedef ::rkk::RenderTarget::ptr	tElementPtr;

        public:
            type();
            virtual ~type();

			::wms::Bool::type ActiveRenderTarget(::rkk::RenderTarget::EUsage inCategory);
			::wms::Void::type DeactiveRenderTarget(::rkk::RenderTarget::EUsage inCategory);

		protected:
			::Wiz::Array::Type<tElementPtr>		RenderTargetTable;
        };
    } /// namespace RenderTargetManager
} /// namespace rkk

#endif __RENDERKINGKONG_RENDERTARGET_MANAGER_HPP__
