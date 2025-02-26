#include "AMateria.hpp"


AMateria::AMateria(): _type("Magic")
{
    // std::cout << "AMateria: Default Constructor Called\n";
}

AMateria::AMateria(std::string const &type): _type(type)
{
    // std::cout << "AMateria: Parametrized Constructor Called\n";
}

AMateria::AMateria(const AMateria& other): _type(other._type)
{
    // std::cout << "AMateria: Copy Constructor Called\n";
}

AMateria&   AMateria::operator = (const AMateria& other)
{
    std::cout << "++++++++++++++++++++++++\n"; 
    if (this == &other)
        return *this;
    return *this;
}

std::string const &AMateria::getType() const
{
    return (_type);
}

void AMateria::use(ICharacter &target)
{
    std::cout << "Hit the target " << target.getName() << "by " << _type << "\n";
}

AMateria::~AMateria()
{
    // std::cout << "AMateria: Destructor Called\n";
}
