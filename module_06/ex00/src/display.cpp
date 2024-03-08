#include "ScalarConverter.hpp"

void display_char(const std::string &input)
{
	char c = input[0];
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void display_int(const std::string &input)
{
	int i = atoi(input.c_str());
	if (static_cast<char>(i) < 32 || static_cast<char>(i) > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void display_float(const std::string &input)
{
	double f = atof(input.c_str());
	if (static_cast<char>(f) < 32 || static_cast<char>(f) > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	if (static_cast<int>(f) - f == 0)
	{
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double " << f << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double " << static_cast<double>(f) << std::endl;
	}
}

void display_double(const std::string &input)
{
	double d = stod(input);
	if (static_cast<char>(d) < 32 || static_cast<char>(d) > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	std::cout << "int: " << static_cast<int>(d) <<  std::endl;
	if (static_cast<int>(d) - d == 0)
	{
		std::cout << "float: " << static_cast<float>(d)<< ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

void display_word(const std::string &input)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (input == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else
	{
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input << std::endl;
	}
}