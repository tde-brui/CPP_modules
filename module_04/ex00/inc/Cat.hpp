#ifndef CAT_H
# define CAT_H
# include "Animal.hpp"

class Cat : public Animal
{   
    public:
        Cat();
        ~Cat();
        Cat(const Cat &cat);
        Cat &operator=(const Cat &cat);
};

#endif