#include "./Cat.hpp"

Cat::Cat() : Animal(), _Brain(new Brain())
{
    type = "Cat";
    std::cout << "Default Cat Constructor\n";
}

Cat::Cat(const Cat& other): Animal(other)
{
    _Brain = new Brain();
    *_Brain = *other._Brain;
    std::cout << "Cat Copy Constructor\n";
}

Cat::~Cat()
{
    delete  _Brain;
    std::cout << "Default Cat Destructor\n";
}

Cat& Cat::operator = (const Cat& other)
{
    if (this == &other)
        return *this;
    this->type = other.type;
    *this->_Brain = *other._Brain;
    return *this;
}

void    Cat::makeSound() const
{
    std::cout << "meow meow  !!\n";
}