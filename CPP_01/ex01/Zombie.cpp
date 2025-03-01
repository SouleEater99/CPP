#include "./Zombie.hpp"
#include <iostream>

Zombie::Zombie(void)
{
    Name = "";
}

Zombie::Zombie(const std::string& name)
{
    Name = name;
}

void    Zombie::announce()
{
    std::cout << Name << ": BraiiiiiiinnnzzzZ...\n";
}

void    Zombie::setName(const std::string & name)
{
    Name = name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << Name << " Is Destroyed\n";
}