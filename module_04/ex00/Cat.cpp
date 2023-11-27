#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    cout << "A cat has been created!" << endl;
}

Cat::~Cat()
{
    cout << "A cat has been destroyed" << endl;
}
