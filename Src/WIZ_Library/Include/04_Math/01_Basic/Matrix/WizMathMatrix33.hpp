#ifndef __WIZ_MATH_MATRIX33_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_MATRIX33_HPP__SHANHAOBO_19800429__

#include "./WizMathMatrix33Base.hpp"
#include "./WizMathMatrix33ColMajorMethod.hpp"
#include "./WizMathMatrix33RowMajorMethod.hpp"

#include "./WizMathMatrix22.hpp"

#include "../Vector/WizMathVector2.hpp"
#include "../Vector/WizMathVector3.hpp"

namespace Wiz
{
    namespace Matrix33
    {
        namespace RowMajor
        {
            //////////////////////////////////////////////////////////////
            template<typename ElementT>
            struct Type : public ::Wiz::Matrix33::RowMajor::Base::Type<ElementT>
            {
                WIZ_DECLARE_CLASS_THIS(Type);
                //////////////////////////////////////////////////////////
                typedef tThis                                               tCore;
                typedef ::Wiz::Matrix33::RowMajor::Base::Type<tElement>     tSuper;
                typedef ::Wiz::Matrix33::RowMajor::Method::Type<tThis>      tMethod;
                typedef ::Wiz::Matrix22::RowMajor::Type<ElementT>           tMatrix22;
                typedef ::Wiz::Vector2::Type<tElement>                      tVector2;
                typedef ::Wiz::Vector3::Type<tElement>                      tVector3;
                //////////////////////////////////////////////////////////
                Type()
                {}
                Type(
                    tElementIn inE00, tElementIn inE01, tElementIn inE02,
                    tElementIn inE10, tElementIn inE11, tElementIn inE12,
                    tElementIn inE20, tElementIn inE21, tElementIn inE22
                    ) : tSuper(inE00, inE01, inE02,inE10, inE11, inE12, inE20, inE21, inE22)
                {}
                explicit Type(tElementIn inEle) : tSuper(inEle)
                {}
                explicit Type(const tSuper& inMat) : tSuper(inMat)
                {}
                //////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////
                WIZ_INLINE tThis& Transpose(tThisOut outMat) const
                {
                    return tMethod::Transpose(outMat, *this);
                }
                WIZ_INLINE tThis& Transpose()
                {
                    return tMethod::Transpose(*this);
                }
                //////////////////////////////////////////////////////////
                WIZ_INLINE tThis& Identity()
                {
                    return tMethod::Identity(*this);
                }
                WIZ_INLINE tThis& Zero()
                {
                    return tMethod::Zero(*this);
                }
                //////////////////////////////////////////////////////////
                WIZ_INLINE tElement Determinant() const
                {
                    return tMethod::Determinant(*this);
                }
                //////////////////////////////////////////////////////////
                ::Wiz::Bool::Type Invert(tThisOut outMat) const
                {
                    return tMethod::Invert(outMat, *this);
                }
                ::Wiz::Bool::Type Invert()
                {
                    return tMethod::Invert(*this);
                }
                //////////////////////////////////////////////////////////
                WIZ_INLINE ::Wiz::Void::Type GetRow(tVector3& outVec3, ::Wiz::U::In Row) const
                {
                    tSuper::GetRow(outVec3.x, outVec3.y, outVec3.z, Row);
                }
                WIZ_INLINE ::Wiz::Void::Type GetCol(tVector3& outVec3, ::Wiz::U::In Col) const
                {
                    tSuper::GetCol(outVec3.x, outVec3.y, outVec3.z, Col);
                }

                WIZ_INLINE ::Wiz::Void::Type GetRow(tElement& outX, tElement& outY, tElement& outZ, ::Wiz::U::In Row) const
                {
                    tSuper::GetRow(outX, outY, outZ, Row);
                }
                WIZ_INLINE ::Wiz::Void::Type GetCol(tElement& outX, tElement& outY, tElement& outZ, ::Wiz::U::In Col) const
                {
                    tSuper::GetCol(outX, outY, outZ, Col);
                }

