#include <iostream>
#include <ctype.h>
#include <string>

using std::cout; 
using std::endl;
using std::string;

enum literal_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	WORD,
	INVALID
};

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		virtual ~ScalarConverter() = 0;
		ScalarConverter &operator=(const ScalarConverter &obj);

		static void convert(const std::string &input);
};

void display_char(const std::string &input);
void display_int(const std::string &input);
void display_float(const std::string &input);
void display_double(const std::string &input);
void display_word(const std::string &input);