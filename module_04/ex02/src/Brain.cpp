#include "../inc/Brain.hpp"

Brain::Brain()
{
    cout << "Brain constructed" << endl;
}

Brain::Brain(const Brain &brain)
{
    cout << "Brain constructed" << endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = brain.ideas[i];
    cout << "Brain constructed" << endl;
}

Brain &Brain::operator=(const Brain &brain)
{
    if (this != &brain)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = brain.ideas[i];
    }
    cout << "Brain constructed" << endl;
    return (*this);
}

Brain::~Brain()
{
    cout << "Brain destructed" << endl;
}