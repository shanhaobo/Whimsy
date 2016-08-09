#ifndef __WIZ_RTTI_METADATA_FIELD_HPP__SHANHAOBO_19800429__
#define __WIZ_RTTI_METADATA_FIELD_HPP__SHANHAOBO_19800429__

#include "./WizRTTIMetaDataBasic.hpp"

namespace Wiz
{
    namespace RTTI
    {
        namespace MetaData
        {
            namespace Field
            {
                class Type : public MetaData::Object::Type
                {
                public:
                    WIZ_DECLARE_RTTI_BASE(Type);

                    typedef Type        tThis;
                    typedef tThis*      tThisPtr;

                protected:
                    typedef tThis       tField;
                    typedef tThisPtr    tFieldPtr;

                public:

                protected:
                    tFieldPtr                           m_SiblingPtr;

                    ::Wiz::Bitsfield64::Type            m_CastFlags;
                };
            } /// end of namespace Field
        } /// end of namespace MetaData
    } /// end of namespace RTTI
} /// end of namespace Wiz

#endif /*__WIZ_METADATA_FIELD_HPP__SHANHAOBO_19800429__*/
