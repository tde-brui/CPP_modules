using namespace std;
#include "Contact.hpp"

class Phonebook
{
    private:
        int index;
        Contact Contact[8];
    public:
        void Add_Contact();
        void Search_Contact();
};