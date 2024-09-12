#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Too little arguments" << std::endl;
		exit(1);
	}
	PmergeMe pmergeme(argv);
	pmergeme.parseVector();
	pmergeme.sortVector();
	pmergeme.createChains();
	pmergeme.createInsertionSequence();
}