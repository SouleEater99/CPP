#include "./Fixed.hpp"

Fixed::Fixed(): _FixValue(0) 
{
    std::cout << "Default constructor called" << std::endl;
} 

Fixed::Fixed(const int value) 
{
    std::cout << "Int constructor called" << std::endl;
    _FixValue = value << _FracBits;
}

Fixed::Fixed(const float value) 
{
    std::cout << "Float constructor called" << std::endl;
    _FixValue = roundf(value * (1 << _FracBits));
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}


Fixed&   Fixed::operator=(const Fixed& copy) 
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

float   Fixed::toFloat( void ) const
{
    return (float)_FixValue / (1 << _FracBits);
}


int     Fixed::toInt( void ) const
{
    return _FixValue >> _FracBits;
}

std::ostream&    operator << (std::ostream& out, const Fixed& other)
{
    out << other.toFloat();
    return out;
}