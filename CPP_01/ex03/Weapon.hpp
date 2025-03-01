#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
private:
    std::string type;
public:
    Weapon();
    Weapon(const std::string& Weapon_type);
    const std::string& getType(void) const;
    void        setType(const std::string& new_type);
    ~Weapon();
};





#endif