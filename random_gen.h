#include <random>

class RandomNGenerator {

public:
	static double returnRandomD(int start, int end) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dis(start,end);
		return dis(gen);
	}

	static int returnRandomI(int start, int end) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(start,end);
		return dis(gen);
	}
};