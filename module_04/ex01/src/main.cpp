#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

int main()
{
    int num = 2;
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