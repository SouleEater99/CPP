#include "./Zombie.hpp"

Zombie  *zombieHorde(int N, std::string &name)
{
    Zombie *zombie;

    if (N < 0)
        return (NULL);
    zombie = new (std::nothrow) Zombie[N];
    if (!zombie)
        return (NULL);
    for (int i = 0; i < N; i++)
        zombie[i].setName(name);
    return zombie;
}