#include "./Fixed.hpp"


Fixed::Fixed() : _FixValue(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    setRawBits(copy._FixValue);
}


Fixed   Fixed::operator=(Fixed& copy) 
{
    std::cout << "Copy assignment operator called" << std::endl;
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
    std::cout << "getRawBits member function called" << std::endl;
    _FixValue = raw;
}