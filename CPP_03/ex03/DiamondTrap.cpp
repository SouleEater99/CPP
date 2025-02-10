#include "./DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Default_Name")
{
    std::cout << "DiamondTrap Default Constructor Called";
}

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name + "_clap_name")
{
    _HitPoits = FragTrap::_HitPoits;
    _EnergyPoints = ScavTrap::_EnergyPoints;
    _AttackDamage = FragTrap::_AttackDamage;

}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
}

DiamondTrap::~ DiamondTrap()
{
}

DiamondTrap&    DiamondTrap::operator = (const DiamondTrap& other)
{
    this->_Name = other._Name;
    this->_HitPoits = other._HitPoits;
    this->_EnergyPoints = other._EnergyPoints;
    this->_AttackDamage = other._AttackDamage;
    return *this;
}

void DiamondTrap::whoAmI()
{
}

