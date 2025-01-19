#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "./Weapon.hpp"
#include <string>

class   HumanA
{
    private:
        std::string _name;
        Weapon      _weapon;
    public:
        std::string getName(void) const;
        void        attack();
        HumanA(std::string Name, Weapon& weapon);
        
};


#endif
