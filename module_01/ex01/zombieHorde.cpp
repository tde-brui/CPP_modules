#include "Zombie.hpp"

void Zombie::set_name(std::string name)
{
    this->name = name;
}

Zombie  *zombieHorde(int N, std::string name)
{
    Zombie *Horde_of_zombies;

    Horde_of_zombies = new Zombie[N];
    for (int i = 0; i < N; i++)
        Horde_of_zombies[i].set_name(name);
    return (Horde_of_zombies);
}