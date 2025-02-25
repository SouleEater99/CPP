#include "./Ice.hpp"

Ice::Ice(): AMateria("ice")
{
    // std::cout << "Ice: Default Constructor Called\n";
}

Ice::Ice(const Ice& other): AMateria(other)
{
    // std::cout << "Ice: Copy Constructor Called\n";
}

Ice::~Ice()
{
    std::cout << "Ice: Destructor Called\n";
}

Ice&       Ice::operator = (const Ice& other)
{
    this->_type = other._type;
    return *this;
}

AMateria    *Ice::clone() const
{
    AMateria* clone;

    clone = new Ice;
    return clone;
}

void        Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at" << target.getName() << " *\n";
}