#ifndef CAT_H
# define CAT_H
# include "Animal.hpp"

class Cat : public Animal
{

    private:
        std::string type;
    
    public:
        Cat();
        ~Cat();
        Cat(const Cat &cat);
        Cat &operator=(const Cat &cat);

        void makeSound() const;
        std::string getType() const;
};

#endif