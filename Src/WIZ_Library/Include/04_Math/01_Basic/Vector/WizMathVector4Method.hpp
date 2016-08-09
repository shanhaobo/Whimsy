#ifndef __WIZ_MATH_VECTOR4_METHOD_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_VECTOR4_METHOD_HPP__SHANHAOBO_19800429__

#include "../../00_Utils/WizMathUtils.hpp"

namespace Wiz
{
    namespace Vector4
    {
        namespace Method
        {
            template<class VectorT>
            struct Type
            {
                //////////////////////////////////////////////////////////////////////////
                typedef VectorT                         tVector;
                typedef typename tVector::tElement      tElement;
                typedef Type                            tThis;


                typedef tElement const &                tElementIn;
                typedef tElement &                      tElementOut;

                typedef tVector const &                 tVectorIn;
                typedef tVector &                       tVectorOut;
                typedef tVector &                       tVectorIO;
                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tVector& Add(tVectorOut outVec, tVectorIn inVec1, tVectorIn inVec2);
                WIZ_INLINE static tVector& Add(tVectorOut outVec, tVectorIn inVec, tElementIn inEle);

                WIZ_INLINE static tVector& AddAssign(tVectorIO ioVec, tVectorIn inVec);
                WIZ_INLINE static tVector& AddAssign(tVectorIO ioVec, tElementIn inEle);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tVector& Subtract(tVectorOut outVec, tVectorIn inVec1, tVectorIn inVec2);
                WIZ_INLINE static tVector& Subtract(tVectorOut outVec, tVectorIn inVec, tElementIn inEle);

                WIZ_INLINE static tVector& SubtractAssign(tVectorIO ioVec, tVectorIn inVec);
                WIZ_INLINE static tVector& SubtractAssign(tVectorIO ioVec, tElementIn inEle);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tVector& Multiply(tVectorOut outVec, tVectorIn inVec1, tVectorIn inVec2);
                WIZ_INLINE static tVector& Multiply(tVectorOut outVec, tVectorIn inVec, tElementIn inEle);

                WIZ_INLINE static tVector& MultiplyAssign(tVectorIO ioVec, tVectorIn inVec);
                WIZ_INLINE static tVector& MultiplyAssign(tVectorIO ioVec, tElementIn inEle);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tVector& Divide(tVectorOut outVec, tVectorIn inVec1, tVectorIn inVec2);
                WIZ_INLINE static tVector& Divide(tVectorOut outVec, tVectorIn inVec, tElementIn inEle);
                WIZ_INLINE static tVector& Divide(tVectorOut outVec, tElementIn inEle, tVectorIn inVec);

                WIZ_INLINE static tVector& DivideAssign(tVectorIO ioVec, tVectorIn inVec);
                WIZ_INLINE static tVector& DivideAssign(tVectorIO ioVec, tElementIn inEle);
                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tElement Dot(tVectorIn inVec1, tVectorIn inVec2);
                WIZ_INLINE static tElement AbsDot(tVectorIn inVec1, tVectorIn inVec2);
                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tElement Normalize(tVectorIO ioVec);
                WIZ_INLINE static tElement Normalize(tVectorOut outVec, tVectorIn inVec);
                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tElement SqrLen(tVectorIn inVec);
                WIZ_INLINE static tElement Length(tVectorIn inVec);
                WIZ_INLINE static tElement RecipLen(tVectorIn inVec);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tElement Distance(tVectorIn inVec1, tVectorIn inVec2);
                WIZ_INLINE static tElement SqrDist(tVectorIn inVec1, tVectorIn inVec2);
                ////////////////////////////////////////////////////////////////

                ////////////////////////////////////////////////////////////////
                WIZ_INLINE static ::Wiz::Bool::Type IsAbsoluteEqual(tVectorIn inVec1, tVectorIn inVec2);
                WIZ_INLINE static ::Wiz::Bool::Type IsAbsoluteZero(tVectorIn inVec);
                WIZ_INLINE static ::Wiz::Bool::Type IsNearlyZero(tVectorIn inVec, tElementIn inTolerance);
                ////////////////////////////////////////////////////////////////
            }; /// end of struct Type
        } /// end of namespace Method
    } /// end of namespace Vector4
} /// end of namespace Wiz

#include "./WizMathVector4Method.inl"

#endif /*__WIZ_MATH_VECTOR4_METHOD_HPP__SHANHAOBO_19800429__*/
