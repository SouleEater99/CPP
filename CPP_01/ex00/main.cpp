#include "./Zombie.hpp"


// Zombie* newZombie(std::string name);
// void    randomChump(std::string name);

int main()
{
    Zombie* first_zombie;
    std::string name;

    std::cout << "Entre Name of the first zombie: ";
    std::cin >> name;
    if (name.empty())
        return (1);
    first_zombie = newZombie(name);
    first_zombie->announce();
    std::cout << "Entre Name of the Second zombie: ";
    std::cin >> name;
    if (name.empty())
    {
        delete first_zombie;
        return (1);
    }
    randomChump(name);
    delete  first_zombie;
}