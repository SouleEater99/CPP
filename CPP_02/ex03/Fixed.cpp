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

bool    Fixed::operator > (const Fixed& other) const
{
    if (this->_FixValue > other._FixValue)
        return true;
    return false;
}

bool    Fixed::operator < (const Fixed& other) const
{
    if (this->_FixValue < other._FixValue)
        return true;
    return false;
}

bool    Fixed::operator >= (const Fixed& other) const
{
    if (this->_FixValue >= other._FixValue)
        return true;
    return false;
}

bool    Fixed::operator <= (const Fixed& other) const
{
    if (this->_FixValue <= other._FixValue)
        return true;
    return false;
}

bool    Fixed::operator == (const Fixed& other) const
{
    if (this->_FixValue == other._FixValue)
        return true;
    return false;
}

bool    Fixed::operator != (const Fixed& other) const
{
    if (this->_FixValue != other._FixValue)
        return true;
    return false;
}


Fixed  Fixed::operator + (const Fixed& other) const
{
    return (Fixed(this->getRawBits() + other.getRawBits()));
}

Fixed  Fixed::operator - (const Fixed& other) const
{
    return (Fixed(this->getRawBits() - other.getRawBits()));
}

Fixed  Fixed::operator * (const Fixed& other) const
{
    Fixed       fixed;
    long long   result;
    int         new_raw;

    result = (long long)this->getRawBits() * other.getRawBits();
    new_raw = result >> this->_FracBits;

    fixed.setRawBits(new_raw);
    return (fixed);
}

Fixed  Fixed::operator / (const Fixed& other) const
{
    Fixed       fixed;
    long long   result;
    int         new_raw;

    if (other.getRawBits() == 0)
    {
        std::cerr << "Division by Zero\n";
        return fixed;
    }
    result = (long long)this->getRawBits() << this->_FracBits;
    new_raw = result / other.getRawBits();

    fixed.setRawBits(new_raw);
    return (fixed);
}


Fixed&   Fixed::operator ++ ()
{
    this->_FixValue++;
    return *this;
}

Fixed   Fixed::operator ++ (int)
{
    Fixed tmp(*this);

    this->_FixValue++;
    return tmp;
}

Fixed&   Fixed::operator -- ()
{
    this->_FixValue--;
    return *this;
}

Fixed   Fixed::operator -- (int)
{
    Fixed tmp(*this);

    this->_FixValue--;
    return tmp;
}


Fixed&  Fixed::min(Fixed& a, Fixed& b)
{
    if (a <= b)
        return (a);
    return b;
}

const Fixed&  Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a <= b)
        return (a);
    return b;
}

Fixed&  Fixed::max(Fixed& a, Fixed& b)
{
    if (a >= b)
        return (a);
    return b;
}

const Fixed&  Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a >= b)
        return (a);
    return b;
}