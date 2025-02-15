#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "Default Dog Constructor\n";
}

Dog::Dog(const Dog& other): Animal(other)
{
    std::cout << "Dog Copy Constructor\n";
}

Dog::~Dog()
{
    std::cout << "Default Dog Destructor\n";
}

Dog& Dog::operator = (const Dog& other)
{
    this->type = other.type;
    return *this;
}

void    Dog::makeSound() const
{
    std::cout << "Dogs bark oho oho !!\n";
}