#include "../inc/Array.hpp"

int main()
{
	Array<int> arr1(50);
	try {
		for (int i = 0; i < 50; i++)
		{
			arr1[i] = i;
			std::cout << i << std::endl;
		}
		std::cout << "Size: " << arr1.size() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}