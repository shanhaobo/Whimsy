#ifndef __ANN_CORE_STORAGE_HPP__ 
#define __ANN_CORE_STORAGE_HPP__

#include "./ANNCoreFwdDclr.hpp"

namespace ann
{
    namespace Neuron
    {
        namespace Storage
        {
            template <class WeightT = ::wms::F64::type>
            class type : public ::wms::Obj::ANN::type
            {
            public:
                typedef WeightT                                 tWeight;
                typedef typename ::wms::Array<tWeight>::type    tWeightList;
                typedef tWeightList const                       tWeightListC;
                typedef tWeightList &                           tWeightListRef;
                typedef tWeightListC &                          tWeightListRefC;

            public:
                type(::wms::Size::in inInputCnt) : m_WeightList(inInputCnt)
                {
                }

                virtual ~type()
                {
                }

                tWeightListRef GetWeightList()
                {
                    return m_WeightList;
                }

                WIZ_INLINE ::wms::Size::type InputCnt() const
                {
                    return m_WeightList.Size();
                }

            protected:
                tWeightList         m_WeightList;
            };
        } /// end of namespace Storage
    } /// end of namespace Neuron

    namespace Layer
    {
        namespace Storage
        {
            template <class WeightT = ::wms::F64::type>
            class type : public ::wms::Obj::ANN::type
            {
            protected:
                typedef ::ann::Neuron::Storage::type<WeightT>       tNeuron;
                typedef tNeuron *                                   tNeuronPtr;
                typedef tNeuronPtr const                            tNeuronPtrF;
                typedef typename ::wms::Array<tNeuronPtrF>::type    tNeuronList;

                typedef typename tNeuron::tWeight                   tWeight;
                typedef typename tNeuron::tWeightList               tWeightList;
				typedef typename tNeuron::tWeightListRef            tWeightListRef;
				typedef typename tNeuron::tWeightListRefC           tWeightListRefC;

            public:
                type(::wms::Size::in inNeuronCnt, ::wms::Size::in inInputCnt) : m_InputCnt(inInputCnt)
                {
                    m_NeuronList.Clear();
                    for (::wms::Size::type i = 0; i < inNeuronCnt; ++i)
                    {
                        m_NeuronList.PushBack(WIZ_NEW tNeuron(inInputCnt));
                    }
                }

                virtual ~type()
                {
                    ::wms::Size::typec lNeuronCnt = m_NeuronList.Size();
                    for (::wms::Size::type i = 0; i < lNeuronCnt; ++i)
                    {
                        WIZ_DEL m_NeuronList[i];
                    }
                    m_NeuronList.Clear();
                }

            public:
				tWeightListRefC GetWeightList(::wms::I::in inIdx) const
                {
                    tNeuronPtrF lNeuronPtr = GetNeuron(inIdx);
                    WIZ_ASSERT(::Wiz::IsValidPtr(lNeuronPtr));

                    return lNeuronPtr->GetWeightList();
                }

                WIZ_INLINE::wms::Size::type NeuronCnt() const
                {
                    return m_NeuronList.Size();
                }

                WIZ_INLINE::wms::Size::type InputCnt() const
                {
                    return m_InputCnt;
                }

                WIZ_INLINE ::wms::Size::type OutputCnt() const
                {
                    return NeuronCnt();
                }

                tNeuronPtrF GetNeuron(::wms::Size::in inIdx) const
                {
                    WIZ_ASSERT((inIdx >= 0) && (inIdx < m_NeuronList.Size()));
                    return m_NeuronList[inIdx];
                }

            protected:
                tNeuronList         m_NeuronList;

                ::wms::Size::type   m_InputCnt;
            };
        } /// end of namespace Storage
    } /// end of namespace Layer

    namespace Network
    {
        namespace Storage
        {
            template <class WeightT = ::wms::F64::type>
            class type : public ::wms::Obj::ANN::type
            {
            protected:
                typedef ::ann::Layer::Storage::type<WeightT>            tLayer;
                typedef tLayer const                                    tLayerC;
                typedef tLayer &                                        tLayerRef;
                typedef tLayer *                                        tLayerPtr;
                typedef tLayerC *                                       tLayerPtrC;
                typedef tLayerPtr const                                 tLayerPtrF;
                typedef tLayerPtrC const                                tLayerPtrFC;

                typedef typename ::wms::Array<tLayerPtrF>::type         tLayerList;

                typedef ::wms::InitList<::wms::Size::type>::type        tInitList;
                typedef typename tInitList::iterator                    tInitListItr;

            public:
                type(tInitList inInitList)
                {
                    for (tInitListItr tItr = inInitList.begin(); tItr != inInitList.end(); ++tItr)
                    {
                        AppendNewLayer(*tItr);
                    }
                }

                tLayerPtr AppendNewLayer(::wms::Size::in inNeuronCnt)
                {
                    if (inNeuronCnt > 0)
                    {
                        tLayerPtr lLayerPtr = WMS_NULLPTR;

                        ::wms::Size::typec lLayerCnt = m_LayerList.Size();
                        if (lLayerCnt > 0)
                        {
                            tLayerPtrFC lPrevLayerPtr = m_LayerList[lLayerCnt - 1];
                            if (::Wiz::IsValidPtr(lPrevLayerPtr))
                            {
                                lLayerPtr = WIZ_NEW tLayer(inNeuronCnt, lPrevLayerPtr->NeuronCnt());
                            }
                        }
                        else if (lLayerCnt == 0)
                        {
                            if (m_InputCnt == 0)
                            {
                                m_InputCnt = inNeuronCnt;
                            }
                            else
                            {
                                lLayerPtr = WIZ_NEW tLayer(inNeuronCnt, m_InputCnt);
                            }
                        }

                        if (::Wiz::IsValidPtr(lLayerPtr))
                        {
                            m_LayerList.PushBack(lLayerPtr);

                            return lLayerPtr;
                        }

                    }

                    return WMS_NULLPTR;
                }

                tLayerPtrF GetLayer(::wms::Size::in inIdx) const
                {
                    WIZ_ASSERT((inIdx >= 0) && (inIdx < m_LayerList.Size()));
                    return m_LayerList[inIdx];
                }

                WIZ_INLINE ::wms::Size::type LayerCnt() const
                {
                    return m_LayerList.Size();
                }

                WIZ_INLINE ::wms::Size::type InputCnt() const
                {
                    return m_InputCnt;
                }

            protected:
                tLayerList          m_LayerList;

                ::wms::Size::type   m_InputCnt;
            };
        } /// end of namespace Storage
    } /// end of namespace Network
} /// end of namespace ann

#endif /// __ANN_CORE_STORAGE_HPP__
