#include <random>

class RandomGen {
public:
	static std::minstd_rand gen;

	static int RandomInt(int min = 0, int max = 100);
	static float RandomFloat(float min = 0, float max = 100);
	static int RandomGeometricInt(float mean);
	static int RandomBinomialInt(float range, float mean);
};
