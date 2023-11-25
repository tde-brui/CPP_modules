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
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif