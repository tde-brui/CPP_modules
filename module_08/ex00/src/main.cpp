#include "../inc/easyfind.hpp"

int main()
{
	std::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8};\
	std::cout << ::easyfind(vec1, 4) << std::endl;

	std::list<int> list1;
	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);
	list1.push_back(4);

	std::cout << ::easyfind(list1, 3) << std::endl;

	std::stack<int> stack1;
	stack1.push(10);
	stack1.push(20);
	stack1.push(30);
	stack1.push(40);
	stack1.push(50);
	stack1.push(60);

	std::cout << ::easyfind(stack1, 20) << std::endl;
}