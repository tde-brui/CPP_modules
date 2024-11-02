#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>

class PmergeMe
{
	public:
		class Vector
		{
			private:
				std::string 	_intList;
				std::vector<int>	vec1;
				std::vector<int> mainVec;
				std::vector<int> pendVec;
				std::vector<int> insertionOrder;
				std::vector<std::pair<int, int> > vecPair;
				bool stragglerFlag;
				std::vector<unsigned int> jacobsthals;
				int straggler;

			public:
				Vector(char **argv);
				Vector(const Vector &vector);
				Vector &operator=(const Vector &vector);
				~Vector();
				std::string appendArgs(char **argv);
				std::string getIntList() const;
				void parseVector();
				void sortVector();
				void sortVectorPairs(int left, int right);
				void mergeVector(int left, int mid, int right);
				void createChains();
				void printVector();
				std::vector<int> createJacobsthalSequence(int n);
				void generateJacobsthalNumbers();
				void createInsertionSequence();
				void vecInsert();
				bool isSortedRange(int left, int right);
				bool isSorted();
			
			class SortedException : public std::exception
			{
				public:
					const char *what() const noexcept;
			};
				
		};

		class Deque
		{
			private:
				std::string 	_intList;
				std::deque<int> deque1;
				std::deque<int> mainDeque;
				std::deque<int> pendDeque;
				std::deque<int> insertionOrder;
				std::deque<std::pair<int, int> > dequePair;
				std::deque<int> jacobsthals;
				bool stragglerFlag;
				int straggler;

			public:
				Deque(char **argv);
				Deque(const Deque &deque);
				Deque &operator=(const Deque &deque);
				~Deque();
				std::string appendedArgs(char **argv);
				std::string getIntList() const;
				void parseDeque();
				void sortDeque();
				void sortDequePairs(int left, int right);
				void mergeDeque(int left, int mid, int right);
				void createChains();
				void createInsertionSequence();
				void dequeInsert();
				void generateJacobsthalGroups();
				void printDeque(std::deque<int> &deque);
				bool isSortedRange(int left, int right);
				bool isSorted();
		};


};
