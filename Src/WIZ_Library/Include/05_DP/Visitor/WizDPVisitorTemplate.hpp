#undef  WIZ_VISITOR_PARAM_COUNT
#define WIZ_VISITOR_PARAM_COUNT        WIZ_MPP_REPEAT_FILE_COUNT

/////////////////////////////////////////////////////////////////////////////////////////
namespace Wiz
{
    namespace DP
	{
		namespace Visitor
		{
            template<WIZ_ENUM_PARAM_X(WIZ_VISITOR_PARAM_COUNT, class T)>
            struct Type<EnumParamWrapper(WIZ_ENUM_PARAM_X(WIZ_VISITOR_PARAM_COUNT, T))> : public ::Wiz::DP::Visitor::Impl::Type<WIZ_TYPELIST_FAST_DEFINE(WIZ_VISITOR_PARAM_COUNT, T)>
			{
			}; /// end of struct Type
		} /// end of namespace Visitor
	} /// end of namespace DesignPattern
} /// end of namespace Wiz
/////////////////////////////////////////////////////////////////////////////////////////

#undef  WIZ_VISITOR_PARAM_COUNT

