#ifndef __WIZ_DESIGNPATTERN_VISITOR_HPP__SHANHAOBO_19800429__
#define __WIZ_DESIGNPATTERN_VISITOR_HPP__SHANHAOBO_19800429__

#include "../../01_Basic/04_TU/WizBasicTUTypeList.hpp"

#include "./WizDPVisitable.hpp"

namespace Wiz
{
    namespace DP
    {
        /// 声明Visitor
        namespace Visitor
        {
            template<class VisitableListT> struct Type;

            namespace Impl
            {
                template <class VisitableT>
                class Type
                {
                protected:
                    typedef VisitableT                      tVisitable;
                    typedef typename tVisitable::tReturn    tReturn;
                    typedef typename tVisitable::tIOParam   tIOParam;
                protected:
                    Type(){}
                public:
                    virtual ~Type(){}
                public:
                    virtual tReturn Visit(tVisitable&, tIOParam) = 0;
                }; /// end of class Type

                template <class HeadT, class TailT>
                class Type< ::Wiz::TypeList::Type<HeadT, TailT> > : public Type<HeadT>, public Type<TailT>
                {
                protected:
                    Type(){}
                public:
                }; /// end of class Type

                template <class HeadT>
                class Type< ::Wiz::TypeList::Type<HeadT, ::Wiz::Null::Type> > : public Type<HeadT>
                {
                protected:
                    Type(){}
                public:
                }; /// end of class Type
            } /// end of namespace Impl
        } /// end of namespace Visitor
    } /// end of namespace DP
} /// end of namespace Wiz

/////////////////////////////////////////////////////////////////////////////////////////

/// WIZ_TYPELIST_1 ~ WIZ_TYPELIST_127
/// 为了加快编译速度，只是用了1~32个(支持1~127个)

#define WIZ_MPP_REPEAT_FILE_BEGIN   1
#define WIZ_MPP_REPEAT_FILE_END     32
#define WIZ_MPP_REPEAT_FILE_1_NAME  "./WizDPVisitorTemplate.hpp"
#undef  WIZ_MPP_REPEAT_FILE_2_NAME
#undef  WIZ_MPP_REPEAT_FILE_3_NAME

#include "../../01_Basic/00_MPP/WizBasicMPPRepeatFile.hpp"

#undef WIZ_MPP_REPEAT_FILE_BEGIN
#undef WIZ_MPP_REPEAT_FILE_END

#undef WIZ_MPP_REPEAT_FILE_1_NAME
#undef WIZ_MPP_REPEAT_FILE_2_NAME
#undef WIZ_MPP_REPEAT_FILE_3_NAME

/////////////////////////////////////////////////////////////////////////////////////////


#endif /*__WIZ_DESIGNPATTERN_VISITOR_HPP__SHANHAOBO_19800429__*/

