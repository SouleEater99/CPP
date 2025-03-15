#include "ScavTrap.hpp"

int main()
{
    {
        std::cout << "+++++++++ test with stack  +++++++++\n";
        ScavTrap scav("Robot");
        for (int i = 0; i < 55; i++)
            scav.attack("ENEMY");
        for (int i = 0; i < 55; i++)
            scav.takeDamage(2);
        scav.guardGate();
    }
    {
        std::cout << "+++++++++ test with dynamic alloc +++++++++\n";
        ScavTrap    *s = new ScavTrap("robot");
        for (int i = 0; i < 55; i++)
            s->attack("ENEMY");
        for (int i = 0; i < 55; i++)
            s->takeDamage(2);
        s->beRepaired(2);
        s->guardGate();
        delete s;
    }
    {
        std::cout << "+++++++++ test with dynamic alloc with subtype +++++++++\n";
        ClapTrap    *s = new ScavTrap("robot");
        for (int i = 0; i < 55; i++)
            s->attack("ENEMY");
        for (int i = 0; i < 55; i++)
            s->takeDamage(2);
        s->beRepaired(2);
        // s.guardGate() ?? < cause subtype couldn't work >
        delete s;
    }
}