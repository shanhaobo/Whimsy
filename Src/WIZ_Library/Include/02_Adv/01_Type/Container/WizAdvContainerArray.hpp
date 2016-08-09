#ifndef __WIZ_ADV_CONTAINER_ARRAY_HPP__SHANHAOBO_19800429__
#define __WIZ_ADV_CONTAINER_ARRAY_HPP__SHANHAOBO_19800429__

#include "./WizAdvContainerBase.hpp"

#include <vector>

namespace Wiz
{
    namespace Array
    {
        template< class ElementT, class AllocatorT = ::std::allocator<ElementT> >
        class Type : public ::Wiz::Container::SimpleBase< Type<ElementT, AllocatorT>, ::std::vector<ElementT, AllocatorT> >
        {
        public:
            //////////////////////////////////////////////////////////////////////////

            typedef typename Type<ElementT, AllocatorT>                         tThis;

            typedef typename ::std::vector<ElementT, AllocatorT>                tSuper;

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

            typedef typename tSuper::reverse_iterator                           tReverseIterator;
            typedef typename tSuper::const_reverse_iterator                     tReverseIteratorConst;

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

            tReverseIterator RBegin()
            {
                return tSuper::rbegin();
            }

            tReverseIteratorConst RBegin() const
            {
                return tSuper::rbegin();
            }

            tReverseIterator REnd()
            {
                return tSuper::rend();
            }

            tReverseIteratorConst REnd() const
            {
                return tSuper::rend();
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

            ///-----------------------///

            tReferenceConst Front() const
            {
                return tSuper::front();
            }

            tReference Front()
            {
                return tSuper::front();
            }

            tReferenceConst Back() const
            {
                return tSuper::back();
            }

            tReference Back()
            {
                return tSuper::back();
            }

            ///-----------------------///

            tSize Capacity()
            {
                return tSuper::capacity();
            }

            ::Wiz::Void::Type Reserve(tSize SZ)
            {
                tSuper::reserve(SZ);
            }

            ///-----------------------///

            tReference operator[](tSize Pos)
            {
                return tSuper::operator [](Pos);
            }

            tReferenceConst operator[](tSize Pos) const
            {
                return tSuper::operator [](Pos);
            }

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

        public:
            tElementPtr GetBuffer()
            {
                return &(tSuper::operator [](0));
            }

            tElementConstPtr GetBuffer() const
            {
                return &(tSuper::operator [](0));
            }
        }; /// end of class Type
    } /// end of namespace Array
} /// end of namespace Wiz

#endif /*__WIZ_ADV_CONTAINER_ARRAY_HPP__SHANHAOBO_19800429__*/
