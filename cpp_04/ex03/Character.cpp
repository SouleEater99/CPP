#include "./Character.hpp"

Character::Character(): _name("Abdelali")
{
    std::cout << "Character: Default Constructor Called\n";
}


Character::Character(const std::string& name): _name(name)
{
    std::cout << "Character: Parametrized Constructor Called\n";
}


Character::Character(const Character& other): _name(other._name)
{
    for (int i = 0; i < 4; i++)
        if (other._invetory[i])
            this->_invetory[i] = other._invetory[i]->clone();
    std::cout << "Character: Copy Constructor Called\n";
}

Character::~Character()
{
    std::cout << "Character: Destructor Called\n";
}

Character&  Character::operator=(const Character& other)
{
    this->_name = other._name;
    for (int i = 0; i < 4; i++)
        if (other._invetory[i])
            this->_invetory[i] = other._invetory[i]->clone();
}

std::string const    &Character::getName() const
{
    return (_name);
}

void Character::equip(AMateria *m)
{

}

void Character::unequip(int idx)
{}


void Character::use(int idx, ICharacter &target)
{}