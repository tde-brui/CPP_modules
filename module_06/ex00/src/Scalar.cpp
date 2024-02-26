#include "../inc/Scalar.hpp"
#include <string.h>

void ScalarConverter::convert(const std::string &input)
{
	cout << "input: " << input << endl;
	cout << "char: ";
	try
	{
		char c = static_cast<char>(stoi(input));
		if (isalpha(c))
			cout << c << endl;
		else
			cout << "non displayable" << endl;
	}
	catch(const std::exception& e)
	{
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
}