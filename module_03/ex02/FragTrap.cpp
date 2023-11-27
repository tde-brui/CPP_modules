#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    cout << "A default FragTrap " << " has been created!"<< endl;
    this->name = "default";
    this->attack_damage = 30;
    this->energy_points = 100;
    this->hitpoints = 100;
}

FragTrap::FragTrap(const std::string &name)
{
    cout << "A FragTrap " << name << " has been created!"<< endl;
    this->name = name;
    this->attack_damage = 30;
    this->energy_points = 100;
    this->hitpoints = 100;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap)
{
    if (this != &fragtrap)
    {
        this->name = fragtrap.name;
        this->attack_damage = fragtrap.attack_damage;
        this->energy_points = fragtrap.energy_points;
        this->hitpoints = fragtrap.hitpoints;
    }
    return (*this);
}

FragTrap::~FragTrap()
{
    cout << "A FragTrap has been destroyed!" << endl;
}

void FragTrap::highFivesGuys(void)
{
    cout << this->name << ": Teamwork deserves a high five, don't you think?" << endl;
}