#include <iostream>
using std::cout;
using std::endl;

class Zombie
{
    private:
        std::string name;
    
    public:
        void announce(void);
        Zombie(std::string name);
        ~Zombie();
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);