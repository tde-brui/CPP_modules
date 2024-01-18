#include "../inc/Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    cout << "A dog has been created!" << endl;
}

Dog::Dog(const Dog &dog)
{
    this->type = dog.type;
    cout << "A dog has been created!" << endl;
}

Dog &Dog::operator=(const Dog &dog)
{
    if (this != &dog)
        this->type = dog.type;
    cout << "a dog has been created" << endl;
    return (*this);
}
Dog::~Dog()
{
    cout << "A dog has been destroyed" << endl;
}
