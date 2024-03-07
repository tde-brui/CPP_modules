#include "../inc/Serializer.hpp"
#include <typeinfo>

int main()
{
	Data *data = new Data();

	std::cout << "Type before serialization: " << typeid(*data).name() << std::endl;
	uintptr_t raw = Serializer::serialize(data);
	Data *data2 = Serializer::deserialize(raw);
	std::cout << "Type after deserialization: " << typeid(*data2).name() << std::endl;

	delete data;
}