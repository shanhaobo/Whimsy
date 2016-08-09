#ifndef __WIZ_BASIC_TU_CALL_PROXY_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TU_CALL_PROXY_HPP__SHANHAOBO_19800429__

#include "./WizBasicTUNoncopyable.hpp"

namespace Wiz
{
    namespace CallProxy
    {
        template <class T>
        class Type : private Noncopyable::Type
        {
            typedef Type<T> tThis;
            typedef tThis*  tThisPtr;

            typedef T* tPtr;
            typedef T& tRef;

            tPtr ManagedPtr;

            class tProxy
            {
                friend class Type<T>;

                tThisPtr OwnerPtr;
                tPtr     ManagedPtr;

            protected:
                tProxy(tPtr inPtr, tThisPtr inOwnerPtr) : OwnerPtr(inOwnerPtr), ManagedPtr(inPtr)
                {

                }
            public:
                ~tProxy()
                {
                    OwnerPtr->Post();
                }

                tPtr operator->() const
                {
                    return ManagedPtr;
                }
            };

        protected:
            virtual Void::Type Prev() = 0;
            virtual Void::Type Post() = 0;

        public:
            Type(tRef inObjRef) : ManagedPtr(&inObjRef)
            {

            }
            Type(tPtr inObjPtr) : ManagedPtr(inObjPtr)
            {

            }

            tProxy operator->()
            {
                Prev();
                return tProxy(ManagedPtr, this);
            }
        };
    } /// end of namespace CallProxy
} /// end of namespace Wiz

#endif /*__WIZ_BASIC_TU_CALL_PROXY_HPP__SHANHAOBO_19800429__*/
