#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "Default WrongCat Constructor\n";
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
    std::cout << "WrongCat Copy Constructor\n";
}

WrongCat::~WrongCat()
{
    std::cout << "Default WrongCat Destructor\n";
}

WrongCat& WrongCat::operator = (const WrongCat& other)
{
    this->type = other.type;
    return *this;
}

void    WrongCat::makeSound() const
{
    std::cout << "WrongCat : meow meow  !!\n";
}