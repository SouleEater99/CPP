#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "./ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
    int    _EnergyPoints;
public:
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(ScavTrap& other);
    ~ScavTrap();
    ScavTrap&   operator = (const ScavTrap& other);
    void attack(const std::string& target);
    void guardGate();
};




#endif