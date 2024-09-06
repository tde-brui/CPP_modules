#include "ScalarConverter.hpp"
#include <limits>

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
	try
	{
		long long ll = std::stoll(input);
		{
		if (static_cast<int>(ll) < 32 || static_cast<int>(ll) > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(ll) << std::endl;
		if (ll > std::numeric_limits<int>::max() || ll < std::numeric_limits<int>::min())
			std::cout << "int: overflow" << std::endl;
		else
			std::cout << "int: " << ll << std::endl;
		if (ll > std::numeric_limits<float>::max() || ll < -std::numeric_limits<float>::max())
			std::cout << "float: overflow" << std::endl;
		else
			std::cout << "float: " << static_cast<float>(ll) << ".0f" << std::endl;
		if (ll > std::numeric_limits<double>::max() || ll < -std::numeric_limits<double>::max())
			std::cout << "double: overflow" << std::endl;
		else
			std::cout << "double: " << static_cast<double>(ll) << ".0" << std::endl;
		}
	}
	catch (std::out_of_range &e)
	{
		std::cout << "Error: int overflow" << std::endl;
	}
	catch (std::invalid_argument &e)
	{
		std::cout << "Error: invalid argument" << std::endl;
	}
}

void display_float(const std::string &input)
{
	try{		
		double f = std::stof(input);
		if (static_cast<int>(f) < 32 || static_cast<int>(f) > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(f) << std::endl;
		if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
			std::cout << "int: overflow" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(f) << std::endl;
		if (static_cast<int>(f) - f == 0)
		{
			std::cout << "float: " << f << ".0f" << std::endl;
			std::cout << "double " << static_cast<double>(f) << ".0" << std::endl;
		}
		else
		{
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double " << static_cast<double>(f) << std::endl;
		}
	}
	catch (std::out_of_range &e)
	{
		std::cout << "Error: float overflow" << std::endl;
	}
	catch (std::invalid_argument &e)
	{
		std::cout << "Error: invalid argument" << std::endl;
	}
}

void display_double(const std::string &input)
{
	try
	{
		double d = stod(input);
		if (static_cast<int>(d) < 32 || static_cast<int>(d) > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(d) << std::endl;
		if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
			std::cout << "int: overflow" << std::endl;
		else
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
	catch(std::out_of_range &e)
	{
		std::cout << "Error: double overflow" << std::endl;
	}
	catch (std::invalid_argument &e)
	{
		std::cout << "Error: invalid argument" << std::endl;
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