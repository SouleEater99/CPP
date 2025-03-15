#include "./DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Default_Name"), ScavTrap("Default_Name"), FragTrap("Default_Name")
{
    DiamondTrap::_Name = "Default_Name";
    _HitPoits = FragTrap::_HitPoits;
    _EnergyPoints = ScavTrap::_EnergyPoints;
    _AttackDamage = FragTrap::_AttackDamage;
    std::cout << "DiamondTrap Default Constructor Called\n";
}

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    DiamondTrap::_Name = name;
    _HitPoits = FragTrap::_HitPoits;
    _EnergyPoints = ScavTrap::_EnergyPoints;
    _AttackDamage = FragTrap::_AttackDamage;
    std::cout << "DiamondTrap Paramterized Constructor Called\n";

}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    DiamondTrap::_Name = other.DiamondTrap::_Name; // i need to test this if i remove DiamondTrap
    std::cout << "DiamondTrap Copy Constructor Called\n";
}

DiamondTrap::~ DiamondTrap()
{
    std::cout << "DiamondTrap Destructor Called\n";
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
    std::cout << "DiamondTrap name : " << DiamondTrap::_Name << " | ClapTrap name : " << ClapTrap::_Name << std::endl;
}

void    DiamondTrap::attack(const std::string& name)
{
    ScavTrap::attack(name);
}

void    DiamondTrap::print_all_variables()
{
    std::cout << "+++++++++++++++ { DiamondTrap Status } ++++++++++++++++\n";
    std::cout << "CarlTrap _Name : " << ClapTrap::_Name << std::endl;
    std::cout << "DiamondTrap _Name : " << DiamondTrap::_Name << std::endl;
    std::cout << "_HitPoits (FragTrap) : " << _HitPoits << std::endl;
    std::cout << "_EnergyPoints (ScavTrap) : " << _EnergyPoints << std::endl;
    std::cout << "_AttackDamage (FragTrap) : " << _AttackDamage << std::endl << std::endl;

    std::cout << "+++++++++++++++ { ClapTrap Status } ++++++++++++++++\n";
    std::cout << "ClapTrap Name (ClapTrap::) : " << ClapTrap::_Name << std::endl;
    std::cout << "_HitPoits (ClapTrap::) : " << ClapTrap::_HitPoits << std::endl;
    std::cout << "_EnergyPoints (ClapTrap::) : " << ClapTrap::_EnergyPoints << std::endl;
    std::cout << "_AttackDamage (ClapTrap::) : " << ClapTrap::_AttackDamage << std::endl << std::endl;

    std::cout << "+++++++++++++++ { FragTrap Status } ++++++++++++++++\n";
    std::cout << "_HitPoits (FragTrap::) : " << FragTrap::_HitPoits << std::endl;
    std::cout << "_AttackDamage (FragTrap::) : " << FragTrap::_AttackDamage << std::endl << std::endl;
    
    std::cout << "+++++++++++++++ { ScavTrap Status } ++++++++++++++++\n";
    std::cout << "_EnergyPoints (ScavTrap::) : " << ScavTrap::_EnergyPoints << std::endl;
}


