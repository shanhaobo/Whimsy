#ifndef __ANN_CORE_NETWORK_HPP__ 
#define __ANN_CORE_NETWORK_HPP__

#include "ANNCoreNeuron.hpp"

namespace ann
{
    namespace Network
    {
        template <class IOT, class WeightT = ::wms::F64::type>
        class type : public ::ann::Obj::type
        {
        public:
            typedef WeightT                                 tWeight;
            typedef IOT                                     tIO;

            typedef typename ::wms::Array<tIO>::type        tIOList;

            typedef ::ann::Network::Storage::type<tWeight>  tStorage;
            typedef tStorage &                              tStorageRef;
            typedef tStorageRef const                       tStorageIn;

        protected:
            typedef tIOList &                               tIOListRef;
            typedef tIOListRef const                        tIOListIn;
            typedef tIOList *                               tIOListPtr;
            typedef tIOList const *                         tIOListPtrC;


            typedef ::wms::InitList<::wms::U::type>::type   tInitList;
            typedef typename tInitList::iterator            tInitListItr;

            typedef ::ann::Layer::type<tIO, tWeight>        tLayer;
            typedef tLayer &                                tLayerRef;
            typedef tLayer *                                tLayerPtr;
            typedef tLayerPtr const                         tLayerPtrF;

            typedef typename ::wms::Array<tLayerPtrF>::type tLayerList;


            typedef ::ann::Layer::Storage::type<tWeight>    tLayerStorage;
            typedef tLayerStorage &                         tLayerStorageRef;
            typedef tLayerStorage const                     tLayerStorageIn;

        public:
            type(tStorageIn inStorage)
                : m_Storage(inStorage)
                , m_InputCnt(inStorage.InputCnt())
            {

            }

            virtual ~type()
            {
            }

        public:
            ::wms::Bool::type Initialize()
            {
                ::wms::Size::typec lLayerCnt = m_Storage.LayerCnt();
                for (::wms::Size::type i = 0; i < lLayerCnt; ++i)
                {
                    tLayerPtr lLayerPtr = AppendNewLayer();
                    if (::Wiz::IsValidPtr(lLayerPtr))
                    {
                        lLayerPtr->Initialize();
                    }
                }

                return ::wms::Bool::True;
            }

            ::wms::Void::type Finalize()
            {
                ::wms::Size::typec lLayerCnt = m_LayerList.Size();
                for (::wms::U::type i = 0; i < lLayerCnt; ++i)
                {
                    tLayerPtr lLayerPtr = m_LayerList[i];
                    if (::Wiz::IsValidPtr(lLayerPtr))
                    {
                        lLayerPtr->Finalize();
                        DestroyLayer(m_LayerList[i]);
                    }
                }

                m_LayerList.Clear();
            }

        protected:
            tLayerPtr AppendNewLayer()
            {
                ::wms::Size::typec lLayerCnt = m_LayerList.Size();

                tLayerPtr lLayerPtr = CreateLayer(*(m_Storage.GetLayer(lLayerCnt)));
                if (::Wiz::IsValidPtr(lLayerPtr))
                {
                    m_LayerList.PushBack(lLayerPtr);

                    return lLayerPtr;
                }

                return WMS_NULLPTR;
            }

        public:
            virtual ::wms::Void::type Update(tIOListIn inInputDatum)
            {
                tIOListPtr lPrevLayerIOListPtr = &inInputDatum;

                ::wms::Size::typec lLayerCnt = m_LayerList.Size();
                for (::wms::U::type i = 0; i < lLayerCnt; ++i)
                {
                    tLayerPtr lLayerPtr = m_LayerList[i];
                    if (::Wiz::IsValidPtr(lLayerPtr))
                    {
                        /// Travel all of layers, The last layer's output  AS current layer's input.
                        lPrevLayerIOListPtr = &(lLayerPtr->Update(*lPrevLayerIOListPtr));
                    }
                }
            }

        public:
            virtual tLayerPtr CreateLayer(tLayerStorageIn inLayerStorage) const = WIZ_NULL;
            virtual ::wms::Void::type DestroyLayer(tLayerPtr inLayerPtr) const = WIZ_NULL;

        protected:
            ::wms::U::type      m_InputCnt;

            tLayerList          m_LayerList;

            tStorageRef         m_Storage;
        };
    } /// end of namespace Network
} /// end of namespace ann

#endif /// __ANN_CORE_NETWORK_HPP__
