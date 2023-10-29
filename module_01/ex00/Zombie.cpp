#include "Zombie.hpp"

void Zombie::announce(void)
{
    cout << this->name << ": BraiiiiiiinnnzzzZ..." << endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    cout << this->name << " has been absolutely destroyed" << endl;
}