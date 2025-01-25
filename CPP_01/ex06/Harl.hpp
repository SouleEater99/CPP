#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
private:
    static const int    _levelCount = 4;
    std::string _levels[_levelCount];
    void    (Harl::*_ptrToLevels[_levelCount])();
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

public:
    void complain( std::string level );
    int  getStringIndex( const std::string& level) const ;
    Harl();
    ~Harl();
};


#endif