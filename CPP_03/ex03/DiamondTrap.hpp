#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"

class  DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string     _Name;
public:
    DiamondTrap();
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& other);
    ~ DiamondTrap();
    DiamondTrap&    operator = (const DiamondTrap& other);
    void    whoAmI();
    void    attack(const std::string& name);
};


#endif