#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

#include <Windows.h>

#include "Utilities.hpp"
#include "NetworkParameters.hpp"
#include "InputNeurons.hpp"
#include "HiddenNeurons.hpp"
#include "OutputNeurons.hpp"


int main() {
	NeuronA neuronA;

	NeuronA2 neuronA2;

	OutputNeuronA outputNeuronA;

	for (int iteration = 0; iteration <= 100'000; iteration++) {
		for (int i = 0; i < 4; i++) {
			int inputX = inputs[i][0];
			int inputY = inputs[i][1];
			int target = targets[i];

			neuronA.CalcOutputA(inputX, inputY, biasA, weightAX, weightAY, outputA);

			neuronA2.CalcOutputA2(inputX, inputY, biasA2, weightA2X, weightA2Y, outputA2);

			outputNeuronA.Update(outputA, outputA2, target, learningRate, weightOutX, weightOutY, biasOut, deltaOut);

			neuronA.Update(inputX, inputY, outputA, weightAX, weightAY, biasA, learningRate, deltaOut, weightOutX);
			neuronA2.Update(inputX, inputY, outputA2, weightA2X, weightA2Y, biasA2, learningRate, deltaOut, weightOutY);
		}
	}

	SYSTEMTIME lt;
	GetLocalTime(&lt);

	std::ofstream outputFile("SavedParameters.txt");

	outputFile << "Local Date " << lt.wMonth << "/" << lt.wDay << "/" << lt.wYear << "\n\n";

	outputFile << "WeightAX: " << weightAX << '\n';
	outputFile << "WeightAY: " << weightAY << '\n';
	outputFile << "WeightA2X: " << weightA2X << '\n';
	outputFile << "WeightA2Y: " << weightA2Y << '\n';
	outputFile << "WeightOutX: " << weightOutX << '\n';
	outputFile << "WeightOutY: " << weightOutY << std::endl << std::endl;

	outputFile << "BiasA: " << biasA << '\n';
	outputFile << "BiasA2: " << biasA2 << '\n';
	outputFile << "BiasOut: " << biasOut << '\n';

	return 0;
} 