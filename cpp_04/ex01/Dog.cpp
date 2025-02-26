#include "Dog.hpp"

Dog::Dog() : Animal(), _Brain(new Brain())
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
    delete  _Brain;
    std::cout << "Default Dog Destructor\n";
}

Dog& Dog::operator = (const Dog& other)
{
    if (this == &other)
        return *this;
    if (this->_Brain)
        delete this->_Brain;
    this->type = other.type;
    return *this;
}

void    Dog::makeSound() const
{
    std::cout << "Dogs bark oho oho !!\n";
}