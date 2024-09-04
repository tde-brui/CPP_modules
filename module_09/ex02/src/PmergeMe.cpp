#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(char **argv)
{
	_intList = appendArgs(argv);
}

std::string PmergeMe::appendArgs(char **argv)
{
	std::string resultString;
	int i = 1;
	while (argv[i])
	{
		resultString += argv[i];
		resultString += " ";
		i++;
	}
	//std::cout << resultString << std::endl;
	return resultString;
}
void PmergeMe::parseVector()
{
	std::istringstream iss(_intList);
	std::string token;
	while (iss >> token)
	{
		int value = 0;
		try
		{
			value = stoi(token);
		}
		catch (std::invalid_argument)
		{
			std::cerr << "invalid argument: " << token << std::endl;
			exit(1);
		}
		catch (std::out_of_range)
		{
			std::cerr << "out of range: " << token << std::endl;
			exit(1);
		}
		if (value < 0)
		{
			std::cerr << "negative value: " << value << std::endl;
			exit(1);
		}
		vec1.push_back(value);
	}
}

void PmergeMe::sortVectorPairs()
{
	for (unsigned long i = 0; i < vec1.size(); i += 2)
	{
		if (vec1[i] > vec1[i + 1])
			std::swap(vec1[i], vec1[i + 1]);
	}
}

void PmergeMe::sortVector()
{
	if (vec1.size() < 2)
		return ;
	if (vec1.size() % 2 == 1)
	{
		straggler = vec1.back();
		vec1.pop_back();
	}
	//sort the pairs
	sortVectorPairs();
	//
	


}


