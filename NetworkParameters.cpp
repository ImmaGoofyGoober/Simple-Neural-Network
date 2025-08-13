// Neuron weights
double weightAX = -0.8;
double weightAY = 0.3;

double weightA2X = -0.3;
double weightA2Y = 0.8;

double weightOutX = -0.7;
double weightOutY = 0.9;

// Neuron biases
double biasA = 0.5;
double biasA2 = 0.5;
double biasOut = 0.5;

// Network state
double outputA = 0.0;
double outputA2 = 0.0;
double deltaOut = 0.0;

// Training
double learningRate = 0.1;
int inputs[4][2] = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };
int targets[4] = { 0, 1, 1, 0 };