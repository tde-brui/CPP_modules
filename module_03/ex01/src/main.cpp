#include "../inc/ScavTrap.hpp"

int main()
{
    ScavTrap opp1("opp1");
    ScavTrap opp2("opp2");

    cout << endl;

    opp1.get_Stats();
    opp2.get_Stats();
    opp1.attack("opp2");
    opp2.takeDamage(opp1.get_AttackDamage());
    opp1.get_Stats();
    opp2.get_Stats();
    opp2.attack("opp1");
    opp1.takeDamage(opp2.get_AttackDamage());
    opp1.get_Stats();
    opp2.get_Stats();

    opp1.guardGate();
    opp2.guardGate();

    cout << endl;
}