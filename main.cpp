#include <iostream>
#include <iomanip>
#include <fstream>

#include <Windows.h>

#include "Utilities.hpp"
#include "NetworkParameters.hpp"
#include "InputNeuron.hpp"
#include "HiddenNeuron.hpp"
#include "OutputNeuron.hpp"


int main() {
	// Add Neurons Under NetworkParameters.cpp
	std::vector<HiddenNeuron> hiddenNeuron(hiddenNeuronParams.size());
	std::vector<OutputNeuron> outputNeuron(outputNeuronParams.size());

	std::cout << "Start\n\n";
	
	for (int iteration = 0; iteration <= 100'000; iteration++) {
		for (int i = 0; i < 4; i++) {
			int inputX = inputs[i][0];
			int inputY = inputs[i][1];
			int target = targets[i];

			
			std::vector<double> hiddenOutput(hiddenNeuron.size());
			std::vector<double> outputDeltas;
			std::vector<double> inputsVec(inputs[i], inputs[i] + sizeof(inputs[i]) / sizeof(inputs[i][0]));
			std::vector<std::vector<double>> weightsToOutput(hiddenNeuron.size(), std::vector<double>(outputNeuron.size()));

			for (int i = 0; i < hiddenNeuron.size(); i++) {
				hiddenNeuron[i].CalcOutput(inputsVec, hiddenNeuronParams[i]);
				hiddenOutput[i] = hiddenNeuronParams[i].output;
			}
			for (int i = 0; i < outputNeuron.size(); i++) {
				double outputValue = outputNeuron[i].Update(outputNeuronParams[i], hiddenOutput, target, learningRate);
				outputNeuron[i].LogResults(inputX, inputY, target, outputValue);
				outputDeltas.push_back(outputNeuronParams[i].deltaOut);
			}
			for (int i = 0; i < hiddenNeuron.size(); i++) {
				for (int j = 0; j < outputNeuron.size(); j++) {
					weightsToOutput[i][j] = outputNeuronParams[j].weights[i];
				}
			}
			for (int i = 0; i < hiddenNeuron.size(); i++) {
				hiddenNeuron[i].Update(inputsVec, hiddenNeuronParams[i], learningRate, outputDeltas, weightsToOutput[i]);
			}
		}
	}
	return 0;
} 
