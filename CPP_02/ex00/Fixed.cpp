#include "./Fixed.hpp"


Fixed::Fixed() : _FixValue(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}


Fixed&   Fixed::operator=(Fixed& copy) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_FixValue = copy.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_FixValue);
}

void Fixed::setRawBits( int const raw )
{
    _FixValue = raw;
}