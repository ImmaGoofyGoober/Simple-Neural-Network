#include "NetworkParameters.hpp"


// Add Neurons
std::vector<HiddenNeuronParams> hiddenNeuronParams = { 
	{ { -0.8, 0.3 }, 0.5, 0.0},
	{ { -0.3, 0.8 }, 0.5, 0.0 }
};
std::vector<OutputNeuronParams> outputNeuronParams = {
	{{ -0.7, 0.9 }, 0.5 }
};

// Training
const double learningRate = 0.1;
const int inputs[4][2] = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };
const int targets[4] = { 0, 1, 1, 0 };


