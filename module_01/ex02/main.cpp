#include <iostream>
using std::cout;
using std::endl;

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str; // points to the address of str
    std::string &stringREF = str; // is a reference to the value of str

    cout << "Memory address of str:           " << &str << endl;
    cout << "Memory address held by stringPTR " << stringPTR << endl;
    cout << "Memory address held by stringREF " << &stringREF << endl;

    cout << "Value of str:                    " << str << endl;
    cout << "Value held by stringPTR          " << *stringPTR << endl; // derefences the pointer to get the value
    cout << "Value held by stringREF          " <<  stringREF << endl;
}