#ifndef __WHIMSY_ATTRIBUTE_REQUEST_HPP__ 
#define __WHIMSY_ATTRIBUTE_REQUEST_HPP__

#include "../Core/WMSFrmwrkFwdDclr.hpp"

namespace wms
{
    namespace Attr
    {
        namespace Request
        {
            WMS_CLASS
            {
            public:
                ID32::type      m_ID;
                ID32::type      m_LayerID;

            public:
                virtual Void::type BreakCallBack() {}
            };
        } /// end of namespace Request
    } /// end of namespace Attr
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_REQUEST_HPP__
