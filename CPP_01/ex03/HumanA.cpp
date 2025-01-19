#include "./HumanA.hpp"
#include "./Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string Name, Weapon& weapon) : _name(Name), _weapon(weapon)
{
}

std::string HumanA::getName() const
{
    return _name;
}


void    HumanA::attack(void)
{
    std::cout << _name << " attacks with their "<< _weapon.getType() << std::endl;
}