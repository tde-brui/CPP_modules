#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        virtual void attack(const std::string &target);
        ScavTrap();
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap &scavtrap);
        ScavTrap &operator=(const ScavTrap &scavtrap);
        ~ScavTrap();
        void guardGate(void);
        int get_Hitpoints() const;
        virtual std::string getClass() const;
};