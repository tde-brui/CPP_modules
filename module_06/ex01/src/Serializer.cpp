#include "../inc/Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer constructor" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor" << std::endl;
}

Serializer::Serializer(const Serializer &obj)
{
	(void)obj;
}

const Serializer &Serializer::operator=(const Serializer &obj)
{
	(void)obj;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

