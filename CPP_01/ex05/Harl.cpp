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

int     Harl::getStringIndex( const std::string& level ) const
{
    for (int i = 0; i < _levelCount; i++)
    {
        if (_levels[i] == level)
            return (i);
    }
    return (-1);
}

void    Harl::complain( std::string level )
{
    void    (Harl::*_ptrToLevel)() = NULL;

    switch (getStringIndex(level))
    {
        case 0:
            _ptrToLevel = &Harl::debug;
            break;
        case 1:
            _ptrToLevel = &Harl::info;
            break;
        case 2:
            _ptrToLevel = &Harl::warning;
            break;
        case 3:
            _ptrToLevel = &Harl::error;
            break;
        default:
            std::cerr << "This level Not Found\n";
    }
    if (_ptrToLevel)
        (this->*_ptrToLevel)();
}

Harl::Harl() : _levels{"debug", "info", "warning", "error"} {}

Harl::~Harl()
{
    std::cout << "Harl Object Destroyed\n";
}