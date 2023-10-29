#include <iostream>
#include <string.h>
#include "phonebook.hpp"

int main()
{
    Phonebook Phonebook;
    std::string  input;
    std::cout << "OPTIONS:" << endl << "ADD" << endl << "SEARCH" << endl << "EXIT" << endl;
    while (1)
    {
        std::cout << "Please enter an option: ";
        getline(cin, input);
        if (input == "ADD")
            Phonebook.Add_Contact();
        else if (input == "SEARCH")
            Phonebook.Search_Contact();
        else if (input == "EXIT")
            break ;
        else
            std::cout << "Please enter a valid option" << endl;
    }
}