#include "./Harl.hpp"

void    Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void    Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";    
}

void    Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";    
}

void    Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";    
}

int     Harl::getStringIndex(std::string& level)
{
    for (int i = 0; i < 4; i++)
    {
        if (_levels[i] == level)
            return (i);
    }
    return (-1);
}

void    Harl::complain( std::string level )
{
    int     index;

    index = getStringIndex(level);
    std::cout << "index:" << index << std::endl;
    switch (index)
    {
        case 0:
            ptrToLevel = &Harl::debug;
            break;
        case 1:
            ptrToLevel = &Harl::info;
            break;
        case 2:
            ptrToLevel = &Harl::warning;
            break;
        case 3:
            ptrToLevel = &Harl::error;
            break;
        default:
            std::cout << "This level Not Found\n";
    }
    this->ptrToLevel;
}

Harl::Harl()
{
    _levels[0] = "debug";
    _levels[1] = "info";
    _levels[2] = "warning";
    _levels[3] = "error";
}

Harl::~Harl()
{
    std::cout << "Harl Object Destroyed\n";
}