#ifndef DOG_H
# define DOG_H
# include "Animal.hpp"

class Dog : public Animal
{
    private:
        std::string type;
    
    public:
        Dog();
        ~Dog();
        Dog(const Dog &dog);
        Dog &operator=(const Dog &dog);

        void makeSound() const;
        std::string getType() const;
};

#endif