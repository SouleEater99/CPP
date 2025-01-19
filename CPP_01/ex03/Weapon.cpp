#include "./Weapon.hpp"

std::string Weapon::getType(void) const {return type;}

void        Weapon::setType(std::string& new_type) {type = new_type;}

Weapon::Weapon(std::string& weapon_type)
{
    type = weapon_type;
}

Weapon::~Weapon()
{
}
