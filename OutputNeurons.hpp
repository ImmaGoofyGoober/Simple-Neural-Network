#ifndef OUTPUTNEURONS_HPP
#define OUTPUTNEURONS_HPP

class OutputNeuronA {
private:

public:
	void Update(const double outputA, const double outputA2, const double target, const double learningRate, double& weightOutX, double& weightOutY, double& biasOut, double& deltaOut);
};

#endif