#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        std::string name;
        int hitpoints;
        int energy_points;
        int attack_damage;
    public:
        void attack(const std::string &target);
        ScavTrap();
        ScavTrap(const std::string &name);
        ScavTrap &operator=(const ScavTrap &scavtrap);
        ~ScavTrap();
        void guardGate(void);
};