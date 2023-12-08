#include "Fixed.hpp"

Fixed::Fixed()
{
    cout << "Default constructor called" << endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
    cout << "Copy constructor called" << endl;
    this->value = fixed.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    cout << "Copy assignment operator called" << endl;
    if (this != &fixed)
        this->value = fixed.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    cout << "Destructor called" << endl;
}

int Fixed::getRawBits(void) const
{
    cout << "getRawBits member function called" << endl;
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
    cout << this->value;
}
