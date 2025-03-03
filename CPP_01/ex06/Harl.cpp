#include "./Harl.hpp"

void    Harl::debug( void )
{
    std::cout << "[ DEBUG ]\n";

    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n\n";
}

void    Harl::info( void )
{
    std::cout << "[ INFO ]\n";
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";    
}

void    Harl::warning( void )
{
    std::cout << "[ WARNING ]\n";
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n\n";    
}

void    Harl::error( void )
{
    std::cout << "[ ERROR ]\n";
    std::cout << "This is unacceptable! I want to speak to the manager now.\n\n";    
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
    switch (getStringIndex(level))
    {
        case 0:
            (this->*_ptrToLevels[0])();
            /* fall through */
        case 1: 
            (this->*_ptrToLevels[1])();
            // fall through
        case 2:
            (this->*_ptrToLevels[2])();
            /* fall through */
        case 3: 
            (this->*_ptrToLevels[3])();
            break;
        default:
            std::cerr << "[ Probably complaining about insignificant problems ]\n";
    }
}

Harl::Harl()
{
    _levels[0] = "DEBUG";
    _levels[1] = "INFO";
    _levels[2] = "WARNING";
    _levels[3] = "ERROR";

    _ptrToLevels[0] = &Harl::debug;
    _ptrToLevels[1] = &Harl::info;
    _ptrToLevels[2] = &Harl::warning;
    _ptrToLevels[3] = &Harl::error;
}

Harl::~Harl() {}