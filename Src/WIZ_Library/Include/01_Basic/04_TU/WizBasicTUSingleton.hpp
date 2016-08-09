#ifndef __WIZ_BASIC_TU_SINGLETON_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TU_SINGLETON_HPP__SHANHAOBO_19800429__

#include "./WizBasicTUNoncopyable.hpp"

///////////////////////////////////////////////////////////////////////////
//////////////////////////// general singleton ////////////////////////////
///////////////////////////////////////////////////////////////////////////

namespace Wiz
{
    /// Singleton
    namespace Singleton
    {
        template <class T>
        class Type : private Noncopyable::Type
        {
        private:
            Type()
            {

            }

            ~Type()
            {

            }

        public:
            static T & instance()
            {
                static T s_T;

                return s_T;
            }

            static T * instancePtr()
            {
                return &instance();
            }
        };
    } /// end of namespace Singleton
} /// end of namespace Wiz

#define WIZ_SINGLETON_DECLARE(ManagedT)                         \
    WIZ_INLINE ManagedT & instance()                            \
    {                                                           \
        return ::Wiz::Singleton::Type<ManagedT>::instance();    \
    }                                                           \
    WIZ_INLINE ManagedT * instancePtr()                         \
    {                                                           \
        return ::Wiz::Singleton::Type<ManagedT>::instancePtr(); \
    }

///////////////////////////////////////////////////////////////////////////
//////////////////////////  singleton with init ///////////////////////////
///////////////////////////////////////////////////////////////////////////

namespace Wiz
{
    /// SingletonInit
    namespace SingletonInit
    {
        template <class T>
        class Type : private Noncopyable::Type
        {
            typedef T * tPtr;
        private:
            static tPtr& Data()
            {
                static tPtr s_Ptr = 0;
                return s_Ptr;
            }
        private:
            Type()
            {
            }
            ~Type()
            {
            }
        public:
            static void init(tPtr inPtr)
            {
                Data() = inPtr;
            }
        public:
            static T & instance()
            {
                return *(Data());
            }
            static tPtr instancePtr()
            {
                return Data();
            }
        };
    } /// end of namespace SingletonInit
} /// end of namespace Wiz

#define WIZ_SINGLETONINIT_DECLARE(ManagedT)                             \
    WIZ_INLINE void init(ManagedT* inMngPtr)                            \
{                                                                   \
    ::Wiz::SingletonInit::Type<ManagedT>::init(inMngPtr);           \
}                                                                   \
    WIZ_INLINE ManagedT & instance()                                    \
{                                                                   \
    return ::Wiz::SingletonInit::Type<ManagedT>::instance();        \
}                                                                   \
    WIZ_INLINE ManagedT * instancePtr()                                 \
{                                                                   \
    return ::Wiz::SingletonInit::Type<ManagedT>::instancePtr();     \
}

#endif /*__WIZ_BASIC_TU_SINGLETON_HPP__SHANHAOBO_19800429__*/
