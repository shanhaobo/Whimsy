#ifndef __WIZ_BASIC_TU_NONCOPYABLE_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TU_NONCOPYABLE_HPP__SHANHAOBO_19800429__

namespace Wiz
{
    //////////////////////////////////////////////////////////////////////////
    /// NONCOPYABLE FROM boost
    namespace Noncopyable
    {
        class Type
        {
        protected:
            Type() {}
            ~Type() {}

        private:  // emphasize the following members are private
            Type(Type const &);
            Type & operator=(Type const &);
        };
    } /// end of namespace Noncopyable
    //////////////////////////////////////////////////////////////////////////
} /// end of namespace Wiz

#endif /*__WIZ_BASIC_TU_NONCOPYABLE_HPP__SHANHAOBO_19800429__*/
