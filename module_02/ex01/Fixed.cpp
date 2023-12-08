#include "Fixed.hpp"
#include <cmath>

//Default constructor
Fixed::Fixed()
{
    cout << "Default constructor called" << endl;
    this->value = 0;
}

//Copy constructor
Fixed::Fixed(const Fixed &fixed)
{
    cout << "Copy constructor called" << endl;
    this->value = fixed.getRawBits();
}

//Copy assignment operator
Fixed &Fixed::operator=(const Fixed &fixed)
{
    cout << "Copy assignment operator called" << endl;
    if (this != &fixed)
        this->value = fixed.getRawBits();
    return (*this);
}

//Destructor
Fixed::~Fixed()
{
    cout << "Destructor called" << endl;
}

Fixed::Fixed(const int value)
{
    cout << "Int constructor called" << endl;
    this->value = value << this->fractional_bits;
}

Fixed::Fixed(const float value)
{
    cout << "Float constructor called" << endl;
    this->value = roundf(value * (1 << this->fractional_bits));
}

int Fixed::toInt(void) const
{
    return (this->value >> this->fractional_bits);
}

// 1 << 8 = 256 dividing by 256 is the same as shifting right by 8
float Fixed::toFloat(void) const
{
    return ((float)this->value / (float)(1 << this->fractional_bits));
}

int Fixed::getRawBits(void) const
{
    //cout << "getRawBits member function called" << endl;
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
    //cout << this->value;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}