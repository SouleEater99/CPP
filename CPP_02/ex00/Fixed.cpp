#include "./Fixed.hpp"


Fixed::Fixed(int value = 0) : _FixValue(value) {}

Fixed::Fixed(Fixed& copy)
{
    setRawBits(copy._FixValue);
}


Fixed   Fixed::operator=(Fixed& copy) 
{
    return Fixed(copy);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    return (_FixValue);
}

void Fixed::setRawBits( int const raw )
{
    _FixValue = raw;
}