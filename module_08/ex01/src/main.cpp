#include "../inc/Span.hpp"

int main()
{
	Span span1(5);
	try 
	{
		span1.addNumber(10);
		span1.longestSpan();
	}
	catch (std::length_error &e)
	{
		std::cout << e.what() << std::endl;
	}
}