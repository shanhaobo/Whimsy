#ifndef __WIZ_MEM_ALLOCATOR_BASE_HPP__SHANHAOBO_19800429__
#define __WIZ_MEM_ALLOCATOR_BASE_HPP__SHANHAOBO_19800429__

#include "./WizBasicMemRecorder.hpp"

namespace Wiz
{
    namespace Allocator
    {
        namespace Base
        {
            template<class DerivedT>
            class Type
            {
            public:
                typedef typename DerivedT       tDerived;

                typedef typename Type<tDerived> tThis;

                WIZ_DECLARE_IN_STDCLASS(tThis);

            public:
                ///////////////////////////////////////////
                /// With Debug info
                static ::Wiz::Void::Ptr AllocateWithDebugInfo(size_t inSZInByte, char const * inFileName, int inLine, char const * inFuncName)
                {
                    ::Wiz::Void::Ptr MemPtr = tDerived::Allocate(inSZInByte);
                    if (::Wiz::IsValidPtr(MemPtr))
                    {
                        ::Wiz::MemRecorder::Alloc(MemPtr, inSZInByte, inFileName, inLine, inFuncName);

                        return MemPtr;
                    }
                    return WIZ_NULL;
                }

                /// With Debug info
                static ::Wiz::Void::Type DeallocateWithDebugInfo(void* MemPtr, const char* inFileName = WIZ_NULL, int inLine = 0, const char* inFuncName = WIZ_NULL)
                {
                    if (::Wiz::IsValidPtr(MemPtr))
                    {
                        tDerived::Deallocate(MemPtr);

                        ::Wiz::MemRecorder::Dealloc(MemPtr);
                    }
                }
                ///////////////////////////////////////////
            }; /// end of class Type
        }  /// end of namespace Base
    } /// end of namespace Allocator
} /// end of namespace Wiz

#endif /*__WIZ_MEM_ALLOCATOR_BASE_HPP__SHANHAOBO_19800429__*/
