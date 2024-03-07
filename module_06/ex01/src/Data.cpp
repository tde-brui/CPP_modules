#include "../inc/Data.hpp"

Data::Data()
{
	i = 42;
	std::cout << "Data constructor" << std::endl;
}

Data::~Data()
{
	std::cout << "Data destructor" << std::endl;
}

Data::Data(const Data &data)
{
	(void)data;
}

Data &Data::operator=(const Data &data)
{
	(void)data;
	return (*this);
}