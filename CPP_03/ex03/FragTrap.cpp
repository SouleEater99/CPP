#include "FragTrap.hpp"

FragTrap::FragTrap():  ClapTrap("Default_Name")
{
    std::cout << "FragTrap Default Constructor Called\n";
    _HitPoits = 100;
    _EnergyPoints = 100;
    _AttackDamage = 30;
}

FragTrap::FragTrap(const std::string& name):  ClapTrap(name)
{
    std::cout << "FragTrap Parameterized Constructor for " << name << " Called\n";
    _HitPoits = 100;
    _EnergyPoints = 100;
    _AttackDamage = 30;
}

FragTrap::FragTrap(FragTrap& other): ClapTrap(other)
{
    std::cout << "FragTrap Copy Constructor Called\n";
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor Called\n";
}

FragTrap&   FragTrap::operator = (const FragTrap& other)
{
    this->_Name = other._Name;
    this->_HitPoits = other._HitPoits;
    this->_EnergyPoints = other._EnergyPoints;
    this->_AttackDamage = other._AttackDamage;
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap: positive high fives request\n";
}

