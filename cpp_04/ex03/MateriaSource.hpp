#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "./IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    int         _src_size;
    AMateria*   _src_store[4];
public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    ~MateriaSource();
    MateriaSource&  operator = (const MateriaSource& other);
    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &type);
};

#endif