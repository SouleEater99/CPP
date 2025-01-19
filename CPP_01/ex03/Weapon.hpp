#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
private:
    std::string type;
public:
    std::string getType(void) const;
    void        setType(std::string new_type);
    Weapon(std::string Weapon_type);
    ~Weapon();
};





#endif