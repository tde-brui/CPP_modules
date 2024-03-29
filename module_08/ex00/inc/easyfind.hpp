#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <stack>

template <typename T>
int easyfind(T &t, int target)
{
	auto it1 = t.begin();
	std::cout << "first element: " <<  *it1 << std::endl;
	auto it = std::find(t.begin(), t.end(), target);
	if (it == t.end())
		return (-1);
	return std::distance(t.begin(), it);
}