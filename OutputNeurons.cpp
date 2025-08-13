#include <iostream>

#include "Utilities.hpp"
#include "OutputNeurons.hpp"


// OutputNeuronA
void OutputNeuronA::Update(const double outputA, const double outputA2, const double target, const double learningRate, double& weightOutX, double& weightOutY, double& biasOut, double& deltaOut) {
	double finalOutput = 0.0;

	finalOutput = CalcSigmoid(outputA * weightOutX + outputA2 * weightOutY + biasOut);

	deltaOut = (finalOutput - target) * finalOutput * (1 - finalOutput);

	weightOutX -= learningRate * deltaOut * outputA;
	weightOutY -= learningRate * deltaOut * outputA2;
	biasOut -= learningRate * deltaOut;

	std::cout << finalOutput << "\n";
}
