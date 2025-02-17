#include "./Brain.hpp"

Brain::Brain()
{
    std::cout << "Default Brain Constructor\n";
}

Brain::Brain(const Brain& other)
{
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
    std::cout << "Copy Brain Constructor\n";
}

Brain::~Brain()
{
    std::cout << "Brain Destructor\n";
}

Brain&  Brain::operator = (const Brain& other)
{
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
    return *this;
}