#include "../inc/PmergeMe.hpp"

PmergeMe::Deque::Deque(char **argv)
{
	_intList = appendedArgs(argv);
	parseDeque();
	sortDeque();
}

PmergeMe::Deque::~Deque()
{

}

PmergeMe::Deque::Deque(const Deque &deque)
{
	_intList = deque._intList;
	deque1 = deque.deque1;
	mainDeque = deque.mainDeque;
	pendDeque = deque.pendDeque;
	insertionOrder = deque.insertionOrder;
	dequePair = deque.dequePair;
	stragglerFlag = deque.stragglerFlag;
	straggler = deque.straggler;
	jacobsthals = deque.jacobsthals;
}

PmergeMe::Deque &PmergeMe::Deque::operator=(const Deque &deque)
{
	_intList = deque._intList;
	deque1 = deque.deque1;
	mainDeque = deque.mainDeque;
	pendDeque = deque.pendDeque;
	insertionOrder = deque.insertionOrder;
	dequePair = deque.dequePair;
	stragglerFlag = deque.stragglerFlag;
	straggler = deque.straggler;
	jacobsthals = deque.jacobsthals;
	return *this;
}

std::string PmergeMe::Deque::appendedArgs(char **argv)
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

void PmergeMe::Deque::parseDeque()
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
		deque1.push_back(value);
	}
}

bool PmergeMe::Deque::isSortedRange(int left, int right)
{
	for (int i = left; i < right; i++)
	{
		if (!(dequePair[i].first < dequePair[i].second && dequePair[i].second <
		dequePair[i + 1].first && dequePair[i + 1].first < dequePair[i + 1].second))
		{
			return false;
		}
	}
	return true;
}

bool PmergeMe::Deque::isSorted()
{
	for (unsigned int i = 0; i < deque1.size() - 1; i++)
	{
		if (deque1[i] > deque1[i + 1])
			return false;
	}
	return true;
}

void PmergeMe::Deque::sortDequePairs(int left, int right)
{
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	sortDequePairs(left, mid);
	sortDequePairs(mid + 1, right);
	mergeDeque(left, mid, right);
}

void PmergeMe::Deque::mergeDeque(int left, int mid, int right)
{
	int sizeLeft = mid - left + 1;
	int sizeRight = right - mid;
	int k = left;

	if (isSortedRange(left, right))
		return;

	std::deque<std::pair<int, int> > leftDeque, rightDeque;

	for (int i = 0; i < sizeLeft; i++)
		leftDeque.push_back(dequePair[left + i]);
	for (int i = 0; i < sizeRight; i++)
		rightDeque.push_back(dequePair[mid + 1 + i]);
	
	int i = 0;
	int j = 0;

	while (i < sizeLeft && j < sizeRight)
	{
		if (leftDeque[i].first <= rightDeque[j].first)
			dequePair[k] = leftDeque[i++];
		else
			dequePair[k] = rightDeque[j++];
		k++;
	}

	while (i < sizeLeft)
		dequePair[k++] = leftDeque[i++];
	while (j < sizeRight)
		dequePair[k++] = rightDeque[j++];
}

void PmergeMe::Deque::createChains()
{
	mainDeque.push_back(dequePair[0].second);
	mainDeque.push_back(dequePair[0].first);
	for (unsigned int i = 1; i < dequePair.size(); i++)
	{
		mainDeque.push_back(dequePair[i].first);
		pendDeque.push_back(dequePair[i].second);
	}
	if (stragglerFlag)
		pendDeque.push_back(straggler);
}

void PmergeMe::Deque::generateJacobsthalGroups()
{
	jacobsthals.push_back(2);
	jacobsthals.push_back(2);
	
	int groupSize = 0;
	size_t pendSize = pendDeque.size();

	while (jacobsthals.size() < pendSize)
	{
		groupSize = jacobsthals.back() + 2 * jacobsthals[jacobsthals.size() - 2];
		jacobsthals.push_back(groupSize);
	}
}

void PmergeMe::Deque::createInsertionSequence()
{
	generateJacobsthalGroups();
	int groupTotal = 0;
	int groupIndex = 0;
	int pendSize = pendDeque.size();
	while (groupTotal < pendSize)
	{
		unsigned int prevJacobsthal = groupTotal;
		groupTotal += jacobsthals[groupIndex];
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
		groupIndex++;
	}
}

void PmergeMe::Deque::dequeInsert()
{
	createChains();
	createInsertionSequence();

	for (unsigned int i = 0; i < pendDeque.size(); i++)
	{
		int val = pendDeque[insertionOrder[i] - 1];
		auto pos = std::lower_bound(mainDeque.begin(), mainDeque.end(), val);
		mainDeque.insert(pos, val);
	}
}

void PmergeMe::Deque::sortDeque()
{
	if (deque1.size() < 2)
		return;
	if (deque1.size() % 2 != 0)
	{
		stragglerFlag = true;
		straggler = deque1.back();
		deque1.pop_back();
	}
	for (int i = 0; i < (int)deque1.size(); i+= 2)
	{
		if (deque1[i] < deque1[i + 1])
			std::swap(deque1[i], deque1[i + 1]);
		dequePair.push_back(std::make_pair(deque1[i], deque1[i + 1]));
	}
	sortDequePairs(0, dequePair.size() - 1);
	dequeInsert();
}

void PmergeMe::Deque::printDeque(std::deque<int> &deque)
{
	for (unsigned int i = 0; i < deque.size(); i++)
		std::cout << deque[i] << " ";
	std::cout << std::endl;
}