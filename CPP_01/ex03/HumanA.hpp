#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "./Weapon.hpp"
#include <string>

class   HumanA
{
    private:
        const std::string&    _name;
        Weapon&         _weapon;
    public:
        const std::string getName(void) const;
        void        attack();
        HumanA(const std::string& Name, Weapon& weapon);
        ~HumanA();
        
};


#endif
