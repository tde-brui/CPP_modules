#ifndef ANIMAL_H
# define ANIMAL_H
# include <iostream>

using std::cout;
using std::endl;

class Animal
{
    private:
        std::string type;

    public:
        Animal();
        virtual ~Animal() ;
        Animal(const Animal &animal);
        Animal &operator=(const Animal &animal);
        
        virtual std::string getType() const;
        virtual void makeSound() const;

};

#endif