#include "Zombie.hpp"

void Zombie::announce(void)
{
    cout << this->name << ": BraiiiiiiinnnzzzZ..." << endl;
}

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
    cout << this->name << " has been absolutely destroyed" << endl;
}