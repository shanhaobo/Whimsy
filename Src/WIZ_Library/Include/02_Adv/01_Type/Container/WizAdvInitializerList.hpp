#ifndef __WIZ_ADV_INITIALIZERLIST_HPP__SHANHAOBO_19800429__
#define __WIZ_ADV_INITIALIZERLIST_HPP__SHANHAOBO_19800429__

#include "./WizAdvContainerBase.hpp"

#include <initializer_list>

namespace Wiz
{
#if 0
    namespace InitializerList
    {
        template<class T>
        struct Type : public ::std::initializer_list<T>
        {
            typedef ::std::initializer_list<T>  tSuper;

            typedef T                           tValue;
            typedef tValue *                    tValuePtr;
            typedef tValue const *              tValuePtrC;
            typedef tValuePtr const             tValuePtrF;

            typedef tValuePtrC                  tIterator;
            typedef tValuePtrC                  tIteratorConst;

            typedef size_t                      tSize;

            Type(tSuper inSuper) : tSuper(inSuper.begin(), inSuper.end())
            {

            }

            operator tSuper()
            {
                return *this;
            }

            tIterator Begin() const
            {
                return tSuper::begin();
            }

            tIterator End() const
            {
                return tSuper::end();
            }

            tSize Size() const
            {
                return tSuper::size();
            }
        };
    } /// end of namespace InitializerList
#else
    template <typename ElementT>
    struct InitializerList
    {
        typedef typename ::std::initializer_list<ElementT>  Type;
    };
#endif 
} /// end of namespace Wiz

#endif /*__WIZ_ADV_INITIALIZERLIST_HPP__SHANHAOBO_19800429__*/
