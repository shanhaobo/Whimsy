#ifndef __WIZ_TIMER_HIGHRES_HPP__SHANHAOBO_19800429__
#define __WIZ_TIMER_HIGHRES_HPP__SHANHAOBO_19800429__

#include "../../01_Basic/01_Type/WizBasicType.hpp"
#include "../../01_Basic/02_MU/WizBasicMU.hpp"

namespace Wiz
{
    namespace Timer
    {
        namespace HighRes
        {
            WIZ_CLASS
            {
            public:
                Type()
                {
                }

                virtual ~Type()
                {
                }

                virtual Void::Type Reset() = 0;

                virtual R64::Type Now_Second() = 0;             /// √Î

                virtual R64::Type Now_MilliSecond() = 0;        /// ∫¡√Î

                virtual R64::Type Now_MicroSecond() = 0;        /// Œ¢√Î
            };

            Ptr instancePtr();
        } /// end of namespace HighRes
    } /// end of namespace Timer
} /// end of namespace Wiz

#endif /*__WIZ_TIMER_HIGHRES_HPP__SHANHAOBO_19800429__*/
