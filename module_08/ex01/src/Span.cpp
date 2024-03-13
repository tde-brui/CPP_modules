#include "../inc/Span.hpp"

Span::Span(): N(0)
{
}

Span::Span(unsigned int _N) : N(_N)
{
}

Span::~Span()
{
}
Span::Span(const Span &span)
{
	N = span.N;
}

Span &Span::operator=(const Span &span)
{
	if (this != &span)
		N = span.N;
	return *this;
}

void Span::addNumber(int num)
{
	if (vec1.size() >= N)
		throw(std::length_error("Vector is full"));
	vec1.push_back(num);
}

unsigned int Span::shortestSpan()
{
	if (vec1.size() < 2)
		throw (std::length_error("List is too short"));
	int minspan = *std::max_element(vec1.begin(), vec1.end());
	int span = 0;
	for (int i = 0; i < static_cast<int>(vec1.size()); i++)
	{
		for (int j = i + 1; j < static_cast<int>(vec1.size()); j++)
		{
			span = std::abs(vec1[i] - vec1[j]);
			minspan = std::min(span, minspan);
		}
	}
	return (minspan);

}

unsigned int Span::longestSpan()
{
	if (vec1.size() < 2)
		throw(std::length_error("List is too short"));
	auto min_iter = std::min_element(vec1.begin(), vec1.end());
	auto max_iter = std::max_element(vec1.begin(), vec1.end());
	return (*max_iter - *min_iter);
	
}

size_t Span::size()
{
	return vec1.size();
}