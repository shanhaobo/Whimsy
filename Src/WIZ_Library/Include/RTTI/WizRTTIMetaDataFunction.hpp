#ifndef __WIZ_RTTI_METADATA_FUNCTION_HPP__SHANHAOBO_19800429__
#define __WIZ_RTTI_METADATA_FUNCTION_HPP__SHANHAOBO_19800429__

#include "./WizRTTIMetaDataStruct.hpp"

namespace Wiz
{
    namespace RTTI
    {
        namespace MetaData
        {
            namespace Function
            {
                class Type : public MetaData::Struct::Type
                {
                    typedef Type                    tThis;
                    typedef tThis*                  tThisPtr;

                    typedef MetaData::Struct::Type  tSuper;

                public:
                    WIZ_DECLARE_RTTI(Type, MetaData::Struct::Type);

                };
            } /// end of namespace Function
        } /// end of namespace MetaData
    } /// end of namespace RTTI
} /// end of namespace Wiz

#endif /*__WIZ_RTTI_METADATA_FUNCTION_HPP__SHANHAOBO_19800429__*/
