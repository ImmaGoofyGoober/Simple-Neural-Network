#ifndef NETWORKPARAMETERS_HPP
#define NETWORKPARAMETERS_HPP

#include <vector>

struct HiddenNeuronParams {
    std::vector<double> weights;
    double bias;
    double output;
};

struct OutputNeuronParams {
    std::vector<double> weights;
    double bias;
    double output;
    double deltaOut;
};

extern const double learningRate;
extern const int inputs[4][2];
extern const int targets[4];

extern std::vector<HiddenNeuronParams> hiddenNeuronParams;
extern std::vector<OutputNeuronParams> outputNeuronParams;

#endif