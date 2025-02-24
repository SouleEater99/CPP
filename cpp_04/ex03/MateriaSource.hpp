#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "./IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria*   _src_store[4] = {NULL};
public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    ~MateriaSource() {}
    MateriaSource&  operator = (const MateriaSource& other);
    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &type);
};

#endif