                WIZ_INLINE ::Wiz::Void::Type SetRow(::Wiz::U::In Row, const tVector3& inVec3)
                {
                    tSuper::SetRow(Row, inVec3.x, inVec3.y, inVec3.z);
                }
                WIZ_INLINE ::Wiz::Void::Type SetCol(::Wiz::U::In Col, const tVector3& inVec3)
                {
                    tSuper::SetCol(Col, inVec3.x, inVec3.y, inVec3.z);
                }

                WIZ_INLINE ::Wiz::Void::Type SetRow(::Wiz::U::In Row, tElementIn inX, tElementIn inY, tElementIn inZ)
                {
                    tSuper::SetRow(Row, inX, inY, inZ);
                }
                WIZ_INLINE ::Wiz::Void::Type SetCol(::Wiz::U::In Col, tElementIn inX, tElementIn inY, tElementIn inZ)
                {
                    tSuper::SetCol(Col, inX, inY, inZ);
                }
                //////////////////////////////////////////////////////////
                template<class Matrix22T, int rj, int ri>
                Matrix22T& GetCofactor(Matrix22T& outCofactor) const
                {
                    return tSuper::GetCofactor<Matrix22T, rj, ri>(outCofactor);
                }
                //////////////////////////////////////////////////////////
                WIZ_INLINE friend tThis operator+(tThisIn inMat1, tThisIn inMat2)
                {
                    tThis outMat;
                    return tMethod::Add(outMat, inMat1, inMat2);
                }
                WIZ_INLINE friend tThis& operator+=(tThis& ioMat, tThisIn inMat)
                {
                    return tMethod::AddAssign(ioMat, inMat);
                }

                WIZ_INLINE friend tThis operator-(tThisIn inMat1, tThisIn inMat2)
                {
                    tThis outMat;
                    return tMethod::Subtract(outMat, inMat1, inMat2);
                }
                WIZ_INLINE friend tThis& operator-=(tThis& ioMat, tThisIn inMat)
                {
                    return tMethod::SubtractAssign(ioMat, inMat);
                }

                WIZ_INLINE friend tThis operator*(tThisIn inMat1, tThisIn inMat2)
                {
                    tThis Mat;
                    return tMethod::Multiply(Mat, inMat1, inMat2);
                }
                WIZ_INLINE friend tThis& operator*=(tThisInOut ioMat, tThisIn inMat)
                {
                    return tMethod::MultiplyAssign(ioMat, inMat);
                }

                WIZ_INLINE friend tThis operator*(tThisIn inMat1, tElementIn inEle)
                {
                    tThis Mat;
                    return tMethod::Multiply(Mat, inMat1, inEle);
                }
                WIZ_INLINE friend tThis& operator*=(tThis& ioMat, tElementIn inEle)
                {
                    return tMethod::MultiplyAssign(ioMat, inEle);
                }

                WIZ_INLINE friend tVector3 operator*(const tVector3& inVec3, tThisIn inMat)
                {
                    tVector3 Vec3;
                    return tMethod::Multiply(Vec3, inVec3, inMat);
                }
                WIZ_INLINE friend tVector3& operator*=(tVector3& ioVec3, tThisIn inMat)
                {
                    return tMethod::MultiplyAssign(ioVec3, inMat);
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
                    tThis outMat;
                    return tMethod::Negative(outMat, *this);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE tThis& operator=(tElementIn inEle)
                {
                    return tMethod::FromElement(*this, inEle);
                }
                WIZ_INLINE tThis& operator=(const tMatrix22& inMat)
                {
                    return tMethod::FromMatrix22(*this, inMat);
                }
                WIZ_INLINE operator tMatrix22() const
                {
                    tMatrix22 outMat;
                    return tMethod::ToMatrix22(outMat, *this);
                }
                WIZ_INLINE tThis& operator=(tThisIn inMat)
                {
                    return tMethod::FromMatrix33(*this, inMat);
                }
                WIZ_INLINE ::Wiz::Void::Type GetTransposeArray(float* outArray) const
                {
                    outArray[0] = this->e00;  outArray[1] = this->e10;  outArray[2] = this->e20;
                    outArray[3] = this->e01;  outArray[4] = this->e11;  outArray[5] = this->e21;
                    outArray[6] = this->e02;  outArray[7] = this->e12;  outArray[8] = this->e22;
                }
                ////////////////////////////////////////////////////////////////
            }; /// end of struct Type
        } /// end of namespace RowMajor

