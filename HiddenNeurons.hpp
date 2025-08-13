#ifndef HIDDENNEURONS_HPP
#define HIDDENNEURONS_HPP

class NeuronA {
private:

public:
	void Update(const double inputX, const double inputY, const double outputA, double& weightAX, double& weightAY, double& biasA, const double learningRate, const double deltaOut, const double weightOutX);

	void CalcOutputA(const double inputX, const double inputY, const double biasA, const double weightAX, const double weightAY, double& outputA);
};

class NeuronA2 {
private:

public:
	void Update(const double inputX, const double inputY, const double outputA2, double& weightA2X, double& weightA2Y, double& biasA2, const double learningRate, const double deltaOut, const double weightOutY);

	void CalcOutputA2(const double inputX, const double inputY, const double biasA2, const double weightA2X, const double weightA2Y, double& outputA2);
};

#endif