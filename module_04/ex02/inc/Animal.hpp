#ifndef ANIMAL_H
# define ANIMAL_H
# include <iostream>

using std::cout;
using std::endl;

class Animal
{
    protected:
        std::string type;

    public:
        Animal();
        virtual ~Animal() ;
        Animal(const Animal &animal);
        Animal &operator=(const Animal &animal);
        
        std::string getType() const;
        virtual void makeSound() const = 0;
};

#endif