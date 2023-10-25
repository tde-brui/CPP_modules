using namespace std;

class Contact{
    public:
        void    set_first_name();
        void    set_last_name();
        void    set_nickname();
        void    set_phone_number();
        void    set_darkest_secret();
        void    print_contacts(Contact contact[]);
    
    private:
        string first_name;
        string last_name;
        string nickname;
        string phone_number;
        string darkest_secret;
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