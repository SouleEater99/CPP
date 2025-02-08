#include "./ClapTrap.hpp"

ClapTrap::ClapTrap(): _Name(""), _HitPoits(10), _EnergyPoints(10), _AttackDamage(0) {}

ClapTrap::ClapTrap(const std::string& name): _Name(name), _HitPoits(10), _EnergyPoints(10), _AttackDamage(0) {}

ClapTrap::ClapTrap(ClapTrap& other): _Name(other._Name), _HitPoits(other._HitPoits), _EnergyPoints(other._EnergyPoints), _AttackDamage(other._AttackDamage) {}

ClapTrap::~ClapTrap() {}

ClapTrap&  ClapTrap::operator = (const ClapTrap& other)
{
    this->_Name = other._Name;
    this->_HitPoits = other._HitPoits;
    this->_EnergyPoints = other._EnergyPoints;
    this->_AttackDamage = other._AttackDamage;
    return *this;
}

void       ClapTrap::attack(const std::string& target)
{

}

void       ClapTrap::takeDamage(unsigned int amount)
{

}

void       ClapTrap::beRepaired(unsigned int amount)
{

}


