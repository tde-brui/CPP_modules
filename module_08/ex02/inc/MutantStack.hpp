#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() {};
        ~MutantStack() {};
        MutantStack(const MutantStack &mutantstack) { *this = mutantstack; };
        MutantStack &operator=(const MutantStack &mutantstack) { (void)mutantstack; return *this; };
        using iterator = typename std::deque<T>::iterator;

        iterator begin()
        {
           return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
};