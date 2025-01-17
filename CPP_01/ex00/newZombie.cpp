#include "./Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie* New_Zombie;
    
    New_Zombie = new Zombie(name);
    return (New_Zombie);
}
