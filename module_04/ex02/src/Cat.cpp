#include "../inc/Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    cout << "A cat has been created!" << endl;
    this->brain = new Brain();
}

Cat::~Cat()
{
    delete this->brain;
    cout << "A cat has been destroyed" << endl;
}

void Cat::makeSound() const
{
    cout << "Meow" << endl;
}
