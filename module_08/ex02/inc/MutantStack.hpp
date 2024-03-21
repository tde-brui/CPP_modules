#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() {};
        ~MutantStack() {};
        MutantStack(const MutantStack &mutantstack) { *this = mutantstack; };
        MutantStack &operator=(const MutantStack &mutantstack) { (void)mutantstack; return *this; };
        using iterator = typename Container::iterator;

        iterator begin()
        {
           return this->c.begin(); 
        }
        iterator end()
        {
            return this->c.end();
        }
};