#include "Animal.hpp"

class Cat : public Animal
{

    public:
        Cat();
        ~Cat();
        Cat(const Cat &cat);
        Cat &operator=(const Cat &cat);

};
