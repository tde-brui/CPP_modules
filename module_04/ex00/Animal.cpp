#include "Animal.hpp"

std::string Animal::getType()
{
    return (this->type);
}

void Animal::makeSound()
{
    if (this->type == "Cat")
        std::cout << "Meowww" << std::endl;
    if (this->type == "Dog")
        std:: cout << "Woofff" << std::endl;
}