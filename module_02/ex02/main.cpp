#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    cout << a << endl;
    cout << ++a << endl;
    cout << a << endl;
    cout << a++ << endl;
    cout << a << endl;

    cout << b << endl;
    cout << Fixed::max(a, b) << endl;

    Fixed c(10.5f);
    Fixed d(10);
    if (c < d)
        cout << "c is less than d" << endl;
    if (c > d)
        cout << "c is greater than d" << endl;
    if (c == d)
        cout << "c is equal to d" << endl;
    if (c != d)
        cout << "c is not equal to d" << endl;
    if (c >= d)
        cout << "c is greater than or equal to d" << endl;
    cout << "c + d = " << c + d << endl;
    cout << "c - d = " << c - d << endl;
}