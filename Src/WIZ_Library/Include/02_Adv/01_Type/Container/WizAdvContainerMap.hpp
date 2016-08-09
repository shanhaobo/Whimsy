#ifndef __WIZ_ADV_CONTAINER_MAP_HPP__SHANHAOBO_19800429__
#define __WIZ_ADV_CONTAINER_MAP_HPP__SHANHAOBO_19800429__

#include "./WizAdvContainerBase.hpp"

#include <map>

namespace Wiz
{
    namespace Map
    {
        template< class indexT, class ValueT, class CompT = ::std::less<indexT>, class AllocatorT = ::std::allocator< ::std::pair<const indexT, ValueT> > >
        class Type : public ::Wiz::Container::MapBase< indexT, ValueT, CompT, Type<indexT, ValueT, CompT, AllocatorT>, ::std::map<indexT, ValueT, CompT, AllocatorT> >
        {
        public:
            ////////////////////////////////////////////////////////////////////////

            typedef typename Type<indexT, ValueT, CompT, AllocatorT>                            tThis;

            typedef typename ::std::map<indexT, ValueT, CompT, AllocatorT>                      tSuper;

            typedef typename ::Wiz::Container::MapBase<indexT, ValueT, CompT, tThis, tSuper>    tContainerBase;

            //////////////////////////////////////////////////////////////////////////

            typedef typename AllocatorT                                                         tAllocator;

            //////////////////////////////////////////////////////////////////////////

        public:
            Type() : tContainerBase()
            {
            }

            Type(tSuper const & inSuper) : tContainerBase(inSuper)
            {
            }

            //////////////////////////////////////////////////////////////////////////
        public:
            ::Wiz::Bool::Type Remove(tIndexIn inIdx)
            {
                tIterator FndItr = Find(inIdx);
                if (FndItr == End())
                {
                    return ::Wiz::Bool::False;
                }

                Erase(FndItr);

                return ::Wiz::Bool::True;
            }

            tIterator Pop(tIndexIn inIdx)
            {
                tIterator FndItr = Find(inIdx);
                if (FndItr == End())
                {
                    return End();
                }

                return Erase(FndItr);
            }

            ///-----------------------///

            tIterator Find(tIndexIn inIdx)
            {
                return tSuper::find(inIdx);
            }

            tIteratorConst Find(tIndexIn inIdx) const
            {
                return tSuper::find(inIdx);
            }

            ///-----------------------///

            ::Wiz::Bool::Type HasData(tIndexIn inIdx) const
            {
                return tSuper::find(inIdx) != tSuper::end();
            }

            ///-----------------------///

            ::Wiz::Bool::Type TryGet(tValueOut outV, tIndexIn inIdx)
            {
                tIterator FndItr = Find(inIdx);
                if (FndItr == End())
                {
                    return ::Wiz::Bool::False;
                }

                outV = FndItr.Value();

                return ::Wiz::Bool::True;
            }

            ValueT* TryGetPtr(tIndexIn inIdx)
            {
                tIterator FndItr = Find(inIdx);
                if (FndItr == End())
                {
                    return WIZ_NULL;
                }

                return &(FndItr.Value());
            }

            ///-----------------------///

            tIterator insert(tIndexIn inIdx, tValueIn inVl)
            {
                return tSuper::insert(tPair(inIdx, inVl)).first;
            }

            ::Wiz::Bool::Type insert(tIterator& outItr, tIndexIn inIdx, tValueIn inVl)
            {
                ::std::pair<tIterator, ::Wiz::Bool::Type> Result = tSuper::insert(tPair(inIdx, inVl));
                outItr = Result.first;
                return Result.second;
            }

            ::Wiz::Bool::Type insertUnique(tIterator& outItr, tIndexIn inIdx, tValueIn inVl)
            {
                if (Find(inIdx) == End())
                {
                    outItr = insert(inIdx, inVl);
                    return ::Wiz::Bool::True;
                }
                return ::Wiz::Bool::False;
            }

            ::Wiz::Bool::Type insertUnique(tIndexIn inIdx, tValueIn inVl)
            {
                tIterator DummyItr;
                return insertUnique(DummyItr, inIdx, inVl);
            }

            //////////////////////////////////////////////////////////////////////////
        };
    } /// end of namespace Map
} /// end of namespace Wiz

#endif /*__WIZ_ADV_CONTAINER_MAP_HPP__SHANHAOBO_19800429__*/
