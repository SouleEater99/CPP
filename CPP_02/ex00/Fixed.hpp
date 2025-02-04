#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _FixValue;
    static const int _FracBits = 8;
public:
    Fixed();
    Fixed(Fixed& copy);
    Fixed&   operator=(Fixed& copy);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};


#endif
