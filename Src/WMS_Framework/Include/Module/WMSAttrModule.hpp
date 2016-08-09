#ifndef __WHIMSY_ATTRIBUTE_MODULE_HPP__ 
#define __WHIMSY_ATTRIBUTE_MODULE_HPP__

#include "./WMSAttrManager.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace Attr
    {
        namespace Module
        {
            WMS_CLASS: public ::wms::CmpntArray::type
            {
            private:
                typedef ::wms::CmpntArray::type tSuper;

            public:
                type();
                type(::wms::Size::in);
                virtual ~type();

            public:
                template<class T>
                T GetValue(::wms::ID32::in inIdx)
                {
                    typedef Attr::Type<T>   tValidAttrType;
                    Attr::ptr lAttrPtr = GetAttrByIdx(inIdx);
                    if (::Wiz::IsValidPtr(lAttrPtr))
                    {
                        tValidAttrType* lAttrTPtr = ::Wiz::Cast::Static<tValidAttrType*>(lAttrPtr);
                        return lAttrTPtr->GetCurrValue();
                    }

                    return T(0);
                }

            protected:
                Attr::ptr GetAttrByIdx(::wms::ID32::in inIdx);
            };
        } /// end of namespace Module
    } /// end of namespace Attr
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_MODULE_HPP__
