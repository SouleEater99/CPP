#include "FragTrap.hpp"

int main()
{
    {
        std::cout << "+++++++++ test with stack  +++++++++\n";
        FragTrap frag("Robot");
        for (int i = 0; i < 55; i++)
            frag.attack("ENEMY");
        for (int i = 0; i < 55; i++)
            frag.takeDamage(2);
        frag.highFivesGuys();
    }
    {
        std::cout << "+++++++++ test with dynamic alloc +++++++++\n";
        FragTrap    *f = new FragTrap("robot");
        for (int i = 0; i < 55; i++)
            f->attack("ENEMY");
        for (int i = 0; i < 55; i++)
            f->takeDamage(2);
        f->beRepaired(2);
        f->highFivesGuys();
        delete f;
    }
    {
        std::cout << "+++++++++ test with dynamic alloc with subtype +++++++++\n";
        ClapTrap    *f = new FragTrap("robot");
        for (int i = 0; i < 55; i++)
            f->attack("ENEMY");
        for (int i = 0; i < 55; i++)
            f->takeDamage(2);
        f->beRepaired(2);
        // f->_HighFiveGuys ?? < cause subtype couldn't work >
        delete f;
    }
}