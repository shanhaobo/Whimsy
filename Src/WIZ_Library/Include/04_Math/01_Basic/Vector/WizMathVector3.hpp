#ifndef __WIZ_MATH_VECTOR3_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_VECTOR3_HPP__SHANHAOBO_19800429__

#include "../../00_Utils/WizMathUtils.hpp"

#include "./WizMathVector3Base.hpp"
#include "./WizMathVector3Method.hpp"

#include "./WizMathVector2.hpp"

namespace Wiz
{
    namespace Vector3
    {
        template<class ElementT>
        struct Type : ::Wiz::Vector3::Base::Type<ElementT>
        {
            typedef ::Wiz::Vector3::Base::Type<tElement>    tSuper;
            typedef tSuper const &                          tSuperIn;

            typedef Type<tElement>                          tThis;
            typedef tThis const &                           tThisIn;
            typedef tThis &                                 tThisOut;
            typedef tThis &                                 tThisIO;

            typedef ::Wiz::Vector3::Method::Type<tThis>     tMethod;

            typedef ::Wiz::Vector2::Type<tElement>          tVector2;
            ////////////////////////////////////////////////////////////////
            Type()
            {}
            Type(tElementIn inX, tElementIn inY, tElementIn inZ) : tSuper(inX, inY, inZ)
            {}
            Type(tElementIn inEle) : tSuper(inEle)
            {}
            Type(tSuperIn inOther) : tSuper(inOther)
            {}
            ////////////////////////////////////////////////////////////////
            WIZ_INLINE tThis& operator=(tSuperIn inVec)
            {
                x = inVec.x;
                y = inVec.y;
                z = inVec.z;

                return *this;
            }
            WIZ_INLINE tThis& operator=(tThisIn inVec)
            {
                x = inVec.x;
                y = inVec.y;
                z = inVec.z;

                return *this;
            }


