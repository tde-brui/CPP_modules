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
	if (this->size() >= N)
		throw(std::length_error("Vector is full"));
	vec1.push_back(num);
}

unsigned int Span::shortestSpan()
{
	if (this->size() == 0 || this->size() == 1)
		throw (std::length_error("List is too short"));
	return (1);

}

unsigned int Span::longestSpan()
{
	if (this->size() == 0 || this->size() == 1)
		throw (std::length_error("List is too short"));
	return (1);
	
}

size_t Span::size()
{
	return vec1.size();
}