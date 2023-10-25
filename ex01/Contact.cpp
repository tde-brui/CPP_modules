using namespace std;
#include <iostream>
#include <string.h>
#include "phonebook.hpp"

void Contact::set_first_name()
{
    cin >> first_name;
}

void Contact::set_last_name()
{
    cin >> last_name;
}

void Contact::set_nickname()
{
    cin >> nickname;
}

void Contact::set_phone_number()
{
    cin >> phone_number;
}

void Contact::set_darkest_secret()
{
    cin >> darkest_secret;
}

void Contact::print_contacts(Contact contact[])
{
    int i;

    i = 0;
    cout << "     Index|First Name| Last Name|  Nickname" << endl;
    while (i < 8)
    {
        cout << "         " << i << "|";
        cout << contact[i].first_name << "|";
        cout << contact[i].last_name << "|";
        cout << contact[i].nickname << endl;
        i++;
    }
}