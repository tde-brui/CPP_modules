#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

using std::cout;
using std::endl;

class Fixed
{
    private:
        int value;
        static const int fractional_bits = 8;

    public:
        Fixed();
        ~Fixed();

        Fixed(const Fixed &fixed);
        Fixed &operator=(const Fixed &fixed);

        Fixed(const int value);
        Fixed(const float value);

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;

        //comparison operators
        Fixed operator<(const Fixed &fixed) const;
        Fixed operator>(const Fixed &fixed) const;
        Fixed operator<=(const Fixed &fixed) const;
        Fixed operator>=(const Fixed &fixed) const;
        Fixed operator==(const Fixed &fixed) const;
        Fixed operator!=(const Fixed &fixed) const;

        //arithmetic operators
        Fixed operator+(const Fixed &fixed) const;
        Fixed operator-(const Fixed &fixed) const;
        Fixed operator*(const Fixed &fixed) const;
        Fixed operator/(const Fixed &fixed) const;

        //increment and decrement operators
        Fixed &operator++(); //pre-increment
        Fixed operator++(int); //post-increment
        Fixed &operator--(); //pre-decrement
        Fixed operator--(int); //post-decrement

        static Fixed &min(Fixed &fixed1, Fixed &fixed2);
        static const Fixed &min(Fixed const &fixed1, Fixed const &fixed2);
        static Fixed &max(Fixed &fixed1, Fixed &fixed2);
        static const Fixed &max(Fixed const &fixed1, Fixed const &fixed2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);


#endif