#include "./Zombie.hpp"
#include <iostream>

void    Zombie::announce()
{
    std::cout << Name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(const std::string& name)
{
    Name = name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << Name << " Is Destroyed\n";
}