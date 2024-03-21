#include "../inc/iter.hpp"

template <typename T>
void print_element(T element)
{
	std::cout << element << std::endl;
}

template <typename U>
void print_element_plus(U element)
{
	std::cout << element + 100 << std::endl;
}

int main()
{
	int arr[50];
	for (int i = 0; i < 50; i++)
		arr[i] = i;
	::iter(arr, 50, print_element<int>);

	double arr2[50];
	for (int i = 0; i < 50; i++)
		arr2[i] = i + 0.5;
	::iter(arr2, 50, print_element<double>);

	::iter(arr2, 50, print_element_plus<double>);
}