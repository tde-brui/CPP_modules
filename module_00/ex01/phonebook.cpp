#include <iostream>
#include <string>
#include <sstream>
#include "phonebook.hpp"

Phonebook::Phonebook()
{
    this->index = 0;
}

Phonebook::~Phonebook()
{
}

void Phonebook::Search_Contact()
{
    int input_index;
    std::string index_string;
    std::istringstream s;

    contact[index].print_contacts(contact);
    std::cout << "Which index would you like to see? ";
    getline(std::cin, index_string);
    s.str(index_string);
    if (s >> input_index && input_index >= 0 && input_index <= 7)
        contact[input_index].print_single_contact(contact[input_index], input_index);
    else
        std::cout << "Error: Invalid index" << endl << "Returning to options" << endl;
}

void Phonebook::Add_Contact()
{
    std::cout << "First name: ";
    contact[index].set_first_name();
    std::cout << "Last name: ";
    contact[index].set_last_name();
    std::cout << "Nickname: ";
    contact[index].set_nickname();
    std::cout << "Phone number: ";
    contact[index].set_phone_number();
    std::cout << "Darkest secret: ";
    contact[index].set_darkest_secret();
    if (index < 7)
        this->index++;
    else
        this->index = 0;
}