#include "DiamondTrap.hpp"

int main()
{

    {
        std::cout << "+++++++++ test with stack  +++++++++\n";
        DiamondTrap diamond("Robot");
        
        diamond.whoAmI();
        diamond.print_all_variables();
        for (int i = 0; i < 55; i++)
            diamond.attack("ENEMY");
        for (int i = 0; i < 55; i++)
            diamond.takeDamage(2);
        diamond.highFivesGuys();
    }
    {
        std::cout << "+++++++++ test with dynamic alloc +++++++++\n";

        DiamondTrap    *d = new DiamondTrap("robot");

        d->whoAmI();
        d->print_all_variables();
        for (int i = 0; i < 55; i++)
            d->attack("ENEMY");
        for (int i = 0; i < 55; i++)
            d->takeDamage(2);
        d->beRepaired(2);
        d->highFivesGuys();
        delete d;
    }
    {
        std::cout << "+++++++++ test with dynamic alloc with subtype +++++++++\n";
        
        ClapTrap    *d = new DiamondTrap("robot");

        // d->whoAmI();  ?? < cause subtype couldn't work >
        // d->print_all_variables();   ?? < cause subtype couldn't work >
        for (int i = 0; i < 55; i++)
            d->attack("ENEMY");
        for (int i = 0; i < 55; i++)
            d->takeDamage(2);
        d->beRepaired(2);
        delete d;
    }
}