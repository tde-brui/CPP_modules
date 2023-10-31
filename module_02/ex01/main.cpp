#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.4321f);

    cout << "a is " << endl;
    cout << "b is " << endl;
    cout << "c is " << endl;
    cout << "d is " << endl;

    cout << "a is " << a.toInt() << " as integer" << endl;
    cout << "b is " << b.toInt() << " as integer" << endl;
    cout << "c is " << c.toInt() << " as integer" << endl;
    cout << "d is " << d.toInt() << " as integer" << endl;

    return (0);
}