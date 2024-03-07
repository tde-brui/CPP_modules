#include <iostream>

class Data
{
	public:
		Data();
		~Data();
		Data(const Data &data);
		Data &operator=(const Data &data);
		int i;
};