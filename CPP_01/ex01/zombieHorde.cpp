#include "./Zombie.hpp"

Zombie  *zombieHorde(int N, std::string &name)
{
    Zombie *zombie;

    zombie = new (std::nothrow) Zombie[N];
    if (!zombie)
        return (nullptr);
    for (int i = 0; i < N; i++)
        zombie[i].setName(name);
    return zombie;
}