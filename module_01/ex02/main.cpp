#include <iostream>
using std::cout;
using std::endl;

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    cout << "Memory address of str:           " << &str << endl;
    cout << "Memory address held by stringPTR " << stringPTR << endl;
    cout << "Memory address held by stringREF " << &stringREF << endl;

    cout << "Value of str:                    " << str << endl;
    cout << "Value held by stringPTR          " << *stringPTR << endl;
    cout << "Value held by stringREF          " <<  stringREF << endl;
}