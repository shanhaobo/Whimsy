#ifndef __WIZ_ADV_CONTAINER_LINKLIST_HPP__SHANHAOBO_19800429__
#define __WIZ_ADV_CONTAINER_LINKLIST_HPP__SHANHAOBO_19800429__

#include "./WizAdvContainerBase.hpp"

namespace Wiz
{
    namespace LinkList
    {
        template<class ElementT>
        class Type
        {
            //////////////////////////////////////////////////////////////////////////

            typedef typename ElementT                                           tElement;
            typedef typename tElement const                                     tElementConst;

            typedef typename ElementT *                                         tElementPtr;
            typedef typename ElementT const *                                   tElementConstPtr;

            typedef typename tElement const &                                   tElementIn;

            //////////////////////////////////////////////////////////////////////////

        public:
            Type()
            {}
        public:

        };
    } /// end of namespace LinkList
} /// end of namespace Wiz

#endif /*__WIZ_ADV_CONTAINER_LIST_HPP__SHANHAOBO_19800429__*/
