#include "./Zombie.hpp"

void    Zombie::announce()
{
    std::cout << Name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string name)
{
    Name = name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << Name << " Is Destroyed\n";
}