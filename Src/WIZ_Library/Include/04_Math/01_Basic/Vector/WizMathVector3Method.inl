#ifndef __WIZ_MATH_VECTOR3_METHOD_INL__SHANHAOBO_19800429__
#define __WIZ_MATH_VECTOR3_METHOD_INL__SHANHAOBO_19800429__

#include "WizMathVector3Method.hpp"

namespace Wiz
{
    namespace Vector3
    {
        namespace Method
        {
            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            VectorT& Type<VectorT>::Add(tVectorOut outVec, tVectorIn inVec1, tVectorIn inVec2)
            {
                outVec.e0 = inVec1.e0 + inVec2.e0;
                outVec.e1 = inVec1.e1 + inVec2.e1;
                outVec.e2 = inVec1.e2 + inVec2.e2;

                return outVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Add(tVectorOut outVec, tVectorIn inVec, tElementIn inEle)
            {
                outVec.e0 = inVec.e0 + inEle;
                outVec.e1 = inVec.e1 + inEle;
                outVec.e2 = inVec.e2 + inEle;

                return outVec;
            }

            template<class VectorT>
            VectorT& Type<VectorT>::AddAssign(tVectorIO ioVec, tVectorIn inVec)

            {
                ioVec.e0 += inVec.e0;
                ioVec.e1 += inVec.e1;
                ioVec.e2 += inVec.e2;

                return ioVec;

            }
            template<class VectorT>
            VectorT& Type<VectorT>::AddAssign(tVectorIO ioVec, tElementIn inEle)

            {
                ioVec.e0 += inEle;
                ioVec.e1 += inEle;
                ioVec.e2 += inEle;

                return ioVec;

            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            VectorT& Type<VectorT>::Subtract(tVectorOut outVec, tVectorIn inVec1, tVectorIn inVec2)
            {
                outVec.e0 = inVec1.e0 - inVec2.e0;
                outVec.e1 = inVec1.e1 - inVec2.e1;
                outVec.e2 = inVec1.e2 - inVec2.e2;

                return outVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Subtract(tVectorOut outVec, tVectorIn inVec, tElementIn inEle)
            {
                outVec.e0 = inVec.e0 - inEle;
                outVec.e1 = inVec.e1 - inEle;
                outVec.e2 = inVec.e2 - inEle;

                return outVec;
            }

            template<class VectorT>
            VectorT& Type<VectorT>::SubtractAssign(tVectorIO ioVec, tVectorIn inVec)

            {
                ioVec.e0 -= inVec.e0;
                ioVec.e1 -= inVec.e1;
                ioVec.e2 -= inVec.e2;


                return ioVec;

            }
            template<class VectorT>
            VectorT& Type<VectorT>::SubtractAssign(tVectorIO ioVec, tElementIn inEle)

            {
                ioVec.e0 -= inEle;
                ioVec.e1 -= inEle;
                ioVec.e2 -= inEle;


                return ioVec;

            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            VectorT& Type<VectorT>::Multiply(tVectorOut outVec, tVectorIn inVec1, tVectorIn inVec2)
            {
                outVec.e0 = inVec1.e0 * inVec2.e0;
                outVec.e1 = inVec1.e1 * inVec2.e1;
                outVec.e2 = inVec1.e2 * inVec2.e2;

                return outVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Multiply(tVectorOut outVec, tVectorIn inVec, tElementIn inEle)
            {
                outVec.e0 = inVec.e0 * inEle;
                outVec.e1 = inVec.e1 * inEle;
                outVec.e2 = inVec.e2 * inEle;

                return outVec;
            }

            template<class VectorT>
            VectorT& Type<VectorT>::MultiplyAssign(tVectorIO ioVec, tVectorIn inVec)

            {
                ioVec.e0 *= inVec.e0;
                ioVec.e1 *= inVec.e1;
                ioVec.e2 *= inVec.e2;


                return ioVec;

            }
            template<class VectorT>
            VectorT& Type<VectorT>::MultiplyAssign(tVectorIO ioVec, tElementIn inEle)

            {
                ioVec.e0 *= inEle;
                ioVec.e1 *= inEle;
                ioVec.e2 *= inEle;


                return ioVec;

            }
            //////////////////////////////////////////////////////////////////////////


            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            VectorT& Type<VectorT>::Divide(tVectorOut outVec, tVectorIn inVec1, tVectorIn inVec2)
            {
                outVec.e0 = inVec1.e0 / inVec2.e0;
                outVec.e1 = inVec1.e1 / inVec2.e1;
                outVec.e2 = inVec1.e2 / inVec2.e2;

                return outVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Divide(tVectorOut outVec, tVectorIn inVec, tElementIn inEle)
            {
                if (::Wiz::Nearly::GreaterZero(inEle))
                {
                    tElement const lRecipEle = 1 / inEle;

                    outVec.e0 = inVec.e0 * lRecipEle;
                    outVec.e1 = inVec.e1 * lRecipEle;
                    outVec.e2 = inVec.e2 * lRecipEle;

                    return outVec;
                }
                return outVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Divide(tVectorOut outVec, tElementIn inEle, tVectorIn inVec)
            {
                outVec.e0 = inEle / inVec.e0;
                outVec.e1 = inEle / inVec.e1;
                outVec.e2 = inEle / inVec.e2;

                return outVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::DivideAssign(tVectorIO ioVec, tVectorIn inVec)

            {
                ioVec.e0 /= inVec.e0;
                ioVec.e1 /= inVec.e1;
                ioVec.e2 /= inVec.e2;


                return ioVec;

            }
            template<class VectorT>
            VectorT& Type<VectorT>::DivideAssign(tVectorIO ioVec, tElementIn inEle)

            {
                if (::Wiz::Nearly::GreaterZero(inEle))
                {
                    tElement const lRecipEle = 1 / inEle;

                    ioVec.e0 *= lRecipEle;
                    ioVec.e1 *= lRecipEle;
                    ioVec.e2 *= lRecipEle;

                }

                return ioVec;

            }
            //////////////////////////////////////////////////////////////////////////

            template<class VectorT>
            VectorT& Type<VectorT>::Cross(tVectorOut outVec, tVectorIn inVec1, tVectorIn inVec2)
            {
                outVec.x = inVec1.y * inVec2.z - inVec1.z * inVec2.y;
                outVec.y = inVec1.z * inVec2.x - inVec1.x * inVec2.z;
                outVec.z = inVec1.x * inVec2.y - inVec1.y * inVec2.x;
                return outVec;
            }

            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::Dot(tVectorIn inVec1, tVectorIn inVec2)
            {
                return inVec1.e0 * inVec2.e0 + inVec1.e1 * inVec2.e1 + inVec1.e2 * inVec2.e2;
            }

            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::AbsDot(tVectorIn inVec1, tVectorIn inVec2)
            {
                return ::Wiz::Abs(inVec1.e0 * inVec2.e0) + ::Wiz::Abs(inVec1.e1 * inVec2.e1) + ::Wiz::Abs(inVec1.e2 * inVec2.e2);
            }

            //////////////////////////////////////////////////////////////////////////

            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::Normalize(tVectorIO ioVec)

            {
                tElement const lLen = Length(ioVec);


                // Will also work for zero-sized Vectors, but will change nothing
                if (::Wiz::Nearly::GreaterZero(lLen))
                {
                    tElement const lRecipLen = 1 / lLen;

                    ioVec.e0 *= lRecipLen;
                    ioVec.e1 *= lRecipLen;
                    ioVec.e2 *= lRecipLen;
                }

                return lLen;
            }

            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::Normalize(tVectorOut outVec, tVectorIn inVec)
            {
                tElement const lLen = Length(inVec);

                // Will also work for zero-sized Vectors, but will change nothing
                if (::Wiz::Nearly::GreaterZero(lLen))
                {
                    tElement const lRecipLen = 1 / lLen;

                    outVec.e0 = inVec.e0 * lRecipLen;
                    outVec.e1 = inVec.e1 * lRecipLen;
                    outVec.e2 = inVec.e2 * lRecipLen;
                }
                else
                {
                    outVec.e0 = inVec.e0;
                    outVec.e1 = inVec.e1;
                    outVec.e2 = inVec.e2;
                }

                return lLen;
            }

            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::SqrLen(tVectorIn inVec)
            {
                return inVec.e0 * inVec.e0 + inVec.e1 * inVec.e1 + inVec.e2 * inVec.e2;
            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::Length(tVectorIn inVec)
            {
                return ::Wiz::Sqrt(SqrLen(inVec));
            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::RecipLen(tVectorIn inVec)
            {
                return ::Wiz::RecipSqrt(SqrLen(inVec));
            }
            //////////////////////////////////////////////////////////////////////////


            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::Distance(tVectorIn inVec1, tVectorIn inVec2)
            {
                return ::Wiz::Sqrt(SqrDist(inVec1, inVec2));
            }
            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::SqrDist(tVectorIn inVec1, tVectorIn inVec2)
            {
                tVector lVec;
                Subtract(lVec, inVec1, inVec2);
                return SqrLen(lVec);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            template<class VectorT>
            ::Wiz::Bool::Type Type<VectorT>::IsAbsoluteEqual(tVectorIn inVec1, tVectorIn inVec2)
            {
                return ::Wiz::Absolute::IsEqual(inVec1.e0, inVec2.e0) && ::Wiz::Absolute::IsEqual(inVec1.e1, inVec2.e1) && ::Wiz::Absolute::IsEqual(inVec1.e2, inVec2.e2);
            }

            template<class VectorT>
            ::Wiz::Bool::Type Type<VectorT>::IsAbsoluteZero(tVectorIn inVec)
            {
                return ::Wiz::Absolute::IsZero(inVec.e0) && ::Wiz::Absolute::IsZero(inVec.e1) && ::Wiz::Absolute::IsZero(inVec.e2);
            }

            template<class VectorT>
            ::Wiz::Bool::Type Type<VectorT>::IsNearlyZero(tVectorIn inVec, tElementIn inTolerance)
            {
                WIZ_ASSERT(::Wiz::Absolute::GreaterZero(inTolerance));
                return ::Wiz::Absolute::inRange(inVec.e0, -inTolerance, inTolerance) && ::Wiz::Absolute::inRange(inVec.e1, -inTolerance, inTolerance) && ::Wiz::Absolute::inRange(inVec.e2, -inTolerance, inTolerance);
            }
            ////////////////////////////////////////////////////////////////
        } /// end of namespace Method
    } /// end of namespace Vector3
} /// end of namespace Wiz

#endif /*__WIZ_MATH_VECTOR3_METHOD_INL__SHANHAOBO_19800429__*/
