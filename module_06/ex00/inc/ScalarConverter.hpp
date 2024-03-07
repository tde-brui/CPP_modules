#include <iostream>
using std::cout; 
using std::endl;
using std::string;

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		virtual ~ScalarConverter() = 0;
		ScalarConverter &operator=(const ScalarConverter &obj);

		static void convert(const std::string &input);
};