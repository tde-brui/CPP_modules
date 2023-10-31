#include <iostream>

using std::cout;
using std::endl;

class Harl
{
    private:
        std::string level;
        void debug();
        void info();
        void warning();
        void error();

    public:
        Harl();
        ~Harl();
        void complain(std::string level);
        void complain_about_everything();
        
};