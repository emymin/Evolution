#include "Utils.h"

std::minstd_rand RandomGen::gen;

int RandomGen::RandomInt(int min, int max) {
	std::uniform_int_distribution<> distr(min, max);
	return distr(gen);
}

float RandomGen::RandomFloat(float min, float max) {
	std::uniform_real_distribution<> distr(min, max);
	return distr(gen);
}

int  RandomGen::RandomGeometricInt(float mean) {
	std::geometric_distribution<int> distr(mean);
	return distr(gen);
}

int RandomGen::RandomBinomialInt(float range, float mean) {
	std::binomial_distribution<int> distr(range, mean);
	return distr(gen);
}