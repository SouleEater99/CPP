#include "./HumanB.hpp"
#include "./Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string Name, Weapon *weapon) : _name(Name), _weapon(weapon) {}

HumanB::~HumanB()
{
    std::cout << "HumanB is Destroyed\n";
}

std::string HumanB::getName() const
{
    return _name;
}

void    HumanB::attack(void)
{
    if (_weapon)
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " has no weapon to attack with! " << std::endl;
}

void    HumanB::setWeapon(Weapon& weapon)
{
    _weapon = &weapon;
}