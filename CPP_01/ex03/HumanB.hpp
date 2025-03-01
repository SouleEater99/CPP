#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "./Weapon.hpp"
#include <string>

class   HumanB
{
    private:
        const std::string&     _name;
        Weapon          *_weapon;
    public:
        const std::string getName(void) const;
        void        attack();
        void        setWeapon(Weapon& weapon);
        HumanB(const std::string& Name, Weapon *weapon = NULL);
        ~HumanB();
        
};


#endif
