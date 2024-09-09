#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <stack>

template <typename T>
int easyfind(T &t, int target)
{
	auto it = std::find(t.begin(), t.end(), target);
	if (it == t.end())
		throw std::exception();
	return std::distance(t.begin(), it);
}