#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    private:
        std::string name;
        int hitpoints;
        int energy_points;
        int attack_damage;
    public:
        FragTrap();
        FragTrap(const std::string &name);
        FragTrap(const FragTrap &fragtrap);
        FragTrap &operator=(const FragTrap &fragtrap);
        ~FragTrap();
        void highFivesGuys(void);
};
