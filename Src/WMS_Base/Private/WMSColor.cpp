#include "../include/WMSColor.hpp"

#include "../../WIZ_Library/include/04_Math/00_Utils/WizMathUtils.hpp"


namespace wms
{
    //////////////////////////////////////////////////////////////////////////
    namespace Color
    {
        type::type()
        {}
        type::type
            (
            F32::in red,
            F32::in green,
            F32::in blue,
            F32::in alpha
            )
        {
            r = ::Wiz::Saturate(red);
            g = ::Wiz::Saturate(green);
            b = ::Wiz::Saturate(blue);
            a = ::Wiz::Saturate(alpha);
        }

        Void::type type::Saturate()
        {
            r = ::Wiz::Saturate(r);
            g = ::Wiz::Saturate(g);
            b = ::Wiz::Saturate(b);
            a = ::Wiz::Saturate(a);
        }
        Void::type type::From(
            U8::in    red,
            U8::in    green,
            U8::in    blue,
            U8::in    alpha
            )
        {
            F32::typec omax = 1 / static_cast<F32::type>(U8::Max);
            r = static_cast<F32::type>(red)    * omax;
            g = static_cast<F32::type>(green)  * omax;
            b = static_cast<F32::type>(blue)   * omax;
            a = static_cast<F32::type>(alpha)  * omax;
        }

        Void::type type::FromRGBA(U32::in color)
        {
            RGBA::ptr pColor = (RGBA::ptr)(&color);

            this->From(pColor->r, pColor->g, pColor->b, pColor->a);
        }

        Void::type type::FromARGB(U32::in color)
        {
            ARGB::ptr pColor = (ARGB::ptr)(&color);

            this->From(pColor->r, pColor->g, pColor->b, pColor->a);
        }

        Void::type type::FromABGR(U32::in color)
        {
            ABGR::ptr pColor = (ABGR::ptr)(&color);

            this->From(pColor->r, pColor->g, pColor->b, pColor->a);
        }

        Void::type type::FromBGRA(U32::in color)
        {
            BGRA::ptr pColor = (BGRA::ptr)(&color);

            this->From(pColor->r, pColor->g, pColor->b, pColor->a);
        }
        Void::type type::To
            (
            U8::out    red,
            U8::out    green,
            U8::out    blue,
            U8::out    alpha
            ) const 
        {
            red     = (U8::type)(this->r * 255);
            green   = (U8::type)(this->g * 255);
            blue    = (U8::type)(this->b * 255);
            alpha   = (U8::type)(this->a * 255);
        }

        U32::type type::ToRGBA() const
        {
            U32::type color;
            RGBA::ptr pColor = (RGBA::ptr)(&color);
            this->To(pColor->r, pColor->g, pColor->b, pColor->a);
            return color;
        }

        U32::type type::ToARGB() const
        {
            U32::type color;
            ARGB::ptr pColor = (ARGB::ptr)(&color);
            this->To(pColor->r, pColor->g, pColor->b, pColor->a);
            return color;
        }

        U32::type type::ToABGR() const
        {
            U32::type color;
            ABGR::ptr pColor = (ABGR::ptr)(&color);
            this->To(pColor->r, pColor->g, pColor->b, pColor->a);
            return color;
        }

        U32::type type::ToBGRA() const
        {
            U32::type color;
            BGRA::ptr pColor = (BGRA::ptr)(&color);
            this->To(pColor->r, pColor->g, pColor->b, pColor->a);
            return color;
        }
    } /// end of namespace color
    //////////////////////////////////////////////////////////////////////////
} /// end of namespace Wiz

