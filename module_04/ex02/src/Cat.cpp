#include "../inc/Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    this->brain = new Brain();
    cout << "A cat has been created!" << endl;
}
Cat::Cat(const Cat &cat)
{
    this->type = cat.type;
    cout << "A cat has been created!" << endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    if (this != &cat)
        this->type = cat.type;
    cout << "a cat has been created" << endl;
    return (*this);
}

Cat::~Cat()
{
    delete this->brain;
    cout << "A cat has been destroyed" << endl;
}

void Cat::makeSound() const
{
    cout << "Meow!" << endl;
}

