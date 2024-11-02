#include "PmergeMe.hpp"
#include <chrono>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Too little arguments" << std::endl;
		exit(1);
	} 
	try {
		auto startVec = std::chrono::high_resolution_clock::now();
		PmergeMe::Vector vector(argv);
		auto endVec = std::chrono::high_resolution_clock::now();

		auto startDeque = std::chrono::high_resolution_clock::now();
		PmergeMe::Deque deque(argv);
		auto endDeque = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double, std::micro> elapsedVec = endVec - startVec;
		std::chrono::duration<double, std::micro> elapsedDeque = endDeque - startDeque;
		
		std::cout << "Before : " << vector.getIntList() << std::endl;
		std::cout << "After : ";
		vector.printVector();
		std::cout << std::endl;

		std::cout << "Time to process a range of ... element with std::vector : " << elapsedVec.count() << "us" << std::endl;
		std::cout << "Time to process a range of ... element with std::deque : " << elapsedDeque.count() << "us" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}