#include <iostream>
#include <string.h>
#include "phonebook.hpp"

void Contact::set_first_name()
{
    getline(cin, first_name);
}

void Contact::set_last_name()
{
    getline(cin, last_name);
}

void Contact::set_nickname()
{
    getline(cin, nickname);
}

void Contact::set_phone_number()
{
    getline(cin, phone_number);
}

void Contact::set_darkest_secret()
{
    getline(cin, darkest_secret);
}

void Contact::print_single_contact(Contact contact, int index)
{
    std::cout << "         " << index << "|";
    print_contact_info(contact.first_name);
    print_contact_info(contact.last_name);
    print_contact_info(contact.nickname);
    std::cout << endl;
}

void Contact::print_contacts(Contact contact[])
{
    int i;

    i = 0;
    std::cout << "     Index|First Name| Last Name|  Nickname" << endl;
    while (i < 8)
    {
        std::cout << "         " << i << "|";
        print_contact_info(contact[i].first_name);
        print_contact_info(contact[i].last_name);
        print_contact_info(contact[i].nickname);
        i++;
        std::cout << endl;
    }
}

void Contact::print_contact_info(string str)
{
    int rest_spaces;

    if (str.length() > 10)
    {
        str.resize(9);
        std::cout << str << ".|";
    }
    else
    {
        rest_spaces = 10 - str.length();
        while (rest_spaces > 0)
        {
            std::cout << " ";
            rest_spaces--;
        }
        std::cout << str;
        std::cout << "|";
    }
}