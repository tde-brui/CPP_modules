#include <iostream>
using std::cout;
using std::endl;

class Zombie
{
    private:
        std::string name;
    
    public:
        void announce(void);
        void set_name(std::string name);
        Zombie();
        ~Zombie();
};

Zombie *newZombie(std::string name);
Zombie* zombieHorde(int N, std::string name);