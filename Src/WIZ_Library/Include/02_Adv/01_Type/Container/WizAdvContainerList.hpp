#ifndef __WIZ_ADV_CONTAINER_LIST_HPP__SHANHAOBO_19800429__
#define __WIZ_ADV_CONTAINER_LIST_HPP__SHANHAOBO_19800429__

#include "./WizAdvContainerBase.hpp"

#include <list>

namespace Wiz
{
    namespace List
    {
        template<class ElementT, class AllocatorT = ::std::allocator<ElementT> >
        class Type : public ::Wiz::Container::SimpleBase< Type<ElementT, AllocatorT>, ::std::list<ElementT, AllocatorT> >
        {
        public:
            //////////////////////////////////////////////////////////////////////////

            typedef typename Type<ElementT, AllocatorT>                         tThis;

            typedef typename ::std::list<ElementT, AllocatorT>                  tSuper;

            typedef typename ::Wiz::Container::SimpleBase< tThis, tSuper >      tContainerBase;

            //////////////////////////////////////////////////////////////////////////

            typedef typename ElementT                                           tElement;
            typedef typename tElement const                                     tElementConst;

            typedef typename ElementT *                                         tElementPtr;
            typedef typename ElementT const *                                   tElementConstPtr;

            typedef typename tElement const &                                   tElementIn;

            //////////////////////////////////////////////////////////////////////////

            typedef typename AllocatorT                                         tAllocator;

            //////////////////////////////////////////////////////////////////////////

        public:
            Type() : tContainerBase()
            {}

            Type(tSuper const & inSuper) : tContainerBase(inSuper)
            {}

            Type(tInitList inInitList) : tContainerBase(inInitList)
            {}

            Type(tSize inSize) : tContainerBase(inSize)
            {}
        public:

            ///-----------------------///

            tIterator Find(tElementIn v)
            {
                return tSuper::find(v);
            }

            tIteratorConst Find(tElementIn v) const
            {
                return tSuper::find(v);
            }

            ::Wiz::Bool::Type Find(tElementIn v, tIterator& OItr)
            {
                OItr = Find(v);
                return OItr != End();
            }

            ::Wiz::Bool::Type Find(tElementIn v, tIteratorConst& OItr) const
            {
                OItr = Find(v);
                return OItr != End();
            }

            ///-----------------------///

            ::Wiz::Bool::Type HasData(tElementIn v) const
            {
                return tSuper::find(v) != End();
            }

            ///-----------------------///

            ::Wiz::Bool::Type Remove(tElementIn inELT)
            {
                tIterator FndItr;

                if (Find(inELT, FndItr))
                {
                    Erase(FndItr);

                    return ::Wiz::Bool::True;
                }

                return ::Wiz::Bool::False;
            }

            ::Wiz::Bool::Type Remove(tElementIn inELT, tIterator& OItr)
            {
                tIterator FndItr;

                if (Find(inELT, FndItr))
                {
                    OItr = Erase(FndItr);

                    return ::Wiz::Bool::True;
                }

                return ::Wiz::Bool::False;
            }

            ///-----------------------///

            ::Wiz::Void::Type PushBack(tElementIn v)
            {
                tSuper::push_back(v);
            }

            ::Wiz::Void::Type PopBack()
            {
                tSuper::pop_back();
            }

            ::Wiz::Void::Type PushFront(tElementIn v)
            {
                tSuper::push_front(v);
            }

            ::Wiz::Void::Type PopFront()
            {
                tSuper::pop_front();
            }

            ::Wiz::Void::Type Sort()
            {
                tSuper::sort();
            }

            ///-----------------------///

            tReference Front()
            {
                return tSuper::front();
            }

            tReference Back()
            {
                return tSuper::back();
            }

            tReferenceConst Front() const
            {
                return tSuper::front();
            }

            tReferenceConst Back() const
            {
                return tSuper::back();
            }
        };
    } /// end of namespace List
} /// end of namespace Wiz

#endif /*__WIZ_ADV_CONTAINER_LIST_HPP__SHANHAOBO_19800429__*/
