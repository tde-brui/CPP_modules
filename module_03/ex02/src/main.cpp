#include "../inc/FragTrap.hpp"

int main()
{
    FragTrap opp1("opp1");
    FragTrap opp2("opp2");
    ClapTrap opp3("opp3");
    ScavTrap opp4("opp4");

    cout << endl;

    opp1.highFivesGuys();
    opp2.highFivesGuys();
    opp4.attack("opp3");
    opp3.takeDamage(opp4.get_AttackDamage());
    opp3.get_Stats();
    opp1.attack("opp3");
    opp3.takeDamage(opp1.get_AttackDamage());
    opp3.get_Stats();
    //opp3.highFivesGuys();

    cout << endl;
}