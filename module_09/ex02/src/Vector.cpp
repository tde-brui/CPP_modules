#include "../inc/PmergeMe.hpp"

PmergeMe::Vector::~Vector()
{
}

PmergeMe::Vector::Vector(const Vector &vector)
{
	_intList = vector._intList;
	vec1 = vector.vec1;
	mainVec = vector.mainVec;
	pendVec = vector.pendVec;
	insertionOrder = vector.insertionOrder;
	vecPair = vector.vecPair;
	stragglerFlag = vector.stragglerFlag;
	straggler = vector.straggler;
	jacobsthalsSize = vector.jacobsthalsSize;
}

PmergeMe::Vector &PmergeMe::Vector::operator=(const Vector &vector)
{
	_intList = vector._intList;
	vec1 = vector.vec1;
	mainVec = vector.mainVec;
	pendVec = vector.pendVec;
	insertionOrder = vector.insertionOrder;
	vecPair = vector.vecPair;
	stragglerFlag = vector.stragglerFlag;
	straggler = vector.straggler;
	jacobsthalsSize = vector.jacobsthalsSize;
	return *this;
}

std::string PmergeMe::Vector::appendArgs(char **argv)
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

std::string PmergeMe::Vector::getIntList() const
{
	return _intList;
}

PmergeMe::Vector::Vector(char **argv)
{
	_intList = appendArgs(argv);
	parseVector();
	sortVector();
}



void PmergeMe::Vector::parseVector()
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
void PmergeMe::Vector::sortVector()
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

void PmergeMe::Vector::sortVectorPairs(int left, int right)
{
	if (left >= right)
		return ;
	int mid = left + (right - left) / 2;
	sortVectorPairs(left, mid);
	sortVectorPairs(mid + 1, right);
	mergeVector(left, mid, right);
}

void PmergeMe::Vector::mergeVector(int left, int mid, int right)
{
	unsigned int sizeLeft = mid - left + 1;
	unsigned int sizeRight = right - mid;

	std::vector<std::pair<int, int> > leftVec, rightVec;

	for (unsigned int i = 0; i < sizeLeft; i++)
	{
		leftVec.push_back(vecPair[left + i]);
	}
	for (unsigned int i = 0; i < sizeRight; i++)
	{
		rightVec.push_back(vecPair[mid + 1 + i]);
	}

	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int k = left;

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

void PmergeMe::Vector::createChains()
{
	mainVec.push_back(vecPair[0].second);
	mainVec.push_back(vecPair[0].first);
	for (unsigned int i = 1; i < vecPair.size(); i++)
	{
		mainVec.push_back(vecPair[i].first);
		pendVec.push_back(vecPair[i].second);
	}
	if (stragglerFlag)
		pendVec.push_back(straggler);
}

void PmergeMe::Vector::generateJacobsthalNumbers()
{
	jacobsthalsSize.push_back(2);
	jacobsthalsSize.push_back(2);

	int groupSize = 0;
	size_t pendSize = pendVec.size();

	while (jacobsthalsSize.size() < pendSize)
	{
		groupSize = jacobsthalsSize.back() + 2 * jacobsthalsSize[jacobsthalsSize.size() - 2];
		jacobsthalsSize.push_back(groupSize);
	}
}


void 	PmergeMe::Vector::createInsertionSequence()
{
	generateJacobsthalNumbers();
	int groupTotal = 0;
	int groupIndex = 0;
	int pendSize = pendVec.size();
	while (groupTotal < pendSize)
	{
		unsigned int prevJacobsthal = groupTotal;
		groupTotal += jacobsthalsSize[groupIndex++];
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

void PmergeMe::Vector::vecInsert()
{
	createChains();
	createInsertionSequence();

	for (unsigned int i = 0; i < pendVec.size(); i++)
	{
		int val = pendVec[insertionOrder[i] - 1];
		auto pos = std::lower_bound(mainVec.begin(), mainVec.end(), val);
		mainVec.insert(pos, val);
	}
}

void PmergeMe::Vector::printVector()
{
	for (int i = 0; i < (int)mainVec.size(); i++)
	{
		std::cout << mainVec[i];
		if (i < (int)mainVec.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}