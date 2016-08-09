#ifndef __WIZ_RANDOM_ENGINE_HC_HPP__SHANHAOBO_19800429__
#define __WIZ_RANDOM_ENGINE_HC_HPP__SHANHAOBO_19800429__

#include "./WizRandomEngine.hpp"
#include <stdlib.h>
#include <time.h>

namespace Wiz
{
    namespace Random
    {
        namespace Engine
        {
			/// hal chamberlin
			namespace HC
			{
				class Type : public ::Wiz::Random::Engine::Type<::Wiz::U32::Type, 0, ::Wiz::U32::Max>
				{
					typedef ::Wiz::Random::Engine::Type<::Wiz::U32::Type, 0, ::Wiz::U32::Max> tSuper;
				public:
					virtual ::Wiz::U32::Type Rand() const
					{
						m_Seed = m_Seed * 196314165 + 907633515;
						return m_Seed;
					}
					virtual ::Wiz::Void::Type Seed(::Wiz::U32::In s)
					{
						m_Seed  = s;
					}
					virtual ::Wiz::Void::Type Seed()
					{
						Seed(::Wiz::Cast::Static<::Wiz::U32::Type>(time(WIZ_NULLPTR)));
					}
				public:
					Type()
					{
					}
				protected:
					mutable ::Wiz::U32::Type		m_Seed;
				};
			} /// end of namespace HC
        } /// end of namespace Engine
    } /// end of namespace Random
} /// end of namespace Wiz

#endif /*__WIZ_RANDOM_ENGINE_HC_HPP__SHANHAOBO_19800429__*/
