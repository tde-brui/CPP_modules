#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(char **argv)
{
	_intList = appendArgs(argv);
	stragglerFlag = false;
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
void PmergeMe::sortVector()
{
	if (vec1.size() < 2)
		return ;
	if (vec1.size() % 2 == 1)
	{
		straggler = vec1.back();
		vec1.pop_back();
		stragglerFlag = true;
	}
	for (unsigned long i = 0; i < vec1.size(); i += 2)
	{
		if (vec1[i] < vec1[i + 1])
			std::swap(vec1[i], vec1[i + 1]);
	}
	for (unsigned int i = 0; i < vec1.size(); i += 2)
		vecPair.push_back(std::make_pair(vec1[i], vec1[i + 1]));
	sortVectorPairs(0, vecPair.size() - 1);
	vecInsert();
}

void PmergeMe::sortVectorPairs(int left, int right)
{
	if (left >= right)
		return ;
	int mid = left + (right - left) / 2;
	sortVectorPairs(left, mid);
	sortVectorPairs(mid + 1, right);
	mergeVector(left, mid, right);
}

void PmergeMe::mergeVector(int left, int mid, int right)
{

	int sizeLeft = mid - left + 1;
	int sizeRight = right - mid;

	std::vector<std::pair<int, int> > leftVec, rightVec;
	//only want to sort the biggest of each pair;
	//bigger of the two is always the first element, and always an even index

	for (int i = 0; i < sizeLeft; i++)
		leftVec.push_back(vecPair[left + i]);
	for (int i = 0; i < sizeRight; i++)
		rightVec.push_back(vecPair[mid + 1 + i]);
	
	int i = 0;
	int j = 0;
	int k = left;

	while (i < sizeLeft && j < sizeRight)
	{
		if (leftVec[i].first <= rightVec[j].first)
		{
			vecPair[k] = leftVec[i];
			i++;
		}
		else
		{
			vecPair[k] = rightVec[j];
			j++;
		}
		k++;
	}
	while (i < sizeLeft)
	{
		vecPair[k] = leftVec[i];
		i++;
		k++;
	}
	while (j < sizeRight)
	{
		vecPair[k] = rightVec[j];
		j++;
		k++;
	}
}

void PmergeMe::createChains()
{
	mainVec.push_back(vecPair[0].second);
	mainVec.push_back(vecPair[0].first);
	for (unsigned int i = 1; i < vecPair.size(); i++)
	{
		mainVec.push_back(vecPair[i].first);
		pendVec.push_back(vecPair[i].second);
	}
}

void PmergeMe::generateJacobsthalGroupSize()
{
	jacobsthalGroupSize.push_back(2);
	jacobsthalGroupSize.push_back(2);

	int groupTotal = 4;
	int groupSize = 0;
	while (groupTotal < 2000000)
	{
		groupSize = jacobsthalGroupSize.back() + 2 * jacobsthalGroupSize[jacobsthalGroupSize.size() - 2];
		jacobsthalGroupSize.push_back(groupSize);
		groupTotal += groupSize;
	}
}


void 	PmergeMe::createInsertionSequence()
{
	generateJacobsthalGroupSize();
	int groupTotal = 0;
	int groupIndex = 0;
	int pendSize = pendVec.size();
	while (groupTotal < pendSize)
	{
		unsigned int prevJacobsthal = groupTotal;
		groupTotal += jacobsthalGroupSize[groupIndex++];
		if (groupTotal <= pendSize)
		{
			for (unsigned int i = groupTotal; i > prevJacobsthal; i--)
				insertionOrder.push_back(i);
		}
		else
		{
			int diff = groupTotal - pendSize;
			for (unsigned int i = groupTotal - diff; i > prevJacobsthal; i--)
				insertionOrder.push_back(i);
		}
	}

}

void PmergeMe::printVector()
{
	for (unsigned long i = 0; i < vecPair.size(); i++)
		std::cout << vecPair[i].first << " " << vecPair[i].second << std::endl;
}

void PmergeMe::vecInsert()
{
	createChains();
	createInsertionSequence();
	int itemsInserted = 1;
	int val = 0;
	int endPos = 0;
	for (size_t i = 0; i < pendVec.size(); i++)
	{
		val = pendVec[insertionOrder[i] - 1];
		endPos = insertionOrder[i] + itemsInserted;
		auto insertPos = std::upper_bound(mainVec.begin(), mainVec.begin() + endPos, val);
		mainVec.insert(insertPos, val);
		itemsInserted++;
	}
	for (size_t i = 0; i < mainVec.size(); i++)
		std::cout << mainVec[i] << " ";
}

