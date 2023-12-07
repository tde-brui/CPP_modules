#include "../inc/Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    cout << "A dog has been created!" << endl;
}

Dog::~Dog()
{
    cout << "A dog has been destroyed" << endl;
}

void Dog::makeSound() const
{
    cout << "Woof" << endl;
}

std::string Dog::getType() const
{
    return (this->type);
}