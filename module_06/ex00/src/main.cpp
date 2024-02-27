#include "../inc/ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout << " Usage: ./convert [value]" << endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
}