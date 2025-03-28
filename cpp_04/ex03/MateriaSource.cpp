#include "./MateriaSource.hpp"

MateriaSource::MateriaSource(): _src_size(0)
{
    for (int i = 0; i < 4; ++i)
        _src_store[i] = NULL;
    // std::cout << "MateriaSource Default Constructor Called\n";
}

MateriaSource::MateriaSource(const MateriaSource& other): _src_size(0)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other._src_store[i])
            _src_store[i] = other._src_store[i]->clone();
        else
            _src_store[i] = NULL;
        _src_size = other._src_size;
    }
    // std::cout << "MateriaSource Copy Constructor Called\n";
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (_src_store[i])
            delete _src_store[i];
    }
    // std::cout << "MateriaSource Destructor Called\n";
}

MateriaSource&  MateriaSource::operator = (const MateriaSource& other)
{
    if (this == &other)
        return *this;
    this->_src_size = other._src_size;
    for (int i = 0; i < 4; i++)
    {
        if (this->_src_store[i])
            delete this->_src_store[i];
        if (other._src_store[i])
            this->_src_store[i] = other._src_store[i]->clone();
        else
            this->_src_store[i] = NULL;
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (m && _src_size < 4)
    {
        for (int i = 0; i < 4; i++)
        {
            if (!_src_store[i])
            {
                _src_store[i] = m;
                _src_size++;
                break;
            }
        }
    }
    else    
        std::cout << (_src_size >= 4 ? "Source Inventory are FULL (PLEASE FREE THAT ONE YOU ENTRED)\n" : "No Materia Found\n");

}
AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < _src_size; i++)
    {
        if (_src_store[i]->getType() == type)
            return _src_store[i]->clone();
    }
    return 0;
}