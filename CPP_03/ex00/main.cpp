#include "ClapTrap.hpp"

int main()
{
    ClapTrap    claptrap("robot");

    for (int i = 0; i < 20 ; i++)
    {
        claptrap.attack("enemy 2");
    }
    std::cout << "====================================\n";
    // claptrap.beRepaired(100);
    std::cout << "====================================\n";
    claptrap.takeDamage(100000);
    claptrap.takeDamage(100000);

}