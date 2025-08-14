#include <iostream>

#include "Utilities.hpp"
#include "OutputNeuron.hpp"


double OutputNeuron::Update(OutputNeuronParams& params, const std::vector<double>& hiddenOutput, const double target, const double learningRate) {
	double sum = params.bias;
	for (int i = 0; i < params.weights.size(); i++) {
		sum += params.weights[i] * hiddenOutput[i];
	}

	double outputValue = CalcSigmoid(sum);

	params.deltaOut = (outputValue - target) * outputValue * (1 - outputValue);

	for (int i = 0; i < params.weights.size(); i++) {
		params.weights[i] -= learningRate * params.deltaOut * hiddenOutput[i];
	}
	return outputValue;
}

int tempCount = 1;

void OutputNeuron::LogResults(const int inputX, const int inputY, const int target, const double outputValue) {
	std::cout << "Input{" << inputX << ", " << inputY << "} | Target{" << target << "} | Result{" << outputValue << "}\n";
	tempCount++;
}