            WIZ_INLINE tThis& operator=(const tVector2& inVec)
            {
                x = inVec.x;
                y = inVec.y;

                return *this;
            }

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement& operator[](::Wiz::U::In i)
            {
                WIZ_ASSERT(i < eCount);
                return e[i];
            }
            WIZ_INLINE tElementIn operator[](::Wiz::U::In i) const
            {
                WIZ_ASSERT(i < eCount);
                return e[i];
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE friend tThis operator +(tThisIn inVec1, tThisIn inVec2)
            {
                tThis lResult;

                return tMethod::Add(lResult, inVec1, inVec2);
            }
            WIZ_INLINE friend tThis operator +(tThisIn inVec, tElementIn inEle)
            {
                tThis lResult;

                return tMethod::Add(lResult, inVec, inEle);
            }
            WIZ_INLINE friend tThis operator +(tElementIn inEle, tThisIn inVec)
            {
                tThis lResult;

                return tMethod::Add(lResult, inVec, inEle);
            }

            WIZ_INLINE friend tThis& operator +=(tThisIO ioVec, tElementIn inEle)
            {
                tMethod::AddAssign(ioVec, inEle);

                return ioVec;
            }
            WIZ_INLINE friend tThis& operator +=(tThisIO ioVec, tThisIn inVec)
            {
                tMethod::AddAssign(ioVec, inVec);

                return ioVec;
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE friend tThis operator-(tThisIn inVec1, tThisIn inVec2)
            {
                tThis lResult;
                tMethod::Subtract(lResult, inVec1, inVec2);

                return lResult;
            }
            WIZ_INLINE friend tThis operator-(tThisIn inVec, tElementIn inEle)
            {
                tThis lResult;

                return tMethod::Subtract(lResult, inVec, inEle);
            }

            WIZ_INLINE friend tThis& operator -=(tThisIO ioVec, tElementIn inEle)
            {
                tMethod::SubtractAssign(ioVec, inEle);

                return ioVec;
            }
            WIZ_INLINE friend tThis& operator -=(tThisIO ioVec, tThisIn inVec)
            {
                tMethod::SubtractAssign(ioVec, inVec);

                return ioVec;
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE friend tThis operator*(tThisIn inVec1, tThisIn inVec2)
            {
                tThis lResult;
                tMethod::Multiply(lResult, inVec1, inVec2);

                return lResult;
            }
            WIZ_INLINE friend tThis operator*(tThisIn inVec, tElementIn inEle)
            {
                tThis lResult;
                tMethod::Multiply(lResult, inVec, inEle);

                return lResult;
            }
            WIZ_INLINE friend tThis operator*(tElementIn inEle, tThisIn inVec)
            {
                tThis lResult;

                return tMethod::Multiply(lResult, inVec, inEle);
            }

            WIZ_INLINE friend tThis& operator *=(tThisIO ioVec, tElementIn inEle)
            {
                tMethod::MultiplyAssign(ioVec, inEle);

                return ioVec;
            }
            WIZ_INLINE friend tThis& operator *=(tThisIO ioVec, tThisIn inVec)
            {
                tMethod::MultiplyAssign(ioVec, inVec);

                return ioVec;
            }
            ////////////////////////////////////////////////////////////////


            ////////////////////////////////////////////////////////////////
            WIZ_INLINE friend tThis operator/(tThisIn inVec1, tThisIn inVec2)
            {
                tThis lResult;

                return tMethod::Divide(lResult, inVec1, inVec2);
            }
            WIZ_INLINE friend tThis operator/(tThisIn inVec, tElementIn inEle)
            {
                tThis lResult;

                return tMethod::Divide(lResult, inVec, inEle);
            }

            WIZ_INLINE friend tThis operator/(tElementIn inEle, tThisIn inVec)
            {
                tThis lResult;

                return tMethod::Divide(lResult, inEle, inVec);
            }

            WIZ_INLINE friend tThis& operator/=(tThisIO ioVec, tElementIn inEle)
            {
                tMethod::DivideAssign(ioVec, inEle);

                return ioVec;
            }
            WIZ_INLINE friend tThis& operator/=(tThisIO ioVec, tThisIn inVec)
            {
                tMethod::DivideAssign(ioVec, inVec);

                return ioVec;
            }
            ////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE ::Wiz::Bool::Type operator==(tThisIn inVec) const
            {
                return tMethod::IsAbsoluteEqual(*this, inVec);
            }

            WIZ_INLINE ::Wiz::Bool::Type operator!=(tThisIn inVec) const
            {
                return !this->operator==(inVec);
            }

            WIZ_INLINE tThisIn operator+() const
            {
                return *this;
            }

            WIZ_INLINE tThis operator-() const
            {
                return tThis(-x, -y, -z);
            }

            WIZ_INLINE operator tVector2() const
            {
                return tVector2(x, y);
            }
            ////////////////////////////////////////////////////////////////
            WIZ_INLINE const tVector2& ToVector2() const
            {
                return *reinterpret_cast<tVector2*>this;
            }
            WIZ_INLINE tVector2& ToVector2()
            {
                return *reinterpret_cast<tVector2*>this;
            }
            ////////////////////////////////////////////////////////////////////
            WIZ_INLINE tThis& operator=(tElementIn inEle)
            {
                x = inEle;
                y = inEle;
                z = inEle;

                return *this;
            }
            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE ::Wiz::Void::Type Zero()
            {
                x = ::Wiz::Absolute::GetZero<tElement>();
                y = ::Wiz::Absolute::GetZero<tElement>();
                z = ::Wiz::Absolute::GetZero<tElement>();
            }
            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE ::Wiz::Void::Type Set(tElementIn inX, tElementIn inY, tElementIn inZ)
            {
                x = inX;
                y = inY;
                z = inZ;
            }
            WIZ_INLINE ::Wiz::Void::Type Get(tElementOut outX, tElementOut outY, tElementOut outZ) const
            {
                outX = x;
                outY = y;
                outZ = z;
            }
            ////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement Dot(tThisIn inVec) const
            {
                return tMethod::Dot(*this, inVec);
            }
            WIZ_INLINE static tElement Dot(tThisIn inVec1, tThisIn inVec2)
            {
                return tMethod::Dot(inVec1, inVec2);
            }
            ////////////////////////////////////////////////////////////////
            WIZ_INLINE static tThis Cross(tThisIn inVec1, tThisIn inVec2)
            {
                tThis lResult;
                tMethod::Cross(lResult, inVec1, inVec2);
                return lResult;
            }
            WIZ_INLINE static tThis& Cross(tThisOut outVec, tThisIn inVec1, tThisIn inVec2)
            {
                tMethod::Cross(outVec, inVec1, inVec2);
                return outVec;
            }
            ////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement AbsDot(tThisIn inVec) const
            {
                return tMethod::AbsDot(*this, inVec);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement Normalize()
            {
                return tMethod::Normalize(*this);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement GetNormal(tThisOut outVec) const
            {
                return tMethod::Normalize(outVec, *this);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE tThis GetNormal() const
            {
                tThis outVec;
                tMethod::Normalize(outVec, *this);
                return outVec;
            }
            ////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement SqrLen() const
            {
                return tMethod::SqrLen(*this);
            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement Length() const
            {
                return tMethod::Length(*this);
            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement RecipLen() const
            {
                return tMethod::RecipLen(*this);
            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement Distance(tThisIn inVec) const
            {
                return tMethod::Distance(*this, inVec);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement SqrDist(tThisIn inVec) const
            {
                return tMethod::SqrDist(*this, inVec);
            }
            ////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE static tElement Distance(tThisIn inVec1, tThisIn inVec2)
            {
                return tMethod::Distance(inVec1, inVec2);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE static tElement SqrDist(tThisIn inVec1, tThisIn inVec2)
            {
                return tMethod::SqrDist(inVec1, inVec2);
            }
            ////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE ::Wiz::Bool::Type IsAbsoluteZero() const
            {
                return tMethod::IsAbsoluteZero(*this);
            }
            //////////////////////////////////////////////////////////////////////////
        }; /// end of struct Type
    } /// end of namespace Vector3
} /// end of namespace Wiz

#endif /*__WIZ_MATH_VECTOR3_HPP__SHANHAOBO_19800429__*/
