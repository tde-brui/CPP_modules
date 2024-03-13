#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

template <typename T>
int easyfind(T &t, int target)
{
	auto it = std::find(t.begin(), t.end(), target);
	if (it == t.end())
		return (-1);
	return std::distance(t.begin(), it);
}