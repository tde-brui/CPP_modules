using namespace std;
#include <iostream>
#include "phonebook.hpp"

Phonebook::Phonebook()
{
    index = 0;
}

Phonebook::~Phonebook()
{
}

void Phonebook::Search_Contact()
{
    contact[index].print_contacts(contact);
    cout << "Which index would you like to see? ";
    cin >> index;
    if (index < 0 || index > 7)
        cout << "Error: invalid index" << endl << "Returning to options" << endl;
    else
        cout << "LOL";
}

void Phonebook::Add_Contact()
{
    cout << "First name: ";
    contact[index].set_first_name();
    cout << "Last name: ";
    contact[index].set_last_name();
    cout << "Nickname: ";
    contact[index].set_nickname();
    cout << "Phone number: ";
    contact[index].set_phone_number();
    cout << "Darkest secret: ";
    contact[index].set_darkest_secret();
    if (index < 7)
        index++;
    else
        index = 0;
}