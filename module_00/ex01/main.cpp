#include <iostream>
#include <string.h>
#include "phonebook.hpp"

int main()
{
    Phonebook Phonebook;
    std::string  input;
    std::cout << "OPTIONS:" << std::endl << "ADD" << std::endl << "SEARCH" << std::endl << "EXIT" << std::endl;
    while (1)
    {
        std::cout << "Please enter an option: ";
        std::getline(std::cin, input);
        if (input == "ADD")
            Phonebook.Add_Contact();
        else if (input == "SEARCH")
            Phonebook.Search_Contact();
        else if (input == "EXIT")
            break ;
        else
            std::cout << "Please enter a valid option" << std::endl;
    }
}