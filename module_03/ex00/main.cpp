#include "ClapTrap.hpp"

int main()
{
    ClapTrap opp1("opp1");
    ClapTrap opp2("opp2");

    opp1.attack("opp2");
    opp2.takeDamage(opp1.get_AttackDamage());

    opp1.get_Stats();
    opp2.get_Stats();

    cout << endl;

    opp2.attack("opp1");
    opp1.takeDamage(opp2.get_AttackDamage());


    opp1.get_Stats();
    opp2.get_Stats();

    cout << endl;

    opp1.beRepaired(10);
    opp2.beRepaired(15);

    opp1.get_Stats();
    opp2.get_Stats();
}