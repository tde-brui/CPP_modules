#include "../inc/Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    cout << "A cat has been created!" << endl;
}

Cat::~Cat()
{
    cout << "A cat has been destroyed" << endl;
}


void Cat::makeSound() const
{
    cout << "Meow" << endl;
}

std::string Cat::getType() const
{
    return (this->type);
}
