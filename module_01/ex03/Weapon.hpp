#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

using std::cout;
using std::endl;

class Weapon
{
    private:
        std::string type;
    
    public:
        const std::string &getType();
        void setType(std::string type);
        Weapon(std::string weapon);

};

#endif