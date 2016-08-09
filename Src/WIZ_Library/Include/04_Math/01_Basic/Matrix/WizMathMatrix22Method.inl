#ifndef __WIZ_MATH_MATRIX22_METHOD_INL__SHANHAOBO_19800429__
#define __WIZ_MATH_MATRIX22_METHOD_INL__SHANHAOBO_19800429__

#include "./WizMathMatrix22RowMajorMethod.hpp"

namespace Wiz
{
    namespace Matrix22
    {
        namespace Method
        {
            ////////////////////////////////////////////////////////////////
            template<class MatrixT>
            MatrixT& Type<MatrixT>::FromElement(tMatrixOut outMat, tElementIn inEle)
            {
                outMat.e[0][0] = inEle;
                outMat.e[0][1] = inEle;

                outMat.e[1][0] = inEle;
                outMat.e[1][1] = inEle;

                return outMat;
            }
            ////////////////////////////////////////////////////////////////
            template<class MatrixT>template<class Matrix22T>
            MatrixT& Type<MatrixT>::FromMatrix22(tMatrixOut outMat, const Matrix22T& inMat)
            {
                /// Notice£ºMatrix22T¡¡is row-major-order or col-major-order
                outMat.e[0][0] = inMat.e00;
                outMat.e[0][1] = inMat.e01;

                outMat.e[1][0] = inMat.e10;
                outMat.e[1][1] = inMat.e11;

                return outMat;
            }
            template<class MatrixT>template<class Matrix22T>
            Matrix22T& Type<MatrixT>::ToMatrix22(Matrix22T& outMat, tMatrixIn inMat)
            {
                outMat.e00 = inMat.e00;
                outMat.e01 = inMat.e01;

                outMat.e10 = inMat.e10;
                outMat.e11 = inMat.e11;

                return outMat;
            }

            template<class MatrixT>template<class Matrix33T>
            MatrixT& Type<MatrixT>::FromMatrix33(tMatrixOut outMat, const Matrix33T& inMat)
            {
                outMat.e00 = inMat.e00;
                outMat.e01 = inMat.e01;

                outMat.e10 = inMat.e10;
                outMat.e11 = inMat.e11;

                return outMat;
            }
            template<class MatrixT>template<class Matrix33T>
            Matrix33T& Type<MatrixT>::ToMatrix33(Matrix33T& outMat, tMatrixIn inMat)
            {
                outMat.e00 = inMat.e00;
                outMat.e01 = inMat.e01;

                outMat.e10 = inMat.e10;
                outMat.e11 = inMat.e11;

                return outMat;
            }

