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
		for (int i = 1000; i < 10000; i++)
		{
			sp.addNumber(i * 100);
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::length_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}