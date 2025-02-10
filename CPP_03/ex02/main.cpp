#include "FragTrap.hpp"

int main()
{
    FragTrap frag("Robot");
    for (int i = 0; i < 95; i++)
        frag.attack("ENEMY");
    for (int i = 0; i < 45; i++)
        frag.takeDamage(2);
    std::cout << "========================================\n";

    FragTrap frag2 = frag;
    for (int i = 0; i < 10; i++)
        frag2.attack("test");
    for (int i = 0; i < 10; i++)
        frag2.takeDamage(2);

    frag.highFivesGuys();

}