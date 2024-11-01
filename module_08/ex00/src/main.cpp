#include "../inc/easyfind.hpp"

int main()
{
	try {
		std::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8};
		bool found = ::easyfind(vec1, 3);
		std::cout << found << std::endl;

		std::list<int> list1;
		list1.push_back(1);
		list1.push_back(2);
		list1.push_back(3);
		list1.push_back(4);
		bool found2 = ::easyfind(list1, 5);
		std::cout << found2 << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << " (exception thrown)" << std::endl;
	}
}