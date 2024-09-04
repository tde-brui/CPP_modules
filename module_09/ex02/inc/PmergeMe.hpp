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
		int straggler;

	public:
		PmergeMe();
		PmergeMe(char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe &pmergeme);
		PmergeMe &operator=(const PmergeMe &pmergeme);

		std::string appendArgs(char **argv);
		void parseVector();
		void sortVector();
		void sortVectorPairs();

};
