#ifndef __WHIMSY_RPG_ATTRIBUTE_HPP__ 
#define __WHIMSY_RPG_ATTRIBUTE_HPP__

#include "../Core/WMSRPGFwdDclr.hpp"
#include "../../../WMS_Framework/Include/Module/WMSAttributeT.hpp"

#include "./WMSRPGAttrDefine.hpp"

namespace wms
{
    namespace RPG
    {
        namespace Attr
        {
            template<class T>
            class Type : public ::wms::Attr::Type<T, ::wms::F32::type>
            {
                typedef ::wms::Attr::Type<T, ::wms::F32::type> tSuper;

            protected:
                RPG::Attr::Category::type   m_Category;

                Type(tValueIn inBaseVal, RPG::Attr::Category::in inCat) : tSuper(inBaseVal), m_Category(inCat)
                {

                }

                virtual ~Type()
                {

                }
            };

            namespace Health
            {
                WMS_CLASS : public RPG::Attr::Type<I32::type>
                {
                protected:
                    typedef public RPG::Attr::Type<I32::type> tSuper;

                public:
                    type(tValueIn inBaseVal);
                    virtual ~type();

                public:

                };
            } /// namespace Health

            namespace HealthMax
            {
                WMS_CLASS: public RPG::Attr::Type<I32::type>
                {
                protected:
                    typedef public RPG::Attr::Type<I32::type> tSuper;

                public:
                    type(tValueIn inBaseVal);
                    virtual ~type();

                public:

                };
            } /// namespace HealthMax
        } /// end of namespace Attr
    } /// end of namespace RPG
} /// end of namespace wms

#endif /// __WHIMSY_RPG_ATTRIBUTE_HPP__
