#include "./ClapTrap.hpp"

ClapTrap::ClapTrap(): _Name("Default"), _HitPoits(10), _EnergyPoints(10), _AttackDamage(0)
{
    std::cout << "ClapTrap Default Constructor Called\n";
}

ClapTrap::ClapTrap(const std::string& name): _Name(name), _HitPoits(10), _EnergyPoints(10), _AttackDamage(0)
{
    std::cout << "ClapTrap Parameterized Constructor for " << name << " Called\n";
}

ClapTrap::ClapTrap(ClapTrap& other): _Name(other._Name), _HitPoits(other._HitPoits), _EnergyPoints(other._EnergyPoints), _AttackDamage(other._AttackDamage)
{
    std::cout << "ClapTrap Copy Constructor Called\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor Called\n";
}

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
    if (_HitPoits > 0 && _EnergyPoints > 0)
    {
        _EnergyPoints--;
        std::cout << "ClapTrap " << _Name << " attacks " << target << " causing " << _AttackDamage << " points of damage!\n";
    }
    else
        std::cout << (_HitPoits > 0 ? "No Enough Enegry Points\n" : "Already Dead\n") ;

}

void       ClapTrap::takeDamage(unsigned int amount)
{
    if (_HitPoits > 0)
    {
        if ((long)_HitPoits - amount <= -1 * __INT_MAX__)
            _HitPoits = 0;
        else
            _HitPoits -= amount;
        _HitPoits =  _HitPoits < 0 ? 0 : _HitPoits;
        std::cout << _Name << " Take Damage causing " << amount << " hit points now is " <<  _HitPoits  << std::endl;
    }
    else
        std::cout << "Already Dead\n";
}

void       ClapTrap::beRepaired(unsigned int amount)
{
    if (_HitPoits > 0 && _EnergyPoints > 0)
    {
        if ((long)_HitPoits + amount >= __INT_MAX__)
            _HitPoits = __INT_MAX__;
        else
            _HitPoits += amount;
        _EnergyPoints--;
        std::cout << "ClapTrap " << _Name << " repaired, Hit Points now is " << _HitPoits << std::endl;
    }
    else
        std::cout << (_HitPoits > 0 ? "No Enough Enegry Points \n" : "Already Dead\n") ;
}


