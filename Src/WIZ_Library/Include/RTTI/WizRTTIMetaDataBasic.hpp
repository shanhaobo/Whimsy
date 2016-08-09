#ifndef __WIZ_RTTI_METADATA_BASIC_HPP__SHANHAOBO_19800429__
#define __WIZ_RTTI_METADATA_BASIC_HPP__SHANHAOBO_19800429__

#include "../01_Basic/01_Type/WizBasicType.hpp"
#include "../01_Basic/02_MU/WizBasicMURTTI.hpp"
#include "../01_Basic/04_TU/WizBasicTU.hpp"
#include "../01_Basic/05_Mem/WizBasicMem.hpp"

#include "../02_Adv/01_Type/WizAdvBitsfield.hpp"

namespace Wiz
{
    namespace RTTI
    {
        namespace MetaData
        {
            namespace Object
            {
                namespace OBJ_CAT
                {
                    enum eOC_Object
                    {
                    };
                };

                namespace Allocator
                {
                    namespace Object
                    {
                        typedef ::Wiz::Allocator::Categorized<OBJ_CAT::eOC_Object>::Type      Type;
                    } /// end of namespace Object
                } /// end of namespace Allocator

                typedef ::Wiz::MemObj::Type<Allocator::Object::Type>    Type;
            } /// end of namespace Object

            namespace Field
            {
                WIZ_FORWARD_DECLARE_CLASS;
            } /// end of namespace Field

            namespace Property
            {
                WIZ_FORWARD_DECLARE_CLASS;
            } /// end of namespace Property

            namespace Struct
            {
                WIZ_FORWARD_DECLARE_CLASS;
            } /// end of namespace Struct

            namespace Class
            {
                WIZ_FORWARD_DECLARE_CLASS;
            } /// end of namespace Class

            namespace Function
            {
                WIZ_FORWARD_DECLARE_CLASS;
            } /// end of namespace Function
        } /// end of namespace MetaData
    } /// end of namespace RTTI
} /// end of namespace Wiz

#endif /*__WIZ_RTTI_METADATA_BASIC_HPP__SHANHAOBO_19800429__*/
