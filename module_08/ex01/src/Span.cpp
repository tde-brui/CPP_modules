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
		throw (std::length_error("List is too short to check shortestSpan"));
	int minspan = *std::max_element(vec1.begin(), vec1.end());
	int span = 0;

	std::vector<int> vec2 = vec1;
	std::sort(vec2.begin(), vec2.end());
	for (size_t i = 0; i < vec2.size() - 1; i++)
	{
		span = std::abs(vec2[i] - vec2[i + 1]);
		minspan = std::min(span, minspan);
	}
	return (minspan);
}

unsigned int Span::longestSpan()
{
	if (vec1.size() < 2)
		throw(std::length_error("List is too short to check longestSpan"));
	auto min_iter = std::min_element(vec1.begin(), vec1.end());
	auto max_iter = std::max_element(vec1.begin(), vec1.end());
	return (*max_iter - *min_iter);
	
}

size_t Span::size()
{
	return vec1.size();
}