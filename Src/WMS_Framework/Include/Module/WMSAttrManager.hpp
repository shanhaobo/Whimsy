#ifndef __WHIMSY_ATTRIBUTE_MANAGER_HPP__ 
#define __WHIMSY_ATTRIBUTE_MANAGER_HPP__

#include "./WMSAttributeT.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace Attr
    {
        namespace Manager
        {
            WMS_CLASS : public ::wms::CmpntArray::type
            {
            private:
                typedef ::wms::CmpntArray::type tSuper;

            public:
                type();
                type(::wms::Size::in);
                virtual ~type();

            public:
                template<class T>
                Bool::type GetValue(T& outValue, ::wms::Size::in inIdx)
                {
                    typedef Attr::Type<T>   tValidAttrType;

                    Attr::ptr       lAttrPtr = GetAttrByIdx(inIdx);
                    tValidAttrType* lAttrTPtr = ::Wiz::Cast::Static<tValidAttrType*>(lAttrPtr);
                    if (::Wiz::IsValidPtr(lAttrTPtr))
                    {
                        outValue = lAttrTPtr->GetCurrValue();

                        return Bool::True;
                    }

                    return Bool::False;
                }

                Attr::ptr GetAttrByIdx(::wms::Size::in inIdx);
            protected:
            };
        } /// end of namespace Manager
    } /// end of namespace Attr
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_MANAGER_HPP__
