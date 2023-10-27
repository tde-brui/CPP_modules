using namespace std;
#include <iostream>
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
    string temp;
    int    input_index;

    contact[index].print_contacts(contact);
    cout << "Which index would you like to see? ";
    getline(cin, temp);
    cout << atoi("d") << endl;
    input_index = atoi(temp.c_str());
    if (input_index < 0 || input_index > 7)
        cout << "Error: invalid index" << endl << "Returning to options" << endl;
    else
        contact[input_index].print_single_contact(contact[input_index], input_index);
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
        this->index++;
    else
        this->index = 0;
}