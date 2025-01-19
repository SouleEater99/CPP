#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "./Weapon.hpp"
#include <string>

class   HumanB
{
    private:
        std::string _name;
        Weapon      *_weapon;
    public:
        std::string getName(void) const;
        void        attack();
        void        setWeapon(Weapon& weapon);
        HumanB(std::string Name, Weapon *weapon = nullptr);
        
};


#endif
