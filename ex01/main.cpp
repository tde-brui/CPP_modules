using namespace std;
#include <iostream>
#include <string.h>
#include "phonebook.hpp"

int main()
{
    Phonebook Phonebook;
    string  input;
    cout << "OPTIONS:" << endl << "ADD" << endl << "SEARCH" << endl << "EXIT" << endl;
    while (1)
    {
        cin >> input;
        if (input == "ADD")
            Phonebook.Add_Contact();
        else if (input == "SEARCH")
            Phonebook.Search_Contact();
        else if (input == "EXIT")
            break ;
        else
            cout << "Please enter a valid option" << endl;
    }
}