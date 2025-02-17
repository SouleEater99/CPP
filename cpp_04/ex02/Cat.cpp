#include "./Cat.hpp"

Cat::Cat() : Animal(), _Brain(new Brain())
{
    type = "Cat";
    std::cout << "Default Cat Constructor\n";
}

Cat::Cat(const Cat& other): Animal(other)
{
    std::cout << "Cat Copy Constructor\n";
}

Cat::~Cat()
{
    delete  _Brain;
    std::cout << "Default Cat Destructor\n";
}

Cat& Cat::operator = (const Cat& other)
{
    this->type = other.type;
    return *this;
}

void    Cat::makeSound() const
{
    std::cout << "meow meow  !!\n";
}