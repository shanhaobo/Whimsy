#ifndef __WIZ_MEM_ALLOCATOR_HPP__SHANHAOBO_19800429__
#define __WIZ_MEM_ALLOCATOR_HPP__SHANHAOBO_19800429__

#include "./WizBasicMemAllocatorDefault.hpp"

#include "./WizBasicMemAllocatorSTLBase.hpp"

namespace Wiz
{
    namespace Allocator
    {
        /// 这里选择使用哪个Allocator
        typedef Allocator::Default::Type                         Type;

        //////////////////////////////////////////////////////////////////////////

        /// 基本使用
        WIZ_INLINE::Wiz::Void::Ptr AllocateWithDebugInfo(size_t inSZInByte, char const * inFileName, int inLine, char const * inFuncName)
        {
            return Allocator::Type::AllocateWithDebugInfo(inSZInByte, inFileName, inLine, inFuncName);
        }

        WIZ_INLINE::Wiz::Void::Type DeallocateWithDebugInfo(void* ptr)
        {
            Allocator::Type::DeallocateWithDebugInfo(ptr, WIZ_NULLPTR, 0, WIZ_NULLPTR);
        }

        WIZ_INLINE::Wiz::Void::Ptr Allocate(size_t sz)
        {
            return Allocator::Type::Allocate(sz);
        }

        WIZ_INLINE::Wiz::Void::Type Deallocate(void* ptr)
        {
            Allocator::Type::Deallocate(ptr);
        }

        //////////////////////////////////////////////////////////////////////////

        /// STL的Allocator
        template<class ElementT>
        struct STL : public Allocator::STLBase::Type<ElementT, Allocator::Type>
        {
            typedef typename Allocator::STL<ElementT>            Type;
        };

        /// 有分类功能的Allocator
        template<typename ICat>
        struct Categorized : public Allocator::Type
        {
            typedef typename Allocator::Categorized<ICat>        Type;
        };

        /// 有分类功能的STL的Allocator
        template<class ElementT, typename ICat>
        struct STLCategorized : public Allocator::STL<ElementT>::Type
        {
            typedef typename Allocator::STLCategorized<ElementT, ICat>   Type;
        };

        //////////////////////////////////////////////////////////////////////////

        /// 临时工具
        template<typename T>
        T* ConstructN(T* basePtr, size_t count)
        {
            for (size_t i = 0; i < count; ++i)
            {
                new ((void*)(basePtr + i)) T();
            }

            return basePtr;
        }

    } /// end of namespace Allocator
} /// end of namespace Wiz

/// Allocator Category Define
#   define  WIZ_ACD(inName)                                     enum inName{};

//////////////////////////////////////////////////////////////////////////
/// New & Del
//////////////////////////////////////////////////////////////////////////
#   define  WIZ_NEW                                             new (WIZ_FILE, WIZ_LINE, WIZ_FUNC)
#   define  WIZ_DEL                                             delete

//////////////////////////////////////////////////////////////////////////
/// General
//////////////////////////////////////////////////////////////////////////
#if  (WIZ_DEBUG_MODE == WIZ_CFG_TRUE)
#   define  WIZ_MALLOC(inSZInByte)                              ::Wiz::Allocator::AllocateWithDebugInfo(inSZInByte, WIZ_FILE, WIZ_LINE, WIZ_FUNC)
#   define  WIZ_FREE(MemPtr)                                    ::Wiz::Allocator::DeallocateWithDebugInfo((void*)MemPtr)
#else
#   define  WIZ_MALLOC(inSZInByte)                              ::Wiz::Allocator::Allocate(inSZInByte)
#   define  WIZ_FREE(MemPtr)                                    ::Wiz::Allocator::Deallocate((void*)MemPtr)
#endif

#   define  WIZ_MALLOC_T(inType)                                static_cast<inType*>(WIZ_MALLOC(sizeof(inType)))
#   define  WIZ_MALLOC_ARRAY_T(inType, inCnt)                   static_cast<inType*>(WIZ_MALLOC(sizeof(inType) * inCnt))

#   define  WIZ_NEW_T(inType)                                   new (WIZ_MALLOC(sizeof(inType))) inType
#   define  WIZ_DEL_T(MemPtr, inType)                           if (MemPtr) {(MemPtr)->~inType(); WIZ_FREE(MemPtr);}

#   define  WIZ_NEW_ARRAY_T(inType, inCnt)                      ::Wiz::Allocator::ConstructN<inType(WIZ_MALLOC_ARRAY_T(inType, inCnt), inCnt);
#   define  WIZ_DEL_ARRAY_T(MemPtr, inType, inCnt)              if(MemPtr) {for (size_t i = 0; i < inCnt; ++i){MemPtr[i].~inType();} WIZ_FREE(MemPtr);}

//////////////////////////////////////////////////////////////////////////
/// With_Cat
//////////////////////////////////////////////////////////////////////////
#if  (WIZ_DEBUG_MODE == WIZ_CFG_TRUE)
#   define  WIZ_MALLOC_CAT(inSZInByte, inCat)                   ::Wiz::Allocator::Categorized<inCat>::AllocateWithDebugInfo(inSZInByte, WIZ_FILE, WIZ_LINE, WIZ_FUNC)
#   define  WIZ_FREE_CAT(MemPtr, inCat)                         ::Wiz::Allocator::Categorized<inCat>::DeallocateWithDebugInfo((void*)MemPtr)
#else
#   define  WIZ_MALLOC_CAT(inSZInByte, inCat)                   ::Wiz::Allocator::Categorized<inCat>::Allocate(inSZInByte)
#   define  WIZ_FREE_CAT(MemPtr, inCat)                         ::Wiz::Allocator::Categorized<inCat>::Deallocate((void*)MemPtr)
#endif

#   define  WIZ_MALLOC_T_CAT(inType, inCat)                     static_cast<inType*>(WIZ_MALLOC_CAT(sizeof(inType), inCat))
#   define  WIZ_MALLOC_ARRAY_T_CAT(inType, inCnt, inCat)        static_cast<inType*>(WIZ_MALLOC_CAT(sizeof(inType) * inCnt, inCat))

#   define  WIZ_NEW_T_CAT(inType, inCat)                        new (WIZ_MALLOC_CAT(sizeof(inType), inCat)) inType
#   define  WIZ_DEL_T_CAT(MemPtr, inType, inCat)                if(MemPtr) {(MemPtr)->~inType(); WIZ_FREE_CAT(MemPtr, inCat);}

#   define  WIZ_NEW_ARRAY_T_CAT(inType, inCnt, inCat)           ::Wiz::Allocator::ConstructN<inType>(WIZ_MALLOC_ARRAY_T_CAT(inType, inCnt, inCat), inCnt);
#   define  WIZ_DEL_ARRAY_T_CAT(MemPtr, inType, inCnt, inCat)   if(MemPtr) {for (size_t i = 0; i < inCnt; ++i){MemPtr[i].~inType();} WIZ_FREE_CAT(MemPtr, inCat);}

#endif /*__WIZ_MEM_ALLOCATOR_HPP__SHANHAOBO_19800429__*/
