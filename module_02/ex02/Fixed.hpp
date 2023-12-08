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

        Fixed operator<(const Fixed &fixed) const;
        Fixed operator>(const Fixed &fixed) const;
        Fixed operator<=(const Fixed &fixed) const;
        Fixed operator>=(const Fixed &fixed) const;
        Fixed operator==(const Fixed &fixed) const;
        Fixed operator!=(const Fixed &fixed) const;

        Fixed operator+(const Fixed &fixed) const;
        Fixed operator-(const Fixed &fixed) const;
        Fixed operator*(const Fixed &fixed) const;
        Fixed operator/(const Fixed &fixed) const;

        Fixed &operator++(); //pre-increment
        Fixed operator++(int); //post-increment
        Fixed &operator--(); //pre-decrement
        Fixed operator--(int); //post-decrement

        Fixed &min(Fixed &fixed1, Fixed &fixed2);
        Fixed &min(Fixed const &fixed1, &Fixed const &fixed2);
        Fixed &max(Fixed &fixed1, Fixed &fixed2);
        Fixed &max(Fixed const &fixed1, Fixed const &fixed2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);


#endif