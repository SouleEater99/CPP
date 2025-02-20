#include "AMateria.hpp"


AMateria::AMateria(): _type("")
{
    std::cout << "AMateria: Default Constructor Called\n";
}

AMateria::AMateria(std::string const &type): _type(type)
{
    std::cout << "AMateria: Parametrized Constructor Called\n";
}

AMateria::AMateria(const AMateria& other): _type(this->_type)
{
    std::cout << "AMateria: Copy Constructor Called\n";
}

AMateria&   AMateria::operator = (const AMateria& other)
{
    this->_type = other._type;
}

std::string const &AMateria::getType() const
{
    return (_type);
}

void AMateria::use(ICharacter &target)
{

}

AMateria::~AMateria()
{
    std::cout << "AMateria: Destructor Called\n";
}
