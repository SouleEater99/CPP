#include "./Zombie.hpp"
#include <iostream>

int main()
{
    Zombie*     HeapZombie;
    std::string name;

    std::cout << "Entre Name of the first zombie: ";
    std::getline(std::cin, name);
    if (name.empty())
    {
        std::cerr << "Error Empty Name Entry\n";
        return (1);
    }
    HeapZombie = newZombie(name);
    HeapZombie->announce();
    std::cout << "Entre Name of the Second zombie: ";
    std::getline(std::cin, name);
    if (name.empty())
    {
        delete HeapZombie;
        std::cerr << "Error Empty Name Entry\n";
        return (2);
    }
    randomChump(name);
    delete  HeapZombie;
}