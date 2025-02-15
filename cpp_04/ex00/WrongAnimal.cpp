#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal Type")
{
    std::cout << "Default WrongAnimal Constructor\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other): type(other.type)
{
    std::cout << "WrongAnimal Copy Constructor\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Default WrongAnimal Destructor\n";
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& other)
{
    this->type = other.type;
    return *this;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal Sound\n";
}

std::string  WrongAnimal::getType() const
{
    return (type);
}