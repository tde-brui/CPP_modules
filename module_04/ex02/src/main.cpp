#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

int main()
{
    Animal *dog = new Dog();
    Animal *cat = new Cat();
    dog->makeSound();
    cat->makeSound();
    // Animal *Animal = new Animal(); // Animal is an abstract class so this is not allowed
    // Animal->makeSound();
    delete dog;
    delete cat;
}