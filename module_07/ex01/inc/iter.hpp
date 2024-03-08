#include <iostream>

template <typename T, typename Func>
void iter(T *address, int len, Func func)
{
	for (int i = 0; i < len; i++)
	{
		func(address[i]);
	}
}