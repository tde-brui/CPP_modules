#include "../inc/Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    this->brain = new Brain();
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
    delete this->brain;
    cout << "A dog has been destroyed" << endl;
}

void Dog::makeSound() const
{
    cout << "Woof!" << endl;
}
