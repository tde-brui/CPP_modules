#include <iostream>

class Contact{
    public:
        void    set_first_name();
        void    set_last_name();
        void    set_nickname();
        void    set_phone_number();
        void    set_darkest_secret();
        void    print_contacts(Contact contact[]);
        void    print_contact_info(std::string str);
        void    print_single_contact(Contact contact, int index);

    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
};

class Phonebook
{
    private:
        int index;
        Contact contact[8];
    public:
        Phonebook();
        ~Phonebook();
        void    Add_Contact();
        void    Search_Contact();
};