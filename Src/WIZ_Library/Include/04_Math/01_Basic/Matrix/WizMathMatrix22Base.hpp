#ifndef __WIZ_MATH_MATRIX22_BASE_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_MATRIX22_BASE_HPP__SHANHAOBO_19800429__

namespace Wiz
{
    //////////////////////////////////////////////////////////////////////////
    namespace Matrix22
    {
        namespace RowMajor
        {
            namespace Base
            {
#       pragma pack(push, 1)
                template<typename ElementT>
                struct Type
                {
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
                        eRowCnt = 2,
                        eColCnt = 2,
                        eCount = eRowCnt * eColCnt,
                        eSize = sizeof(tElement) * eCount
                    };
                    ////////////////////////////////////////////////////////////////
                    typedef tElement                tElementArray[eCount];
                    ////////////////////////////////////////////////////////////////
                    union
                    {
                        ////////////////////////////////////////////////////////////
                        struct 
                        {
                            tElementArray           eAll;
                        };
                        ////////////////////////////////////////////////////////////

                        ////////////////////////////////////////////////////////////
                        struct
                        {
                            tElement                e00, e01;
                            tElement                e10, e11;
                        };
                        struct
                        {
                            tElement                e[eColCnt][eRowCnt];
                        };
                        ////////////////////////////////////////////////////////////
                    };
                    ////////////////////////////////////////////////////////////////
                    Type()
                    {}
                    Type(
                        tElementIn inE00, tElementIn inE01,
                        tElementIn inE10, tElementIn inE11
                        )
                    {
                        this->e00 = inE00; this->e01 = inE01;
                        this->e10 = inE10; this->e11 = inE11;
                    }
                    Type(tElementIn inEle)
                    {
                        this->e00 = inEle; this->e01 = inEle;
                        this->e10 = inEle; this->e11 = inEle;
                    }
                    Type(const Type& inMat)
                    {
                        this->e00 = inMat.e00; this->e01 = inMat.e01;
                        this->e10 = inMat.e10; this->e11 = inMat.e11;
                    }
                    ////////////////////////////////////////////////////////////////
                    tElement& GetElement(I::In Row, I::In Col)
                    {
                        return this->e[Col][Row];
                    }
                    template<I::Type Row, I::Type Col>
                    tElement& GetElement()
                    {
                        return this->e[Col][Row];
                    }
                    ////////////////////////////////////////////////////////////////
                    ::Wiz::Void::Type GetRow(tElement& outX, tElement& outY, U::In Row)
                    {
                        WIZ_ASSERT(Row < eRowCnt);
                        outX = this->GetElement(Row, 0);
                        outY = this->GetElement(Row, 1);
                    }
                    ::Wiz::Void::Type GetCol(tElement& outX, tElement& outY, U::In Col)
                    {
                        WIZ_ASSERT(Col < eColCnt);
                        outX = this->GetElement(0, Col);
                        outY = this->GetElement(1, Col);
                    }

                    ::Wiz::Void::Type SetRow(U::In Row, tElementIn inX, tElementIn inY)
                    {
                        WIZ_ASSERT(Row < eRowCnt);
                        this->GetElement(Row, 0) = inX;
                        this->GetElement(Row, 1) = inY;
                    }
                    ::Wiz::Void::Type SetCol(U::In Col, tElementIn inX, tElementIn inY)
                    {
                        WIZ_ASSERT(Col < eColCnt);
                        this->GetElement(0, Col) = inX;
                        this->GetElement(1, Col) = inY;
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
                    ////////////////////////////////////////////////////////////////
                }; /// end of struct Type
#       pragma pack(pop)
            } /// end of namespace Base
        } /// end of namespace RowMajor

        namespace ColMajor
        {
            namespace Base
            {
#       pragma pack(push, 1)
                template<typename ElementT>
                struct Type
                {
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
                        eRowCnt = 2,
                        eColCnt = 2,
                        eCount = eRowCnt * eColCnt,
                        eSize = sizeof(tElement) * eCount
                    };
                    ////////////////////////////////////////////////////////////////
                    typedef tElement                tElementArray[eCount];
                    ////////////////////////////////////////////////////////////////
                    union
                    {
                        ////////////////////////////////////////////////////////////
                        struct 
                        {
                            tElementArray           eAll;
                        };
                        ////////////////////////////////////////////////////////////

                        ////////////////////////////////////////////////////////////
                        struct
                        {
                            tElement                e00, e10;
                            tElement                e01, e11;
                        };
                        struct
                        {
                            tElement                e[eRowCnt][eColCnt];
                        };
                        ////////////////////////////////////////////////////////////
                    };
                    ////////////////////////////////////////////////////////////////
                    Type()
                    {}
                    Type(
                        tElementIn inE00, tElementIn inE10,
                        tElementIn inE01, tElementIn inE11
                        )
                    {
                        this->e00 = inE00; this->e10 = inE10;
                        this->e01 = inE01; this->e11 = inE11;
                    }
                    Type(tElementIn inEle)
                    {
                        this->e00 = inEle; this->e10 = inEle;
                        this->e01 = inEle; this->e11 = inEle;
                    }
                    Type(const Type& inMat)
                    {
                        this->e00 = inMat.e00; this->e10 = inMat.e10;
                        this->e01 = inMat.e01; this->e11 = inMat.e11;
                    }
                    ////////////////////////////////////////////////////////////////
                    tElement& GetElement(I::In Row, I::In Col)
                    {
                        return this->e[Row][Col];
                    }
                    template<I::Type Row, I::Type Col>
                    tElement& GetElement()
                    {
                        return this->e[Row][Col];
                    }
                    ////////////////////////////////////////////////////////////////
                    ::Wiz::Void::Type GetRow(tElement& outX, tElement& outY, U::In Row)
                    {
                        WIZ_ASSERT(Row < eRowCnt);
                        outX = this->GetElement(Row, 0);
                        outY = this->GetElement(Row, 1);
                    }
                    ::Wiz::Void::Type GetCol(tElement& outX, tElement& outY, U::In Col)
                    {
                        WIZ_ASSERT(Col < eColCnt);
                        outX = this->GetElement(0, Col);
                        outY = this->GetElement(1, Col);
                    }

                    ::Wiz::Void::Type SetRow(U::In Row, tElementIn inX, tElementIn inY)
                    {
                        WIZ_ASSERT(Row < eRowCnt);
                        this->GetElement(Row, 0) = inX;
                        this->GetElement(Row, 1) = inY;
                    }
                    ::Wiz::Void::Type SetCol(U::In Col, tElementIn inX, tElementIn inY)
                    {
                        WIZ_ASSERT(Col < eColCnt);
                        this->GetElement(0, Col) = inX;
                        this->GetElement(1, Col) = inY;
                    }
                    ////////////////////////////////////////////////////////////////
                    WIZ_INLINE ::Wiz::Size::TypeConst GetSizeInByte() const
                    {
                        return eSize;
                    }
                    WIZ_INLINE ::Wiz::Size::TypeConst GetElementCount() const
                    {
                        return eCount;
                    }
                    WIZ_INLINE tElement* GetElementPtr()
                    {
                        return this->e;
                    }
                    ////////////////////////////////////////////////////////////////
                }; /// end of struct Type
#       pragma pack(pop)
            } /// end of namespace Base
        } /// end of namespace ColMajor
    } /// end of namespace Matrix22
} /// end of namespace Wiz

#endif /*__WIZ_MATH_MATRIX22_BASE_HPP__SHANHAOBO_19800429__*/
