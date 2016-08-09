#ifndef __WHIMSY_CORE_COMPONENT_META_PROPERTY_HPP__ 
#define __WHIMSY_CORE_COMPONENT_META_PROPERTY_HPP__

#include "WMSCoreFwdDclr.hpp"

/// CBD  Component-Based Development

namespace wms
{
	namespace Cmpnt
	{
		namespace MetaPrprty
		{
			WMS_CLASS: public ::wms::Obj::Cmpnt::MetaPrprty::type
			{
			public:
				type(::wms::Cmpnt::ptr inOwnerPtr, ::wms::Name::in inName);
				virtual ~type();

			protected:
				::wms::Cmpnt::ptr m_OwnerPtr;
				::wms::Name::type m_Name;
			};

			template<class DataT>
			class Type : public ::wms::Cmpnt::MetaPrprty::type
			{
				typedef ::wms::Cmpnt::MetaPrprty::type	tSuper;
			protected:
				typedef DataT							tData;
				typedef tData*							tDataPtr;
				typedef tData&							tDataRef;
				typedef tDataRef const					tDataIn;

			public:
				Type(::wms::Cmpnt::ptr inOwnerPtr, ::wms::Name::in inName, tDataPtr inDataPtr)
					: tSuper(inOwnerPtr, inName)
					, m_DataPtr(inDataPtr)
					, m_Valid(Bool::True)
				{

				}

				Bool::type  IsValid() const
				{
					return m_Valid;
				}

				operator DataT()
				{
					return *m_DataPtr;
				}

			public:
				virtual Void::type Init() = WIZ_NULL;

			protected:
				tDataPtr		m_DataPtr;

				Bool::type		m_Valid;
			};
		} /// end of namespace MetaPrprty
	} /// end of namespace Cmpnt
} /// end of namespace wms

#endif /// __WHIMSY_CORE_COMPONENT_META_PROPERTY_HPP__
