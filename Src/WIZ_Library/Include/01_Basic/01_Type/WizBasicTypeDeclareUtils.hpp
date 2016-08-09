#ifndef __WIZ_BASIC_CORE_DECLARE_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_CORE_DECLARE_HPP__SHANHAOBO_19800429__

#include "../../00_Config/WizConfig.hpp"

////////////////////////////////////////////////////////////////////////////

#   define WIZ_DECLARE_STDNAME_TYPE                 Type

#   define WIZ_DECLARE_TYPE_STDNAME(t)              \
    typedef t                   WIZ_DECLARE_STDNAME_TYPE;

#   define WIZ_DECLARE_TYPE_CONST(t)                \
    typedef t const             TypeC;

#   define WIZ_DECLARE_PTR(t)                       \
    typedef t *                 Ptr;                \
    typedef t const *           PtrC;               \
    typedef t * const           PtrF;               \
    typedef t const * const     PtrFC;

#   define WIZ_DECLARE_REF(t)                       \
    typedef t &                 Ref;                \
    typedef t const &           RefC;

#   define WIZ_DECLARE_PARAM(t)                     \
    typedef t const &           In;                 \
    typedef t &                 Out;                \
    typedef t &                 IO;

#   define WIZ_DECLARE_PARAM_SIMPLE(t)              \
    typedef t const             In;                 \
    typedef t &                 Out;                \
    typedef t &                 IO;

////////////////////////////////////////////////////////////////////////////

#   define WIZ_DECLARE_TYPE(t)                      \
    WIZ_DECLARE_TYPE_STDNAME(t);                    \
    WIZ_DECLARE_TYPE_CONST(t)

#   define WIZ_DECLARE_BASE(t)                      \
    WIZ_DECLARE_TYPE(t)                             \
    WIZ_DECLARE_PTR(t)                              \
    WIZ_DECLARE_REF(t)

#   define WIZ_DECLARE(t)                           \
    WIZ_DECLARE_BASE(t)                             \
    WIZ_DECLARE_PARAM(t)

#   define WIZ_DECLARE_SIMPLE(t)                    \
    WIZ_DECLARE_BASE(t)                             \
    WIZ_DECLARE_PARAM_SIMPLE(t)

#   define WIZ_DECLARE_IN_STDCLASS(t)                \
    WIZ_DECLARE_TYPE_CONST(t)                       \
    WIZ_DECLARE_PTR(t)                              \
    WIZ_DECLARE_REF(t)                              \
    WIZ_DECLARE_PARAM(t)

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

#   define WIZ_FORWARD_DECLARE(t)                   \
    WIZ_DECLARE_TYPE_CONST(t)                       \
    WIZ_DECLARE_PTR(t)                              \
    WIZ_DECLARE_REF(t)                              \
    WIZ_DECLARE_PARAM(t)

#   define WIZ_FORWARD_DECLARE_CLASS                \
    class WIZ_DECLARE_STDNAME_TYPE;                 \
    WIZ_FORWARD_DECLARE(WIZ_DECLARE_STDNAME_TYPE)

#   define WIZ_FORWARD_DECLARE_STRUCT               \
    struct WIZ_DECLARE_STDNAME_TYPE;                \
    WIZ_FORWARD_DECLARE(WIZ_DECLARE_STDNAME_TYPE)

////////////////////////////////////////////////////////////////////////////

#   define WIZ_CLASS                                \
    class WIZ_DECLARE_STDNAME_TYPE;                 \
    WIZ_FORWARD_DECLARE(WIZ_DECLARE_STDNAME_TYPE)   \
    class WIZ_DECLARE_STDNAME_TYPE

#   define WIZ_STRUCT                               \
    struct WIZ_DECLARE_STDNAME_TYPE;                \
    WIZ_FORWARD_DECLARE(WIZ_DECLARE_STDNAME_TYPE)   \
    struct WIZ_DECLARE_STDNAME_TYPE

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

#   define WIZ_DECLARE_ITER(itr)                    \
    typedef itr                                     Iterator;

#   define WIZ_DECLARE_ITER_CONST(itr)              \
    typedef itr                                     IteratorC;

#endif /*__WIZ_BASIC_CORE_DECLARE_HPP__SHANHAOBO_19800429__*/
