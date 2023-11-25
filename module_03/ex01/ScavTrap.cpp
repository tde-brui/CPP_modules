#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    cout << "A ScavTrap " << " has been created!"<< endl;
    this->name = "default";
    this->attack_damage = 20;
    this->energy_points = 50;
    this->hitpoints = 100;
}

ScavTrap::ScavTrap(const std::string &name)
{
    cout << "A ScavTrap " << name << " has been created!"<< endl;
    this->name = name;
    this->attack_damage = 20;
    this->energy_points = 50;
    this->hitpoints = 100;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
    if (this != &scavtrap)
    {
        this->name = scavtrap.name;
        this->attack_damage = scavtrap.attack_damage;
        this->energy_points = scavtrap.energy_points;
        this->hitpoints = scavtrap.hitpoints;
    }
    return (*this);
}

void ScavTrap::attack(const std::string &target)
{
    if (this->energy_points == 0)
    {
        cout << "ScavTrap " << this->name << " has no energy points left and can not attack!" << endl;
        return ;
    }
    else if (this->hitpoints == 0)
    {
        cout << "ScavTrap " << this->name << " has no hitpoints and can not attack!" << endl;
        return ;
    }
    cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << endl;
    this->energy_points -= 1;
}

ScavTrap::~ScavTrap()
{
    cout << "A ScavTrap " << " has been destroyed!" << endl;
}
