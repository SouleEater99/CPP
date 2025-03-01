#include "./Zombie.hpp"
#include <iostream>

int main()
{
    std::string name;
    Zombie      *zombie = NULL;
    int         hordeSize;

    name = "fifo";
    hordeSize = 3;
    zombie = zombieHorde(hordeSize, name);
    if (!zombie)
    {
        std::cerr << "Fail to Allocate to Zombies\n";
        return 1;
    }
    for (int i = 0; i < hordeSize; i++)
        zombie[i].announce();
    delete[]  zombie;
}