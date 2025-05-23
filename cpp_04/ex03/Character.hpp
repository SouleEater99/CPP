#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "./ICharacter.hpp"
#include "./AMateria.hpp"
#include <iostream>

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria    *_inventory[4];
    AMateria    *_addr_saver[100];
    int         _inv_size; 
public:
    Character();
    Character(const std::string& name);
    Character(const Character& other);
    ~Character();
    Character&  operator = (const Character& other);
    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
    void set_addr(AMateria* addr);
    void clear_addr();
};





#endif