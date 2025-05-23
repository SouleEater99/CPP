#include "./HumanA.hpp"
#include "./Weapon.hpp"
#include <iostream>

HumanA::HumanA(const std::string& Name, Weapon& weapon) : _name(Name), _weapon(weapon) {}

HumanA::~HumanA()
{
    std::cout << "HumanA is Destroyed\n";
}


const std::string HumanA::getName() const
{
    return _name;
}


void    HumanA::attack(void)
{
    std::cout << _name << " attacks with their "<< _weapon.getType() << std::endl;
}