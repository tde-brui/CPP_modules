#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

class Span
{
	private:
		unsigned int N;
		std::vector<int> vec1;

	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span &span);
		Span &operator=(const Span &span);

		void addNumber(int num);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		size_t size();
};