            template<class MatrixT>template<class Matrix44T>
            MatrixT& Type<MatrixT>::FromMatrix44(tMatrixOut outMat, const Matrix44T& inMat)
            {
                outMat.e00 = inMat.e00;
                outMat.e01 = inMat.e01;

                outMat.e10 = inMat.e10;
                outMat.e11 = inMat.e11;

                return outMat;
            }
            template<class MatrixT>template<class Matrix44T>
            Matrix44T& Type<MatrixT>::ToMatrix44(Matrix44T& outMat, tMatrixIn inMat)
            {
                outMat.e00 = inMat.e00;
                outMat.e01 = inMat.e01;

                outMat.e10 = inMat.e10;
                outMat.e11 = inMat.e11;

                return outMat;
            }
            ////////////////////////////////////////////////////////////////
            template<class MatrixT>
            MatrixT& Type<MatrixT>::Add(tMatrixOut outMat, tMatrixIn inMat1, tMatrixIn inMat2)
            {
                outMat.e00 = inMat1.e00 + inMat2.e00;
                outMat.e01 = inMat1.e01 + inMat2.e01;

                outMat.e10 = inMat1.e10 + inMat2.e10;
                outMat.e11 = inMat1.e11 + inMat2.e11;

                return outMat;
            }
            template<class MatrixT>
            MatrixT& Type<MatrixT>::Subtract(tMatrixOut outMat, tMatrixIn inMat1, tMatrixIn inMat2)
            {
                outMat.e00 = inMat1.e00 - inMat2.e00;
                outMat.e01 = inMat1.e01 - inMat2.e01;

                outMat.e10 = inMat1.e10 - inMat2.e10;
                outMat.e11 = inMat1.e11 - inMat2.e11;

                return outMat;
            }
            ////////////////////////////////////////////////////////////////
            template<class MatrixT>
            MatrixT& Type<MatrixT>::Multiply(tMatrixOut outMat, tMatrixIn inMat1, tElementIn inEle)
            {
                outMat.e00 = inMat1.e00 * inEle;
                outMat.e01 = inMat1.e01 * inEle;

                outMat.e10 = inMat1.e10 * inEle;
                outMat.e11 = inMat1.e11 * inEle;

                return outMat;
            }
            template<class MatrixT>
            MatrixT& Type<MatrixT>::Multiply(tMatrixOut outMat, tMatrixIn inMat1, tMatrixIn inMat2)
            {
                tElement const le00 = inMat1.e00 * inMat2.e00 + inMat1.e01 * inMat2.e10;
                tElement const le01 = inMat1.e00 * inMat2.e01 + inMat1.e01 * inMat2.e11;
                tElement const le10 = inMat1.e10 * inMat2.e00 + inMat1.e11 * inMat2.e10;
                tElement const le11 = inMat1.e10 * inMat2.e01 + inMat1.e11 * inMat2.e11;

                /// 
                outMat.e00 = le00;
                outMat.e01 = le01;

                outMat.e10 = le10;
                outMat.e11 = le11;

                return outMat;
            }
            template<class MatrixT>
            ::Wiz::Vector2::Type<typename MatrixT::tElement>& Type<MatrixT>::Multiply(tVector2Out outVec2, const tVector2& inVec2, tMatrixIn inMat)
            {
                /// Row vector /// D3D
                tElement const lx = inVec2.x * inMat.e00 + inVec2.y * inMat.e10;
                tElement const ly = inVec2.x * inMat.e01 + inVec2.y * inMat.e11;

                outVec2.x = lx;
                outVec2.y = ly;

                return outVec2;
            }
            ////////////////////////////////////////////////////////////////
            template<class MatrixT>
            ::Wiz::Bool::Type Type<MatrixT>::IsEqual(tMatrixIn inMat1, tMatrixIn inMat2)
            {
                return
                    ::Wiz::IsEqual(inMat1.e00, inMat2.e00) &&
                    ::Wiz::IsEqual(inMat1.e01, inMat2.e01) &&
                    ::Wiz::IsEqual(inMat1.e10, inMat2.e10) &&
                    ::Wiz::IsEqual(inMat1.e11, inMat2.e11);
            }
            ////////////////////////////////////////////////////////////////
            template<class MatrixT>
            typename MatrixT::tElement Type<MatrixT>::Determinant
                (
                tElementIn inE00, tElementIn inE01,
                tElementIn inE10, tElementIn inE11
                )
            {
                return inE00 * inE11 - inE01 * inE10;
            }
            ////////////////////////////////////////////////////////////////
            template<class MatrixT>
            ::Wiz::Bool::Type Type<MatrixT>::Invert(tMatrixOut outMat, tMatrixIn inMat)
            {
                MatrixT lt = Type<MatrixT>::Determinant(inMat);
                if (::Wiz::IsZero(lt))
                {
                    return ::Wiz::Bool::False;
                }
                lt = 1 / lt;

                tElement const le00 = inMat.e11 * lt;
                tElement const le01 = -inMat.e10 * lt;
                tElement const le10 = -inMat.e01 * lt;
                tElement const le11 = inMat.e00 * lt;

                /// 
                outMat.e00 = le00;
                outMat.e01 = le01;

                outMat.e10 = le10;
                outMat.e11 = le11;

                return ::Wiz::Bool::True;
            }
            ////////////////////////////////////////////////////////////////
            template<class MatrixT>
            MatrixT& Type<MatrixT>::Transpose(tMatrixOut outMat, tMatrixIn inMat)
            {
                tElement const le00 = inMat.e00;
                tElement const le01 = inMat.e10;
                tElement const le10 = inMat.e01;
                tElement const le11 = inMat.e11;

                /// 
                outMat.e00 = le00;
                outMat.e01 = le01;

                outMat.e10 = le10;
                outMat.e11 = le11;

                return outMat;
            }
            template<class MatrixT>
            MatrixT& Type<MatrixT>::Transpose(tMatrixIO ioMat)
            {
                ::Wiz::Swap(ioMat.e01, ioMat.e10);

                return ioMat;
            }
            ////////////////////////////////////////////////////////////////
            template<class MatrixT>
            MatrixT& Type<MatrixT>::Identity(tMatrixIO ioMat)
            {
                ioMat.e00 = 1; ioMat.e01 = 0;
                ioMat.e10 = 0; ioMat.e11 = 1;

                return ioMat;
            }
            template<class MatrixT>
            MatrixT& Type<MatrixT>::Zero(tMatrixIO ioMat)
            {
                ioMat.e00 = 0; ioMat.e01 = 0;
                ioMat.e10 = 0; ioMat.e11 = 0;

                return ioMat;
            }
            ////////////////////////////////////////////////////////////////
        } /// end of namespace Method
    } /// end of namespace Matrix22
} /// end of namespace Wiz

#endif /*__WIZ_MATH_MATRIX22_ROWMAJOR_METHOD_INL__SHANHAOBO_19800429__*/
