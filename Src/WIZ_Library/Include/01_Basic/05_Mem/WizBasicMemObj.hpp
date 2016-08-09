#ifndef __WIZ_BASIC_MEMOBJ_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_MEMOBJ_HPP__SHANHAOBO_19800429__

////////////////////////////////////////////////////////////////////////////
#ifdef new
#   undef new
#endif

#ifdef delete
#   undef delete
#endif

namespace Wiz
{
    namespace MemObj
    {
        template <class AllocatorT, class BaseT = Null::Type>
        class WIZ_EXPORT Type : public BaseT
        {
            typedef AllocatorT              tAllocator;

        public:
            explicit Type()
            { }

            ~Type()
            { }

            //////////////////////////////////////////////////////////////////////////
            ///=============================STANDARD ==============================///
            //////////////////////////////////////////////////////////////////////////

            void* operator new(size_t sz)
            {
                return tAllocator::Allocate(sz);
            }

            void* operator new[](size_t sz)
            {
                return tAllocator::Allocate(sz);
            }

            void operator delete(void* ptr)
            {
                tAllocator::Deallocate(ptr);
            }

            void operator delete[](void* ptr)
            {
                tAllocator::Deallocate(ptr);
            }

            //////////////////////////////////////////////////////////////////////////
            ///==============================STANDARD==============================///
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            ///============================DEBUG inFO==============================///
            //////////////////////////////////////////////////////////////////////////
            /// with debug info
            /// operator new, with debug line info
            void* operator new(size_t sz, const char* file, int line, const char* func)
            {
                return tAllocator::AllocateWithDebugInfo(sz, file, line, func);
            }

            /// array operator new, with debug line info
            void* operator new[](size_t sz, const char* file, int line, const char* func)
            {
                return tAllocator::AllocateWithDebugInfo(sz, file, line, func);
            }

            // only called if there is an exception in corresponding 'new'
            void operator delete(void* ptr, const char*, int, const char*)
            {
                tAllocator::DeallocateWithDebugInfo(ptr);
            }

            void operator delete[](void* ptr, const char*, int, const char*)
            {
                tAllocator::DeallocateWithDebugInfo(ptr);
            }
            //////////////////////////////////////////////////////////////////////////
            ///============================DEBUG inFO==============================///
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            ///============================PLACEMENT===============================///
            //////////////////////////////////////////////////////////////////////////

            /// placement operator new
            void* operator new(size_t sz, void* placement_ptr)
            {
                (void)sz;
                return placement_ptr;
            }

            // Corresponding operator for placement delete (second param same as the first)
            void operator delete(void* ptr, void*)
            {
                tAllocator::Deallocate(ptr);
            }

            //////////////////////////////////////////////////////////////////////////
            ///=========================PLACEMENT==================================///
            //////////////////////////////////////////////////////////////////////////
        };
    } /// end of namespace MemObj
}

////////////////////////////////////////////////////////////////////////////

#endif /*__WIZ_BASIC_MEMOBJ_HPP__SHANHAOBO_19800429__*/
