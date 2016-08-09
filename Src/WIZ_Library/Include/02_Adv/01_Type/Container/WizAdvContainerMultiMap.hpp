#ifndef __WIZ_ADV_CONTAINER_MULTIMAP_HPP__SHANHAOBO_19800429__
#define __WIZ_ADV_CONTAINER_MULTIMAP_HPP__SHANHAOBO_19800429__

#include "./WizAdvContainerBase.hpp"

#include <map>

namespace Wiz
{
    namespace MultiMap
    {
        template< class indexT, class ValueT, class CompT = ::std::less<indexT>, class AllocatorT = ::std::allocator< ::std::pair<const indexT, ValueT> >  >
        class Type : public ::Wiz::Container::MapBase< indexT, ValueT, CompT, Type<indexT, ValueT, CompT, AllocatorT>, ::std::multimap<indexT, ValueT, CompT, AllocatorT> >
        {
        public:
            ////////////////////////////////////////////////////////////////////////

            typedef typename Type<indexT, ValueT, CompT, AllocatorT>                            tThis;

            typedef typename ::std::multimap<indexT, ValueT, CompT, AllocatorT>                 tSuper;

            typedef typename ::Wiz::Container::MapBase<indexT, ValueT, CompT, tThis, tSuper>    tContainerBase;

            /////////////////////////////////////////////////////////////////////////

            typedef typename AllocatorT                                                         tAllocator;

            ////////////////////////////////////////////////////////////////////////

        public:
            Type() : tContainerBase()
            {
            }

            Type(tSuper const & inSuper) : tContainerBase(inSuper)
            {
            }
            //////////////////////////////////////////////////////////////////////////
        public:

            ::Wiz::Bool::Type Remove(tIndexIn v)
            {
                tIterator Found = Find(v);
                if (Found == End())
                {
                    return ::Wiz::Bool::False;
                }

                Erase(Found);

                return ::Wiz::Bool::True;
            }

            tIterator Pop(tIndexIn v)
            {
                tIterator Found = Find(v);
                if (Found == End())
                {
                    return End();
                }

                return Erase(Found);
            }

            ///-----------------------///

            ::Wiz::Bool::Type HasData(tIndexIn v) const
            {
                return tSuper::find(v) != tSuper::end();
            }

            ///-----------------------///

            ::Wiz::Size::Type CountBound(tIndexIn v)
            {
                return tSuper::count(v);
            }

            tIterator LowerBound(tIndexIn v)
            {
                return tSuper::lower_bound(v);
            }

            tIterator UpperBound(tIndexIn v)
            {
                return tSuper::upper_bound(v);
            }

            ///-----------------------///

            tIterator insert(tIndexIn f, tValueIn s)
            {
                return tSuper::insert(tPair(f, s)).first;
            }

            ::Wiz::Bool::Type insert(tIterator& outItr, tIndexIn f, tValueIn s)
            {
                ::std::pair<tIterator, ::Wiz::Bool::Type> Result = tSuper::insert(tPair(f, s));
                outItr = Result.first;
                return Result.second;
            }

            ::Wiz::Bool::Type insertUnique(tIterator& outItr, tIndexIn Idx, tValueIn Val)
            {
                if (this->Find(Idx) == this->End())
                {
                    outItr = this->insert(Idx, Val);
                    return ::Wiz::Bool::True;
                }
                return ::Wiz::Bool::False;
            }

            ::Wiz::Bool::Type insertUnique(tIndexIn Idx, tValueIn Val)
            {
                tIterator DummyItr;
                return insertUnique(DummyItr, Idx, Val);
            }

            //////////////////////////////////////////////////////////////////////////
        };
    } /// end of namespace MultiMap
} /// end of namespace Wiz

#endif /*__WIZ_ADV_CONTAINER_MULTIMAP_HPP__SHANHAOBO_19800429__*/