        namespace ColMajor
        {
            //////////////////////////////////////////////////////////////
            template<typename ElementT>
            struct Type : public ::Wiz::Matrix33::ColMajor::Base::Type<ElementT>
            {
                WIZ_DECLARE_CLASS_THIS(Type);
                //////////////////////////////////////////////////////////
                typedef tThis                                               tCore;
                typedef ::Wiz::Matrix33::ColMajor::Base::Type<tElement>     tSuper;
                typedef ::Wiz::Matrix33::ColMajor::Method::Type<tThis>      tMethod;
                typedef ::Wiz::Matrix22::ColMajor::Type<ElementT>           tMatrix22;
                typedef ::Wiz::Vector2::Type<tElement>                      tVector2;
                typedef ::Wiz::Vector3::Type<tElement>                      tVector3;
                //////////////////////////////////////////////////////////
                Type()
                {}
                Type(
                    tElementIn inE00, tElementIn inE10, tElementIn inE20,
                    tElementIn inE01, tElementIn inE11, tElementIn inE21,
                    tElementIn inE02, tElementIn inE12, tElementIn inE22
                    ) : tSuper(inE00, inE10, inE20, inE01, inE11, inE21, inE02, inE12, inE22)
                {}
                Type(tElementIn inEle) : tSuper(inEle)
                {}
                Type(const tSuper& inMat) : tSuper(inMat)
                {}
                //////////////////////////////////////////////////////////

