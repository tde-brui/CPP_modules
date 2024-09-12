#include <iostream>
#include "../inc/whatever.hpp"

int main( void ) 
{
	int a = 2;
	int b = 3;
	std::cout << "a before swap: " << a << std::endl;
	std::cout << "b before swap: " << b << std::endl;
	std::cout << std::endl;

	::swap( a, b );
	std::cout << "a after swap: " << a << std::endl;
	std::cout << "b after swap: " << b << std::endl;
	std::cout << std::endl;

	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::cout << std::endl;

	std::string c = "string1";
	std::string d = "string2";
	std::cout << "c before swap: " << c << std::endl;
	std::cout << "d before swap: " << d << std::endl;
	std::cout << std::endl;

	::swap(c, d);
	std::cout << "c after swap: " << c << std::endl;
	std::cout << "d after swap: " << d << std::endl;
	std::cout << std::endl;

	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	double e = 42.42;
	double f = 1000.0;

	std::cout << "e before swap: " << e << std::endl;
	std::cout << "f before swap: " << f << std::endl;
	::swap(e, f);
	std::cout << std::endl;
	
	std::cout << "e after swap: " << e << std::endl;
	std::cout << "f after swap: " << f << std::endl;

	return 0;
}