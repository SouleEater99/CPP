#include "./Cure.hpp"

Cure::Cure(): AMateria("cure")
{
    // std::cout << "Cure: Default Constructor Called\n";
}

Cure::Cure(const Cure& other): AMateria(other)
{
    // std::cout << "Cure: Copy Constructor Called\n";
}

Cure::~Cure()
{
    // std::cout << "Cure: Destructor Called\n";
}

Cure&       Cure::operator = (const Cure& other)
{
    this->_type = other._type;
    return *this;
}

AMateria    *Cure::clone() const
{
    AMateria* clone;

    clone = new Cure;
    return clone;
}

void        Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *\n";
}