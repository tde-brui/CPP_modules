#include <iostream>
#include "Data.hpp"

class Serializer
{
	public:
		Serializer();
		virtual ~Serializer() = 0;
		Serializer(const Serializer &obj);
		const Serializer &operator=(const Serializer &obj);

		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};