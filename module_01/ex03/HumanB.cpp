#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack()
{
    if (weapon)
        cout << name << " attacks with their " << weapon->getType() << endl;
    else
        cout << name << " has no weapon" << endl;
}
