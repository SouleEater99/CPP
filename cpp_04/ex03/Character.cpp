#include "./Character.hpp"

Character::Character() : _name("Abdelali"), _inv_size(0)
{
    for (int i = 0; i < 4; ++i)
        _invetory[i] = NULL;
    for (int i = 0; i < 100; ++i)
        _addr_saver[i] = NULL;
    std::cout << "Character: Default Constructor Called\n";
}

Character::Character(const std::string &name) : _name(name), _inv_size(0)
{
    for (int i = 0; i < 4; ++i)
        _invetory[i] = NULL;
    for (int i = 0; i < 100; ++i)
        _addr_saver[i] = NULL;
    std::cout << "Character: Parametrized Constructor Called\n";
}

Character::Character(const Character &other) : _name(other._name)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._invetory[i])
        {
            this->_invetory[i] = other._invetory[i]->clone();
            this->set_addr(this->_invetory[i]);
        }
    }
    this->_inv_size = other._inv_size;
    std::cout << "Character: Copy Constructor Called\n";
}

Character::~Character()
{
    clear_addr();
    std::cout << "Character: Destructor Called\n";
}

Character &Character::operator=(const Character &other)
{
    this->_name = other._name;
    for (int i = 0; i < 4; i++)
    {
        if (other._invetory[i])
        {
            this->_invetory[i] = other._invetory[i]->clone();
            this->set_addr(this->_invetory[i]);
        }
    }
    this->_inv_size = other._inv_size;
    return (*this);
}

std::string const &Character::getName() const
{
    return (_name);
}

void Character::equip(AMateria *m)
{
    if (_inv_size >= 4)
        std::cout << "Inventory is Full(use unequip method to get a place)\n";
    else if (!m)
        std::cout << "AMateria Not found (NULL)\n";
    else
    {
        for (int i = 0; i < 4 ; i++)
        {
            if (_invetory[i] == NULL)
            {
                _invetory[i] = m;
                std::cout << m->getType() << " is equiped\n";
                break;
            }
        }
    }
}

void Character::unequip(int idx)
{
    if (_inv_size == 0)
        std::cout << "There is nothing in the Inventory\n";
    else if (idx >= 0 && idx <= 3)
        _invetory[idx] = NULL;
    else
        std::cout << "This index not found in Inventory\n";
        
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx <= 3)
        if (_invetory[idx])
            _invetory[idx]->use(target);
}

void Character::set_addr(AMateria *addr)
{
    int i;

    i = 0;
    while (i < 100 && _addr_saver[i] != NULL)
        i++;
    if (i >= 100)
    {
        clear_addr();
        i = 0;
    }
    _addr_saver[i] = addr;
}

void Character::clear_addr()
{
    for (int i = 0; i < 100; i++)
    {
        delete _addr_saver[i];
        _addr_saver[i] = NULL;
    }
}