#ifndef __WIZ_MATH_MATRIX33_BASE_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_MATRIX33_BASE_HPP__SHANHAOBO_19800429__

namespace Wiz
{
    //////////////////////////////////////////////////////////////////////////
    namespace Matrix33
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
                        eRowCnt = 3,
                        eColCnt = 3,
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
                            tElement                e00, e01, e02;
                            tElement                e10, e11, e12;
                            tElement                e20, e21, e22;
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
                        tElementIn inE00, tElementIn inE01, tElementIn inE02,
                        tElementIn inE10, tElementIn inE11, tElementIn inE12,
                        tElementIn inE20, tElementIn inE21, tElementIn inE22
                        )
                    {
                        this->e00 = inE00; this->e01 = inE01; this->e02 = inE02; 
                        this->e10 = inE10; this->e11 = inE11; this->e12 = inE12;
                        this->e20 = inE20; this->e21 = inE21; this->e22 = inE22;
                    }
                    Type(tElementIn inEle)
                    {
                        this->e00 = inEle; this->e01 = inEle; this->e02 = inEle;
                        this->e10 = inEle; this->e11 = inEle; this->e12 = inEle;
                        this->e20 = inEle; this->e21 = inEle; this->e22 = inEle;
                    }
                    Type(const Type& inMat)
                    {
                        this->e00 = inMat.e00; this->e01 = inMat.e01; this->e02 = inMat.e02;
                        this->e10 = inMat.e10; this->e11 = inMat.e11; this->e12 = inMat.e12;
                        this->e20 = inMat.e20; this->e21 = inMat.e21; this->e22 = inMat.e22;
                    }
                    ////////////////////////////////////////////////////////////////
                    tElement& GetElement(I::In Row, I::In Col)
                    {
                        return this->e[Row][Col];
                    }
                    template<I::In Row, I::In Col>
                    tElement& GetElement()
                    {
                        return this->e[Row][Col];
                    }
                    ////////////////////////////////////////////////////////////////
                    ////////////////////////////////////////////////////////////////
                    ::Wiz::Void::Type GetRow(tElement& outX, tElement& outY, tElement& outZ, ::Wiz::U::In Row)
                    {
                        WIZ_ASSERT(Row < eRowCnt);
                        outX = this->GetElement(Row, 0);
                        outY = this->GetElement(Row, 1);
                        outZ = this->GetElement(Row, 2);
                    }
                    ::Wiz::Void::Type GetCol(tElement& outX, tElement& outY, tElement& outZ, ::Wiz::U::In Col)
                    {
                        WIZ_ASSERT(Col < eColCnt);
                        outX = this->GetElement(0, Col);
                        outY = this->GetElement(1, Col);
                        outZ = this->GetElement(2, Col);
                    }

                    ::Wiz::Void::Type SetRow(::Wiz::U::In Row, tElementIn inX, tElementIn inY, tElementIn inZ)
                    {
                        WIZ_ASSERT(Row < eRowCnt);
                        this->GetElement(Row, 0) = inX;
                        this->GetElement(Row, 1) = inY;
                        this->GetElement(Row, 2) = inZ;
                    }
                    ::Wiz::Void::Type SetCol(::Wiz::U::In Col, tElementIn inX, tElementIn inY, tElementIn inZ)
                    {
                        WIZ_ASSERT(Col < eColCnt);
                        this->GetElement(0, Col) = inX;
                        this->GetElement(1, Col) = inY;
                        this->GetElement(2, Col) = inZ;
                    }
                    //////////////////////////////////////////////////////////////////////////
                    template<class Matrix22T, I::Type rj, I::Type ri>
                    WIZ_INLINE Matrix22T& GetCofactor(Matrix22T& outMat) const
                    {
                        ::Wiz::Size::Type i, j, ci, cj;
                        for (j = 0, cj = 0; j < eRowCnt; j++)
                        {
                            if (j != rj)
                            {
                                for (i = 0, ci = 0; i < eColCnt; i++)
                                {
                                    if (i != ri)
                                    {
                                        outMat.GetElement(cj, ci) = this->GetElement(j, i);
                                        ci++;
                                    }
                                }
                                cj++;
                            }
                        }

                        return outMat;
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
                        eRowCnt = 3,
                        eColCnt = 3,
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
                            tElement                e00, e10, e20;
                            tElement                e01, e11, e21;
                            tElement                e02, e12, e22;
                        };
                        struct
                        {
                            tElement                e[eColCnt][eRowCnt];
                        };
                        ////////////////////////////////////////////////////////////
                    };
                    ////////////////////////////////////////////////////////////////

                    ////////////////////////////////////////////////////////////////
                    Type()
                    {}
                    Type(
                        tElementIn inE00, tElementIn inE10, tElementIn inE20,
                        tElementIn inE01, tElementIn inE11, tElementIn inE21,
                        tElementIn inE02, tElementIn inE12, tElementIn inE22
                        )
                    {
                        this->e00 = inE00; this->e10 = inE10; this->e20 = inE20;
                        this->e01 = inE01; this->e11 = inE11; this->e21 = inE21;
                        this->e02 = inE02; this->e12 = inE12; this->e22 = inE22;
                    }
                    Type(tElementIn inEle)
                    {
                        this->e00 = inEle; this->e10 = inEle; this->e20 = inEle;
                        this->e01 = inEle; this->e11 = inEle; this->e21 = inEle;
                        this->e02 = inEle; this->e12 = inEle; this->e22 = inEle;
                    }
                    Type(const Type& inMat)
                    {
                        this->e00 = inMat.e00; this->e10 = inMat.e10; this->e20 = inMat.e20;
                        this->e01 = inMat.e01; this->e11 = inMat.e11; this->e21 = inMat.e21;
                        this->e02 = inMat.e02; this->e12 = inMat.e12; this->e22 = inMat.e22;
                    }
                    ////////////////////////////////////////////////////////////////
                    tElement& GetElement(I::In Row, I::In Col)
                    {
                        return this->e[Col][Row];
                    }
                    template<I::In Row, I::In Col>
                    tElement& GetElement()
                    {
                        return this->e[Col][Row];
                    }
                    ////////////////////////////////////////////////////////////////

                    ////////////////////////////////////////////////////////////////
                    ::Wiz::Void::Type GetRow(tElement& outX, tElement& outY, tElement& outZ, ::Wiz::U::In Row)
                    {
                        WIZ_ASSERT(Row < eRowCnt);
                        outX = this->GetElement(Row, 0);
                        outY = this->GetElement(Row, 1);
                        outZ = this->GetElement(Row, 2);
                    }
                    ::Wiz::Void::Type GetCol(tElement& outX, tElement& outY, tElement& outZ, ::Wiz::U::In Col)
                    {
                        WIZ_ASSERT(Col < eColCnt);
                        outX = this->GetElement(0, Col);
                        outY = this->GetElement(1, Col);
                        outZ = this->GetElement(2, Col);
                    }

                    ::Wiz::Void::Type SetRow(::Wiz::U::In Row, tElementIn inX, tElementIn inY, tElementIn inZ)
                    {
                        WIZ_ASSERT(Row < eRowCnt);
                        this->GetElement(Row, 0) = inX;
                        this->GetElement(Row, 1) = inY;
                        this->GetElement(Row, 2) = inZ;
                    }
                    ::Wiz::Void::Type SetCol(::Wiz::U::In Col, tElementIn inX, tElementIn inY, tElementIn inZ)
                    {
                        WIZ_ASSERT(Col < eColCnt);
                        this->GetElement(0, Col) = inX;
                        this->GetElement(1, Col) = inY;
                        this->GetElement(2, Col) = inZ;
                    }
                    //////////////////////////////////////////////////////////////////////////
                    template<class Matrix22T, I::Type rj, I::Type ri>
                    WIZ_INLINE Matrix22T& GetCofactor(Matrix22T& outMat)
                    {
                        ::Wiz::Size::Type i, j, ci, cj;
                        for (i = 0, ci = 0; i < eColCnt; i++)
                        {
                            if (i != ri)
                            {
                                for (j = 0, cj = 0; j < eRowCnt; j++)
                                {
                                    if (j != rj)
                                    {
                                        outMat.GetElement(cj, ci) = this->GetElement(j, i);
                                        cj++;
                                    }
                                }
                                ci++;
                            }
                        }

                        return outMat;
                    }
                    ////////////////////////////////////////////////////////////////
                    WIZ_INLINE ::Wiz::Size::TypeC GetSizeInByte() const
                    {
                        return eSize;
                    }
                    WIZ_INLINE::Wiz::Size::TypeC GetElementCount() const
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
    } /// end of namespace Matrix33
    //////////////////////////////////////////////////////////////////////////
} /// end of namespace Wiz

#endif /*__WIZ_MATH_MATRIX33_BASE_HPP__SHANHAOBO_19800429__*/
