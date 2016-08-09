#include "../SampleBase.hpp"

struct NullANNNeuron : public ::ann::Neuron::type < ::wms::F32::type, ::wms::F64::type >
{
	typedef ::ann::Neuron::type<::wms::F32::type, ::wms::F64::type> tBase;

	NullANNNeuron(tStorage inStorage) : tBase(inStorage)
	{
	}

	virtual ::wms::Void::type Update(tOut outOutput, tInputListIn inInputList)
	{

	}
};

struct NullANNLayer : public ::ann::Layer::type<::wms::F32::type, ::wms::F64::type>
{
	typedef ::ann::Layer::type<::wms::F32::type, ::wms::F64::type> tBase;

	NullANNLayer(tStorage inStorage) : tBase(inStorage)
	{
	}

	virtual tNeuronPtr CreateNeuron(tNeuronStorageIn inStorage) const
	{
		return WIZ_NEW NullANNNeuron(inStorage);
	}

	virtual ::wms::Void::type DestroyNeuron(tNeuronPtr inNeuronPtr) const
	{
		WIZ_DEL inNeuronPtr;
	}
};

struct NullANN : public ::ann::Network::type<::wms::F32::type, ::wms::F64::type>
{
    typedef ::ann::Network::type<::wms::F32::type, ::wms::F64::type> tBase;

    NullANN(tStorage inStorage) : tBase(inStorage)
    {
    }

    virtual tLayerPtr CreateLayer(tLayerStorageIn inStorage) const
    {
        return WIZ_NEW NullANNLayer(inStorage);
    }
    virtual ::wms::Void::type DestroyLayer(tLayerPtr inLayerPtr) const
    {
        WIZ_DEL inLayerPtr;
    }
};

void CreateNULLANN()
{
    NullANN::tStorage lStorage = { 5, 3, 4 };

    NullANN lNetwork(lStorage);
    lNetwork.Initialize();
    lNetwork.Finalize();

    NullANN lNetwork2 = lStorage;
    lNetwork2.Initialize();
    lNetwork2.Finalize();
}

int _tmain(int argc, _TCHAR* argv[])
{
    CreateNULLANN();

    return 0;
}

