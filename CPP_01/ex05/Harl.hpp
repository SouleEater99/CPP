#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
private:
    std::string _levels[4];
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

public:
    void    (Harl::*ptrToLevel)();
    void complain( std::string level );
    int  getStringIndex(std::string& level);
    Harl();
    ~Harl();
};


#endif