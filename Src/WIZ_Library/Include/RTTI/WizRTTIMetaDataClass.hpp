#ifndef __WIZ_RTTI_METADATA_CLASS_HPP__SHANHAOBO_19800429__
#define __WIZ_RTTI_METADATA_CLASS_HPP__SHANHAOBO_19800429__

#include "./WizRTTIMetaDataStruct.hpp"

namespace Wiz
{
    namespace RTTI
    {
        namespace MetaData
        {
            namespace Class
            {
                class Type : public MetaData::Struct::Type
                {
                public:
                    WIZ_DECLARE_RTTI(Type, MetaData::Struct::Type);

                    typedef Type                    tThis;
                    typedef tThis*                  tThisPtr;

                    typedef MetaData::Struct::Type  tSuper;
                };
            } /// end of namespace Class
        } /// end of namespace MetaData
    } /// end of namespace RTTI
} /// end of namespace Wiz

#endif /*__WIZ_RTTI_METADATA_CLASS_HPP__SHANHAOBO_19800429__*/
