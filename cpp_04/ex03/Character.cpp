#include "./Character.hpp"

Character::Character() : _name("Abdelali"), _inv_size(0)
{
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
    for (int i = 0; i < 100; ++i)
        _addr_saver[i] = NULL;
    // std::cout << "Character: Default Constructor Called\n";
}

Character::Character(const std::string &name) : _name(name), _inv_size(0)
{
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
    for (int i = 0; i < 100; ++i)
        _addr_saver[i] = NULL;
    // std::cout << "Character: Parametrized Constructor Called\n";
}

Character::Character(const Character &other) : _name(other._name)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._inventory[i])
            this->_inventory[i] = other._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
    this->_inv_size = other._inv_size;
    // std::cout << "Character: Copy Constructor Called\n";
}

Character &Character::operator=(const Character &other)
{
    if (this == &other)
        return *this;
    this->_name = other._name;
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i])
            delete _inventory[i];
        if (other._inventory[i])
            this->_inventory[i] = other._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
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
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i] == NULL)
            {
                _inventory[i] = m;
                std::cout << m->getType() << " is equiped\n";
                _inv_size++;
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
    {
        if (_inventory[idx])
        {
            set_addr(_inventory[idx]);
            std::cout << "Unequip MAteria type : " << _inventory[idx]->getType() << "\n";
            _inventory[idx] = NULL;
            _inv_size--;
        }
        else
            std::cout << "There is No Materia in this Index\n";
    }
    else
        std::cout << "This index not found in Inventory\n";
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx <= 3)
    {
        if (_inventory[idx])
            _inventory[idx]->use(target);
        else
            std::cout << "There Is Nothing In Inventory[" << idx << "]\n";
    }
    else
        std::cout << "This Index Is Not Valid\n";
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
    // std::cout << "+++++++++++++++ Freeing Mode ++++++++++++++++\n";
    for (int i = 0; i < 100; i++)
    {
        for (int k = 0; k < 4 && _addr_saver[i]; k++)
            if (_addr_saver[i] == _inventory[k])
                _addr_saver[i] = NULL;
        // std::cout << "{" << this->getName() << "} : address[" << i << "] : " << _addr_saver[i] << "\n";
        if (_addr_saver[i])
        {
            for (int j = i + 1; j < 100; j++)
                if (_addr_saver[i] == _addr_saver[j])
                    _addr_saver[j] = NULL;
            delete _addr_saver[i];
        }
        _addr_saver[i] = NULL;
    }
}

Character::~Character()
{
    clear_addr();
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
        {
            for (int j = i + 1; j < 4; j++)
                if (_inventory[i] == _inventory[j])
                    _inventory[j] = NULL;
            delete _inventory[i];
        }
    }
    // std::cout << "Character: Destructor Called\n";
}