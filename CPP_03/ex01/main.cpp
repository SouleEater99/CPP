#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav("Robot");
    for (int i = 0; i < 55; i++)
        scav.attack("ENEMY");
    for (int i = 0; i < 55; i++)
        scav.takeDamage(2);
    scav.guardGate();

}