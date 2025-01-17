#include "./Zombie.hpp"
#include <iostream>

int main()
{
    std::string name;
    Zombie      *zombie;

    name = "fifo";
    zombie = zombieHorde(3, name);
    if (!zombie)
    {
        std::cerr << "Fail to Allocate to Zombies\n";
        return 1;
    }
    for (int i = 0; i < 3; i++)
        zombie[i].announce();
    delete[]  zombie;
}