#include "../inc/ScalarConverter.hpp"
#include <string.h>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	(void)obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)obj;
	return *this;
}

void ScalarConverter::convert(const std::string &input)
{
	cout << "char: ";
	try
	{
		if (input == "nan" || input == "nanf")
			throw std::exception();
		char c = static_cast<char>(stoi(input));
		if (c < 32 || c > 126)
			cout << "Non displayable" << endl;
		else
			cout << "'" << c << "'" << endl;
	}
	catch(const std::exception& e){
		cout << "impossible" << endl;
	}
	cout << "int: ";
	try
	{
		int i = static_cast<int>(stoi(input));
		cout << i << endl;
	}
	catch(const std::exception& e)
	{
		cout << "impossible" << endl;
	}
	cout << "float: ";
	try
	{
		float f = static_cast<float>(stof(input));
		cout << f;
		if (f - static_cast<int>(f) == 0)
			cout << ".0";
		cout << "f" << endl;
	}
	catch(const std::exception& e)
	{
		cout << "impossible" << endl;
	}
	cout << "double: ";
	try
	{
		double d = static_cast<double>(stod(input));
		cout << d;
		if (d - static_cast<int>(d) == 0)
			cout << ".0";
		cout << endl;
	}
	catch(const std::exception& e)
	{
		cout << "impossible" << endl;
	}
}