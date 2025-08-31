#ifndef OUTPUTNEURON_HPP
#define OUTPUTNEURON_HPP

#include "NetworkParameters.hpp"

class OutputNeuron {
private:

public:
	double Update(OutputNeuronParams& params, const std::vector<double>& hiddenOutput, const double target, const double learningRate);

	void LogResults(const int inputX, const int inputY, const int target, const double outputValue);
};


#endif
