#ifndef __WIZ_RTTI_METADATA_PROPERTY_HPP__SHANHAOBO_19800429__
#define __WIZ_RTTI_METADATA_PROPERTY_HPP__SHANHAOBO_19800429__

#include "./WizRTTIMetaDataField.hpp"

namespace Wiz
{
    namespace RTTI
    {
        namespace MetaData
        {
            namespace Property
            {
                class Type : public MetaData::Field::Type
                {
                    typedef Type                    tThis;
                    typedef tThis*                  tThisPtr;

                    typedef MetaData::Field::Type   tSuper;

                public:
                    WIZ_DECLARE_RTTI(Type, MetaData::Field::Type);

                };
            } /// end of namespace Property
        } /// end of namespace MetaData
    } /// end of namespace RTTI
} /// end of namespace Wiz

#endif /*__WIZ_RTTI_METADATA_PROPERTY_HPP__SHANHAOBO_19800429__*/
