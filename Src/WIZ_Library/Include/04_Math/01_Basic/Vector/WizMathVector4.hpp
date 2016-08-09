#ifndef __WIZ_MATH_VECTOR4_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_VECTOR4_HPP__SHANHAOBO_19800429__

#include "../../00_Utils/WizMathUtils.hpp"

#include "./WizMathVector4Base.hpp"
#include "./WizMathVector4Method.hpp"

#include "./WizMathVector3.hpp"

namespace Wiz
{
    namespace Vector4
    {
        template<class ElementT>
        struct Type : ::Wiz::Vector4::Base::Type<ElementT>
        {
            typedef ::Wiz::Vector4::Base::Type<tElement>    tSuper;
            typedef tSuper const &                          tSuperIn;

            typedef Type                                    tThis;
            typedef tThis const &                           tThisIn;
            typedef tThis &                                 tThisOut;
            typedef tThis &                                 tThisIO;

            typedef ::Wiz::Vector4::Method::Type<tThis>     tMethod;

            typedef ::Wiz::Vector2::Type<tElement>          tVector2;
            typedef tVector2 const &                        tVector2In;

            typedef ::Wiz::Vector3::Type<tElement>          tVector3;
            typedef tVector3 const &                        tVector3In;
            ////////////////////////////////////////////////////////////////
            Type()
            {}
            Type(tElementIn inX, tElementIn inY, tElementIn inZ, tElementIn inW) : tSuper(inX, inY, inZ, inW)
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
                w = inVec.w;

                return *this;
            }
            WIZ_INLINE tThis& operator=(tThisIn inVec)
            {
                x = inVec.x;
                y = inVec.y;
                z = inVec.z;
                w = inVec.w;

                return *this;
            }


            WIZ_INLINE tThis& operator=(tVector2In inVec)
            {
                x = inVec.x;
                y = inVec.y;

                return *this;
            }


            WIZ_INLINE tThis& operator=(tVector3In inVec)
            {
                x = inVec.x;
                y = inVec.y;
                z = inVec.z;

                return *this;
            }

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement& operator[](::Wiz::U::In i)
            {
                WIZ_ASSERT(i < eCount);
                return this->e[i];
            }
            WIZ_INLINE tElementIn operator[](::Wiz::U::In i) const
            {
                WIZ_ASSERT(i < eCount);
                return this->e[i];
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE friend tThis operator +(tThisIn inVec1, tThisIn inVec2)
            {
                tThis lResult;
                tMethod::Add(lResult, inVec1, inVec2);
                return lResult;
            }
            WIZ_INLINE friend tThis operator +(tThisIn inVec, tElementIn inEle)
            {
                tThis lResult;
                tMethod::Add(lResult, inVec, inEle);
                return lResult;
            }
            WIZ_INLINE friend tThis operator +(tElementIn inEle, tThisIn inVec)
            {
                tThis lResult;
                tMethod::Add(lResult, inVec, inEle);
                return lResult;
            }

            WIZ_INLINE friend tThis& operator +=(tThisIO ioVec, tElementIn inEle)
            {
                return tMethod::AddAssign(ioVec, inEle);
            }
            WIZ_INLINE friend tThis& operator +=(tThisIO ioVec, tThisIn inVec)
            {
                return tMethod::AddAssign(ioVec, inVec);
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
                tMethod::Subtract(lResult, inVec, inEle);
                return lResult;
            }

            WIZ_INLINE friend tThis& operator -=(tThisIO ioVec, tElementIn inEle)
            {
                return tMethod::SubtractAssign(ioVec, inEle);
            }
            WIZ_INLINE friend tThis& operator -=(tThisIO ioVec, tThisIn inVec)
            {
                return tMethod::SubtractAssign(ioVec, inVec);
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
                tMethod::Multiply(lResult, inVec, inEle);
                return lResult;
            }

            WIZ_INLINE friend tThis& operator *=(tThisIO ioVec, tElementIn inEle)
            {
                return tMethod::MultiplyAssign(ioVec, inEle);
            }
            WIZ_INLINE friend tThis& operator *=(tThisIO ioVec, tThisIn inVec)
            {
                return tMethod::MultiplyAssign(ioVec, inVec);
            }
            ////////////////////////////////////////////////////////////////


            ////////////////////////////////////////////////////////////////
            WIZ_INLINE friend tThis operator/(tThisIn inVec1, tThisIn inVec2)
            {
                tThis lResult;
                tMethod::Divide(lResult, inVec1, inVec2);
                return lResult;
            }
            WIZ_INLINE friend tThis operator/(tThisIn inVec, tElementIn inEle)
            {
                tThis lResult;
                tMethod::Divide(lResult, inVec, inEle);
                return lResult;
            }

            WIZ_INLINE friend tThis operator/(tElementIn inEle, tThisIn inVec)
            {
                tThis lResult;
                tMethod::Divide(lResult, inEle, inVec);
                return lResult;
            }

            WIZ_INLINE friend tThis& operator/=(tThisIO ioVec, tElementIn inEle)
            {
                return tMethod::DivideAssign(ioVec, inEle);
            }
            WIZ_INLINE friend tThis& operator/=(tThisIO ioVec, tThisIn inVec)
            {
                return tMethod::DivideAssign(ioVec, inVec);
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
                return tThis(-x, -y, -z, -w);
            }

            WIZ_INLINE operator tVector2() const
            {
                return tVector2(x, y);
            }
            WIZ_INLINE operator tVector3() const
            {
                return tVector3(x, y, z);
            }
            ////////////////////////////////////////////////////////////////

            WIZ_INLINE const tVector2& ToVector2() const
            {
                return *reinterpret_cast<tVector2*>(this);
            }
            WIZ_INLINE tVector2& ToVector2()
            {
                return *reinterpret_cast<tVector2*>(this);
            }

            WIZ_INLINE const tVector3& ToVector3() const
            {
                return *reinterpret_cast<tVector3*>(this);
            }
            WIZ_INLINE tVector3& ToVector3()
            {
                return *reinterpret_cast<tVector3*>(this);
            }

            ////////////////////////////////////////////////////////////////////
            WIZ_INLINE tThis& operator=(tElementIn inEle)
            {
                x = inEle;
                y = inEle;
                z = inEle;
                w = inEle;

                return *this;
            }
            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE ::Wiz::Void::Type Zero()
            {
                x = ::Wiz::Absolute::GetZero<tElement>();
                y = ::Wiz::Absolute::GetZero<tElement>();
                z = ::Wiz::Absolute::GetZero<tElement>();
                w = ::Wiz::Absolute::GetZero<tElement>();
            }
            //////////////////////////////////////////////////////////////////////////

            WIZ_INLINE ::Wiz::Void::Type Set(tElementIn inX, tElementIn inY, tElementIn inZ, tElementIn inW)
            {
                x = inX;
                y = inY;
                z = inZ;
                w = inW;
            }

            WIZ_INLINE::Wiz::Void::Type Get(tElementOut outX, tElementOut outY, tElementOut outZ, tElementOut outW)
            {
                outX = x;
                outY = y;
                outZ = z;
                outW = w;
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

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement AbsDot(tThisIn inVec) const
            {
                return tMethod::AbsDot(*this, inVec);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE static tElement AbsDot(tThisIn inVec1, tThisIn inVec2)
            {
                return tMethod::AbsDot(inVec1, inVec2);
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
                tThis lResult;
                tMethod::Normalize(lResult, *this);
                return lResult;
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
    } /// end of namespace Vector4
} /// end of namespace Wiz

#endif /*__WIZ_MATH_VECTOR4_HPP__SHANHAOBO_19800429__*/
