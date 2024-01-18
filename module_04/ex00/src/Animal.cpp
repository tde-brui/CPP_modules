#include "../inc/Animal.hpp"

Animal::Animal()
{
    this->type = "Animal";
    cout << "An animal has been created!" << endl;
}

Animal::Animal(const Animal &animal)
{
    this->type = animal.type;
    cout << "An animal has been created!" << endl;
}

Animal &Animal::operator=(const Animal &animal)
{
    if (this != &animal)
        this->type = animal.type;
    cout << "An animal has been created!" << endl;
    return (*this);
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
    if (this->getType() == "Cat")
        cout << "Meow!" << endl;
    else if (this->getType() == "Dog")
        cout << "Woof!" << endl;
    else
        cout << "Animal sound!" << endl;
}
