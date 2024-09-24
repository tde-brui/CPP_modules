#include "../inc/Span.hpp"

int main()
{
	Span sp(1000000);
	try 
	{
		for (int i = 0; i < 100; i++)
		{
			sp.addNumber(i * 10);
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		Span sp2;
		sp2.addNumber(1);
	}
	catch (std::length_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}