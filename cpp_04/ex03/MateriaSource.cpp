#include "./MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource Default Constructor Called\n";
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    std::cout << "MateriaSource Copy Constructor Called\n";
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (_src_store[i])
            delete _src_store[i];
    }
    std::cout << "MateriaSource Destructor Called\n";
}

MateriaSource&  MateriaSource::operator = (const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._src_store[i])
            this->_src_store[i] = other._src_store[i]->clone();
    }

}

void MateriaSource::learnMateria(AMateria *)
{

}
AMateria *MateriaSource::createMateria(std::string const &type)
{

}