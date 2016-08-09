#ifndef __ANN_CORE_LAYER_HPP__ 
#define __ANN_CORE_LAYER_HPP__

#include "ANNCoreNeuron.hpp"

namespace ann
{
    namespace Layer
    {
        template <class IOT, class WeightT = ::wms::F64::type>
        class type : public ::wms::Obj::ANN::type
        {
        protected:
            typedef IOT                                         tIO;

            typedef typename ::wms::Array<tIO>::type            tIOList;
            typedef tIOList &                                   tIOListRef;
            typedef tIOListRef const                            tIOListRefC;
            typedef tIOListRef const                            tIOListIn;
            typedef tIOListRef                                  tIOListOut;
            typedef tIOListRef const                            tIOListOutC;

            typedef WeightT                                     tWeight;

            typedef ::ann::Layer::Storage::type<tWeight>        tStorage;
            typedef tStorage &                                  tStorageRef;
            typedef tStorageRef const                           tStorageIn;

            typedef ::ann::Neuron::Storage::type<tWeight>       tNeuronStorage;
            typedef tNeuronStorage &                            tNeuronStorageRef;
            typedef tNeuronStorage const                        tNeuronStorageIn;

            typedef ::ann::Neuron::type<tIO, tWeight>           tNeuron;
            typedef tNeuron &                                   tNeuronRef;
            typedef tNeuron *                                   tNeuronPtr;
            typedef tNeuronPtr const                            tNeuronPtrF;

            typedef typename ::wms::Array<tNeuronPtrF>::type    tNeuronList;

        public:
            type(tStorageIn inStorage)
                : m_Storage(inStorage)
                , m_OutputList(inStorage.NeuronCnt())
            {
            }
            virtual ~type()
            {
            }
        public:
            ::wms::Bool::type Initialize()
            {
                m_NeuronList.Clear();

                ::wms::Size::type lNeuronCnt = m_NeuronList.Size();
                for (::wms::Size::type i = 0; i < lNeuronCnt; ++i)
                {
                    m_NeuronList.PushBack(CreateNeuron(*(m_Storage.GetNeuron(i))));
                }

                return ::wms::Bool::True;
            }

            ::wms::Void::type Finalize()
            {
                ::wms::Size::typec lNeuronCnt = m_NeuronList.Size();
                for (::wms::Size::type i = 0; i < lNeuronCnt; ++i)
                {
                    DestroyNeuron(m_NeuronList[i]);
                }

                m_NeuronList.Clear();
            }

        public:
            virtual tIOListRefC Update(tIOListIn inInputList)
            {
                ::wms::Size::typec lNeuronCnt = m_NeuronList.Size();
                for (::wms::Size::type i = 0; i < lNeuronCnt; ++i)
                {
                    tNeuronPtrF lNeuronPtr = m_NeuronList[i];
                    if (::Wiz::IsValidPtr(lNeuronPtr))
                    {
                        lNeuronPtr->Update(m_OutputList[i], inInputList);
                    }
                }

                return m_OutputList;
            }

            WIZ_INLINE ::wms::Size::typec NeuronCnt() const
            {
                return m_NeuronList.Size();
            }

            WIZ_INLINE ::wms::Size::typec InputCnt() const
            {
                return m_Storage.InputCnt();
            }

        public:
            virtual tNeuronPtr CreateNeuron(tNeuronStorageIn inStorage) const = WIZ_NULL;
            virtual ::wms::Void::type DestroyNeuron(tNeuronPtr inNeuronPtr) const = WIZ_NULL;

        protected:
            tStorageRef         m_Storage;

            tNeuronList         m_NeuronList;

            /// 这个输出将作为最后输出,或者下一层的输入
            tIOList             m_OutputList;
        };
    } /// end of namespace Layer
} /// end of namespace ann

#endif /// __ANN_CORE_LAYER_HPP__
