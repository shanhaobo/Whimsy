#ifndef __WHIMSY_TYPEDECLAREUTILS_HPP__SHANHAOBO_19800429__
#define __WHIMSY_TYPEDECLAREUTILS_HPP__SHANHAOBO_19800429__

////////////////////////////////////////////////////////////////////////////

#   define WMS_DECLARE_TYPE_STDNAME(t)  \
    typedef t           type;

#   define WMS_DECLARE_TYPE_CONST(t)    \
    typedef t const     typec;

#   define WMS_DECLARE_PTR(t)           \
    typedef t *         ptr;            \
    typedef t const *   ptrc;           \
    typedef t * const   ptrf;           \
    typedef t const * const  ptrfc;

#   define WMS_DECLARE_REF(t)           \
    typedef t &         ref;            \
    typedef t const &   refc;

#   define WMS_DECLARE_PARAM(t)         \
    typedef t const &   in;             \
    typedef t &         out;            \
    typedef t &         io;

#   define WMS_DECLARE_PARAM_SIMPLE(t)  \
    typedef t const     in;             \
    typedef t &         out;            \
    typedef t &         io;

////////////////////////////////////////////////////////////////////////////

#   define WMS_DECLARE_TYPE(t)          \
    WMS_DECLARE_TYPE_STDNAME(t);        \
    WMS_DECLARE_TYPE_CONST(t)

#   define WMS_DECLARE_BASE(t)          \
    WMS_DECLARE_TYPE(t)                 \
    WMS_DECLARE_PTR(t)                  \
    WMS_DECLARE_REF(t)

#   define WMS_DECLARE(t)               \
    WMS_DECLARE_BASE(t)                 \
    WMS_DECLARE_PARAM(t)

#   define WMS_DECLARE_SIMPLE(t)        \
    WMS_DECLARE_BASE(t)                 \
    WMS_DECLARE_PARAM_SIMPLE(t)

////////////////////////////////////////////////////////////////////////////

#   define WMS_FORWARD_DECLARE(t)       \
    WMS_DECLARE_TYPE_CONST(t)           \
    WMS_DECLARE_PTR(t)                  \
    WMS_DECLARE_REF(t)                  \
    WMS_DECLARE_PARAM(t)

#   define WMS_FORWARD_DECLARE_CLASS    \
    class type;                         \
    WMS_FORWARD_DECLARE(type)

#   define WMS_FORWARD_DECLARE_STRUCT   \
    struct type;                        \
    WMS_FORWARD_DECLARE(type)

////////////////////////////////////////////////////////////////////////////

#   define WMS_CLASS                    \
    class type;                         \
    WMS_FORWARD_DECLARE(type)           \
    class type

#   define WMS_STRUCT                   \
    struct type;                        \
    WMS_FORWARD_DECLARE(type)           \
    struct type

////////////////////////////////////////////////////////////////////////////

#   define WMS_DECLARE_ITER(t)          \
    typedef t                           itr;

#   define WMS_DECLARE_ITER_CONST(t)    \
    typedef t                           itrc;

////////////////////////////////////////////////////////////////////////////

#endif /*__WHIMSY_TYPEDECLAREUTILS_HPP__SHANHAOBO_19800429__*/
