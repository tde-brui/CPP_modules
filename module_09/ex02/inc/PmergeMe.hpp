#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

class PmergeMe
{
	private:
		std::string 	_intList;
		std::vector<int>	vec1;
		std::vector<std::pair<int, int> > vecPair;
		std::vector<int> mainVec;
		std::vector<int> pendVec;


		int straggler;

	public:
		PmergeMe();
		PmergeMe(char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe &pmergeme);
		PmergeMe &operator=(const PmergeMe &pmergeme);

		//Vector functions
		std::string appendArgs(char **argv);
		void parseVector();
		void sortVector();
		void sortVectorPairs(int left, int right);
		void mergeVector(int left, int mid, int right);
		void createChains();
		void printVector();
		std::vector<int> createJacobsthalSequence(int n);
		std::vector<int> createInsertionSequence();
		// void jacobsthalInsertion();



};
