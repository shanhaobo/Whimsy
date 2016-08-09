#ifndef __WIZ_DESIGNPATTERN_VISITABLE_HPP__SHANHAOBO_19800429__
#define __WIZ_DESIGNPATTERN_VISITABLE_HPP__SHANHAOBO_19800429__

namespace Wiz
{
	namespace DP
    {
        /// 声明Visitable
        namespace Visitable
        {
            /// 在使用过程中,必须先声明这个Visitable::Base::Type,然后具体类,使用下面的Visitable::Type
            namespace Base
            {
                template<class VisitorT, class ReturnT, class IOParamT, class BaseT = ::Wiz::Null::Type>
                struct Type : public BaseT
                {
                    typedef VisitorT                    tVisitor;
                    typedef ReturnT                     tReturn;
                    typedef IOParamT                    tIOParam;
                public:
                    Type() : BaseT(){}
                    virtual ~Type(){}

                public:
                    virtual tReturn Accept(VisitorT& VisitorRef, tIOParam ioParam) = 0;

                protected:
                    template<class T>
                    static tReturn StaticAcceptImpl(T* inVisitablePtr, VisitorT& VisitorRef, tIOParam ioParam)
                    {
                        return VisitorRef.Visit(*inVisitablePtr, ioParam);
                    }
                }; /// end of struct Type
            } /// end of namespace Base

            template<class DerivedT, class BaseT>
            struct Type : public BaseT
            {
                typedef BaseT                       tSuper;

                typedef typename tSuper::tVisitor   tVisitor;
                typedef typename tSuper::tIOParam   tIOParam;
                typedef typename tSuper::tReturn    tReturn;
            public:
                Type() : tSuper(){}
                virtual ~Type(){}

            public:
                virtual tReturn Accept(tVisitor& VisitorRef, tIOParam ioParam)
                {
                    return StaticAcceptImpl<DerivedT>(::Wiz::Cast::Static<DerivedT*>(this), VisitorRef, ioParam);
                }
            }; /// end of struct Type
        } /// end of namespace Visitable
	} /// end of namespace DesignPattern
} /// end of namespace Wiz

#endif /*__WIZ_DESIGNPATTERN_VISITABLE_HPP__SHANHAOBO_19800429__*/
