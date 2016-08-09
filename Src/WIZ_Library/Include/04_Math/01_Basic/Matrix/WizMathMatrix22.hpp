#ifndef __WIZ_MATH_MATRIX22_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_MATRIX22_HPP__SHANHAOBO_19800429__

#include "./WizMathMatrix22Base.hpp"
#include "./WizMathMatrix22RowMajorMethod.hpp"
#include "./WizMathMatrix22ColMajorMethod.hpp"

namespace Wiz
{
    //////////////////////////////////////////////////////////////////////////
    namespace Matrix22
    {
        namespace RowMajor
        {
            //////////////////////////////////////////////////////////////////////////
            template<typename ElementT>
            struct Type : public ::Wiz::Matrix22::RowMajor::Base::Type<ElementT>
            {
                ////////////////////////////////////////////////////////////////
                typedef ::Wiz::Matrix22::RowMajor::Base::Type<tElement>     tSuper;
                typedef tSuper const &                                      tSuperIn;

                typedef Type                                                tThis;
                typedef tThis const &                                       tThisIn;
                typedef tThis &                                             tThisOut;
                typedef tThisOut                                            tThisIO;

                typedef ::Wiz::Matrix22::RowMajor::Method::Type<tThis>      tMethod;

                typedef ::Wiz::Vector2::Type<tElement>                      tVector2;
                typedef tVector2 const &                                    tVector2In;
                typedef tVector2 &                                          tVector2Out;
                ////////////////////////////////////////////////////////////////
                Type()
                {}
                Type(tElementIn inE00, tElementIn inE01, tElementIn inE10, tElementIn inE11) : tSuper(inE00, inE01, inE10, inE11)
                {}
                Type(tElementIn inEle) : tSuper(inEle)
                {}
                Type(tSuperIn inMat) : tSuper(inMat)
                {}
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE tThisOut Transpose(tThisOut outMat) const
                {
                    return tMethod::Transpose(outMat, *this);
                }
                WIZ_INLINE tThisOut Transpose()
                {
                    return tMethod::Transpose(*this);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE tThisOut Identity()
                {
                    return tMethod::Identity(*this);
                }
                WIZ_INLINE tThisOut Zero()
                {
                    return tMethod::Zero(*this);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE tElement Determinant() const
                {
                    return tMethod::Determinant(*this);
                }
                ////////////////////////////////////////////////////////////////
                ::Wiz::Bool::Type Invert(tThisOut outMat) const
                {
                    return tMethod::Invert(outMat, *this);
                }
                ::Wiz::Bool::Type Invert()
                {
                    return tMethod::Invert(*this, *this);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE ::Wiz::Void::Type GetRow(tVector2Out outVec2, ::Wiz::U::In Row) const
                {
                    tSuper::GetRow(outVec2.x, outVec2.y, Row);
                }
                WIZ_INLINE::Wiz::Void::Type GetCol(tVector2Out outVec2, ::Wiz::U::In Col) const
                {
                    tSuper::GetCol(outVec2.x, outVec2.y, Col);
                }

                WIZ_INLINE::Wiz::Void::Type GetRow(tElementOut outX, tElementOut outY, ::Wiz::U::In Row) const
                {
                    tSuper::GetRow(outX, outY, Row);
                }
                WIZ_INLINE::Wiz::Void::Type GetCol(tElementOut outX, tElementOut outY, ::Wiz::U::In Col) const
                {
                    tSuper::GetCol(outX, outY, Col);
                }

                WIZ_INLINE ::Wiz::Void::Type SetRow(::Wiz::U::In Row, const tVector2& inVec2)
                {
                    tSuper::SetRow(Row, inVec2.x, inVec2.y);
                }
                WIZ_INLINE ::Wiz::Void::Type SetCol(::Wiz::U::In Col, const tVector2& inVec2)
                {
                    tSuper::SetCol(Col, inVec2.x, inVec2.y);
                }

                WIZ_INLINE ::Wiz::Void::Type SetRow(::Wiz::U::In inRow, tElementIn inX, tElementIn inY)
                {
                    tSuper::SetRow(inRow, inX, inY);
                }
                WIZ_INLINE ::Wiz::Void::Type SetCol(::Wiz::U::In inCol, tElementIn inX, tElementIn inY)
                {
                    tSuper::SetCol(inCol, inX, inY);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE friend tThis operator+(tThisIn inMat1, tThisIn inMat2)
                {
                    tThis lMat;
                    return tMethod::Add(lMat, inMat1, inMat2);
                }
                WIZ_INLINE friend tThis& operator+=(tThis& ioMat, tThisIn inMat)
                {
                    return tMethod::AddAssign(ioMat, inMat);
                }

                WIZ_INLINE friend tThis operator-(tThisIn inMat1, tThisIn inMat2)
                {
                    tThis lMat;
                    return tMethod::Subtract(lMat, inMat1, inMat2);
                }
                WIZ_INLINE friend tThis& operator-=(tThis& ioMat, tThisIn inMat)
                {
                    return tMethod::SubtractAssign(ioMat, inMat);
                }

                WIZ_INLINE friend tThis operator*(tThisIn inMat1, tThisIn inMat2)
                {
                    tThis lMat;
                    return tMethod::Multiply(lMat, inMat1, inMat2);
                }
                WIZ_INLINE friend tThisOut operator*=(tThisIO ioMat, tThisIn inMat)
                {
                    return tMethod::MultiplyAssign(ioMat, inMat);
                }

                WIZ_INLINE friend tThis operator*(tThisIn inMat, tElementIn inEle)
                {
                    tThis lMat;
                    return tMethod::Multiply(lMat, inMat, inEle);
                }
                WIZ_INLINE friend tThis& operator*=(tThis& ioMat, tElementIn inEle)
                {
                    return tMethod::MultiplyAssign(ioMat, inEle);
                }

                WIZ_INLINE friend tVector2 operator*(const tVector2& inVec, tThisIn inMat)
                {
                    tVector2 lVec;
                    return tMethod::Multiply(lVec, inVec, inMat);
                }
                WIZ_INLINE friend tVector2& operator*=(tVector2& ioVec, tThisIn inMat)
                {
                    return tMethod::MultiplyAssign(ioVec, inMat);
                }
                ////////////////////////////////////////////////////////////////

                ////////////////////////////////////////////////////////////////
                WIZ_INLINE ::Wiz::Bool::Type operator==(tThisIn inMat) const
                {
                    return tMethod::IsEqual(*this, inMat);
                }

                WIZ_INLINE ::Wiz::Bool::Type operator!=(tThisIn inMat) const
                {
                    return tMethod::IsEqual(*this, inMat) == ::Wiz::Bool::False;
                }

                WIZ_INLINE tThisIn operator+() const
                {
                    return *this;
                }

                WIZ_INLINE tThis operator-() const
                {
                    tThis lMat;
                    return tMethod::Negative(lMat, *this);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE tThis& operator=(tElementIn inEle)
                {
                    return tMethod::FromElement(*this, inEle);
                }

                WIZ_INLINE tThis& operator=(tThisIn inMat)
                {
                    return tMethod::FromMatrix22(*this, inMat);
                }

                WIZ_INLINE ::Wiz::Void::Type GetTransposeArray(float* outArray) const
                {
                    outArray[0] = this->e00;  outArray[1] = this->e10;
                    outArray[2] = this->e01;  outArray[3] = this->e11;
                }
                ////////////////////////////////////////////////////////////////
            }; /// end of struct Type
        } /// end of namespace Matrix22
    } /// end of namespace RowMajor
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    namespace Matrix22
    {
        namespace ColMajor
        {
            //////////////////////////////////////////////////////////////////////////
            template<typename ElementT>
            struct Type : public ::Wiz::Matrix22::ColMajor::Base::Type<ElementT>
            {
                WIZ_DECLARE_CLASS_THIS(Type);
                ////////////////////////////////////////////////////////////////
                typedef ::Wiz::Matrix22::ColMajor::Base::Type<tElement>     tSuper;
                typedef tSuper const &                                      tSuperIn;

                typedef Type                                                tThis;
                typedef tThis const &                                       tThisIn;
                typedef tThis &                                             tThisOut;
                typedef tThisOut                                            tThisIO;

                typedef ::Wiz::Matrix22::ColMajor::Method::Type<tThis>      tMethod;

                typedef ::Wiz::Vector2::Type<tElement>                      tVector2;
                typedef tVector2 const &                                    tVector2In;
                typedef tVector2 &                                          tVector2Out;
                ////////////////////////////////////////////////////////////////
                Type()
                {}
                Type(
                    tElementIn inE00, tElementIn inE10,
                    tElementIn inE01, tElementIn inE11
                    ) : tSuper(inE00, inE10, inE01, inE11)
                {}
                Type(tElementIn inEle) : tSuper(inEle)
                {}
                Type(const tSuper& inMat) : tSuper(inMat)
                {}
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE tThisOut Transpose(tThisOut outMat) const
                {
                    return tMethod::Transpose(outMat, *this);
                }
                WIZ_INLINE tThisOut Transpose()
                {
                    return tMethod::Transpose(*this);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE tThisOut Identity()
                {
                    return tMethod::Identity(*this);
                }
                WIZ_INLINE tThisOut Zero()
                {
                    return tMethod::Zero(*this);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE tElement Determinant() const
                {
                    return tMethod::Determinant(*this);
                }
                ////////////////////////////////////////////////////////////////
                ::Wiz::Bool::Type Invert(tThisOut outMat) const
                {
                    return tMethod::Invert(outMat, *this);
                }
                ::Wiz::Bool::Type Invert()
                {
                    return tMethod::Invert(*this);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE ::Wiz::Void::Type GetRow(tVector2Out outVec, ::Wiz::U::In Row) const
                {
                    tSuper::GetRow(outVec.x, outVec.y, Row);
                }
                WIZ_INLINE ::Wiz::Void::Type GetCol(tVector2Out outVec, ::Wiz::U::In Col) const
                {
                    tSuper::GetCol(outVec.x, outVec.y, Col);
                }

                WIZ_INLINE ::Wiz::Void::Type GetRow(tElement& outX, tElement& outY, ::Wiz::U::In Row) const
                {
                    tSuper::GetRow(outX, outY, Row);
                }
                WIZ_INLINE ::Wiz::Void::Type GetCol(tElement& outX, tElement& outY, ::Wiz::U::In Col) const
                {
                    tSuper::GetCol(outX, outY, Col);
                }

                /**/
                WIZ_INLINE ::Wiz::Void::Type SetRow(::Wiz::U::In Row, const tVector2& inVec)
                {
                    tSuper::SetRow(Row, inVec.x, inVec.y);
                }
                WIZ_INLINE ::Wiz::Void::Type SetCol(::Wiz::U::In Col, const tVector2& inVec)
                {
                    tSuper::SetCol(Col, inVec.x, inVec.y);
                }

                WIZ_INLINE ::Wiz::Void::Type SetRow(::Wiz::U::In Row, tElementIn inX, tElementIn inY)
                {
                    tSuper::SetRow(Row, inX, inY);
                }
                WIZ_INLINE ::Wiz::Void::Type SetCol(::Wiz::U::In Col, tElementIn inX, tElementIn inY)
                {
                    tSuper::SetCol(Col, inX, inY);
                }

                ////////////////////////////////////////////////////////////////
                WIZ_INLINE friend tThis operator+(tThisIn inMat1, tThisIn inMat2)
                {
                    tThis lMat;
                    return tMethod::Add(lMat, inMat1, inMat2);
                }
                WIZ_INLINE friend tThis& operator+=(tThis& ioMat, tThisIn inMat)
                {
                    return tMethod::AddAssign(ioMat, inMat);
                }

                WIZ_INLINE friend tThis operator-(tThisIn inMat1, tThisIn inMat2)
                {
                    tThis lMat;
                    return tMethod::Subtract(lMat, inMat1, inMat2);
                }
                WIZ_INLINE friend tThis& operator-=(tThis& ioMat, tThisIn inMat)
                {
                    return tMethod::SubtractAssign(ioMat, inMat);
                }

                WIZ_INLINE friend tThis operator*(tThisIn inMat1, tThisIn inMat2)
                {
                    tThis lMat;
                    return tMethod::Multiply(lMat, inMat1, inMat2);
                }
                WIZ_INLINE friend tThis& operator*=(tThis& ioMat, tThisIn inMat)
                {
                    return tMethod::MultiplyAssign(ioMat, inMat);
                }

                WIZ_INLINE friend tThis operator*(tThisIn inMat, tElementIn inEle)
                {
                    tThis lMat;
                    return tMethod::Multiply(lMat, inMat, inEle);
                }
                WIZ_INLINE friend tThis& operator*=(tThis& ioMat, tElementIn inEle)
                {
                    return tMethod::MultiplyAssign(ioMat, inEle);
                }

                WIZ_INLINE friend tVector2 operator*(tThisIn inMat, const tVector2& inVec)
                {
                    tVector2 lVec;
                    return tMethod::Multiply(lVec, inVec, inMat);
                }
                WIZ_INLINE friend tVector2& operator*=(tVector2& ioVec, tThisIn inMat)
                {
                    return tMethod::MultiplyAssign(ioVec, inMat);
                }
                ////////////////////////////////////////////////////////////////

                ////////////////////////////////////////////////////////////////
                WIZ_INLINE ::Wiz::Bool::Type operator==(tThisIn inMat) const
                {
                    return tMethod::IsEqual(*this, inMat);
                }

                WIZ_INLINE ::Wiz::Bool::Type operator!=(tThisIn inMat) const
                {
                    return tMethod::IsEqual(*this, inMat) == ::Wiz::Bool::False;
                }
                WIZ_INLINE tThisIn operator+() const
                {
                    return *this;
                }
                WIZ_INLINE tThis operator-() const
                {
                    tThis lMat;
                    return tMethod::Negative(lMat, *this);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE tThis& operator=(tElementIn inEle)
                {
                    return tMethod::FromElement(*this, inEle);
                }

                WIZ_INLINE tThis& operator=(tThisIn inMat)
                {
                    return tMethod::FromMatrix22(*this, inMat);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE ::Wiz::Void::Type GetTransposeArray(float* outArray) const
                {
                    outArray[0] = this->e00; outArray[1] = this->e01;
                    outArray[2] = this->e10; outArray[3] = this->e11;
                }
                ////////////////////////////////////////////////////////////////
            }; /// end of struct Type
        } /// end of namespace ColMajor
    } /// end of namespace Matrix22
} /// end of namespace Wiz

#endif /*__WIZ_MATH_MATRIX22_HPP__SHANHAOBO_19800429__*/
