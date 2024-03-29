#include <iostream>

using std::cout;
using std::endl;
class ClapTrap
{
    protected:
        std::string name;
        int hitpoints;
        int energy_points;
        int attack_damage;

    public:
        ClapTrap();
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &claptrap);
        ClapTrap &operator=(const ClapTrap &claptrap);
        ~ClapTrap();
        virtual void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        int get_AttackDamage(void);
        void get_Stats(void);
        virtual std::string getClass() const;
        int get_AttackDamage() const;
};
