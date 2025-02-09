#include "ClapTrap.hpp"

int main()
{
    ClapTrap    claptrap("robot");

    for (int i = 0; i < 20 ; i++)
        claptrap.attack("enemy 2");
    claptrap.beRepaired(100);
    claptrap.takeDamage(200);

}