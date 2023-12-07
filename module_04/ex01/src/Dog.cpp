#include "../inc/Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    cout << "A dog has been created!" << endl;
    this->brain = new Brain();
}

Dog::~Dog()
{
    delete this->brain;
    cout << "A dog has been destroyed" << endl;
}

void Dog::makeSound() const
{
    cout << "Woof" << endl;
}
