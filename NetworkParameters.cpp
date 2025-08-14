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



/*Local Date 8/14/2025

Starting WeightAX: -0.8
Starting WeightAY: 0.3
Starting WeightA2X: -0.3
Starting WeightA2Y: 0.8
Starting WeightOutX: -0.7
Starting WeightOutY: 0.9

Starting BiasA: 0.5
Starting BiasA2: 0.5
Starting BiasOut: 0.5


Final WeightAX: -7.8196
Final WeightAY: 8.04409
Final WeightA2X: -7.25613
Final WeightA2Y: 7.09472
Final WeightOutX: -14.4354
Final WeightOutY: 14.8693

Final BiasA: 3.90039
Final BiasA2: -3.768
Final BiasOut: 6.97361
*/