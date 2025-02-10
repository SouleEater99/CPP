#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
protected:
    std::string     _Name;
    int    _HitPoits;
    int    _EnergyPoints;
    int    _AttackDamage;

public:
    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(ClapTrap& other);
    ~ClapTrap();
    ClapTrap&  operator = (const ClapTrap& other);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif