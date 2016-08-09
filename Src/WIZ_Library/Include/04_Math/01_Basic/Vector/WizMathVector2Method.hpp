#ifndef __WIZ_MATH_VECTOR2_METHOD_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_VECTOR2_METHOD_HPP__SHANHAOBO_19800429__

#include "../../00_Utils/WizMathUtils.hpp"
#include "./WizMathVector2Base.hpp"

namespace Wiz
{
    namespace Vector2
    {
        namespace Method
        {
            template<class VectorT>
            struct WIZ_EXPORT Type
            {
                typedef VectorT                         tVector;
                typedef typename tVector::tElement      tElement;
                typedef Type                            tThis;

                typedef tElement const &                tElementIn;
                typedef tElement &                      tElementOut;

                typedef tVector const &                 tVectorIn;
                typedef tVector &                       tVectorOut;
                typedef tVector &                       tVectorIO;
                ////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tVectorOut Add(tVectorOut outVec, tVectorIn inVec1, tVectorIn inVec2);
                WIZ_INLINE static tVectorOut Add(tVectorOut outVec, tVectorIn inVec, tElementIn inEle);

                WIZ_INLINE static tVectorOut AddAssign(tVectorIO ioVec, tVectorIn inVec);
                WIZ_INLINE static tVectorOut AddAssign(tVectorIO ioVec, tElementIn inEle);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tVectorOut Subtract(tVectorOut outVec, tVectorIn inVec1, tVectorIn inVec2);
                WIZ_INLINE static tVectorOut Subtract(tVectorOut outVec, tVectorIn inVec, tElementIn inEle);

                WIZ_INLINE static tVectorOut SubtractAssign(tVectorIO ioVec, tVectorIn inVec);
                WIZ_INLINE static tVectorOut SubtractAssign(tVectorIO ioVec, tElementIn inEle);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tVectorOut Multiply(tVectorOut outVec, tVectorIn inVec1, tVectorIn inVec2);
                WIZ_INLINE static tVectorOut Multiply(tVectorOut outVec, tVectorIn inVec, tElementIn inEle);

                WIZ_INLINE static tVectorOut MultiplyAssign(tVectorIO ioVec, tVectorIn inVec);
                WIZ_INLINE static tVectorOut MultiplyAssign(tVectorIO ioVec, tElementIn inEle);
                //////////////////////////////////////////////////////////////////////////


                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tVectorOut Divide(tVectorOut outVec, tVectorIn inVec1, tVectorIn inVec2);
                WIZ_INLINE static tVectorOut Divide(tVectorOut outVec, tVectorIn inVec, tElementIn inEle);
                WIZ_INLINE static tVectorOut Divide(tVectorOut outVec, tElementIn inEle, tVectorIn inVec);

                WIZ_INLINE static tVectorOut DivideAssign(tVectorIO ioVec, tVectorIn inVec);
                WIZ_INLINE static tVectorOut DivideAssign(tVectorIO ioVec, tElementIn inEle);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tElement Dot(tVectorIn inVec1, tVectorIn inVec2);
                WIZ_INLINE static tElement AbsDot(tVectorIn inVec1, tVectorIn inVec2);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tElement Normalize(tVectorIO ioVec);
                WIZ_INLINE static tElement Normalize(tVectorOut outVec, tVectorIn inVec);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tElement Length(tVectorIn inVec);
                WIZ_INLINE static tElement SqrLen(tVectorIn inVec);
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
    } /// end of namespace Vector2
} /// end of namespace Wiz

#include "./WizMathVector2Method.inl"

#endif /*__WIZ_MATH_VECTOR2_METHOD_HPP__SHANHAOBO_19800429__*/
