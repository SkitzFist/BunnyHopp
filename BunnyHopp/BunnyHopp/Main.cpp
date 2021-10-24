#include <iostream>
#include <random>
#include <time.h>
#include "Tree.h"

int main() {

	time_t nTime;
	srand((unsigned)time(&nTime));
	int min = 1;
	int max = 10;
	int nrOfBars = rand() % max + min;
	std::vector<int> bars;
	for (int i = 0; i < nrOfBars; ++i) {
		int nr = rand() % max + min;
		bars.push_back(nr);
	}

	for (unsigned int i = 0; i < bars.size(); ++i) {
		std::cout << i << " = " << bars[i] << '\n';
	}

	std::cout << '\n';

	for (unsigned int i = 0; i < bars.size(); ++i) {
		for (int j = 0; j < bars[i]; ++j) {
			std::cout << "*";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	Tree tree(bars);

	int maxJump = 0;
	for (unsigned int i = 0; i < tree.getNodes().size(); ++i) {
		int jump = tree.getMaxJumps(i, 0);
		std::cout << "Node[" << i << "] max jumps: " << jump << "\n";
		if (jump > maxJump) {
			maxJump = jump;
		}
	}

	std::cout << '\n';
	std::cout << "Maximum number of possible jumps: " << maxJump << std::endl;

	return 0;
}