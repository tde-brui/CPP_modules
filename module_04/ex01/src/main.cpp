#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Brain.hpp"

int main()
{
    int num = 10;
    Animal *animals[num];

    for (int i = 0; i < num; i++)
    {
        if (i % 2 == 0)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
    }
    cout << endl;
    for (int i = 0; i < num; i++)
    {
        delete animals[i];
    }
}