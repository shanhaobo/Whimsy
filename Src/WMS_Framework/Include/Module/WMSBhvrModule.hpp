#ifndef __WHIMSY_BHVRMODULE_HPP__ 
#define __WHIMSY_BHVRMODULE_HPP__

#include "./WMSBehavior.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace BhvrModule
    {
        WMS_CLASS: public ::wms::CmpntArray::type
        {
        private:
            typedef ::wms::CmpntArray::type tSuper;

        public:
            type();
            type(::wms::Size::in);
            virtual ~type();
        };
    } /// end of namespace BhvrModule
} /// end of namespace wms

#endif /// __WHIMSY_BHVRMODULE_HPP__
