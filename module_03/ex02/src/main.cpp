#include "../inc/FragTrap.hpp"

int main()
{
    FragTrap opp1("opp1");
    FragTrap opp2("opp2");

    opp1.highFivesGuys();
    opp1.throwGrenade("opp2");
    opp2.highFivesGuys();
    opp2.throwGrenade("opp1");
}