#include "../inc/ScalarConverter.hpp"

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

bool check_if_float(const std::string &input)
{
	int i = 0;
	int dot = 0;
	int f = 0;
	if (input[i] == '-' || input[i] == '+')
		i++;
	if (input[i] == '\0')
		return false;
	for(; input[i]; i++)
	{
		if (input[i] == '.')
			dot++;
		else if (input[i] == 'f' && input[i + 1] == '\0')
			f++;
		else if (!isdigit(input[i]))
			return false;
	}
	if (dot == 1 && f == 1)
		return true;
	return false;
}

bool check_if_double(const std::string &input)
{
	int i = 0;
	int dot = 0;
	if (input[i] == '-' || input[i] == '+')
		i++;
	if (input[i] == '\0')
		return false;
	for(; input[i]; i++)
	{
		if (input[i] == '.')
			dot++;
		else if (!isdigit(input[i]))
			return false;
	}
	if (dot == 1)
		return true;
	return false;
}

bool check_if_int(const std::string &input)
{
	int i = 0;
	if (input[i] == '-' || input[i] == '+')
		i++;
	if (input[i] == '\0')
		return false;
	for(; input[i]; i++)
	{
		if (input[i] == '-' || input[i] == '+')
			return false;
		else if (!isdigit(input[i]))
			return false;
	}
	return true;
}

literal_type getType(const std::string &input)
{
	if (input.length() == 1 && isalpha(input[0]))
		return CHAR;
	else if (check_if_float(input))
		return FLOAT;
	else if (check_if_int(input))
		return INT;
	else if (check_if_double(input))
		return DOUBLE;
	else if (input == "+inf" || input == "-inf" || input == "nan" || input == "nanf" || input == "-inff" || input == "+inff")
		return WORD;
	return INVALID;
}

void ScalarConverter::convert(const std::string &input)
{
	literal_type type = getType(input);
	switch(type)
	{
		case CHAR:
		{
			display_char(input);
			break ;
		}
		case INT:
		{
			display_int(input);
			break ;
		}
		case FLOAT:
		{
			display_float(input);
			break ;
		}
		case DOUBLE:
		{
			display_double(input);
			break ;
		}
		case WORD:
		{
			display_word(input);
			break ;
		}
		case INVALID:
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			break ;
		}
	}
}