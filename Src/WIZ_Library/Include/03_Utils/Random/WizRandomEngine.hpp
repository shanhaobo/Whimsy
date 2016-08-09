#ifndef __WIZ_RANDOM_ENGINE_HPP__SHANHAOBO_19800429__
#define __WIZ_RANDOM_ENGINE_HPP__SHANHAOBO_19800429__

#include "../../01_Basic/01_Type/WizBasicType.hpp"

#include "../../01_Basic/04_TU/WizBasicTU.hpp"

namespace Wiz
{
    namespace Random
    {
        namespace Engine
		{
			/// 每个随机引擎有它自己的数据类型
			/// 每个随机引擎有它自己的范围(随机范围只能用整型)
			template<class NumT, ::Wiz::U::Type UMin, ::Wiz::U::Type UMax>
            class Type : public ::Wiz::Noncopyable::Type
            {
			public:
				typedef NumT					tNum;
                typedef tNum const 				tNumIn;
            public:
                virtual tNum Rand() const = 0;
                virtual ::Wiz::Void::Type Seed() = 0;
                virtual ::Wiz::Void::Type Seed(tNumIn) = 0;
            public:
                static WIZ_INLINE tNum GetMin()
				{
					return ::Wiz::Cast::Static<tNum>(UMin);
				}
                static WIZ_INLINE tNum GetMax()
				{
					return ::Wiz::Cast::Static<tNum>(UMax);
				}
                static WIZ_INLINE tNum GetRange()
                {
                    return GetMax() - GetMin();
                }
            protected:
                Type()
                {
                }
            };
        } /// end of namespace Engine
    } /// end of namespace Random
} /// end of namespace Wiz

#endif /*__WIZ_RANDOM_ENGINE_HPP__SHANHAOBO_19800429__*/
