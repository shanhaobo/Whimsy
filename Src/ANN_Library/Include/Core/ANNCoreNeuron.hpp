#ifndef __ANN_CORE_NEURON_HPP__ 
#define __ANN_CORE_NEURON_HPP__

#include "./ANNCoreFwdDclr.hpp"
#include "./ANNCoreStorage.hpp"

namespace ann
{
    namespace Neuron
    {
        template <class IOT, class WeightT = ::wms::F64::type>
        class type : public ::wms::Obj::ANN::type
        {
        protected:
            typedef IOT                                     tIO;
            typedef tIO &                                   tIORef;
            typedef tIORef                                  tOut;

            typedef typename ::wms::Array<tIO>::type        tInputList;
            typedef tInputList &                            tInputListRef;
            typedef tInputListRef const                     tInputListIn;

            typedef ::ann::Neuron::Storage::type<WeightT>   tStorage;
            typedef tStorage &                              tStorageRef;
            typedef tStorageRef const                       tStorageIn;

            typedef typename tStorage::tWeight              tWeight;
            typedef typename tStorage::tWeightList          tWeightList;
            typedef typename tStorage::tWeightListRef       tWeightListRef;

        public:
            type(tStorageIn inStorage) : m_Storage(inStorage), m_WeightList(inStorage.GetWeightList())
            {
            }

            virtual ~type()
            {
            }

        public:
            virtual ::wms::Void::type Update(tOut outOutput, tInputListIn inInputList) = WIZ_NULL;

        protected:
            tStorageRef         m_Storage;

            tWeightListRef      m_WeightList;
        };
    } /// end of namespace Neuron
} /// end of namespace ann

#endif /// __ANN_CORE_NEURON_HPP__
