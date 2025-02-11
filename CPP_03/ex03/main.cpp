#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamond("Ali");

    diamond.print_all_variables();
    diamond.whoAmI();
    for (size_t i = 0; i < 55; i++)
        diamond.attack("ENEMY");
    diamond.beRepaired(100);
    diamond.takeDamage(2);

}