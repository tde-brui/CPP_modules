#include "../inc/ScavTrap.hpp"

int main()
{
    ScavTrap opp1("opp1");
    ScavTrap opp2("opp2");

    opp1.attack("opp2");
    opp2.attack("opp1");
}