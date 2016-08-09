#ifndef __WIZ_MEM_ALLOCATOR_DEFAULT_HPP__SHANHAOBO_19800429__
#define __WIZ_MEM_ALLOCATOR_DEFAULT_HPP__SHANHAOBO_19800429__

#include "./WizBasicMemAllocatorBase.hpp"

#include <memory>

namespace Wiz
{
    namespace Allocator
    {
        namespace Default
        {
            WIZ_CLASS: public Base::Type<Allocator::Default::Type>
            {
            public:
                ///////////////////////////////////////////

                static WIZ_INLINE ::Wiz::Void::Ptr Allocate(size_t sz)
                {
                    return ::malloc(sz);
                }

                static WIZ_INLINE::Wiz::Void::Type Deallocate(void* ptr)
                {
                    ::free(ptr);
                }
                ///////////////////////////////////////////
            };
        } /// end of namespace Default
    } /// end of namespace Allocator
} /// end of namespace Wiz

#endif /*__WIZ_MEM_ALLOCATOR_DEFAULT_HPP__SHANHAOBO_19800429__*/
 