#ifndef __WIZ_MATH_MATRIX22_COLMAJOR_METHOD_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_MATRIX22_COLMAJOR_METHOD_HPP__SHANHAOBO_19800429__

#include "../Vector/WizMathVector2.hpp"

namespace Wiz
{
    namespace Matrix22
    {
        namespace ColMajor
        {
            namespace Method
            {
                template<class MatrixT>
                struct Type
                {
                    //////////////////////////////////////////////////////////////////////////
                    typedef MatrixT                                             tMatrix;
                    typedef Type<tMatrix>                                       tThis;
                    typedef typename tMatrix::tElement                          tElement;
                    typedef ::Wiz::Vector2::Type<tElement>                      tVector2;
                    //////////////////////////////////////////////////////////////////////////
                    WIZ_INLINE static tMatrix& FromElement(tMatrixOut outMat, tElementIn inEle);
                    ////////////////////////////////////////////////////////////////
                    template<class Matrix22T>
                    WIZ_INLINE static tMatrix& FromMatrix22(tMatrixOut outMat, const Matrix22T& inMat);
                    template<class Matrix22T>
                    WIZ_INLINE static Matrix22T& ToMatrix22(Matrix22T& outMat, tMatrixIn inMat);

                    template<class Matrix33T>
                    WIZ_INLINE static tMatrix& FromMatrix33(tMatrixOut outMat, const Matrix33T& inMat);
                    template<class Matrix33T>
                    WIZ_INLINE static Matrix33T& ToMatrix33(Matrix33T& outMat, tMatrixIn inMat);

                    template<class Matrix44T>
                    WIZ_INLINE static tMatrix& FromMatrix44(tMatrixOut outMat, const Matrix44T& inMat);
                    template<class Matrix44T>
                    WIZ_INLINE static Matrix44T& ToMatrix44(Matrix44T& outMat, tMatrixIn inMat);
                    ////////////////////////////////////////////////////////////////
                    ////////////////////////////////////////////////////////////////
                    WIZ_INLINE static tMatrix& Add(tMatrixOut outMat, tMatrixIn inMat1, tMatrixIn inMat2);
                    WIZ_INLINE static tMatrix& AddAssign(tMatrixIO ioMat, tMatrixIn inMat)
                    {
                        return tThis::Add(ioMat, ioMat, inMat);
                    }

                    WIZ_INLINE static tMatrix& Subtract(tMatrixOut outMat, tMatrixIn inMat1, tMatrixIn inMat2);
                    WIZ_INLINE static tMatrix& SubtractAssign(tMatrixIO ioMat, tMatrixIn inMat)
                    {
                        return tThis::Subtract(ioMat, ioMat, inMat);
                    }

                    WIZ_INLINE static tMatrix& Multiply(tMatrixOut outMat, tMatrixIn inMat1, tElementIn inEle);
                    WIZ_INLINE static tMatrix& MultiplyAssign(tMatrixIO ioMat, tElementIn inEle)
                    {
                        return tThis::Multiply(ioMat, ioMat, inEle);
                    }

                    WIZ_INLINE static tMatrix& Multiply(tMatrixOut outMat, tMatrixIn inMat1, tMatrixIn inMat2);
                    WIZ_INLINE static tMatrix& MultiplyAssign(tMatrixIO ioMat, tMatrixIn inMat)
                    {
                        return tThis::Multiply(ioMat, ioMat, inMat);
                    }

                    WIZ_INLINE static tVector2& Multiply(tVector2Out outVec2, const tVector2& inVec2, tMatrixIn inMat);
                    WIZ_INLINE static tVector2& MultiplyAssign(tVector2& ioVec2, tMatrixIn inMat)
                    {
                        return tThis::Multiply(ioVec2, ioVec2, inMat);
                    }
                    ////////////////////////////////////////////////////////////////
                    WIZ_INLINE static ::Wiz::Bool::Type IsEqual(tMatrixIn inMat1, tMatrixIn inMat2);
                    WIZ_INLINE static ::Wiz::Bool::Type NotEqual(tMatrixIn inMat1, tMatrixIn inMat2)
                    {
                        return  tMatrix::IsEqual(inMat1, inMat2) == ::Wiz::Bool::False;
                    }
                    ////////////////////////////////////////////////////////////////
                    WIZ_INLINE static tElement Determinant
                        (
                        tElementIn inE00, tElementIn inE10,
                        tElementIn inE01, tElementIn inE11
                        );
                    WIZ_INLINE static tElement Determinant(tMatrixIn inMat)
                    {
                        return tMatrix::Determinant(inMat.e00, inMat.e10, inMat.e01, inMat.e11);
                    }
                    ////////////////////////////////////////////////////////////////
                    WIZ_INLINE static ::Wiz::Bool::Type Invert(tMatrixOut outMat, tMatrixIn inMat);
                    ////////////////////////////////////////////////////////////////
                    WIZ_INLINE static tMatrix& Transpose(tMatrixOut outMat, tMatrixIn inMat);
                    WIZ_INLINE static tMatrix& Transpose(tMatrixIO ioMat);
                    ////////////////////////////////////////////////////////////////
                    WIZ_INLINE static tMatrix& Identity(tMatrixIO ioMat);
                    WIZ_INLINE static tMatrix& Zero(tMatrixIO ioMat);
                    ////////////////////////////////////////////////////////////////

                    ////////////////////////////////////////////////////////////////
                    WIZ_INLINE static tMatrix& Negative(tMatrixOut outMat, tMatrixIn inMat);
                    ////////////////////////////////////////////////////////////////
                }; /// end of struct Type
            } /// end of namespace Method
        } /// end of namespace ColMajor
    } /// end of namespace Matrix22
} /// end of namespace Wiz

#include "./WizMathMatrix22ColMajorMethod.inl"

#endif /*__WIZ_MATH_MATRIX22_COLMAJOR_METHOD_HPP__SHANHAOBO_19800429__*/
