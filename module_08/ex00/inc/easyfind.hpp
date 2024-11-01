#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <stack>

template <typename T>
bool easyfind(T &t, int target)
{
	auto it = std::find(t.begin(), t.end(), target);
	if (it == t.end())
		throw std::out_of_range("Element not found");
	return true;
}