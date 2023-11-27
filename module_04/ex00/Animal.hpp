#include <iostream>

class Animal
{
    private:
        std::string type;

    public:
        Animal();
        ~Animal();
        Animal(const Animal &animal);
        Animal &operator=(const Animal &animal);
        
        std::string getType();
        void makeSound();

};
