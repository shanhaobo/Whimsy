#ifndef __WHIMSY_COLOR_U32_HPP__SHANHAOBO_19800429__
#define __WHIMSY_COLOR_U32_HPP__SHANHAOBO_19800429__

#include "./WMSType.hpp"

namespace wms
{
    namespace RGBA
    {
        WMS_STRUCT
        {
            union
            {
                struct
                {
#           if (WIZ_CFG_ENDIAN_NATIVE == WIZ_CFG_ENDIAN_BIG)
                    U8::type  r, g, b, a;
#           else
                    U8::type  a, b, g, r;
#           endif /**/
                };
                U32::type     m_Value;
            };

            type() : m_Value(0)
            {
            }
            type(U8::in R, U8::in G, U8::in B, U8::in A) : r(R), g(G), b(B), a(A)
            {
            }
            type(U32::in V) : m_Value(V)
            {
            }

            ////////////////////////////////////////////////////////////////
        };

    } /// end of namespace RGBA

    namespace ARGB
    {
        WMS_STRUCT
        {
            union
            {
                struct
                {
#           if (WIZ_CFG_ENDIAN_NATIVE == WIZ_CFG_ENDIAN_BIG)
                    U8::type  a, r, g, b;
#           else
                    U8::type  b, g, r, a;
#           endif /**/
                };
                U32::type     m_Value;
            };

            type() : m_Value(0)
            {
            }
            type(U8::in R, U8::in G, U8::in B, U8::in A) : r(R), g(G), b(B), a(A)
            {
            }
            type(U32::in V) : m_Value(V)
            {
            }

            ////////////////////////////////////////////////////////////////
        };
    } /// end of namespace ARGB

    namespace ABGR
    {
        WMS_STRUCT
        {
            union
            {
                struct
                {
#           if (WIZ_CFG_ENDIAN_NATIVE == WIZ_CFG_ENDIAN_BIG)
                    U8::type  a, b, g, r;
#           else
                    U8::type  r, g, b, a;
#           endif /**/
                };
                U32::type     m_Value;
            };

            type() : m_Value(0)
            {
            }
            type(U8::in R, U8::in G, U8::in B, U8::in A) : r(R), g(G), b(B), a(A)
            {
            }
            type(U32::in V) : m_Value(V)
            {
            }

            ////////////////////////////////////////////////////////////////
        };
    } /// end of namespace ABGR

    namespace BGRA
    {
        WMS_STRUCT
        {
            union
            {
                struct
                {
#           if (WIZ_CFG_ENDIAN_NATIVE == WIZ_CFG_ENDIAN_BIG)
                    U8::type  b, g, r, a;
#           else
                    U8::type  a, r, g, b;
#           endif /**/
                };
                U32::type     m_Value;
            };

            type() : m_Value(0)
            {
            }
            type(U8::in R, U8::in G, U8::in B, U8::in A) : r(R), g(G), b(B), a(A)
            {
            }
            type(U32::in V) : m_Value(V)
            {
            }

        };
    } /// end of namespace BGRA

    //////////////////////////////////////////////////////////////////////////
} /// end of namespace wms

#endif /*__WHIMSY_COLOR_U32_HPP__SHANHAOBO_19800429__*/
