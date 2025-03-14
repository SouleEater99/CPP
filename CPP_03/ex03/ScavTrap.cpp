#include "ScavTrap.hpp"

ScavTrap::ScavTrap():  ClapTrap("Default_Name")
{
    std::cout << "ScavTrap Default Constructor Called\n";
    _HitPoits = 100;
    _EnergyPoints = 50;
    _AttackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name):  ClapTrap(name)
{
    std::cout << "ScavTrap Parameterized Constructor for " << name << " Called\n";
    _HitPoits = 100;
    _EnergyPoints = 50;
    _AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap Copy Constructor for Called\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor Called\n";
}

ScavTrap&   ScavTrap::operator = (const ScavTrap& other)
{
    this->_Name = other._Name;
    this->_HitPoits = other._HitPoits;
    this->_EnergyPoints = other._EnergyPoints;
    this->_AttackDamage = other._AttackDamage;
    return *this;
}

void    ScavTrap::attack(const std::string& target)
{
    if (_HitPoits > 0 && _EnergyPoints > 0)
    {
        _EnergyPoints--;
        std::cout << "ScavTrap " << _Name << " attacks " << target << " causing " << _AttackDamage << " points of damage!\n";
    }
    else
        std::cout << (_HitPoits > 0 ? "No Enough Enegry Points\n" : "Already Dead\n") ;
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode\n";
}