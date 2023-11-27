#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    cout << "A dog has been created!" << endl;
}

Dog::~Dog()
{
    cout << "A dog has been destroyed" << endl;
}