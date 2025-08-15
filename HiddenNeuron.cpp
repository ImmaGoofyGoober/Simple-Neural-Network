#include "Utilities.hpp"
#include "HiddenNeuron.hpp"


void HiddenNeuron::Update(const std::vector<double>& inputs, HiddenNeuronParams& params, const double learningRate, const std::vector<double>& outputDeltas, const std::vector<double>& weightsToOutputs) {
    double totalDelta = 0.0;
    for (int i = 0; i < outputDeltas.size(); i++) {
        totalDelta += outputDeltas[i] * weightsToOutputs[i];
    }

    double delta = totalDelta * params.output * (1.0 - params.output);

    // Update each input weight
    for (int i = 0; i < params.weights.size(); i++) {
        params.weights[i] -= learningRate * delta * inputs[i];
    }

    // Update bias
    params.bias -= learningRate * delta;
}

void HiddenNeuron::CalcOutput(const std::vector<double>& inputs, HiddenNeuronParams& params) {
    double sum = params.bias;
    for (int i = 0; i < inputs.size(); i++) {
        sum += inputs[i] * params.weights[i];
    }
    params.output = CalcSigmoid(sum);

}

