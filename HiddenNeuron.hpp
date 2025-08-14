#ifndef HIDDENNEURON_HPP
#define HIDDENNEURON_HPP

#include "NetworkParameters.hpp"

class HiddenNeuron {
private:

public:
	void Update(const std::vector<double>& inputs, HiddenNeuronParams& params, const double learningRate, const std::vector<double>& outputDeltas, const std::vector<double>& weightsToOutputs);

	void CalcOutput(const std::vector<double>& inputs, HiddenNeuronParams& params);
};

#endif