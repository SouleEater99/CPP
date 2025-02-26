#include "Animal.hpp"

Animal::Animal() : type("Animal Type")
{
    std::cout << "Default Animal Constructor\n";
}

Animal::Animal(const Animal& other): type(other.type)
{
    std::cout << "Animal Copy Constructor\n";
}

Animal::~Animal()
{
    std::cout << "Default Animal Destructor\n";
}

Animal& Animal::operator = (const Animal& other)
{
    if (this == &other)
        return *this;
    this->type = other.type;
    return *this;
}

void    Animal::makeSound() const
{
    std::cout << "Animal Sound\n";
}

std::string  Animal::getType() const
{
    return (type);
}