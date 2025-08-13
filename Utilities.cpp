#include <cmath>

#include "Utilities.hpp"


double WeightedSum(const double inputX, const double inputY, double bias, double weightX, double weightY) {
	return ((inputX * weightX) + (inputY * weightY) + bias);
}

// Activation Function
double CalcSigmoid(const double weightedSum) {
	return 1.0 / (1.0 + std::exp(-weightedSum));
}
