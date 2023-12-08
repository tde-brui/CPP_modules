#include "Fixed.hpp"
#include <cmath>

//Default constructor
Fixed::Fixed()
{
    this->value = 0;
}

//Copy constructor
Fixed::Fixed(const Fixed &fixed)
{
    this->value = fixed.getRawBits();
}

//Copy assignment operator
Fixed &Fixed::operator=(const Fixed &fixed)
{
    if (this != &fixed)
        this->value = fixed.getRawBits();
    return (*this);
}

//Destructor
Fixed::~Fixed()
{
}

Fixed::Fixed(const int value)
{
    this->value = value << this->fractional_bits;
}

Fixed::Fixed(const float value)
{
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

Fixed Fixed::operator<(const Fixed &fixed) const
{
    Fixed res(this->toFloat() < fixed.toFloat());

    return (res);
}

Fixed Fixed::operator>(const Fixed &fixed) const
{
    Fixed res(this->toFloat() > fixed.toFloat());

    return (res);
}

Fixed Fixed::operator>=(const Fixed &fixed) const
{
    Fixed res(this->toFloat() >=  fixed.toFloat());

    return (res);
}

Fixed Fixed::operator<=(const Fixed &fixed) const
{
    Fixed res(this->toFloat() <= fixed.toFloat());

    return (res);
}

Fixed Fixed::operator==(const Fixed &fixed) const
{
    Fixed res(this->toFloat() == fixed.toFloat());

    return (res);
}

Fixed Fixed::operator!=(const Fixed &fixed) const
{
    Fixed res(this->toFloat() != fixed.toFloat());

    return (res);
}
Fixed Fixed::operator+(const Fixed &fixed) const
{
    Fixed res(this->toFloat() + fixed.toFloat());

    return (res);
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    Fixed res(this->toFloat() - fixed.toFloat());

    return (res);
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    Fixed res(this->toFloat() * fixed.toFloat());

    return (res);
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    Fixed res(this->toFloat() / fixed.toFloat());

    return (res);
}

Fixed &Fixed::operator++()
{
    this->value += 1;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);

    this->value += 1;
    return (tmp);
}

Fixed &Fixed::operator--()
{
    this->value -= 1;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);

    this->value -= 1;
    return (tmp);
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
    
}