                ////////////////////////////////////////////////////////////////
                WIZ_INLINE tThis& Transpose(tThisOut outMat) const
                {
                    return tMethod::Transpose(outMat, *this);
                }
                WIZ_INLINE tThis& Transpose()
                {
                    return tMethod::Transpose(*this);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE tThis& Identity()
                {
                    return tMethod::Identity(*this);
                }
                WIZ_INLINE tThis& Zero()
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
                WIZ_INLINE ::Wiz::Void::Type GetRow(tVector3& outVec3, ::Wiz::U::In Row) const
                {
                    tSuper::GetRow(outVec3.x, outVec3.y, outVec3.z, Row);
                }
                WIZ_INLINE ::Wiz::Void::Type GetCol(tVector3& outVec3, ::Wiz::U::In Col) const
                {
                    tSuper::GetCol(outVec3.x, outVec3.y, outVec3.z, Col);
                }

                WIZ_INLINE ::Wiz::Void::Type GetRow(tElement& outX, tElement& outY, tElement& outZ, ::Wiz::U::In Row) const
                {
                    tSuper::GetRow(outX, outY, outZ, Row);
                }
                WIZ_INLINE ::Wiz::Void::Type GetCol(tElement& outX, tElement& outY, tElement& outZ, ::Wiz::U::In Col) const
                {
                    tSuper::GetCol(outX, outY, outZ, Col);
                }

                WIZ_INLINE ::Wiz::Void::Type SetRow(::Wiz::U::In Row, const tVector3& inVec3)
                {
                    tSuper::SetRow(Row, inVec3.x, inVec3.y, inVec3.z);
                }
                WIZ_INLINE ::Wiz::Void::Type SetCol(::Wiz::U::In Col, const tVector3& inVec3)
                {
                    tSuper::SetCol(Col, inVec3.x, inVec3.y, inVec3.z);
                }

                WIZ_INLINE ::Wiz::Void::Type SetRow(::Wiz::U::In Row, tElementIn inX, tElementIn inY, tElementIn inZ)
                {
                    tSuper::SetRow(Row, inX, inY, inZ);
                }
                WIZ_INLINE ::Wiz::Void::Type SetCol(::Wiz::U::In Col, tElementIn inX, tElementIn inY, tElementIn inZ)
                {
                    tSuper::SetCol(Col, inX, inY, inZ);
                }
                //////////////////////////////////////////////////////////////////////////
                template<class Matrix22T, int rj, int ri>
                Matrix22T& GetCofactor(Matrix22T& outCofactor) const
                {
                    return tSuper::GetCofactor<Matrix22T, rj, ri>(outCofactor, *this);
                }
                //////////////////////////////////////////////////////////
                WIZ_INLINE friend tThis operator+(tThisIn inMat1, tThisIn inMat2)
                {
                    tThis outMat;
                    return tMethod::Add(outMat, inMat1, inMat2);
                }
                WIZ_INLINE friend tThis& operator+=(tThis& ioMat, tThisIn inMat2)
                {
                    return tMethod::AddAssign(ioMat, inMat2);
                }

                WIZ_INLINE friend tThis operator-(tThisIn inMat1, tThisIn inMat2)
                {
                    tThis outMat;
                    return tMethod::Subtract(outMat, inMat1, inMat2);
                }
                WIZ_INLINE friend tThis& operator-=(tThis& ioMat, tThisIn inMat2)
                {
                    return tMethod::SubtractAssign(ioMat, inMat2);
                }

                WIZ_INLINE friend tThis operator*(tThisIn inMat1, tThisIn inMat2)
                {
                    tThis Mat;
                    return tMethod::Multiply(Mat, inMat1, inMat2);
                }
                WIZ_INLINE friend tThis& operator*=(tThis& ioMat, tThisIn inMat)
                {
                    return tMethod::MultiplyAssign(ioMat, inMat);
                }

                WIZ_INLINE friend tThis operator*(tThisIn inMat1, tElementIn inEle)
                {
                    tThis Mat;
                    return tMethod::Multiply(Mat, inMat1, inEle);
                }
                WIZ_INLINE friend tThis& operator*=(tThis& ioMat, tElementIn inEle)
                {
                    return tMethod::MultiplyAssign(ioMat, inEle);
                }

                WIZ_INLINE friend tVector3 operator*(tThisIn inMat, const tVector3& inVec3)
                {
                    tVector3 Vec3;
                    return tMethod::Multiply(Vec3, inVec3, inMat);
                }
                WIZ_INLINE friend tVector3& operator*=(tVector3& ioVec3, tThisIn inMat)
                {
                    return tMethod::MultiplyAssign(ioVec3, inMat);
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
                    tThis outMat;
                    return tMethod::Negative(outMat, *this);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE tThis& operator=(tElementIn inEle)
                {
                    return tMethod::FromElement(*this, inEle);
                }
                WIZ_INLINE tThis& operator=(tThisIn inMat)
                {
                    return tMethod::FromMatrix33(*this, inMat);
                }
                WIZ_INLINE ::Wiz::Void::Type GetTransposeArray(float* outArray) const
                {
                    outArray[0] = this->e00; outArray[1] = this->e01; outArray[2] = this->e02;
                    outArray[3] = this->e10; outArray[4] = this->e11; outArray[5] = this->e12;
                    outArray[6] = this->e20; outArray[7] = this->e21; outArray[8] = this->e22;
                }
                ////////////////////////////////////////////////////////////////
            }; /// end of struct Type
        } /// end of namespace ColMajor
    } /// end of namespace Matrix33
} /// end of namespace Wiz

#endif /*__WIZ_MATH_MATRIX33_HPP__SHANHAOBO_19800429__*/
