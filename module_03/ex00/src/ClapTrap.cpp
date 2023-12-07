#include "ClapTrap.hpp"

    ClapTrap::ClapTrap()
    {
        cout << "A ClapTrap " << " has been created!"<< endl;
        this->name = "default";
        this->attack_damage = 0;
        this->energy_points = 10;
        this->hitpoints = 10;
    }

    ClapTrap::ClapTrap(const std::string &name)
    {
        cout << "ClapTrap " << name << " has been created!"<< endl;
        this->name = name;
        this->attack_damage = 0;
        this->energy_points = 10;
        this->hitpoints = 10;
    }

    ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
    {
        if (this != &claptrap)
        {
            this->name = claptrap.name;
            this->attack_damage = claptrap.attack_damage;
            this->energy_points = claptrap.energy_points;
            this->hitpoints = claptrap.hitpoints;
            return (*this);
        }
        return (*this);
    }

    ClapTrap::~ClapTrap()
    {
        cout << "A ClapTrap " << " has been destroyed!" << endl;
    }

    void ClapTrap::attack(const std::string &target)
    {
        if (this->energy_points <= 0)
        {
            cout << "ClapTrap " << this->name << " has no energy points left!" << endl;
            return ;
        }
        else if (this->hitpoints <= 0)
        {
            cout << "ClapTrap " << this->name << " has no hitpoints and can not attack!" << endl;
            return ;
        }
        cout << "Claptrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << endl;
        this->energy_points -= 1;
    }

    void ClapTrap::takeDamage(unsigned int amount)
    {
        if (this->hitpoints <= 0)
        {
            cout << "ClapTrap " << this->name << " is already dead!" << endl;
            this->hitpoints = 0;
            return ;
        }
        cout << "ClapTrap " << this->name << " took " << amount << " damage!" << endl;
        this->hitpoints -= amount;
        if (this->hitpoints <= 0)
        {
            cout << "ClapTrap " << this->name << " has died!" << endl;
            this->hitpoints = 0;
        }
    }
    void ClapTrap::beRepaired(unsigned int amount)
    {
        if (this->hitpoints == 0)
        {
            cout << "ClapTrap " << this->name << " is dead and can not be repaired!" << endl;
            return ;
        }
        else if (this->energy_points == 0)
        {
            cout << "ClapTrap " << this->name << " has no energy points and can not be repaired!" << endl;
            return ;
        }
        cout << "ClapTrap " << this->name << " has been repaired for " << amount << " hitpoints!" << endl;
        this->hitpoints += amount;
        this->energy_points -= 1;
    }

    int ClapTrap::get_AttackDamage(void)
    {
        return (this->attack_damage);
    }

    void ClapTrap::get_Stats(void)
    {
        cout << "ClapTrap " << this->name << " has " << this->hitpoints << " hitpoints, " << this->energy_points << " energy points and " << this->attack_damage << " attack damage!" << endl;
    }