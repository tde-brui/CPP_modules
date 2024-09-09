#include "../inc/easyfind.hpp"

int main()
{
	try {
		std::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8};
		std::cout << ::easyfind(vec1, 4) << std::endl;

		std::list<int> list1;
		list1.push_back(1);
		list1.push_back(2);
		list1.push_back(3);
		list1.push_back(4);
		std::cout << ::easyfind(list1, 3) << std::endl;
		std::cout << ::easyfind(list1, 5) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Element not found" << std::endl;
	}
}