#include "Zombie.hpp"

int main()
{
    Zombie *tijmen;

    tijmen = newZombie("tijmen");
    tijmen->announce();
    delete tijmen;

    randomChump("randomChump");
}