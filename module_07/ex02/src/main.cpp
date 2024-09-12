#include "../inc/Array.hpp"

int main()
{
	std::cout << "Initializing two arrays, one of integers and one of doubles" << std::endl;

	Array<int> arr1(50);
	for (int i = 0; i < 50; i++)
		arr1[i] = i;

	Array<double> arr2(100);
	for(int i = 0; i < 100; i++)
		arr2[i] = i + 0.5;

	std::cout << "Printing the first array" << std::endl;
	for (int i = 0; i < 50; i++)
		std::cout << arr1[i] << std::endl;
	std::cout << "Printing the second array" << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << arr2[i] << std::endl;

	std::cout << "Accessing a valid array element" << std::endl;
	std::cout << "arr1[10]: " << arr1[10] << std::endl;
	std::cout << "arr2[10]: " << arr2[10] << std::endl;

	std::cout << "Accessing an invalid array element" << std::endl;
	try
	{
		std::cout << arr1[100] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}