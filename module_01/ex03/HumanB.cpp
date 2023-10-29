#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = nullptr;
}

void HumanB::setWeapon(Weapon weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack()
{
    if (weapon != nullptr)
        cout << name << " attacks with their " << weapon->getType() << endl;
    else
        cout << name << "has no weapon" << endl;
}