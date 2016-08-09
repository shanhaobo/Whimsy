#ifndef __WIZ_MATH_VECTOR3_BASE_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_VECTOR3_BASE_HPP__SHANHAOBO_19800429__

namespace Wiz
{
    namespace Vector3
    {
        namespace Base
        {
#       pragma pack(push, 1)
            template<typename ElementT>
            struct Type
            {
                ////////////////////////////////////////////////////////////////

                typedef ElementT            tElement;

                typedef tElement const &    tElementIn;
                typedef tElement &          tElementOut;
                typedef tElementOut         tElementIO;

                typedef Type<tElement>      tThis;
                typedef tThis const &       tThisIn;
                typedef tThis &             tThisOut;

                ////////////////////////////////////////////////////////////////
                enum
                {
                    eCount = 3,
                    eSize = sizeof(tElement) * eCount,
                };
                ////////////////////////////////////////////////////////////////
                typedef tElement            tElementArray[eCount];
                ////////////////////////////////////////////////////////////////
                union
                {
                    struct
                    {
                        tElement              x, y, z;
                    };
                    struct
                    {
                        tElement              X, Y, Z;
                    };
                    struct
                    {
                        tElement              e0, e1, e2;
                    };
                    struct
                    {

                        tElement              e[eCount];
                    };
                    struct
                    {
                        tElementArray         v;
                    };
                };
                ////////////////////////////////////////////////////////////////
                Type()
                {}
                Type(tElementIn inX, tElementIn inY, tElementIn inZ)
                {
                    this->x = inX;
                    this->y = inY;
                    this->z = inZ;
                }
                Type(tElementIn inEle) 
                {
                    this->x = inEle;
                    this->y = inEle;
                    this->z = inEle;
                }
                Type(tThisIn inOther)
                {
                    this->x = inOther.x;
                    this->y = inOther.y;
                    this->z = inOther.z;
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE ::Wiz::Size::TypeC GetSizeInByte() const
                {
                    return eSize;
                }
                WIZ_INLINE ::Wiz::Size::TypeC GetElementCount() const
                {
                    return eCount;
                }
                WIZ_INLINE tElement* GetElementPtr()
                {
                    return this->e;
                }
            };
#       pragma pack(pop)
        } /// end of namespace Base
    } /// end of namespace Vector3
} /// end of namespace Wiz

#endif /*__WIZ_MATH_VECTOR3_BASE_HPP__SHANHAOBO_19800429__*/
