#include "./Zombie.hpp"

void    randomChump(std::string name)
{
    Zombie  New_Zombie(name);
    New_Zombie.announce();
}
