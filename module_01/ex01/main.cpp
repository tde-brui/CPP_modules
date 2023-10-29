#include "Zombie.hpp"

int main()
{
    int num;
    Zombie *Horde_of_Zombies;

    num = 5;
    Horde_of_Zombies = zombieHorde(num, "tijmen");
    for (int i = 0; i < num; i++)
        Horde_of_Zombies[i].announce();
    delete [] Horde_of_Zombies;
}