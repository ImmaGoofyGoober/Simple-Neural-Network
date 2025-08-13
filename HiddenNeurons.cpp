#include "Utilities.hpp"
#include "HiddenNeurons.hpp"


// HiddenNeuronA
void NeuronA::Update(const double inputX, const double inputY, const double outputA, double& weightAX, double& weightAY, double& biasA, const double learningRate, const double deltaOut, const double weightOutX) {
	double deltaA = deltaOut * weightOutX * outputA * (1 - outputA); // call after output
	weightAX -= learningRate * deltaA * inputX;
	weightAY -= learningRate * deltaA * inputY;
	biasA -= learningRate * deltaA;
}

void NeuronA::CalcOutputA(const double inputX, const double inputY, const double biasA, const double weightAX, const double weightAY, double& outputA) {
	outputA = CalcSigmoid(WeightedSum(inputX, inputY, biasA, weightAX, weightAY)); // call first
}

// HiddenNeuronA2
void NeuronA2::Update(const double inputX, const double inputY, const double outputA2, double& weightA2X, double& weightA2Y, double& biasA2, const double learningRate, const double deltaOut, const double weightOutY) {
	double deltaA2 = deltaOut * weightOutY * outputA2 * (1 - outputA2); // call after output
	weightA2X -= learningRate * deltaA2 * inputX;
	weightA2Y -= learningRate * deltaA2 * inputY;
	biasA2 -= learningRate * deltaA2;
}

void NeuronA2::CalcOutputA2(const double inputX, const double inputY, const double biasA2, const double weightA2X, const double weightA2Y, double& outputA2) {
	outputA2 = CalcSigmoid(WeightedSum(inputX, inputY, biasA2, weightA2X, weightA2Y)); // call first
}
