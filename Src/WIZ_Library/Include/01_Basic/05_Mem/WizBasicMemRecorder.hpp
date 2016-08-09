#ifndef __WIZ_MEM_RECORDER_HPP__SHANHAOBO_19800429__
#define __WIZ_MEM_RECORDER_HPP__SHANHAOBO_19800429__

#include "../01_Type/WizBasicType.hpp"
#include "../02_MU/WizBasicMU.hpp"

namespace Wiz
{
    namespace MemRecorder
    {
        void Alloc(void* ptr, size_t sz, const char* file = 0, size_t ln = 0, const char* func = 0);
        void Dealloc(void* ptr);
    } /// end of namespace MemRecorder
} /// end of namespace Wiz

#endif /*__WIZ_MEM_RECORDER_HPP__SHANHAOBO_19800429__*/
