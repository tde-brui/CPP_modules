#include "Animal.hpp"

Animal::Animal()
{
    cout << "An animal has been created!" << endl;
}

Animal::~Animal()
{
    cout << "An animal has been destroyed" << endl;
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::makeSound() const
{
    cout << "Animal sound!" << endl;
}