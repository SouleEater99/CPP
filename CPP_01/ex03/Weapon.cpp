#include "./Weapon.hpp"

Weapon::Weapon() : type("Wooden Club") {}

Weapon::Weapon(const std::string& weapon_type) : type(weapon_type) {}

const std::string& Weapon::getType(void) const {return type;}

void        Weapon::setType(const std::string& new_type) {type = new_type;}

Weapon::~Weapon()
{
    std::cout << "Weapon " << type << ": is Destroyed\n";
}
